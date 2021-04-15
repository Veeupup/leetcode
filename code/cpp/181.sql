-- 直接自连接即可
select 
    a.name as 'Employee'
from
    Employee as a,
    Employee as b
where 
    a.ManagerId = b.id and
    a.Salary > b.Salary;