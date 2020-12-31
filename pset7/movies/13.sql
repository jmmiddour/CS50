-- Write a SQL query to list the names of all people who starred in a movie
--   in which Kevin Bacon also starred.
-- Output table w/ 1 column for the names of each person.
-- There might be multiple people named Kevin Bacon in db, 
--   only select the one born in 1958.
-- Do not include Kevin Bacon in the list.

-- CREATE INDEX movie_index ON movies(title);

-- CREATE INDEX name_index ON people(name);

SELECT DISTINCT(p.name) FROM people AS p
    JOIN stars AS s ON s.person_id = p.id
    WHERE s.movie_id IN (
        SELECT s.movie_id FROM stars AS s
        JOIN people AS p ON p.id = s.person_id
        WHERE p.name = "Kevin Bacon"
            AND p.birth = "1958")
    AND p.name != "Kevin Bacon";