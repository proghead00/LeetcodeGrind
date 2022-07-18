# Write your MySQL query statement below

SELECT d.name Department, e1.name Employee, e1.salary
FROM Employee e1 
JOIN Department d
on e1.DepartmentId = d.Id

WHERE 3 > (SELECT count(DISTINCT(e2.salary)) 
                  from Employee e2 
                  where e2.Salary > e1.Salary 
                  and e1.DepartmentId = e2.DepartmentId
           );