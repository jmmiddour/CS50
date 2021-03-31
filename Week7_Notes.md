## CS50 - Week 7 - [SQL](https://youtu.be/u5pDdEKnbKA)

**SQL:** Structured Query Language - relational database

`lambda` just an annonomous function

How to run SQLite3 in the command line:
- `sqlite3 <name of database you want to work with.db>` lets you turn the command line into SQLite3 command prompt to work with the file. If the file does not already exist this command will also create it.
- `.mode csv` turns on the csv functionallity
- `.import "<csv file you want to run>" <name of table to import to>` imports the csv file you want to use into file name you specify
- Now you are ready to start working with that file and table in SQLite3 mode.
- `.quit` exit out of that sqllite3 command prompt

SQLite3 commands
- `SELECT <column> FROM <table>;`
  - will print out all the titles in the favorites table
- `SELECT <column> FROM <table> ORDER BY <column>;` 
  - will sort the column in alphabetical order from a-z
- `SELECT <column>, COUNT(<column>) FROM <table> GROUP BY <column>;` 
  - gives you the value in the column and how many times it appears in the column
- `SELECT <column>, COUNT(<column>) FROM <table> GROUP BY <column> LIMIT <num of values>;` 
  - limits it to the number of values you specify
- `SELECT <column>, COUNT(<column>) AS <alias> FROM <table> GROUP BY <column> ORDER BY <alias of count> DESC LIMIT <num of values>;` 
  - Shows the top <num of vlaues> based on count, starting with greatest to least
- `.schema` outputs the `CREATE TABLE` statments that was used to generate each table in the database. Shows the types of data in the database.

4 Fundimental Operations for Dealing with Data (CRUD):
- **C**reate = *SQL:* `INSERT`
- **R**ead   = *SQL:* `SELECT`
- **U**pdate = *SQL:* `UPDATE`
- **D**elete = *SQL:* `DELETE`

Create a new table in SQL:
  `CREATE TABLE <table name> (<column> <type>, ...);` can create multiple columns at once
  
SQL(PostgreSQL) Data Types:
- `BLOB` = Binary Large Object - for storing binary data only (not commonly used)
- `INTEGER` = integer (whole number)
  - `smallint` = < 32 bits
  - `integer`  = 32 bits
  - `bigint`   = 64 bits
- `NUMERIC` = Catch all for numerical numbers
  - `boolean` = true / false numerical values
  - `date` = shows in date format only
  - `datetime` = shows date and time only
  - `numeric(scale, precision)` = specify exactly how many numbers before and after decimal
  - `time` = time only
  - `timestamp` = timestamp pre-defined format
- `REAL` = similar to a float number
  - `real` = 32 bits
  - `double precision` = 64 bits
- `TEXT` = alphanumerical characters
  - `char(n)` = specify the number of characters that every column cell will accept (all have to be exactly `n` in length)
  - `varchar(n)` = specify the max number of characters for each cell in that column
  - `text` = Unspecified number of characters

Insert Values in a Table:
  `INSERT INTO <table> (<column>, ...) VALUES (<value>, ...);` can insert multiple columns and values at one time

Select Data from a Database:
  `SELECT <column> FROM <table>;`
  
Updating a Value:
  `UPDATE <table> SET <column>=<value> WHERE <condition>;`
  - example:
    `UPDATE favorites SET title = "The Office" WHERE title LIKE "%office%";`

Delete a Value:
  `DELETE FROM <table> WHERE <condition>;`

Delete an Entire Column or Table:
- `DELETE <column> FROM <table>;` deletes the column from the table
- `DELETE FROM <table>;` deletes everything in the table
- `DROP <table>;` deletes the whole table

Common Functions in SQL:
- `AVG <column>` = gives you the average of a column
- `COUNT <column>` = gives you a count of how many times something appears in a column
- `DISTINCT <column>` = gives you the unique values
- `MAX <column>` = gives you the max value in a column
- `MIN <column>` = gives you the min value in a column
- `WHERE <condition>` = creates a conditional statement - Always goes at the end of a query
- `%` = wild card for characters
- `LIKE "%<value>%"` = will return anything that has that value within the value (i.e. `... WHERE title LIKE "%office%";` returns any values with "office" anywhere within the value) - NOT case sensitive (will return upper and lower case)
- `LIMIT <number of values to return>` = limits the number of values returned based on the number you specify
- `GROUP BY <value or column>` = groups results by a specified value or column
- `ORDER BY <value or column>` = orders results by a specified value or column (default = `ASC` (ascending), or specify `DESC` (descending (greatest - least)))
- `JOIN` = joins tables together into one table or view
- `?` can use as a placeholder
- `*` wild card to select all columns
- `IN` lets you search through another table and match it to values in starting table based on a condition

Using `cs50` Library to run SQL Commands in a Python Program:
- `db = cs50.SQL("sqlite:///<database>")` need to make sure the file already exist
- `db.execute("<SQL query>)"` gives you the ability to run SQL queries in python

Relationships:
- One to One = There will be only one unique value that matches in both tables
- One to Many = There will only be one unique value in one table but can have multiples of that same value in another table that it is connected to.
- Many to Many = There can be multiplies of the matching values in both tables

[SQL Keywords Reference](https://www.w3schools.com/sql/sql_ref_keywords.asp)

Other Command Line Arguements that can be Helpful:
- `vim <file name>` shows the file contents in the terminal window
- `wc -l <file name>` or `<file> | wc -l` returns a word count
- `cp <file> .` makes a copy of the file
- `cp <directory>` makes a copy of the whole directory
- `touch <file name>` creates an empty file with the name specified
