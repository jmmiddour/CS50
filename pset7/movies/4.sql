-- Write a SQL query to determine the number of movies w/ rating of 10.0
-- Should output a table with a single column and row, 
--   plus optional header, containing the number of movies rated 10.0

SELECT COUNT(rating) AS "Number of 10.0 Ratings" 
    FROM ratings 
    WHERE rating = "10.0";