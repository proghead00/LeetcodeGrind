# Write your MySQL query statement below
SELECT 
CASE WHEN id % 2 = 0 THEN id - 1
WHEN id % 2 != 0 AND (SELECT MAX(id) FROM Seat) != id THEN id + 1
ELSE id end id, student FROM Seat ORDER BY 1;