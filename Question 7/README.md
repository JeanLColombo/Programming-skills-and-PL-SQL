# Question 7

Information about pets is kept in two separate tables.

```sql
TABLE dogs
id INTEGER NOT NULL PRIMARY KEY,
name VARCHAR(50) NOT NULL

TABLE cats
id INTEGER NOT NULL PRIMARY KEY,
name VARCHAR(50) NOT NULL
```

Write an **SQL query** that select all distinct pet names.

## Solution

Run the following query:

```sql
select distinct t.name
from 
(selec name from dogs
union select name from cats) t
```

which unifies both tables, and the select entries based on name distinction.