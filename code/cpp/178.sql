-- Write your MySQL query statement below
-- row_number()：依次递增排名，无重复排名
-- rank()：相同分数有重复排名，但是重复后下一个人按照实际排名
-- dense_rank()：分数一致排名一致，分数不一致排名+1
-- NTILE(4)：分组排名，里面的数字是几，最多排名就是几，里面的数字是4，最多的排名就是4

SELECT Score, DENSE_RANK() OVER( ORDER BY SCORE DESC ) AS 'Rank' FROM Scores;