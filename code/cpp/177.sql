CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N := N-1;
  RETURN (
      # Write your MySQL query statement below.
        select 
        Salary 
        from 
        Employee
        group by 
        Salary
        order by 
        Salary desc 
        limit N, 1 -- limit N, 1 代表从 N 开始取一条数据
  );
END