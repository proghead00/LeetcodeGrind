# Write your MySQL query statement below

SELECT Customers.name as "Customers"
FROM Customers LEFT JOIN ORDERS ON Customers.id = Orders.customerId 
WHERE customerId IS NULL