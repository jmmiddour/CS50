-- Write a SQL query to determine the average rating of all movies released in 2012
-- Output a table w/ 1 column and 1 row, plus optional header, 
--   containing the average rating

SELECT AVG(rating) AS "Average Rating 2012"
    FROM ratings 
    WHERE movie_id IN (
        SELECT id 
        FROM movies
        WHERE year = "2012");