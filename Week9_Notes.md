# CS50 - Week - 9 - Flask

Resources:
- [Flask Lecture on YouTube](https://youtu.be/x_c8pTW8ZUc)

- [Lecture Notes](https://cs50.harvard.edu/x/2021/notes/9/)

- [Lecture Slides](https://docs.google.com/presentation/d/1E3N-8puMqS2545GR4E7pfo4nAKPx36dwDDvOVv6oGAc/edit#slide=id.g9f210aecbc_0_1)

- [Lecture Source Code - Web-access](https://cdn.cs50.net/2020/fall/lectures/9/src9/)

- [Lecture Source Code - PDF](https://cdn.cs50.net/2020/fall/lectures/9/src9.pdf)

- [Lecture Transcript](https://cdn.cs50.net/2020/fall/lectures/9/lang/en/lecture9.txt)

- [Flask Short on YouTube](https://youtu.be/X0dwkDh8kwA)

- [Ajax Short on YouTube](https://youtu.be/dQcBs4S-wEQ)

---
## [Web Servers](https://youtu.be/x_c8pTW8ZUc?t=50)

- Refresher on last week's lecture.
- `http=server` - web server that serves a static web page (a webpage that does not change)
- Web Server: A piece of software that is constantly listening on port 80 or 443 (tcp) and is just listening for connections. Then serves up a web page.
- `GET / HTTP/1.1` A virtual "envelope" that holds the data you are trying to request. 
- If you are wanting to set up a backend, you have to know how to parse the information in the virtual "envelope".

---
## [Flask](https://youtu.be/x_c8pTW8ZUc?t=266)
- To import Flask:  
  `from flask import Flask`

- Flask is a library, but it is also called a "framework".

- Framework:  
    A way of organizing your code, and it is a way of writing your code that utilizes the specific library.

- Flask is an easy way to parse and analyse what the information in the "virtual envelope" is telling the program to do. Such as things like what route the information is saying to take.

- The framework for a simple Flask based web app is like this:
    - `application.py`:  
      Where your main code goes
    - `requirements.txt`:  
      What dependencies are needed to run this app.
    - `static/`:  
      Contains all static files, such as images, gifs, css files, javascript files, etc.
    - `templates/`:  
      Your HTML files for the web application.

- Flask implements a **MVC** (Model, View, Controller) design pattern.
    - **Model:**  
      What technique, service, software you are using for your data. Such as a database, csv file, etc.
    - **View:**  
      All of the stuff that the human user views. Such as the HTML, CSS, or more in general, the user interface. 
    - **Controller:**  
      Where you write most of your python code. The file(s) that control your web application.

- Minimal code needed to write a Flask based web application:
    ```
    from flask import Flask
  
    app = Flask(__name__)
  
    @app.route("/")
    def index:
        return render_template("index.html")
    ```

- To run Flask you would type the following in the terminal:  
    `flask run`

---
## [Hello](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=633s)
```
# Greets user

# Import Flask
from flask import Flask

# Instantiates Flask, turning this file into an application
app = Flask(__name__)

# Python decorator to define the route needed to be call to run this program
@app.route("/")
# Defines the program that runs when the above route is called
def index():
    return "hello, world"
```
- The above code, once you run `flask run` command in the terminal, will only show a blank white page with the words `hello, world`

---

## [Templates](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=913s)
`application.py`
```
# Greets user using a template

# Import Flask
from flask import Flask, render_template, request

# Instantiates Flask, turning this file into an application
app = Flask(__name__)

# Python decorator to define the route needed to be call to run this program
@app.route("/")
# Defines the program that runs when the above route is called
def index():
    # render_template -> Creates the HTML template that you specify
    # No need to specify what directory your HTML file is in as long as it is in a directory named "templates"
    # name=request.args.get -> gets the name of the parameter that you specify from the URL
    # You make `name=` anything you want, it is just a variable name but will also want the 1st parameter to be the same.
    # So if you wanted the user to enter just their first name, it would look like this:
        # `first_name=request.args.get("first_name", "world")`
    # The first parameter in .get() is the variable and the 2nd is the defualt if nothing is entered
    return render_template("index.html", name=request.args.get("name", "world"))
```
`index.html`
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>hello</title>
    </head>
    <body>
        hello, {{ name }}  
    </body>
</html>
```
- By putting a variable in `{{ }}` in your HTML file, you are telling `Flask` that variable will be in the `render_template` code in your main `app` file
- For this task, `name` is going to get requested arguments from the URL
- To use this functionality the user will have to include `/?name=<the users name>` at the end of the URL for it to work unless you set a default value in your `render_template` method.

---
## [Forms](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=1541s)
`index.html`
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>hello</title>
    </head>
    <body>
        <form action="/greet? method="get">
            <input autocomplete="off" autofocus name="name" placeholder="Name" name="name" type="text">
            <input type="submit">
        </form>
    </body>
</html>
```
- Created a form where the user can enter their `name` and click `submit` to take them to the `greet` page of the website.
- In the first input of the form can turn the `autocomplete` off
- Can also use `autofocus` here to show a blinking cursor in the text box to grab the users' attention quickly.
- Can also use a `placeholder` here too in order to show the user what you want them to type in the box.

`greet.html`
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>hello</title>
    </head>
    <body>
        hello, {{ name }}
    </body>
</html>
```
- Just a very basic static page that greets the user by the `name` they entered in the form on the `index.html` page

`application.py`
```
# Greets user via a form using GET

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    # Now our template for index is just a static form.
    # So, all we have to do is just have the route run that static page
    return render_template("index.html")


@app.route("/greet")
def greet():
    # Rendering a template for our `greet` page.
    return render_template("greet.html", name=request.args.get("name", "world"))
```

---
## [GET and POST](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=2013s)

- There is a problem with the above code. Even though it does work, there is a security issue.
- It is possibly leaking personal data into the users url bar.
- Can fix this by using `post` instead of `get` and it will still send the information in the "virtual envelope", but it will be buried further down in the information and will not be leaked into the url.

`index.html`
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>hello</title>
    </head>
    <body>
        <form action="/greet" method="post">
            <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
            <input type="submit">
        </form>
    </body>
</html>
```

`application.py`
```
# Greets user via a form using GET

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")

# Here you have to add `methods=["POST"]` to the route parameters or it does GET by default
@app.route("/greet", methods=["POST"])
def greet():
    # Then you need to change where the request is coming from too.
    # now it will be `request.form.get()` to get the data from the form on the index page.
    return render_template("greet.html", name=request.form.get("name", "world"))
```

---
## [Layouts](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=2306s)

`layout.html` - Standard naming convention
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <title>hello</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```
- `{% block body %}{% endblock %}` this special syntax in `Flask` (took from `Jinja`) to act as placeholder.

`index.html`  
This code inherits from the `layout.html` file
```
{% extends "layout.html" %}

```
This is the beginning of the specific code for this page
```
{% block body %}

    <form action="/" method="get">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <input type="submit">
    </form>

```
This is the end of the specific code for this page.
```
{% endblock %}
```
- Changed one other thing here, in the `form` action we have it now going to the default route of `"/"` because we changed the code in the route in the `applications.py` file to combine the `post` and `get` request into one route.

`greet.html`  
Can do the same thing with the `greet` page.
```
{% extends "layout.html" %}

{% block body %}

    hello, {{ name }}

{% endblock %}
```

`application.py`
```
# Greets user via a form using POST, a layout, and a single route

from flask import Flask, render_template, request

app = Flask(__name__)

# Can combine both post and get routing in the same route and specify what to do if it is a `get` request or a `post` request.
# The route in the url will still be the same, the magic happens with the method that is called when the request is sent.
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
    return render_template("index.html")
```

---
## [froshims](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=2900s)

- The first app that David created
- Going to recreate this idea in the next section.

---
## [Error Checking](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=2999s)
`layout.html`
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width">
        <title>froshims</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```
- `meta name="viewport"` defines the rectangular area that the user is able to view of the page.
- `content="initial-scale=1, width=device-width"` defines the size of the rectangle, this is so that users can view this page on a mobile device, and it will adapt to the size of their device.
- If you want to make your site more responsive on mobile devices than you have to use other methods, such as `bootstrap`. This is just going to resize the page to be max width of the users' device width.

`application.py`
```
# Implements a registration form using a select menu

# Import Flask
from flask import Flask, render_template, request

# Instantiate Flask, making this an app file
app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/register", methods=["POST"])
def register():

    # Validate submission to prevent the user from going to the register page if not a valid sport and/or name is empty.
    if not request.form.get("name") or not request.form.get("sport"):
        return render_template("failure.html")

    # Confirmed registration, send user to the success page
    return render_template("success.html")
```

`index.html`
```
{% extends "layout.html" %}

{% block body %}
    <h1>Register</h1>
```
Create the `form` for the user to input to
```
    <form action="/register" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
```
Creates a `dropdown` menu
```
        <select name="sport">
```
Create the default the user sees first (adding disabled makes it an invalid input) then add the "children" for the dropdown
```
            <option disabled selected value="">Sport</option>
            <option value="Dodgeball">Dodgeball</option>
            <option value="Flag Football">Flag Football</option>
            <option value="Soccer">Soccer</option>
            <option value="Volleyball">Volleyball</option>
            <option value="Ultimate Frisbee">Ultimate Frisbee</option>
        </select>
```
Creates the submit button
```
        <input type="submit" value="Register">
    </form>
{% endblock %}
```

`success.html`
```
{% extends "layout.html" %}

{% block body %}
    You are registered!
{% endblock %}
```

`failure.html`
```
{% extends "layout.html" %}

{% block body %}
    You are not registered!
{% endblock %}
```

---
## [Loops](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=3885s)

`application.py`
```
# Implements a registration form using a select menu

# Import Flask
from flask import Flask, render_template, request

# Instantiate Flask, making this an app file
app = Flask(__name__)

# Capitalized is the convention when defining constant variables
# Doing this to avoid a user from "hacking" the site by changing a value in the dropdown for sports
SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    # Add sports list to the render_template
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():

    # Validate submission and verifying that it is in our SPORTS list.
    if not request.form.get("name") or request.form.get("sport") not in SPORTS:
        return render_template("failure.html")

    # Confirm registration
    return render_template("success.html")
```

`index.html`
```
{% extends "layout.html" %}

{% block body %}
    <h1>Register</h1>
    <form action="/register" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
```
Create a dropdown menu
```
        <select name="sport">
```
Create the default the user sees first (adding disabled makes it an invalid input) then add the "children" for the dropdown
```
            <option disabled selected value="">Sport</option>
```
Use a `for` loop to add the sports from the `SPORTS` list in the `application` file to populate the `dropdown` menu to prevent hacking of the values.
```
            {% for sport in sports %}
                <option value="{{ sport }}">{{ sport }}</option>
            {% endfor %}
        </select>
```
Creates the submit button and what it does when clicked
```
        <input type="submit" value="Register">
    </form>
{% endblock %}
```
- Can also make it a `radio button`, instead of a dropdown by simply changing the `type=` in the `<input` under the `for` loop for the sports.
- With the use of a `radio button`, the user can only click one.

`index.html`
```
{% extends "layout.html" %}

{% block body %}
    <h1>Register</h1>
    <form action="/register" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        {% for sport in sports %}
            <input name="sport" type="radio" value="{{ sport }}"> {{ sport }}
        {% endfor %}
        <input type="submit" value="Register">
    </form>
{% endblock %}
```
- Can also change it to a `checkbox` by changing the `type` from radio to checkbox.

`index.html`
```
{% extends "layout.html" %}

{% block body %}
    <h1>Register</h1>
    <form action="/register" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        {% for sport in sports %}
            <input name="sport" type="checkbox" value="{{ sport }}"> {{ sport }}
        {% endfor %}
        <input type="submit" value="Register">
    </form>
{% endblock %}
```

---
## [Storing Data](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=4318s)

- Create a dictionary to hold the registrants

`application.py`
```
# Implements a registration form, storing registrants in a dictionary, with error messages

from flask import Flask, render_template, request

app = Flask(__name__)

# Create an empty dictionary to add the registrants and their sport
REGISTRANTS = {}

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():

    # Validate submission
    # Create a variable to hold the user's name
    name = request.form.get("name")
    # Check if the user did not type a name...
    if not name:
        # Send the user to the error page and give them a message as to why they got an error.
        return render_template("error.html", message="Missing Name")
    # Create a variable to hold the users choice for the sport
    sport = request.form.get("sport")
    # If the user did not choose a sport...
    if not sport:
        # Send the user to the error page and give them a message as to why they got an error.
        return render_template("error.html", message="Missing Sport")
    # Check that the user sent a valid sport based on the list above.
    if sport not in SPORTS:
        # Send the user to the error page and give them a message as to why they got an error.
        return render_template("error.html", message="Invalid sport")

    # Remember registrant
    # Add the registrant at `key` <name> and `value` <sport>
    REGISTRANTS[name] = sport

    # Sends the user to the registrants page where they can see a table of the current registrants from the REGISTRANTS dictionary
    return render_template("registrants.html", registrants=REGISTRANTS)
```

`error.html`
```
{% extends "layout.html" %}

{% block body %}
    <h1>Error</h1>
```
Will return the message inputted as `message=` in the `render_template` function in the `application` file
```
    <p>{{ message }}</p>
    <img alt="Grumpy Cat" src="/static/cat.jpg">
{% endblock %}
```

`registrants.html`
```
{% extends "layout.html" %}

{% block body %}
```
The title for the page
```
    <h1>Registrants</h1>
```
Creates a table
```
    <table>
```
Creates the header of the table
```
        <thead>
```
Creates the table row for the header
```
            <tr>
```
`<th>` is the "bold" for a table
```
                <th>Name</th>
                <th>Sport</th>
            </tr>
        </thead>
```
Creates the body of the table
```
        <tbody>
```
Use a `for` loop to enter the registrants into the table from the dictionary in the `application` file
```
            {% for name in registrants %}
```
Creates a new table row
```
                <tr>
```
Adds the table data
```
                    <td>{{ name }}</td>
                    <td>{{ registrants[name] }}</td>
                </tr>
            {% endfor %}
        </tbody>
    </table>
{% endblock %}
```

---
## [Databases](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=4881s)

- Using a dictionary as in the code above, is not the best way to store data because if the server gets shutdown for anything, it will lose all the data currently in that dictionary.

- Another "bug" is that you have to register to see who else has already registered.

`application.py`
```
# Implements a registration form, storing registrants in a dictionary, with error messages

from flask import Flask, redirect, render_template, request

app = Flask(__name__)

REGISTRANTS = {}

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():

    # Validate submission
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    # Remember registrant
    REGISTRANTS[name] = sport

    # Confirm registration and redirect the user to the registration page
    return redirect("/registrants")

# Fix the problem of only being able to access current registrants by the user having to register.
# Do this by creating a new route
@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
```

- Now time to fix the dictionary problem

Command Line:

- Once you already have a database set up, you can view the contents of the database with the following command line code:
    - To get into the SQL interpreter: `sqlite3 froshims.db` (replace `froshims.db` with the name of your SQLite database file)
    - `.schema` shows the database table

`application.py`
```
# Implements a registration form, storing registrants in a SQLite database

from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

# Connects to the SQLite database specified
db = SQL("sqlite:///froshims.db")

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


# If a registrant wants to remove themselves from the registration database
@app.route("/deregister", methods=["POST"])
def deregister():

    # Forget registrant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")


@app.route("/register", methods=["POST"])
def register():

    # Validate submission
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html")

    # Remember registrant by adding to the database
    # The ?'s in the VALUES are placeholders, 
    #   then you close the "" and add the variables where the values will come from
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    # Confirm registration
    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    # How to query the database to still show the user who is registered already
    # What this is going to return is rows from the database.
    # Each row is going to be a dictionary with the column as the key and the data as the value
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)
```

`registrants.html`
```
{% extends "layout.html" %}

{% block body %}
    <h1>Registrants</h1>
    <table>
        <thead>
            <tr>
                <th>Name</th>
                <th>Sport</th>
                <th></th>
            </tr>
        </thead>
        <tbody>
```
- Replace `for name` to `for registrant`
- This is the same as saying `for row in rows` just more descriptive names for the variables
```
            {% for registrant in registrants %}
                <tr>
```
- Need to also change this to reflect that how we are getting the data now
- registrant is the variable where our data is located
- `.name` is the key we want
```
                    <td>{{ registrant.name }}</td>
```
Same thing for this one, except that `.sport` is the key we want now for the value
```
                    <td>{{ registrant.sport }}</td>
                    <td>
```
Create a form for a registrant to remove their registration from the database
```
                        <form action="/deregister" method="post">
                            <input name="id" type="hidden" value="{{ registrant.id }}">
                            <input type="submit" value="Deregister">
                        </form>
                    </td>
                </tr>
            {% endfor %}
        </tbody>
    </table>
{% endblock %}
```
- Adding the functionality to send the user a confirmation email after successfully registering. Taking out the SQL database code because now we just want to send the confirmation email.

`application.py`
```
# Implements a registration form, confirming registration via email

# Import os to use the getenv function
import os
# Import reg ex 
import re

# Import methods needed from Flask
from flask import Flask, render_template, request
# Flask has it's own main functionality
from flask_mail import Mail, Message

# Instantiate Flask
app = Flask(__name__)
# Configure mail default sender using variable set up in your environment for privacy reasons
app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
# Configure mail password, the same as the default sender using getenv
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
# Configure your tcp mail port
app.config["MAIL_PORT"] = 587
# Configure your smtp mail server
app.config["MAIL_SERVER"] = "smtp.gmail.com"
# Configure tls which is a type of encryption
app.config["MAIL_USE_TLS"] = True
# Configure your mail user name with the getenv method
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
# Create a variable for the app to be passed into the Mail function from Flask
mail = Mail(app)


SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():

    # Validate submission
    name = request.form.get("name")
    email = request.form.get("email")
    sport = request.form.get("sport")
    if not name or not email or sport not in SPORTS:
        return render_template("failure.html")

    # Send email
    # Message(<subject line>, <recipients email>)
    message = Message("You are registered!", recipients=[email])
    # This code will send the email to the email recipient
    mail.send(message)

    # Confirm registration
    return render_template("success.html")
```

`index.html`
```
{% extends "layout.html" %}

{% block body %}
    <h1>Register</h1>
    <form action="/register" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
```
Add this code to get the users email address to send the confirmation email to.
```
        <input autocomplete="off" name="email" placeholder="Email" type="email">
        {% for sport in sports %}
            <input name="sport" type="radio" value="{{ sport }}"> {{ sport }}
        {% endfor %}
        <input type="submit" value="Register">
    </form>
{% endblock %}
```

---
## [Sessions](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=5821s)

- Session:  
    - A way for the website to remember you.
    - Such as logging into your gmail account.
    - Sets tracking cookies for the site to help the site remember you were there.
    - Then it will send this cookie to every subsequent page you visit within that site to let it know that you have been to the main url before.
    - It is like getting your hand stamped saying that you have been there before and then each time that you enter a page on the site it automatically checks for that "hand stamp".
    
`login/layout.html`
```
<!DOCTYPE html>

<html>
    <head>
```
This meta tag just lets the computer know that you are using `utf-8` character encoding for this site. Not necessary but good practice to do.
```
        <meta charset="utf-8">
        <meta name="viewport" content="initial-scale=1, width=device-width"/>
        <title>login</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```

`login/application.py`
```
from flask import Flask, redirect, render_template, request, session
# Import the "hand stamper"
from flask_session import Session

# Configure app
app = Flask(__name__)

# Configure sessions
app.config["SESSION_PERMANENT"] = False
# This is just assign the session to your computer's memeory
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/login")
def login():
    return render_template("login.html")
```

---
## [login](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=6387s)

`login.html`
```
{% extends "layout.html" %}

{% block body %}
```
Create a simple form for the user to use to log in.
```
    <form action="/login" method="post">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <input type="submit" value="Log In">
    </form>

{% endblock %}
```

`index.html`
```
{% extends "layout.html" %}

{% block body %}

    {% if session.name %}
```
Lets the user know they are currently logged in as `{{ name }}` and provides a `link` for them to be able to log out if they want.
```
        You are logged in as {{ session.name }}. <a href="/logout">Log out</a>.
    {% else %}
```
Tell the user they are not logged in and create a `link` they can click to log in
```
        You are not logged in. <a href="/login">Log in</a>.
    {% endif %}

{% endblock %}
```

`application.py`
```
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Configure sessions
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    # Check if the user is already logged in and if not, redirect them to the login page to login.
    if not session.get("name"):
        return redirect("/login")
    # If user is already logged in, just simply send them to the index page.
    return render_template("index.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        # Remember that the user logged in using the session global variable and the name of the user
        session["name"] = request.form.get("name")
        # Redirect user to index
        return redirect("/")
    return render_template("login.html")


@app.route("/logout")
def logout():
    # Forgets that the user was logged in
    session["name"] = None
    # Redirect back to index
    return redirect("/")
```
- You can set a `cookie` to last forever but not something that you want to do.
- Most `cookies` only last for a specific amount of time unless the server reactivates it. These are called `"session cookies"`.
- You can set `permanent cookies` that last until you delete them, like the "remember me" checkboxes.

---
## [store](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=7207s)
- An ecommerce website for a book store

`application.py`
```
from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///store.db")

# Configure sessions
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)


@app.route("/cart", methods=["GET", "POST"])
def cart():

    # Ensure cart exists
    # Creates a cart if it does not exist already
    if "cart" not in session:
        session["cart"] = []

    # POST
    if request.method == "POST":
        # Gets the id of a book to add to the cart
        id = request.form.get("id")
        # If the user adds a new item to the cart...
        if id:
            # Send user to the cart page with new item added to their cart.
            session["cart"].append(id)
        return redirect("/cart")

    # GET
    # Implements a cart for the current session
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)
```

`layout.html`
```
<!DOCTYPE html>

<html>
    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width"/>
        <title>store</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```

`books.html`
```
{% extends "layout.html" %}

{% block body %}

    <h1>Books</h1>
    {% for book in books %}
```
page header
```
        <h2>{{ book.title }}</h2>
```
A form for a shopping cart
```
        <form action="/cart" method="post">
```
`hidden` allows you to submit a piece of data in a form that is visually hidden to the user.
```
            <input name="id" type="hidden" value="{{ book.id }}">
            <input type="submit" value="Add to Cart">
        </form>
    {% endfor %}

{% endblock %}
```

`cart.html`
```
{% extends "layout.html" %}

{% block body %}

    <h1>Cart</h1>
    <ol>
        {% for book in books %}
            <li>{{ book.title }}</li>
        {% endfor %}
    </ol>

{% endblock %}
```

---
## [shows](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=7795s)
- The "front end" is what the user sees on a webpage
- The "back end" is what the developer sees (the code under the hood)

`application.py`
```
# Searches for shows

from cs50 import SQL
from flask import Flask, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///shows.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():
    # This will execute the search using a SQL query
    # The "?" in the query is a placeholder,
    # The "%"'s are wild cards that can have multiple values to before the q and after the q
    shows = db.execute("SELECT * FROM shows WHERE title LIKE ?", "%" + request.args.get("q") + "%")
    return render_template("search.html", shows=shows)
```

`layout.html`
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <meta name="viewport" content="initial-scale=1, width=device-width">
        <title>shows</title>
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```

`index.html`
```
{% extends "layout.html" %}

{% block body %}
    <form action="/search" method="get">
```
In this form `name=q` will give us that search url like with Google where the url will include `/search?q=<search term used>`
```
        <input autocomplete="off" autofocus name="q" placeholder="Query" type="search">
        <input type="submit" value="Search">
    </form>
{% endblock %}
```

`search.html`
```
{% extends "layout.html" %}

{% block body %}
```
Tag for unordered list (i.e. a bullet list)
```
    <ul>
        {% for show in shows %}
```
Tag for list instance (or a row of the list)
```
            <li>{{ show.title }}</li>
        {% endfor %}
    </ul>
{% endblock %}
```

- Changes to `application.py` to work with JavaScript to make it more dynamic:
```
# Searches for shows

from cs50 import SQL
from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

db = SQL("sqlite:///shows.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():
    shows = db.execute("SELECT * FROM shows WHERE title LIKE ?", "%" + request.args.get("q") + "%")
    # jsonify is a method that Flask uses to take a python list or dictionary and converts it into json form (j(java)s(script)o(object)n(notation)
    # A dictionary is considered an object in Java Script
    return jsonify(shows)
```

---
## [Ajax](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=8747s)
- Got rid of `layout.html` and `search.html` and rework the `index.html` using `jQuery` to make the site more dynamic. This way there is no need to click the submit button, the list will start `auto-populating` when you start typing in the query box.
```
<!DOCTYPE html>

<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="initial-scale=1, width=device-width">\
        <title>shows</title>
    </head>
    <body>
```
Creates a simple search box
```
        <input autocomplete="off" autofocus placeholder="Query" type="text">
```
Creates an empty unordered list
```
        <ul></ul>
```
Imports the jQuery library
```
        <script crossorigin="anonymous" integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0=" src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
        <script>
```
Use querySelector to create an input variable to access the input tag from a few lines above in this code
```
            let input = document.querySelector('input');
```
- Creates an event listener to listen for a "keyup" to run the function
- `$.get` is short for `jQuery.get`, this is a "callback" function (it is like when you are waiting on a phone when the other person is busy, and you say call me back later when you are not busy). Lets the website continue to run while it is waiting on this callback to run the function. Also called an `aJax` call. It is the ability for a webpage to make additional http requests programmatically to a server. 
- So on "keyup" the `aJax` function will run to get any input after `/search?q=` then it will be given an input called "show" that will render the json file of the shows' database.
```
            input.addEventListener('keyup', function() {
                $.get('/search?q=' + input.value, function(shows) {
                    let html = '';
```
For each id in the json shows file...
```
                    for (let id in shows) {
                        let title = shows[id].title.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;');
```
Creates one line after another by appending it in the html code
```
                        html += '<li>' + title + '</li>';
                    }
```
Go select me that `unordered list` (`ul`) and plug into it's inner html (the contents of it) the data in my variable `html` from above.
```
                    document.querySelector('ul').innerHTML = html;
                });
            });

        </script>

    </body>
</html>
```
