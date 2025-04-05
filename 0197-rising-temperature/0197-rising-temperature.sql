# Write your MySQL query statement below
select distinct w.id from Weather w join Weather s on DATEDIFF(w.recordDate,s.recordDate)=1 where w.temperature>s.temperature;