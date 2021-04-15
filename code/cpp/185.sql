-- 采用开窗法， 使用窗口函数来计算每个部门每个人的工资排名，然后取排名大于前三名的
select
    Department, Employee, Salary
from (
    select d.name Department, e.name Employee,Salary,
    dense_rank() over (partition by DepartmentId order by Salary desc) rk
    from Employee e inner join Department d 
    on e.DepartmentId = d.id
)t
where rk <= 3;

