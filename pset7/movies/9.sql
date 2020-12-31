-- Write a SQL query to list the names of all people who starred in a movie
--   released in 2004, ordered by birth year.
-- A table w/ 1 column for the name of each person
-- People w/ the same birth year may be listed in any order.
-- Don't worry about people with no birth year, just make sure those that
--   do have a birth year are listed in order.
-- If person appears more than once in 2004, should only appear once.

SELECT name
    FROM people 
    WHERE id IN (
        SELECT person_id
        FROM stars
        WHERE movie_id IN (
            SELECT id 
            FROM movies
            WHERE year = "2004"))
    ORDER BY birth;