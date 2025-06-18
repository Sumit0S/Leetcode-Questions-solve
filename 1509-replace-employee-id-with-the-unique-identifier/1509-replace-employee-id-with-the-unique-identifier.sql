SELECT em.unique_id AS unique_id, un.name AS name
from Employees un
left join EmployeeUNI em
on un.id=em.id;