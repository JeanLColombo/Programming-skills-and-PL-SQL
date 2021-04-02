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
