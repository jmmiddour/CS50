from cs50 import SQL
from helpers import apology, login_required, lookup, usd


# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

stocks = db.execute("SELECT * FROM stocks WHERE user = ?",
                    1)
symbol = db.execute("SELECT symbol FROM stocks WHERE user = ?",
                    1)
user_shares = db.execute("SELECT shares FROM stocks WHERE user = ?",
                         1)

print(f'Stocks: {stocks}\nSymbols: {symbol}\nShares: {user_shares}')
                    
stock_lookup = []

for sym in symbol:
    for _, val in sym.items():
        stock_lookup.append(lookup(val))

print(f'Stock Lookup: {stock_lookup}')

curr_price = [stock_lookup[i]["price"] for i in range(len(stock_lookup))]

# print(f'Current Prices: {curr_price}')

shares = []

for share in user_shares:
    for _, val in share.items():
        shares.append(val)
        
# print(f'Shares: {shares}')
    
stock_total = [(curr_price[i] * shares[i]) for i in range(len(curr_price))]

stock_totals = [{'total': usd(val)} for idx, val in enumerate(stock_total)]

# print(f'Stock Totals: {stock_totals}')

user_stocks = [stocks[i] for i in range(len(stocks))]

for i in range(len(stocks)):
    user_stocks[i].update(user_shares[i].items())
    user_stocks[i].update(stock_lookup[i].items())
    user_stocks[i].update(stock_totals[i].items())
    user_stocks[i]['cost'] = usd(stocks[i]['cost'])
    user_stocks[i]['price'] = usd(stock_lookup[i]['price'])
    
# print(f'Users Stocks:  {user_stocks}')

# print(f'3rd Index of User Stocks: {user_stocks[2]}')

# print(f'3rd Index of User Stocks - symbol only: {user_stocks[2]["symbol"]}')
