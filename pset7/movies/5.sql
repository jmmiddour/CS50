-- Write a SQL query to list the titles and release years of all Harry Potter
--   movies in chronological order
-- Output a table w/ 2 columns, one - title of each movie,
--   the other - release year of each movie
-- Assume the title of all Harry Potter movies begin with "Harry Potter"

SELECT title, year FROM movies 
    WHERE title LIKE "Harry Potter%"
    ORDER BY year;