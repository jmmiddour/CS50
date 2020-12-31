-- Write a SQL query to list all movies released in 2010 and their ratings,
--   in descending order by rating. If rating is the same, alphabetically
-- Output a table w/ 2 columns, title and rating for each movie.
-- Movies without a rating should not be included.

SELECT m.title, r.rating
    FROM movies AS m
    JOIN ratings AS r
        ON r.movie_id = m.id
    WHERE m.year = "2010"
        AND r.rating > "0"
    ORDER BY r.rating DESC, m.title ASC;