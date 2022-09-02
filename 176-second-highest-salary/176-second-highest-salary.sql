# Write your MySQL query statement below

SELECT IFNULL(
    NULL,
    
    (SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1))
    
    AS SecondHighestSalary # AS --> in the end 
