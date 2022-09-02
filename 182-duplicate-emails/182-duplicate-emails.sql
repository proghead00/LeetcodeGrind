# Write your MySQL query statement below

SELECT email AS Email
FROM(
    SELECT email, COUNT(email) AS cnt
    FROM Person
    GROUP BY email
) TEMP

WHERE TEMP.cnt > 1