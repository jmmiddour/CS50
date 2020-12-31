-- Write a SQL query to determine the birth year of Emma Stone
-- Should output a table with a single column and single row, 
--   plus optional header, containing Emma Stone's birth year.
-- Can assume that there is only 1 person in the db w/ the name Emma Stone.

SELECT birth FROM people WHERE name = "Emma Stone";