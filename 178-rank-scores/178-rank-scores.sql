# Write your MySQL query statement below
SELECT s1.Score,

(SELECT COUNT(DISTINCT s2.Score) FROM Scores s2 WHERE s1.Score <= s2.Score) AS 'Rank'

FROM Scores s1

ORDER BY s1.Score DESC