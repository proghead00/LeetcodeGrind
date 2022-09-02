# Write your MySQL query statement below
SELECT s1.score, 
    (
        SELECT COUNT(DISTINCT s2.score)
        FROM Scores s2
        WHERE s1.score <= s2.score
    )
    AS "rank"
    
FROM Scores s1
ORDER BY s1.score DESC
