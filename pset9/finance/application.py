import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter from `helpers.py` to make it easier to format values as USD
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
# Will store the session on the users disk vs digitially signed cookies,
#   which is done by default with Flask
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required  # Function from `helpers.py` to require login first
def index():
    """
    Show portfolio of stocks
    This is the main page the user will see after every "transaction"
        as long as they are logged in
        
    What I need to complete:
        Display a table with all of the current user's stocks, the number
            of shares for each stock, the current price of each stock, and
            the total value of each holding. Run a query on the table I 
            set up to hold all the stocks owned. You can get access to the 
            currently logged in user by taking a look at the value of 
            `session["user_id"]` then us the `lookup` function to get the 
            current prices for all of the stocks owned to display for the
            user and multiply that by the number of shares the user "owns".
        Display the user's current cash balance.
        Display the user's current total balance at current stock prices
    """
    # Check to make sure the user is already logged in
    if not session.get("user_id"):
        # If the user is not logged in, redirect them to the login page
        return redirect("/login")

    # Get the cash row from the database for the current user
    cash_row = db.execute("SELECT cash FROM users WHERE id = ?", 
                          session.get("user_id"))
    
    # Get the cash value for the current user in US dollars format
    cash = usd(cash_row[0]["cash"])
    
    # Get all the stocks for the current user from the data base table stocks
    stocks = db.execute("SELECT * FROM stocks WHERE user = ?",
                        session.get("user_id"))
    
    # Get all the stock symbols only from the data base for the ones the 
    #   current user owns
    symbol = db.execute("SELECT symbol FROM stocks WHERE user = ?",
                        session.get("user_id"))
    
    # Get all the shares that the current user has for each stock from the 
    #   data base table stocks
    user_shares = db.execute("SELECT shares FROM stocks WHERE user = ?",
                             session.get("user_id"))
    
    # Create a list to hold all the lookup values
    stock_lookup = []

    # Iterate through all the stock symbols the current user owns
    for sym in symbol:
        # Iterate through all the values in the symbols dictionary
        for _, val in sym.items():
            # Add the values only to the stock lookup list
            stock_lookup.append(lookup(val))

    # Pull out all the values for the current price out of the lookup 
    #   dictionary
    curr_price = [stock_lookup[i]["price"] for i in range(len(stock_lookup))]
    
    # Create a shares list to hold the values of the number of shares the 
    #   user holds
    shares = []

    # Iterate through the user shares 
    for share in user_shares:
        # Iterate through the values only in the user shares
        for _, val in share.items():
            # Add the values only to the shares list
            shares.append(val)
        
    # Create a list of the stock totals based on the current 
    #   share price * the current user shares
    stock_total = [(curr_price[i] * shares[i]) for i in range(len(curr_price))]

    # Create a list with the value of the stock totals in US dollars format
    stock_totals = [{'total': usd(val)} for idx, val in enumerate(stock_total)]
    # Get the total assest value of all stocks at current value + cash that 
    #   the current user owns
    total_assests = usd(sum(stock_total) + cash_row[0]["cash"])
    
    # Break down the users stocks into a list of dictionarys
    user_stocks = [stocks[i] for i in range(len(stocks))]

    # Iterate through the stocks
    for i in range(len(stocks)):
        # Add all the values I will need to populate the database on the 
        #   index page to the user_stocks list
        user_stocks[i].update(stock_lookup[i].items())
        user_stocks[i].update(user_shares[i].items())
        user_stocks[i].update(stock_totals[i].items())
        user_stocks[i]['cost'] = usd(stocks[i]['cost'])
        user_stocks[i]['price'] = usd(stock_lookup[i]['price'])
    
    # Return the rendered template of index with the variables 
    #   total_assests, stocks, and cash
    return render_template("index.html", total_assets=total_assests,
                           stocks=user_stocks, cash=cash)

    # Currently just returns an apology message to the user "TODO"
    # Can you this apology function where needed as a placeholder when 
    #   something is not completed yet or being worked on.
    # You can put any message you want the user to see as the parameter
    # return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required  # Function from `helpers.py` to require login first
def buy():
    """
    Buy shares of stock
    Need to display a form for the user to type what stock they want to buy
    Also needs to handle the logic of purchasing a stock
    
    What I need to complete:
        When requested via GET, should display a form for the user to buy a 
            stock. (Name of the stock to buy and the number of shares)
        When form is submitted via POST, purchase the stock as long as the 
            user can afford it. Need to query the current database for the 
            user to make sure the user has enough available "money". The user's
            cash value is stored in the `users` table. Then multiply the 
            current price of the stock (found via `lookup` function) by the
            number of shares the user wants to buy and compare that to their
            cash value. 
        Need to set up the logic to "purchase" the stock. You will likely need
            to add one or more tables to the database. The only table currently
            in the database is `users`. Things to keep track of:
                What the name of the stock is?
                The Stock symbol.
                The user's id (to reference back to the `users` table)
                How many shares.
                The cost at purchase per stock.
        Can access the DB by going to the terminal and typing the following:
            `sqlite3 finance.db`  <-- Puts me in the sqlite command prompt
            `SELECT * FROM users;`  <-- Selects all users from the users table
            `.schema users`  <-- Shows how the table was created
            `CREATE TABLE...`  <-- To create a new table in the DB
        Display the results of the buy by redirecting back to index.
    """
    # Check to make sure the user is already logged in
    if not session.get("user_id"):
        # If not logged in, redirect the user to the login page
        return redirect("/login")
        
    # Get the cash row from the database for the current user 
    cash_row = db.execute("SELECT cash FROM users WHERE id = ?", 
                          session.get("user_id"))
    
    # Get the cash value for the current user in US dollars format
    cash = cash_row[0]["cash"]
    
    # If POST is sent as the request method...
    if request.method == "POST":
        # Get the symbol the user entered in the form
        sym = request.form.get("symbol")
        # Get the shares the user wants to purchase
        shares = request.form.get("shares")

        # Check if the shares are inputted as a number
        if not shares.isdigit():
            return apology("Must enter a Valid Number!\nPlease try again!")
        
        # Check if shares is empty or 0 or negative number
        elif shares == [] or int(shares) < 1:
            return apology("Invalid number of shares.\nPlease try again!")
        
        # Get the current price for the stock the user inputted
        stocks = lookup(sym)
        
        # Check if the user inputted a valid stock
        if stocks is None or sym is None:
            return apology("I could not find that stock.\nPlease try again!")

        # Get the stock symbol from the stock lookup
        symbol = stocks["symbol"].upper()
        # Get the name from the stock lookup
        name = stocks["name"]
        # Get the current price from the stock lookup
        curr_price = stocks["price"]
        # Calculate the current user's cost based on 
        #   the current price per share * number of shares
        cost = curr_price * int(shares)
        
        # Verify that the user has enough available cash to purchase the stock
        if cost <= cash:
            # Get the user's current stocks if they already own the stock
            #   they are wanting to purchase shares for
            user_stocks = db.execute("""
                            SELECT symbol, shares, cost 
                            FROM stocks WHERE user = ? AND symbol = ?
                            """, session.get("user_id"), symbol)

            # If the user does not currently own any of this stock...
            if user_stocks == [] or symbol != user_stocks[0]['symbol']:
                # Need to add a new stock with the user's id
                db.execute(
                    """
                    INSERT INTO stocks (
                        user, symbol, name, shares, cost
                            ) VALUES (?, ?, ?, ?, ?)
                    """, session.get("user_id"), symbol, name, shares, cost
                )
            
            else:  # Otherwise, if the user already owns some shares
                # Need to update the share and cost amount 
                #   to reflect new shares
                db.execute("""
                        UPDATE stocks SET shares = ?, cost = ? 
                        WHERE user = ? AND symbol = ?
                        """, user_stocks[0]['shares'] + int(shares), 
                           user_stocks[0]['cost'] + cost, 
                           session.get("user_id"), symbol)
                    
            # Add the transaction to the history table in the database
            db.execute(
                """
                INSERT INTO history (
                    user, symbol, name, shares, amount
                        ) VALUES (?, ?, ?, ?, ?)
                """, session.get("user_id"), symbol, name, 
                shares, -(cost))
                
            # Need to subtract the total cost of the new shares from the 
            #   cash value for user in the data base
            db.execute(
                """
                UPDATE users SET cash = ? WHERE id = ?
                """, cash - cost, session.get("user_id"))
        
        else:  # Otherwise, the user does not have enough money to purchase
            return apology("You do not have enough money.\nPlease try again.")
        
        # Once the transaction is complete, return the user to their portfolio
        return redirect("/")
    
    else:
        return render_template("buy.html", cash=usd(cash))


@app.route("/history")
@login_required  # Function from `helpers.py` to require login first
def history():
    """
    Show history of transactions
    Need to display the history of all the transactions that the user has
        made in a table on the page
    
    What I need to complete:
        Could impliment a new table to keep track of this information. 
            (When bought or sold, What stock, How many shares, Cost)
        Display a table with a history of all transactions, listed row by 
            row every buy and sell.
    """
    # Check to make sure the user is already logged in
    if not session.get("user_id"):
        # If not logged in, redirect the user to the login page
        return redirect("/login")
    
    # Get the current user's history of transactions
    user_history = db.execute("SELECT * FROM history WHERE user = ?",
                              session.get("user_id"))

    # Iterate through the user's history
    for i in range(len(user_history)):
        # Change the amount format to US dollars format
        user_history[i]['amount'] = usd(user_history[i]['amount'])
    
    # Show the user their history from the data base
    return render_template("history.html", history=user_history)


# Do not need to do anything with this route, it is already all set up
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        # The way CS50 implimented this 
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        # Stores the users "id" in the Flask session by taking the 1 and only
        #   row in the rows list and grabbing the value from the "id" column
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


# Do not need to do anything with this route, it has already been completed
@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required  # Function from `helpers.py` to require login first
def quote():
    """
    Get stock quote.
    Need to impliment a form that lets the user look up a stock qoute
    
    What I need to complete:
        When requested via GET, should display a form to request a stock
            qoute. (Name of the stock the user is wanting a qoute for)
        When form is submitted via POST, lookup the stock symbol by
            calling the `lookup` function from the `helpers.py` file, 
            and display the results.
        If the stock symbol is invalid, `lookup` will return None. Need to set 
            up some kind of message to inform the user that the stock symbol
            was not found or is invalid if this occurs.
    """
    # Check to make sure the user is already logged in
    if not session.get("user_id"):
        # If not logged in, redirect the user to the login page
        return redirect("/login")
    
    # If POST is sent as the request method...
    if request.method == "POST":
        # Get the symbol that the user inputted
        sym = request.form.get("symbol")
        # Look up the stock for the symbol the user inputted
        stocks = lookup(sym)
        
        # If the stock symbol is not valid
        if stocks is None:
            # Return error message page
            return apology("I could not find that stock.\nPlease try again.")
        
        # Get the name of the stock from the lookup
        name = stocks["name"]
        # Get the symbol of the stock from the lookup
        symbol = stocks["symbol"]
        # Get the current price for the stock from the lookup
        curr_price = usd(stocks["price"])
        
        # Return the template to display the quote with the name, symbol,
        #   and current price
        return render_template("quote.html", name=name,
                               symbol=symbol,
                               curr_price=curr_price)
    
    else:  # Otherwise, if a GET request, forward user to quote form
        return render_template("quote_form.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """
    Register user
    Need to create a form that allows the user to register with a user name
        and password 
    
    What I need to complete:
        When requested via GET, should display registration form 
            (HINT: add a password confirmation field also)
        When form is submitted via POST, insert the new user into the 
            `users` table or return an apology message if error 
            (i.e. passwords, origin and confirmation, don't match, or 
            wrong username and pasword) then take back to registration
            if error occurred. Otherwise take to index
        Be sure to check for invalid inputs, and to hash the user's password
    """
    # Forget any user_id
    session.clear()
        
    # If POST is sent as the request method...
    if request.method == "POST":
        # Get the username the user would like
        name = request.form.get("username")
        # Get the password the user wants to use
        password = request.form.get("password")
        # Get the confirmation password to confirm a match
        conf_pass = request.form.get("confirmation")
        
        # If the user does not enter a username...
        if not name:
            # Send them to error message page
            return apology("Need to enter a username. Please try again!")
        
        # If the user did not enter their password twice...
        if not password or not conf_pass:
            # Send them to error message page
            return apology(
                "Need to enter your password twice. Please try again!"
            )
        
        # If the user's passwords do not match
        if password != conf_pass:
            # Send them to error message page
            return apology("Your passwords do not match. Please try again!")
        
        # Look for a duplicate username in the data base
        no_dup = db.execute("SELECT * FROM users WHERE username = ?", name)
            
        # If that username is already in the data base
        if no_dup:
            # Send them to error message page
            return apology(
                "Username already exists.\nLog in or try another username."
            )
        
        # Hash the user's password to store in the data base
        hashed_pw = generate_password_hash(password)
        # Add the username and hashed password into the user's data base table
        db.execute(
            "INSERT INTO users (username, hash) VALUES(:username, :hash)", 
            username=name, hash=hashed_pw
        )
            
        # Get the row where the username is in the data base
        rows = db.execute("SELECT * FROM users WHERE username = ?", 
                          name)
        # The `:username` is like a placeholder for the username

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        # Stores the users "id" in the Flask session by taking the 1 and only
        #   row in the rows list and grabbing the value from the "id" column
        session["user_id"] = rows[0]["id"]

        # Send the user to the portfolio page
        return redirect("/")
    
    else:  # Otherwise, sent a GET request, need to send to register form
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required  # Function from `helpers.py` to require login first
def sell():
    """
    Sell shares of stock
    Need to impliment a way to allow the user to sell stocks
    
    What I need to complete:
        When requested via GET, should display a form to sell a stock.
            (What stock to sell and how many shares)
        When form is submitted via POST, "sell" the specified number of
            shares of stock, and update the user's cash based on the number
            of shares selling * the current price of the stock.
        Check to make sure the user owns that stock and that many shares
        Update table that is keeping track of the stock the users have
    """
    # Check to make sure the user is already logged in
    if not session.get("user_id"):
        # If not logged in, redirect the user to the login page
        return redirect("/login")
        
    # Get the cash value for the current user from the data base
    cash_row = db.execute("SELECT cash FROM users WHERE id = ?", 
                          session.get("user_id"))
    # Get the user's cash value
    cash = cash_row[0]["cash"]
    
    # Get the user's owned stock symbols from the data base
    user_symbols = db.execute("SELECT symbol FROM stocks WHERE user = ?",
                              session.get("user_id"))
                                
    # Put the values of the symbols into a list
    symbols = [val for i in range(len(
        user_symbols)) for _, val in user_symbols[i].items()]
    
    # If POST is sent as the request method...
    if request.method == "POST":
        # Get the stock symbol the user inputted
        sym = request.form.get("symbol")
        # Get the number of shares the user inputted
        shares = int(request.form.get("shares"))
        # Get the current values for the stock based on the symbol entered
        stocks = lookup(sym)
        # Get the current price of the stock from the loopkup
        curr_price = stocks["price"]
        # Calculate the current cost based on current price * shares
        cost = curr_price * int(shares)
        
        # Get the user's current stocks if any match the symbol entered
        user_stocks = db.execute("""
                                SELECT shares, cost
                                    FROM stocks 
                                    WHERE user = ? and symbol = ?
                                """, session.get("user_id"), sym)
                                
        # Check to make sure the user entered less than or = number of shares
        #   they currently have
        if 0 < shares <= user_stocks[0]['shares']:
            # If the shares they entered are = to the shares they own...
            if shares == user_stocks[0]['shares']:
                # Delete the whole row from the data base for that user
                db.execute(
                    "DELETE FROM stocks WHERE user = ? AND symbol = ?", 
                    session.get("user_id"), sym)
                    
            # If the shares they entered are less than the shares they own...
            elif shares < user_stocks[0]['shares']:
                # Subtract the number of shares entered
                db.execute("""
                        UPDATE stocks SET shares = ?, cost = ? 
                            WHERE user = ? and symbol = ?
                        """, user_stocks[0]['shares'] - shares, 
                           user_stocks[0]['cost'] - cost, 
                           session.get("user_id"), sym)

            # Add the transaction to the history table in the data base
            db.execute(
                """
                INSERT INTO history (
                    user, symbol, name, shares, amount
                        ) VALUES (?, ?, ?, ?, ?)
                """, session.get("user_id"), sym, stocks["name"], 
                -(shares), cost)
                
            # Update the user's cash to reflect the sale
            db.execute(
                """
                UPDATE users SET cash = ? WHERE id = ?
                """, cash + cost, session.get("user_id"))
        
        else:  # Otherwise, they enter an invalid number of shares
            return apology("You entered an Invalid\nNumber of Shares.\nPlease try again!\n")
        
        # Return the user to the portfolio page
        return redirect("/")
    
    else:  # Otherwise, sent a GET request, send user to sell form
        return render_template("sell.html", cash=usd(cash), symbols=symbols)


"""
Add a function that has a Personal Touch

Some ideas to implement:
    Allow the users to change their password.
    Allow users to add cash.
    Allow buying or selling from the index page.
    Add password complexity requirements.
"""


# Do not need to do anything with this code, it is already completed
def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
