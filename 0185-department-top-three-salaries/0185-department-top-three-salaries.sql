# Write your MySQL query statement below

SELECT d.name Department, e1.name Employee, e1.salary
FROM Employee e1 
JOIN Department d
ON e1.DepartmentId = d.Id

WHERE 3 > (SELECT COUNT(DISTINCT(e2.salary)) 
                  FROM Employee e2 
                  WHERE e2.Salary > e1.Salary 
                  AND e1.DepartmentId = e2.DepartmentId
           );