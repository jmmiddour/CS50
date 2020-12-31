-- Write a SQL query to list names of all people who starred in Toy Story
-- Output a table w/ 1 column for the names of each person.
-- Assuming that there is only one movie in the db with the title "Toy Story"

SELECT name 
    FROM people 
    WHERE id IN (
        SELECT person_id
        FROM stars
        WHERE movie_id = (
            SELECT id 
            FROM movies
            WHERE title = "Toy Story")); 