-- Write a SQL query to list the titles of the 5 highest rated movies (in order)
--   that Chadwick Boseman starred in, starting with the hightest rated
-- Output a table w/ 1 column for the title of each movie
-- Assuming there is only one person in the db with that name.

-- SELECT title FROM movies 
--     WHERE id IN (
--         SELECT movie_id FROM ratings
--         WHERE movie_id IN (
--             SELECT movie_id FROM stars
--             WHERE person_id IN (
--                 SELECT id
--                 FROM people
--                 WHERE name = "Chadwick Boseman"))
--         ORDER BY rating DESC)
--     LIMIT 5;

SELECT m.title FROM movies AS m
    JOIN ratings AS r ON r.movie_id = m.id
    JOIN stars AS s ON s.movie_id = m.id
    JOIN people AS p ON p.id = s.person_id
    WHERE p.name = "Chadwick Boseman"
    ORDER BY r.rating DESC
    LIMIT 5;