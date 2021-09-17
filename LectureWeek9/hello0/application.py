# Greets user

# Import Flask
from flask import Flask, render_template, request

# Instantiates Flask, turning this file into an application
app = Flask(__name__)

# Python decorator (`@`) to define the route needed to be call to run this
# program
@app.route("/")
# Defines the program that runs when the above route is called
def index():
    # render_template -> Creates the HTML templates that you specify
    # No need to specify what directory your HTML file is in as long as it is
    #   in a directory named "templates"
    # name=request.args.get -> gets the name of the parameter that you
    #   specify from the URL
    # By putting a variable in {{ }} in your HTML file, you are telling Flask
    #   that variable will be in the render_template code in your main app
    #   file
    # For this task, name is going to get requested arguments from the URL
    # To use this functionality the user will have to include
    #   `/?name=<the users name>` for it to work
    # The first parameter in .get() is the variable and the 2nd is the
    #   default if nothing is entered
    return render_template("index.html", name=request.args.get("name", "world"))
