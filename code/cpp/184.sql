-- Write your MySQL query statement below
select 
    d.Name as 'Department',
    e.Name as 'Employee',
    e.Salary
from
    Department as d
    join
    Employee as e
    on e.DepartmentId = d.id
where
    (e.DepartmentId, e.Salary) in (
        select 
            DepartmentId, max(Salary)
        from Employee
        group by DepartmentId
    );