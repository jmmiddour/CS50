## CS50 - Week - 8

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
    | HTTP | 80 | Sending messages over the internet |
    | ... | ... | Many other ports |
    
  - DNS: Domain Name System (a server)
    - A mapping between URLs and IP Addresses.
    
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
        | 403 | Forbidden |
        | 404 | Not Found |
        | 500 | Internal Server Error |

      - `OK` description of the status code
      - `Content-Type: text/html` the type of information that is being returned
    
`?` in a http address denotes that after the "?" there are going to be some parameters inputted with values following them. 

### [HTML](https://youtu.be/78wdlyzrKOA)
**Hyper-Text Markup Language**

The language that describes the structure of a webpage.

Uses *tags* called *elements* to structure the webpage. Most must have a closing element.
  Example: `<html>Contents</html>`

Metadata: Additional information about the webpage that is going to be relevant for a web browser that wants to read that webpage and understand how to display it to the user.

Tags / Elements:
- `<html></html>` Start and end of the html content
- `<head></head>` Metadata for the page
- `<body></body>` 
- `<img src="<where to get the image from>" alt="<alternate text if image can not be viewed>">`
- `<a href="<link address>">text you want the user to see</a>`
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
  - `<input type="submit" value="<text you want to display on the button>">` creates the button for user to click on (nested inside `<form>` tags)
- `<div></div>` Start and end of a div (a section of the webpage)
- `<select></select>` Creates a drop down menu
  - `<option value="<what the value is of this option>">option1</option>`

### [CSS](https://youtu.be/g7nZFp2zSJ4)
CSS: Cascading Style Sheets

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
        text-align: center;
        color: blue;
    }
    ```
- `font-family: <font style>` changes font style

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

DOM: Document Object Model - Structure of the webpage.

JavaScript, when used in your webpage, can manipulate the DOM of the page to create an interative webpage.

To include JavaScript in your webpage:
- Go to your html file
- Nest inside the `<head>` tags:
  ```
  <script>
    your JavaScript code lives here
  </script>
  ```

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
  
