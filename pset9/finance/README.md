# CS50 Finance - Complete Web Application

## What is CS50 Finance?

While working my way through the CS50 course at Harvard University, I was tasked with creating a fully functioning web application. This web application was to be called CS50 Finance and needed to allow the user to do the following task with a mock account:

The user needed the ability to:

- Register for an account that gives them $10,000 of "play money" to practice buying and selling stocks

- Login to their account and see their current mock portfolio

- Look up a quote for a stock symbol based on current market value

- Buy a stock with their mock account at the current market value

- Sell a stock from their mock account at the current market value

- View the history of transactions on their mock account over the entire life of the account

## Screenshots of the Application in Action:

Registration Page

![Registration](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/registration_screenshot1.jpg?raw=true)

Login Page

![Login](https://raw.githubusercontent.com/jmmiddour/CS50/main/pset9/finance/images/index_screenshot1.jpg)

Portfolio / Home Page Example

![Portfolio](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/index_screenshot2.jpg?raw=true)

Quote Page

![Quote](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/quote_screenshot1.jpg?raw=true)

Quote Results Page Example

![Quote Example](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/quote_screenshot2.jpg?raw=true)

Buy Page Example

![Buy](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/buy_screenshot1.jpg?raw=true)

Sell Page Example

![Sell](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/sell_screenshot1.jpg?raw=true)

Sell Page Drop-Down Example

![Sell Drop-Down](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/sell_screenshot2.jpg?raw=true)

History Page Example

![History Example](https://github.com/jmmiddour/CS50/blob/main/pset9/finance/images/history_screenshot2.jpg?raw=true)

## Deployment

This is application is currently only being deployed by the users local machine. To be able to deploy this application on your local machine, you need to follow these steps:

1. Register for an API key in order to be able to query IEX’s data for the stock prices. To do so, follow these steps:

    - Visit [iexcloud.io/cloud-login#/register/](https://iexcloud.io/cloud-login#/register/)
    
    - Select the “Individual” account type, then enter your email address and a password, and click “Create account”.
    
    - Once registered, scroll down to “Get started for free” and click “Select Start” to choose the free plan.
    
    - Once you’ve confirmed your account via a confirmation email, visit [iexcloud.io/console/tokens](https://iexcloud.io/console/tokens).
    
    - Copy the key that appears under the *Token* column (it should begin with `pk_`).
    
2. In the terminal, use the command: `export API_KEY=<your API key>` to add your API key to your environment variables

3. In the terminal, use the command: `export FLASK_APP=application.py:app` to add the app to the flask app environment variable

4. Finally, in the terminal, use the command: `flask run` to run the application locally.

## Contributors

| [Joanne Middour](https://github.com/jmmiddour) | 
| :---: | 
| [<img src="https://avatars.githubusercontent.com/u/64432505?v=4" width = "100"/>](https://github.com/jmmiddour) |
| [<img src="https://img.shields.io/badge/-Github-333?style=flat&logo=Github&logoColor=white">](https://github.com/jmmiddour) |
| [<img src="https://img.shields.io/badge/-LinkedIn-blue?style=flat&logo=Linkedin&logoColor=white">](https://www.linkedin.com/in/joanne-middour/) |

Work done in `application.py`:

- Lines 47 - 315

    - `index()` function
    
    - `buy()` function

    - `history()` function

- Lines 370 - 616

    - `quote()` function

    - `register()` function
    
    - `sell()` function
    
- Added comments and doc strings to my code and the code that was provided by CS50

- `finance.db` - `history` table

Files Completed 100%

- `templates/buy.html`

- `templates/history.html`

- `templates/index.html`

- `templates/quote.html`

- `templates/quote_form.html`

- `templates/register.html`

- `templates/sell.html`

| [CS50 Team](https://github.com/cs50) | 
| :---: | 
| [<img src="https://avatars.githubusercontent.com/u/788676?s=200&v=4" width = "100" />](https://github.com/cs50) |
| [<img src="https://img.shields.io/badge/-Github-333?style=flat&logo=Github&logoColor=white">](https://github.com/cs50) |
| [<img src="https://img.shields.io/badge/-LinkedIn-blue?style=flat&logo=Linkedin&logoColor=white">](https://www.linkedin.com/school/cs50/) |

All other functionality in the `application.py` file.

Files Completed

- `static/favicon.ico`

- `style.css`

- `templates/apology.html`
  
- `templates/layout.html`
  
- `templates/login.html`

- `finance.db` - `users` table

- `helpers.py`

- `requirements.txt`
