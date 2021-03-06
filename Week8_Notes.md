## CS50 - Week - 8 - [HTML, CSS, JavaScript](https://youtu.be/5g0x2xv3aHU)

### [Introduction](https://youtu.be/BB7xPefB8og)
- HTML: A language used to design webpages that web browsers can understand
- CSS: A language used to style webpages
- JavaScript: A language used to make webpages more interactive
- Flask: A Python framework that will allow you to create web applications that are interactive, able to store information, and more.

### [HTTP](https://youtu.be/iSFEjQRulf0)
Computers and other devices on the internet have standardized on a set of protocols, some basic rules to follow, the government governs how it is that these devices should be communicating with one another.

Protocols:
- TCP/IP: Transmission Control Protocol / Internet Protocol
  - These are the protocols that determine how computers are able to communicate with one another over the internet.
  - IP Addresses: Internet Protocol Addresses
    - Looks like `<num 0-255>.<num 0-255>.<num 0-255>.<num 0-255>`
      - This is known as `IPv4` for a 32-bit address, which can only go up to about 4 billion unique numbers.
    - In *binary* 255 = 11111111, 
      - meaning that each number is represented by 8 bits of information,
      - that totals 32 bits per IP address.
    - There is a new protocol `IPv6` for a 128-bit address, this allows for far more addresses on the internet.
  - Port Number: 
    - Looks like `<IP Address>:<Port Number>`
    
    | Service | Port | Common Use |
    | --- | --- | --- |
    | FTP | 21 | File Transfer |
    | SMTP | 25 | Email (Send and Receive) |
    | HTTP | 80 | Website |
    | HTTPS | 443 | Secure Website |
    | ... | ... | Many other ports |
  
  - Packets: The *package* that the request and response is put into, such as an envelope. If data is too large to fit in just one packet, it will be divided into multiple packets which may take different routes to get to the receiver. This will make it faster to send and receive the data.
  
  - HTTPS: the content of the packets are encrypted and can only be viewed by the sender and receiver. 
    
  - DNS: Domain Name System (a server)
    - A mapping between URLs and IP Addresses.
    - Top Level Domain (TLD): denotes the type of website you are trying to visit, such as `.com`, `.edu`, etc. There really is no "hard rules" on domain types anymore though, expect for specific TLD that are still assigned to a specific type of website, such as `.org`, `.edu`, etc. 
    
    Examples:
    
    | URL | IP Address |
    | --- | --- |
    | google.com | 172.217.7.206 |
    | harvard.edu | 23.22.75.102 |
    | yale.edu | 104.16.243.4 |
    
- HTTP: Hyper-Text Transfer Protocol
  - Hyper-Text: HTML
    - What it looks like when you send a request to go to a webpage:
      ```
      GET / HTTP/1.1
      Host: www.example.com
      ```
      - `GET` request to *get* the webpage
      - `POST` Changes the way the browser displays the website address by hiding the personal information, such as a search engine will display in the url what you searched for if processed via a `GET` request, but if you use a `POST` request the information needed still goes to the server but will not be displayed in the url.  
      - `HTTP/<version of the protocol>` tells the version of HTTP you are using.
      - `Host: <domain name>` the domain name of the site you are trying to reach.
    - What the return request looks like:
      
      ```
      HTTP/1.1 200 OK
      Content-Type: text/html
      ```
      
      - `HTTP/<version of the protocol>` tells the version of HTTP you are using.
      - `200` status code - how the response was handled
        
        | Status Code | Description |
        | --- | --- |
        | 200 | OK |
        | 301 | Moved Permanently |
        | 302 | Found |
        | 304 | Not Modified |
        | 307 | Temporary Redirect |
        | 401 | Unauthorized |
        | 403 | Forbidden |
        | 404 | Not Found |
        | 418 | I'm a Teapot |
        | 500 | Internal Server Error |
        | 503 | Service Unavailable |

      - `OK` description of the status code
      - `Content-Type: text/html` the type of information that is being returned
    
`?` in a http address denotes that after the "?" there are going to be some parameters inputted with values following them. 

Command line `curl` just connects to a URL.
  `curl -I <website>` show http headers

### [HTML](https://youtu.be/78wdlyzrKOA)
**Hyper-Text Markup Language**

The language that describes the structure of a webpage. Since it is not actually a machine language there are no loops or if conditions within actual HTML.

Uses *tags* called *elements* to structure the webpage. Most must have a closing element.
  Example: `<html>Contents</html>`

Attribute: a perimeter included in the tag / element of the page with a value.

Metadata: Additional information about the webpage that is going to be relevant for a web browser that wants to read that webpage and understand how to display it to the user.

Tags / Elements:
- `<html></html>` Start and end of the html content
- `<head></head>` Metadata for the page
- `<body></body>` The body of the page, the viewable portion to the user
- `<img src="<where to get the image from>" alt="<alternate text if image can not be viewed>">` Inserts a picture to the page
- `<a href="<link address>">text you want the user to see</a>` Inserts a hyper-link to another webpage.
  - `a` anchor
  - `href` hyper-link reference
- `<p></p>` Beginning and ending of a paragraph
- `<h1></h1>` The largest heading text
- `<table></table>` Start and end of a table
  - `<th></th>` Start and end of the table header
  - `<tr></tr>` Start and end of a row in the table (nest inside the `<table>` tags, one set for each row)
  - `<td></td>` Start and end of a cell in the table (nest inside the `<tr>` tags, one set for each cell)
- `<form></form>` Start and end of a form
  - `<form action="<address where the form should go to>" method="get"`
    - Need to use this code as your 1st `<form>` code to define what the form will do
  - `<input type="text">` the box where the user can type in *text* (nested inside `<form>` tags)
    - `<input name="<att name>" type="text">` Need to add a name attribute for the action
      - `placeholder="<text you want to be a placeholder>"` will add a placeholder that the user will see but with disappear when user starts typing
      - `autocomplete="off"` turns off the autocomplete for this form
      - `autofocus` when the page is load it automatically "clicks" the input field so user just needs to start typing.
  - `<input type="submit" value="<text you want to display on the button>">` creates the button for user to click on (nested inside `<form>` tags)
- `<div></div>` Start and end of a div (a section of the webpage)
- `<select></select>` Creates a drop down menu
  - `<option value="<what the value is of this option>">option1</option>` set each one of the options you want in your list
  - Add `selected` in `<option...>` tag of the option you want as your default.
- `<ul></ul>` Start and end of an unordered list
- `<ol></ol>` Start and end of an ordered list (1., 2., 3., etc.)
- `<li></li>` Nested inside `<ul>` or `<ol>` tags, start and end of a list item
- `<header></header>` defines the head of your page. Nested inside `<body>` tags.
- `<main></main>` defines your page between the header and footer. Goes under your `<header>` tags.
- `<footer></footer>` defines the bottom of your page. Goes under your `<main>` tags.

`&#169;` gives you the copyright symbol.

PHP: (Hypertext Pre-processor) a server side scripting language that is used to develop static or dynamic websites or web application. It is embedded in HTML and is used to manage dynamic content, such as email, databases, session tracking, and even build an entire e-commerce site.

### [CSS](https://youtu.be/g7nZFp2zSJ4)
CSS: Cascading Style Sheets

An argument or parameter in CSS is called a "property"

CSS selectors:
- `type` you can style based on any HTML element / tag
- `class` coded as `.<class name>` can create class style attributes
- `ID` coded as `#<id name>` can create style attributes for a unique ID.

A language that allows you to add style to your webpage using different html tags/elements.

Modifications to html to add in-line styling:
- `<h1 style="color: blue;">` Changes the heading text color to blue (default = black)
- `<p style="color: blue;">` Changes paragraph text color to blue
- `<body style="color: blue;">` Changes all the text to blue that is inside the body
- `<body style="text-align: center;>"` Changes alignment of text in the body to center (default is left)
- `<body style="font-size: large;">` Changes the font size
- `<body style="font-size: large; background-color: blue;">` Changes font size and the background color
- `<style></style>` Start and end style element if you want to specify for whole page
  - Add this inside the `<style>` tags to add the styling attributes for heading 2:
    ```
    h2
    {
        text-align: center;  # Changes text alignment
        color: blue;  # Changes text color
    }
    ```
- `font-family: <font style>` changes font style
- `text-decoration: none;` removes the underline on a hyperlink

Pseudo Selectors:
  ```
  a:hover  # When the user hovers over anything with the `a` tag, denoting a hyperlink
  {
      text-decoration: underline;  # The link will be underlined when they hover
  }
  ```

CSS class: defines a category of elements that you want to add the same styling to.
- Create a CSS class:
  ```
    .title  # name of the class
    {
        text-align: center;
        color: blue;
    }
  ```
- To use the class (you can use multiple classes to the same element, just sep with a space):
  - `<h1 class="title">` just one class assigned
  - `<h1 class="title green">` assigns both the `title` and the `green` class

Best practice is to separate the styling classes in and create a new file with all of your styling elements

To connect your html page to the style.css file:
- Nested in the `<head>` tags you need to add the following metadata:
  `<link rel="stylesheet" href="<location of style.css>">`
  - `rel` the relationship
  - `href` the location of the style.css file
    
To add CSS styling to a table:
- Nested in the `<head>` and `<style>` tags:
  ```
  table  # sets styling for the whole table
  {
    border: 1px solid black;  # Adds a border of solid black 1 pixel wide to table elements
    border-collapse: collapse;  # collapses the borders into each other
  }
  
  td  # sets styling for the cells inside the table
  {
    border: 1px solid black;  # adds the border to each individual cell
    padding: 5px;  # gives padding between the text and the border
  }
  ```
- Can also use CSS classes to make specific cells styled differently

Bootstrap: A CSS styling library that has already been created by someone and shared
- Go to [Get Bootstrap](https://getbootstrap.com/)
- Click on "Documentation"
- In the "Quick Start" section
- Go to CSS section
- Copy and paste the `<link rel...>` code into the `<head>` tags

If you want to change the stylesheet from getbootstrap.com, when you are on the "Documentation" page, look on the left of the page for a link called "Components". Then it will populate a list of all the elements that have already been coded for you. Just click on what element you want to change. They will also have a code block with the code you need for each styling that is available. Just need to copy and paste that code into your html file.

### [JavaScript](https://youtu.be/7NPcZSrcA5o)
A language that can run inside the browser to create an interactive user experience.

Variables:
- JavaScript variables are similar to Python variables.
  - No type specifier
  - When a local variable is first declared, preface with the `var` keyword.
    - Example: `var x = 44;` creates a local variable.
  - If you just type `x = 44;` that will give you a global variable.
  
Conditionals:
- Very similar to C
  - `if`
  - `else if`
  - `else`
  - `switch`
  - `?:`
  
Loops:
- Very similar to C
  - `while`
  - `do-while`
  - `for`
    - In Python:
      ```
      for key in list:
          use key here as stand-in for list[i]
      ```
    - In JS (iterate over all the keys):
      ```
      for (var key in object)
      {
          use object[key] in here
      }
      ```
    - In JS (iterate over all the values):
      ```
      for (var key of object)
      {
          use key in here
      }
      ```
  
Functions:
- All functions are introduced with the `function` keyword.
  - Example:
    ```
    function() {
        <body of the function>
    }
    ```
- JS functions, particularly those bound specifically to HTML elements, can be *anonymous* - you don't have to them a name!
  - ```
    var nums = [1, 2, 3, 4, 5];
    
    nums = nums.map(function(num) {
        return num * 2;
    });
    ```

Arrays:
- Declaring an array is pretty straightforward:
  - `var nums = [1, 2, 3, 4, 5];`
- Can be mixed data types.
- Arrays are a special case of an object and has numerous methods that can applied to them:
  - `array.size()`
  - `array.pop()`
  - `array.push()`
  - `array.shift()`
- There is also a method for arrays called `map()`, which can be used to apply a function to all elements of an array.

Objects:
- JS has the ability to behave in a few different ways, but in particular it can behave as an *object-oriented* programming language.
- Have *properties* but also *methods* (functions that are inherent to the object), meaning nothing outside of it.
  - Thus, like properties can methods not ever stand on their own.
  - In C would code as: `function(object);`
  - In JS would code it as: `object.function();`
  - The fields and methods of an object are similar to the idea of a dictionary, which is part of Python.
    - Example: `var herbie = {year: 1963, model: 'Beetle};`
  
Events:
- An *event* in HTML and JS is a response to user interaction with the web page.
  - A user clicks a button, a page has finished loading, a user has hovered over a portion of the page, the user typed in an input field.
- JS has support for *event handlers*, which are callback functions that respond to HTML events.
  - Many HTML elements have support for events as an attribute.
- We can write a generic event handler in JS, creating an *event object*, that will tell us which of the buttons were clicked.
  - Example: `<button onclick="alertname(event)">Button 1</button>`
    - Example of the function code:
      ```
      function alertname(event)
      {
          var trigger = event.srcElement;
          alert('You clicked on ' + trigger.innerHTML);
      }
      ```
      - `srcElement` the HTML element / tag that was interacted with and recorded.
      - `innerHTML` the data between HTML tags.
      - `alert()` is similar to print, it will print, for the user to view, what is passed inside the `()`.

JavaScript vs C:
  
| C | JavaScript|
| --- | --- |
| int counter = 0; | let counter = 0; | 
| counter++; | counter++; |
| if statement | same as C |
| else statement | same as C |
| while loop | same as C |
| for loop | same as C but `let` vs `<data type>` in C |
| define a function | slightly different |
| void cough(int n) | function cough(n) |

JavaScript, when used in your webpage, can manipulate the DOM of the page to create an interactive webpage.

To include JavaScript in your webpage:
- Go to your html file
- Nest inside the `<head>` tags:
  ```
  <script>
    your JavaScript code lives here
  </script>
  ```
- Can also put your JavaScript into another file and references it from the html file as so:
  `<script src="<your JS file>"></script>`

Built in functions to JavaScript:
- `alert('<text you want the user to see>');` creates a pop up box at the top when the user goes to the website
- `document.querySelector(#<id name>)` searches the html code for the id name you specified.
  - Can also find a class `document.querySelector(.<class name>)`
  - Can also find a html element `document.querySelector(<element name>)`
  - Will only return 1 element, so make sure there is only the one element name in the html code.
  - Adding `.value` will return the value it searched for
  - Adding `.onclick = <function your define>` you can make it change elements within the DOM
    - If you use `.onclick` need to have your `<script></script>` functionality under the element to be changed.
  - Adding `.style.<the style you want to change> = <style value>` you can change the style of the DOM
  - Adding `.addEventListener("<event to listen for>", <function to preform>);` will run the function specified when the event is heard. 
    - Can also run this method as just `document.addEventListener('DOMContentLoaded', <function where your querySelector listener is>) ` this will prevent the error of it not being able to find the event since it is further down the page. If you don't do this, you will have to move your whole `<script>` code below what it needs to listen for.
      
      Examples:
      ```
      function listen()
      {
        document.querySelector('form').addEventListener('submit', greet);
      }
      ```
      or
      ```
      document.addEventListener('DOMContentLoaded', function() {
          document.querySelector('form').addEventListener('submit', greet);
      });  # This will combine the function and extra line of code all in one line and you do not have to name the function. In JS you can just create a function without a name when done this way. You can add multiple unnamed functions like this too as long as you make sure you still have the {} to define the functions body.
      ```
      Example of nesting 2 functions:
      ```
      document.addEventListener('DOMContentLoaded', function() {
          document.querySelector('form').addEventListener('submit', function{
              let name = document.querySelector('#name').value;
              alert('Hello, ' + name + '!');
          });
      });
      ```
      - Some events you can listen for:
        - blur
        - change
        - click
        - drag
        - focus
        - keyup
        - load
        - mousedown
        - mouseover
        - mouseup
        - submit
        - touchmove
        - unload
        - etc...
  - `console.log();` is similar to `printf`
  - `parseInt()` forces the data type to integer.

Create a function to have the user enter their name and click submit to have an "alert" pop up to say hello and their name.
- Include the following in your `<head>` tags:
  ```
  <script>
    function greet()
    {
        let name = document.querySelector('#name').value;  # with the `#` says to find the exact id name
        if (name === '')  # If user does not type anything
        {
            name = 'world';  # Alert will just say "Hello, world!" 
        }
        alert('Hello, ' + name + '!');  # Creates the alert functionality using a built-in method in JavaScript.
    }
  </script>
  ```
  
- Include the following in your `<body>` tags:
  ```
  <form onsubmit="greet(); return false;">  # Need to return false or the form will try to redirect to another page.
    <input type="text" id="name">
    <input type="submit">
  </form>
  ```

Can also use JS to modify code within your html

How to make it say hello and the users name directly on the page vs a popup alert:
- Include the following in your `<head>` tags:
  ```
  <script>
    function greet()
    {
        let name = document.querySelector('#name').value;  # with the `#` says to find the exact id name
        if (name === '')  # If user does not type anything
        {
            name = 'world';  # Alert will just say "Hello, world!" 
        }
        document.querySelector('#result').innerHTML = 'Hello, ' + name + '!'
    }
  </script>
  ```
  
- Put the following code in your `<body>` tag:
  ```
  <form onsubmit="greet(); return false;">  # Need to return false or the form will try to redirect to another page.
    <input type="text" id="name">
    <input type="submit">
  </form>
  <br>  # Adds a new line between the form and text
  <div id="result">  # Create a new section that just says Hello! Need `id="result"` to let JS know where to look.
    Hello!
  </div>
  ```
  
### [DOM: Document Object Model](https://youtu.be/LKWJpgvfH3U) 
Structure of the webpage.

- JS object are incredibly flexible and can contain various fields, even when those fields are other objects.
- The *document object* is one way of employing this paradigm, whereby that object organizes the entire contents of a web page.
- By organizing an entire page into a JS object, we can manipulate the page's elements programmatically.
- The document object itself, as well as all the objects contained within it, have a number of *properties*, and a number of *methods* that can be used to drill down to a very specific piece of your website.
- By resetting those properties or calling certain methods, the contents of our web pages can change without us needing to refresh the page.

DOM Properties:

| Property | Description |
| --- | --- |
| innerHTML | Holds the HTML inside a set of HTML tags |
| nodeName | Name of an HTML element or element's attributes |
| id | The "id" attribute of an HTML element |
| parentNode | A reference to the node one level up in the DOM |
| childNodes | An array of references to the nodes one level down in the DOM |
| attributes | An array of attributes of an HTML element|
| style | An object encapsulating the CSS/HTML styling of an element |

DOM Methods:

| Method | Description |
| --- | --- |
| getElementById(id) | Gets the element with a given ID below this point in the DOM |
| getElementsByTagName(tag) | Gets all elements with the given tag below this point in the DOM |
| appendChild(node) | Add the given node to the DOM below this point |
| removeChild(node) | Remove the specified child node from the DOM |

If we start from document, we can get to any piece of our web page that we choose, through careful use of DOM properties and methods.

jQuery:
- Because DOM manipulation is so common with JS, and because the JS to do so can get quite lengthy, people wanted alternatives.
- jQuery is a popular open-source library, released in 2006, that is designed to simplify client-side scripting (such as DOM manipulations).
- Example:
  In JS: `document.getElementById('colorDiv').style.backgroundColor = 'green`
  In jQuery: `$('#colorDiv').css('background-color', 'green');`
  - `$` is shorthand for jQuery
  
