select distinct t.name
from 
(selec name from dogs
union select name from cats) t