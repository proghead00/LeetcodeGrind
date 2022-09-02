CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1; # SET BEFORE RETURN STATEMENT
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT Salary  # DISTINCT!!!
      FROM Employee 
      ORDER BY Salary DESC # MAINTAIN THE ORDER: SELECT -> FROM -> ORDER -> LIMIT
      LIMIT 1 OFFSET N  
  );
END