# Write your MySQL query statement below
SELECT id, 

CASE

WHEN p_id is NULL THEN 'Root'
WHEN id in (SELECT DISTINCT p_id FROM Tree) THEN 'Inner' # if id is also present as a parent
ELSE 'Leaf'

END AS type
FROM Tree
