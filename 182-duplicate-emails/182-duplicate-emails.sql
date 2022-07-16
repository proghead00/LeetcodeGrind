# Write your MySQL query statement below

# get the count of each email, and then filter them accordingly

SELECT email FROM

(SELECT email, COUNT(email) AS cnt
FROM Person 
GROUP BY email) AS tempTable

WHERE cnt > 1