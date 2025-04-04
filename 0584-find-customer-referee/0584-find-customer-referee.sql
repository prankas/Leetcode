# Write your MySQL query statement below
SELECT name from Customer where referee_id != 2 or ISNULL(referee_id);