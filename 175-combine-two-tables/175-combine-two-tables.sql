# Write your MySQL query statement below

SELECT firstName, lastName, state, city
FROM Person LEFT JOIN Address ON Person.personId = Address.personId