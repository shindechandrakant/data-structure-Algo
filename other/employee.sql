
insert into employee values (1, "A", "PUNE", 100), 
							(2, "B", "NASHIK", 200), 
							(3, "C", "DELHI", 300), 
							(4, "D", "NAGPUR", 400), 
							(5, "E", "MUMBAI", 500), 
							(6, "F", "NASHIK", 500);


-- Function which resturn table;


create function employee_departments()
	returns @emp_depts table (

		EMPLOYEE_ID integer,
		FIRST_NAME varchar(30),
		department_name varchar(30))

	as 
	begin
		insert into @emp_depts
			select EMPLOYEE_ID, FIRST_NAME, department_name
			from employees, departments
			where employees.department_id = departments.department_id;


	end;


create function employee_departments()
	returns table
	as 
	return
		select EMPLOYEE_ID, FIRST_NAME, department_name
		from employees, departments
		where employees.department_id = departments.department_id;


	end;


create or replace function count_employees(dep_name varchar(30))
	returns integer
	begin
		declare emp_count integer;
		select count(*) into emp_count
		from employees
		where employees.department_id = 
			(select department_id 
				from departments 
				where departments.department_name = dep_name);

		return emp_count;
	end;




select count(*) 
		from employees
		where employees.department_id =
			(select department_id 
				from departments 
				where departments.department_name = "IT");



select count(*) 
from employees
group by department_id
having employees.department_id =
(select department_id 
from departments 
where departments.department_name = "IT");


select count(*) 
from employees natural join departments 
on (employees.department_id = departments.department_id)
where departments.department_name = "IT";

group by department_id
having employees.department_id =
(select department_id 
from departments 
where departments.department_name = "IT");





-- joins
/*Write a query to 
find the addresses (location_id, street_address, city, state_province, country_name)
of all the departments. */

select location_id, street_address, city, state_province, country_name
from locations natural join countries on country_id;

select location_id, street_address, city, state_province, country_name
from locations, countries
where locations.country_id = countries.country_id;


 -- Write a query to find the name (first_name, last name), department ID and name of all the employees.

 select FIRST_NAME, last_name, department_id, department_name
 from employees join departments using (department_id);

SELECT first_name, last_name, department_id, department_name 
FROM employees JOIN departments USING(department_id);


select FIRST_NAME, last_name, employees.department_id, department_name
from employees, departments
where employees.department_id = departments.department_id;


/*
Write a query to find the name (first_name, last_name), 
job, department ID and name of the employees who works in London
*/

select first_name, last_name, DEPARTMENT_ID, DEPARTMENT_NAME






