# Write your MySQL query statement below

SELECT IFNULL(
    (
    SELECT DISTINCT salary  
    FROM Employee e1
    WHERE 1 = (
              SELECT COUNT(DISTINCT salary) # there should not be space b/w count and the parenthesis
              FROM Employee e2
              WHERE e1.salary < e2.salary # check the condition... less than e2.salary!!
              )
    ),
    
    NULL
)
              
AS SecondHighestSalary 