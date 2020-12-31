-- Write a SQL query to list the title of all movies in which both Johnny Depp
--   and Helena Bonham Carter starred.
-- Output table w/ 1 column for the title of each movie.
-- Assume that there is only one person w/ each name.

SELECT title FROM movies 
    WHERE id IN (
        SELECT movie_id FROM stars
        WHERE person_id IN (
            SELECT id FROM people
            WHERE name = "Johnny Depp"))
    AND id IN (
        SELECT movie_id FROM stars
        WHERE person_id IN (
            SELECT id FROM people
            WHERE name = "Helena Bonham Carter"));