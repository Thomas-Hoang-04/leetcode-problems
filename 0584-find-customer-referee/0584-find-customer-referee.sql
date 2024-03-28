-- Write your PostgreSQL query statement below
select Customer.name from Customer where (referee_id is null) or referee_id <> 2;