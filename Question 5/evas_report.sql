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