-- Write your MySQL query statement below
select
    Customers.Name as 'Customers'
from
    Customers
where
    id not in (
        select CustomerId from Orders
    );