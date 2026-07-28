# Write your MySQL query statement below
select a.name as name , b.bonus as bonus
from Employee a left join Bonus b
on a.empId = b.empId
where b.bonus is null or bonus<1000