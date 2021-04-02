# Question 5

Joana gives Eva the task of generating a report containing three columns: Name, Grade and Value. Joana does not want the names of students who received a grade lower than 8. The report must be in descending order by grade, that is, the highest grades are inserted first. If there are more than one student with the same grade (8-10) assigned to them, sort those students in particular by their names in alphabetical order. Finally, if the grade is less than 8, use "NULL" as the name and list them in grades in descending order. If there are more than one student with the same grade (1-7) assigned to them, sort those students in particular by their grades in ascending order.

Write an **SQL query** to help Eva.

## Solution

To help EVA, the following query was created:

```sql
select 
    case                                            
        when n.grade >= 8 
        then s.name 
        else NULL 
    end "name",                 -- Select name based on grade.
    n.grade, 
    s.value
from students s
inner join notes n
on s.value 
    between 
        n.min_value 
        and n.max_value         -- Defining grade based on values between min and max.
order by 
    s.value*
    case 
        when n.grade >= 8 
        then -1 
        else 1 
    end                         -- Ordering according to Joana's demand.
```

To properly order the grades, the following line was implemented:

```sql
order by 
    s.value*
    case 
        when n.grade >= 8 
        then -1 
        else 1 
    end						-- Ordering according to Joana's demand.
```

By multiplying `s.value` by -1  or 1, according to the naming rule, we can guarantee that every grade greater than 8 is negative, therefore, is displayed first, is ascending order, in opposition to the positive value.

To test the query, a database was implemented. Run the following statements if you don’t have a test set.

```sql
CREATE TABLE IF NOT EXISTS Students(
    ID serial PRIMARY KEY,
    Name varchar(255) NOT NULL,
    Value integer
);

Insert into Students(Name, Value)
values('Julia', 81)
,('Carol', 68)
,('Maria', 99)
,('Andreia', 78)
,('Jaqueline', 63)
,('Marcela', 88);

CREATE TABLE IF NOT EXISTS Notes(
    Grade integer,
    Min_Value integer,
    Max_Value integer
);

Insert into Notes(Grade, Min_Value, Max_Value)
values(1, 0, 9)
,(2, 10, 19)
,(3, 20,29)
,(4, 30, 39)
,(5, 40, 49)
,(6, 50, 59)
,(7, 60, 69)
,(8, 70, 79)
,(9, 80, 89)
,(10, 90, 100);
```

This database was implement in postgresql.