# CS50 - Week - 9 - Flask

- [Flask Lecture on YouTube](https://youtu.be/x_c8pTW8ZUc)

- [Lecture Notes](https://cs50.harvard.edu/x/2021/notes/9/)

- [Lecture Slides](https://docs.google.com/presentation/d/1E3N-8puMqS2545GR4E7pfo4nAKPx36dwDDvOVv6oGAc/edit#slide=id.g9f210aecbc_0_1)

- [Lecture Source Code - Web-access](https://cdn.cs50.net/2020/fall/lectures/9/src9/)

- [Lecture Source Code - PDF](https://cdn.cs50.net/2020/fall/lectures/9/src9.pdf)

- [Lecture Transcript](https://cdn.cs50.net/2020/fall/lectures/9/lang/en/lecture9.txt)

- [Flask Short on YouTube](https://youtu.be/X0dwkDh8kwA)

- [Ajax Short on YouTube](https://youtu.be/dQcBs4S-wEQ)

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
# By putting a variable in {{}} in your HTML file, you are telling Flask that variable
#   will be in the render_template code in your main app file
# For this task, name is going to get requested arguments from the URL
# To use this functionality the user will have to include `/?name=<the users name>` at the end of the URL for it to work unless you set a default value in your `render_template` method.
```

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

# Created a form where the user can enter their name and click submit to take them to the greet page of the website.
# In the first input of the form can turn the `autocomplete` off
# Can also use `autofocus` here to show a blinking cursor in the text box to grab the users attention quickly.
# Can also use a `placeholder` here too in order to show the user what you want them to type in the box.
```

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
# Just a very basic static page that greets the user by the name they entered in the form on the index.html page
```

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
- It is leaking possibly personal data into the users url bar.
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

# `{% block body %}{% endblock %}` this special syntex in Flask (took from Jinja) to act as placeholder
```

`index.html`

```
# This code inheriets from the layout.html file
{% extends "layout.html" %}

# This is the beginning of the specific code for this page
{% block body %}

    <form action="/" method="get">
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        <input type="submit">
    </form>

# This if the end of the specific cod for this page.
{% endblock %}

# Changed one other thing here, in the form action we have it now going to the default route of "/" becuase we changed the code in the route in the applications.py file to combine the post and get request into one route.
```

`greet.html`

```
# Can do the same thing with the greet page too.
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

## [froshims](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=2900s)

- The first app that David created
- Going to recreate this idea in the next section.

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

# `meta name="viewport"` defines the rectangular area that the user is able to view of the page.
# `content="initial-scale=1, width=device-width"` defines the size of the triangle, this is so that users can view this page on a mobile device and it will adapt to the size of their device.
# If you want to make your site more responsive on mobile devices then you have to use other methods, such as bootstrap. This is just going to resize the page to be max width of the users device width.
```

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
    # Create the form for the user to input to
    <form action="/register" method="post">
        # 
        <input autocomplete="off" autofocus name="name" placeholder="Name" type="text">
        # Creates a dropdown menu
        <select name="sport">
            # Create the default the user sees first (adding disabled makes it an invalid input) then add the "children" for the dropdown
            <option disabled selected value="">Sport</option>
            <option value="Dodgeball">Dodgeball</option>
            <option value="Flag Football">Flag Football</option>
            <option value="Soccer">Soccer</option>
            <option value="Volleyball">Volleyball</option>
            <option value="Ultimate Frisbee">Ultimate Frisbee</option>
        </select>
        # Creates the submit button
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
        # Create a dropdown menu
        <select name="sport">
             # Create the default the user sees first (adding disabled makes it an invalid input) then add the "children" for the dropdown
            <option disabled selected value="">Sport</option>
            # Use a for loop to add the sports from the SPORTS list in the application file to populate the dropdown menu to prevent hacking of the values.
            {% for sport in sports %}
                <option value="{{ sport }}">{{ sport }}</option>
            {% endfor %}
        </select>
        # Creates the submit button and what it does when clicked
        <input type="submit" value="Register">
    </form>
{% endblock %}
```

- Can also make it a radio button, instead of a dropdown by simply changing the `type=` in the `<input` under the for loop for the sports.
- With the use of a radio button, the user can only click one.

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

- Can also change it to a checkbox by changing the type from radio to checkbox.

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
    # Will return the message inputted as `message=` in the render_template function in the application file
    <p>{{ message }}</p>
    <img alt="Grumpy Cat" src="/static/cat.jpg">
{% endblock %}
```

`registrants.html`

```
{% extends "layout.html" %}

{% block body %}
    # The title for the page
    <h1>Registrants</h1>
    # Creates a table
    <table>
        # Creates the header of the table
        <thead>
            # Creates the table row for the header
            <tr>
                # <th> is the "bold" for a table
                <th>Name</th>
                <th>Sport</th>
            </tr>
        </thead>
        # Creates the body of the table
        <tbody>
            # Use a for loop to enter the registrants into the table from the dictionary in the application file
            {% for name in registrants %}
                # Creates a new table row
                <tr>
                    # Adds the table data
                    <td>{{ name }}</td>
                    <td>{{ registrants[name] }}</td>
                </tr>
            {% endfor %}
        </tbody>
    </table>
{% endblock %}
```

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

`application.py`

```

```

## [Sessions](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=5821s)

## [login](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=6387s)

## [store](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=7207s)

## [shows](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=7795s)

## [Ajax](https://www.youtube.com/watch?v=x_c8pTW8ZUc&t=8747s)
