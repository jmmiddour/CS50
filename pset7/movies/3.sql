-- Write a SQL query to list the titles of all movies with a release date 
--   on or after 2018, in alphabetical order.
-- Should output a table w/ a single column for the title of each movie.
-- Movies released in 2018 and in the future should be included.

SELECT title FROM movies 
    WHERE year > "2017" ORDER BY title;