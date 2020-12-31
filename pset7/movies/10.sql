-- Write a SQL query to list the names of all people who have directed a movie
--   that received a rating of at lease 9.0
-- Output a table w/ 1 column for the name of each person.

SELECT name
    FROM people 
    WHERE id IN (
        SELECT person_id
        FROM directors
        WHERE movie_id IN (
            SELECT movie_id 
            FROM ratings
            WHERE rating >= "9.0"));