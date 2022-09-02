# Write your MySQL query statement below

SELECT email 
FROM(
    SELECT email, COUNT(email) AS cnt
    FROM Person
    GROUP BY email
) TEMP

WHERE TEMP.cnt > 1