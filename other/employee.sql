
insert into employee values (1, "A", "PUNE", 100), 
							(2, "B", "NASHIK", 200), 
							(3, "C", "DELHI", 300), 
							(4, "D", "NAGPUR", 400), 
							(5, "E", "MUMBAI", 500), 
							(6, "F", "NASHIK", 500);


-- Function which resturn table;


DELIMITER #
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
			returns emp_depts;
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











-- function-----------------------
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
	
  declare M int;
  set m = 99;
  RETURN (
      # Write your MySQL query statement below.
      
    	# select DISTINCT salary
    	# from employee e1
    	# where N = (select count(DISTINCT salary)
    	# from employee e2
    	# where e2.salary >= e1.salary)

      select (select distinct salary
      from employee
      order by salary desc
      limit N, 1)
  );
END


select count(*) 
		from employees
		where employees.department_id =
			(	select department_id 
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




-- Write a SQL statement to create a 
-- duplicate copy of countries table 
-- including structure and data by name dup_countries.


create table if not exists copy_countries as select * from countries;


-- Write a SQL statement to create a table named jobs 
-- including columns job_id, job_title, min_salary, 
-- max_salary and check whether the max_salary amount 
-- exceeding the upper limit 25000.



create table jobs (

	job_id int,
	job_title int,
	min_salary int,
	max_salary int check(min_salary <= 25000),
);

-- Check

ALTER TABLE Persons
ADD CHECK (Age>=18);

ALTER TABLE Persons
ADD CONSTRAINT CHK_PersonAge CHECK (Age>=18 AND City='Sandnes');

ALTER TABLE Persons
DROP CHECK CHK_PersonAge;

-- Write a SQL statement to create a table named countries 
-- including columns country_id, country_name and region_id
--  and make sure that no countries except Italy, India and 
--  China will be entered in the table.

create table countries (
	country_id int , 
	country_name varchar(30) check(country_name in ("Italy", "India", "china")),
	region_id int
);


-- Write a SQL statement to create a table named job_histry 
-- including columns employee_id, start_date, end_date, job_id
-- and department_id and make sure that the value against
-- column end_date will be entered at the time of insertion to the format like '--/--/----'.


CREATE TABLE IF NOT EXISTS job_history ( 

	EMPLOYEE_ID decimal(6,0) NOT NULL, 
	START_DATE date NOT NULL, 
	END_DATE date NOT NULL
	CHECK (END_DATE LIKE '--/--/----'), 
	JOB_ID varchar(10) NOT NULL, 
	DEPARTMENT_ID decimal(4,0) NOT NULL 
);


--10. Write a SQL statement to create a table named jobs including 
-- columns job_id, job_title, min_salary and max_salary, and make 
-- sure that, the default value for job_title is blank and min_salary 
-- is 8000 and max_salary is NULL will be entered automatically at the 
-- time of insertion if no value assigned for the specified columns.


create table jobs (

	job_id int,
	job_title varchar(25) default " ",
	min_salary int default 8000,
	max_salary int default NULL,
);



-- Write a SQL statement insert rows from country_new table to countries table.
-- Here is the rows for country_new table. Assume that, the countries table is empty.

INSERT INTO countries
SELECT * FROM country_new;


-------------------------------------UPDATE-----------------------------------



-- 1. Write a SQL statement to change the email column 
-- of employees table with 'not available' for all employees.

update employees set email = "not available";


-- 3. Write a SQL statement to change the email and commission_pct column of 
-- employees table with 'not available' and 0.10 for those employees whose department_id is 110.


update employees set email = "not available" and commision_pct = 0.10 where department_id = 110; 



 -- Write a SQL statement to change the email column of employees 
 -- table with 'not available' for those employees who belongs to the 'Accouning' department.


update employees set email = "not available" 
	where department_id = (select department_id where department_name = "Accouning");


-- 7. Write a SQL statement to change job ID of employee which ID is 118, to SH_CLERK if the employee 
-- belongs to department, which ID is 30 and the existing job ID does not start with SH.

update employees set job_id = "SH_CLERK"
where EMPLOYEE_ID = 30 and NOT job_id LIKE 'SH%';


-- 8. Write a SQL statement to increase the salary of employees under 
-- the department 40, 90 and 110 according to the company rules that, 
-- salary will be increased by 25% for the department 40, 
-- 15% for department 90 and 10% for the department 110 and 
-- the rest of the departments will remain same.



update employees set salary = 
	case(department_id)
		when 40 then salary + (salary * 0.25)
		when 90 then salary + (salary * 0.15)
		when 110 then salary + (salary * 0.10)
		else salary
	end;



-- 9. Write a SQL statement to increase the minimum and maximum salary of PU_CLERK 
-- by 2000 as well as the salary for those employees by 20% and commission percent by .10.


UPDATE jobs,employees
SET jobs.min_salary=jobs.min_salary+2000,
jobs.max_salary=jobs.max_salary+2000,
employees.salary=employees.salary+(employees.salary*.20),
employees.commission_pct=employees.commission_pct+.10
WHERE jobs.job_id='PU_CLERK'
AND employees.job_id='PU_CLERK';



----------------------------------------ALTER TABLE---------------------------------------

-- 1. Write a SQL statement to rename the table countries to country_new.
	
	alter table countries Rename country_new;
	
	
-- 2. Write a SQL statement to add a column region_id to the table locations.

	alter table locations add column region_id integer;

	-- modify datatype
	ALTER TABLE table_name
	MODIFY COLUMN column_name datatype;

-- 3. Write a SQL statement to add a columns ID as the first column of the table locations.

	alter table locations add column ID integer first;


-- 4. Write a SQL statement to add a column region_id after state_province to the table locations.

	alter table locations add column region_id integer after state_province;

-- 5. Write a SQL statement change the data type of the column country_id to integer in the table locations.

	alter table locations MODIFY COLUMN country_id integer;

-- 6. Write a SQL statement to drop the column city from the table locations.

	alter table locations DROP column city;

-- 7. Write a SQL statement to change the name of the column state_province to state,
-- keeping the data type and size same.

	ALTER TABLE locations
	CHANGE state_province state varchar(25);

	-- if table is empty
	ALTER TABLE locations
	DROP state_province,
	ADD state varchar(25)
	AFTER city;


-- 8. Write a SQL statement to add a primary key for the columns location_id in the locations table.

	alter table locations add constraint primary key(location_id);


-- 9. Write a SQL statement to add a primary key for a combination of columns location_id and country_id.
	
	alter table locations add constraint primary key(location_id, country_id);
	

-- 10. Write a SQL statement to drop the existing primary from the table locations 
-- on a combination of columns location_id and country_id.

	alter table locations DROP constraint primary key;

-- 11. Write a SQL statement to add a foreign key on job_id column 
-- of job_history table referencing to the primary key job_id of jobs table.


	alter table job_history add constraint foreign key job_id references jobs(job_id)


-- 12. Write a SQL statement to add a foreign key constraint 
-- named fk_job_id on job_id column of job_history table referencing to the primary key job_id of jobs table.

	alter table job_history add constraint fk_job_id foreign key job_id references jobs(job_id);

-- 13. Write a SQL statement to drop the existing foreign key fk_job_id 
-- from job_history table on job_id column which is referencing to the job_id of jobs table.

	alter table job_history drop constraint foreign key fk_job_id;

-- 14. Write a SQL statement to add an index named indx_job_id on job_id column in the table job_history.

	ALTER TABLE job_history
	ADD INDEX indx_job_id(job_id);

	

-- 15. Write a SQL statement to drop the index indx_job_id from job_history table.

	ALTER TABLE job_history
	DROP INDEX indx_job_id;

------------------------------------------------------------------------------------

-- uinque vs distinct 
-- Unique is a keyword used in the Create Table() directive to denote that 
-- a field will contain unique data, usually used for natural keys, foreign keys etc.
-- For example:

-- Create Table Employee(   
--     Emp_PKey Int Identity(1, 1) Constraint PK_Employee_Emp_PKey Primary Key,  
--     Emp_SSN Numeric Not Null Unique,  
--     Emp_FName varchar(16),   
--     Emp_LName varchar(16) 
-- )
-- i.e. Someone's Social Security Number would likely be a unique field in your table, 
-- but not necessarily the primary key.

-- Distinct is used in the Select statement to notify the query that you only want the 
-- unique items returned when a field holds data that may not be unique.

-- Select Distinct Emp_LName
-- From Employee
-- You may have many employees with the same last name, but you only want each different last name.

-- Obviously if the field you are querying holds unique data, then the Distinct keyword becomes superfluous.

-------------------------------------------------------------------------------------


-- 7. Write a query to check if the first_name fields of the employees table contains numbers

	select * 
	from employees
	where first_name REGEXP '[0-9]';

-- 19. Write a query to get monthly salary (round 2 decimal places) 
-- of each and every employee Go to the editor
-- Note : Assume the salary field provides the 'annual salary' information.

	select round((salary)/12, 2) as monthly_salary
	from employees;


-- Write a query to display the name (first_name, last_name) 
-- and salary for all employees whose salary is not in the range $10,000 through $15,000.

	select FIRST_NAME, last_name, salary
	from employees
	where salary not between 10000 and 15000;
	-- or 
	where salary < 10000 or salary > 15000;

-- Write a query to display the name (first_name, last_name) and salary
--  for all employees whose salary is not in the range $10,000 through $15,000 
--  and are in department 30 or 100.

	select FIRST_NAME, last_name, salary
	from employees
	where salary not between 10000 and 15000 and department_id in (30, 100);


-- in VS Exist
	-- Simply IN can't compare anything with Null but Exists can
/*

	The EXISTS operator is a Boolean operator that returns either true or false. 
	The EXISTS operator is often used the in a subquery to test for an “exist” condition.

		SELECT 
		    select_list
		FROM
		    a_table
		WHERE
		    [NOT] EXISTS(subquery);

	If the subquery returns any row, the EXISTS operator returns true, otherwise, it returns false.

	In addition, the EXISTS operator terminates further processing immediately once it finds a matching row. 
	Because of this characteristic, you can use the EXISTS operator to improve the performance of the query in
	 some cases.

	The NOT operator negates the EXISTS operator. In other words, the NOT EXISTS returns true if the 
	subquery returns no row, otherwise it returns false.

	You can use SELECT *, SELECT column, SELECT a_constant, or anything in the subquery. The results
	 are the same because MySQL ignores the select_list that appears in the SELECT clause.

	The reason is that the EXISTS operator works based on the “at least found” principle. It returns 
	true and stops scanning table once at least one matching row found.

	On the other hands, when the IN operator is combined with a subquery, MySQL must process the subquery 
	first and then uses the result of the subquery to process the whole query.

	The general rule of thumb is that if the subquery contains a large volume of data, the EXISTS operator 
	provides a better performance.

	However, the query that uses the IN operator will perform faster if the result set returned from the 
	subquery is very small. 

 */

 -- Write a query to display the first_name of all employees who have both "b" and "c" in their first name

 	select FIRST_NAME from employees
 	where first_name LIKE '%b%' and first_name LIKE '%c%';

-- Write a query to find the manager ID and the salary of the lowest-paid employee for that manager.

	SELECT manager_id, MIN(salary)
	FROM employees
	WHERE manager_id IS NOT NULL
	GROUP BY manager_id
	ORDER BY MIN(salary) DESC;

-- Write a query to get the department ID and the total salary payable in each department.

	select department_id, sum(salary)
	from employees
	group by department_id;

-- 13. Write a query to get the job ID and maximum salary 
-- of the employees where maximum salary is greater than or equal to $4000.

	
	select job_id, max(salary)
	from employees
	group by job_id
	having max(salary) >= 4000;


-- 14. Write a query to get the average salary for all departments 
-- employing more than 10 employee


	select department_id, avg(salary), count(*) total
	from employees
	group by department_id
	having count(*) > 10;


-----------------------------------------subqueries-----------------------------

-- 1. Write a query to find the name (first_name, last_name) 
-- and the salary of the employees who have a higher salary than the employee whose last_name='Bull'.


	select FIRST_NAME, last_name, salary
	from employees
	where salary > (select salary from employees where last_name = 'Bull');


-- Write a query to find the name (first_name, last_name) of the employee
--  who have a manager and worked in a USA based department


	select FIRST_NAME, last_name
	from employees
	where manager_id in (select EMPLOYEE_ID from employees
	where department_id in 	
	(select department_id
	from departments
	where location_id in (select location_id from locations where country_id = 'US')));



-- 6. Write a query to find the name (first_name, last_name), 
-- and salary of the employees whose salary is equal to the minimum salary for their job grad



	select FIRST_NAME, last_name
	from employees as emp
	where salary = (select min_salary from jobs where emp.job_id = jobs.job_id);


-- 7. Write a query to find the name (first_name, last_name), and salary of the employees 
-- who earns more than the average salary and works in any of the IT departments


	select FIRST_NAME, last_name, salary
	from employees
	where salary > (select avg(salary) from employees)
	and department_id IN (select department_id from departments where department_name = "IT");




-- 9. Write a query to find the name (first_name, last_name), and salary of the employees 
-- who earn the same salary as the minimum salary for all departments

	SELECT * FROM employees 
	WHERE salary = (SELECT MIN(salary) FROM employees);


	
-- Write a query to display the employee ID, first name, last name, 
-- salary of all employees whose salary is above average for their departments.

	SELECT employee_id, first_name 
	FROM employees AS A 
	WHERE salary > 
	(SELECT AVG(salary) FROM employees WHERE department_id = A.department_id);


-- Write a query to fetch even numbered records from employees table.

	SET @i = 0; 
	SELECT i, employee_id 
	FROM (SELECT @i := @i + 1 AS i, employee_id FROM employees)
	a WHERE MOD(a.i, 2) = 0;


 -- Write a query to find the 5th maximum salary in the employees table

	SELECT DISTINCT salary 
	FROM employees e1 
	WHERE 5 = (SELECT COUNT(DISTINCT salary) 
	FROM employees  e2 
	WHERE e2.salary >= e1.salary);
	
-- 17. Write a query to find the 4th minimum salary in the employees table

	select DISTINCT salary
	from employees e1
	where 4 = (select count(DISTINCT salary))
	from employees e2
	where e2.salary >= e1.salary);


-- Write a query to select last 10 records from a table.

	SELECT * FROM (
	SELECT * FROM employees ORDER BY employee_id DESC LIMIT 10) sub 
	ORDER BY employee_id ASC;


-- Write a query to list the department ID and name of all the departments where no employee is working.

	SELECT * FROM departments 
	WHERE department_id 
	NOT IN (select department_id FROM employees);

--Write a query to get 3 maximum salaries

	select distinct salary
	from employees
	ORDER by salary desc
	LIMIT 3;

	or 

	SELECT DISTINCT salary 
	FROM employees a 
	WHERE 3 >= (SELECT COUNT(DISTINCT salary) 
	FROM employees b 
	WHERE b.salary >= a.salary) 
	ORDER BY a.salary DESC;


-- Write a query to get 3 minimum salaries.

	select distinct salary
	from employees
	ORDER by salary asc
	LIMIT 3;

	or 

	SELECT DISTINCT salary 
	FROM employees a 
	WHERE  3 >= (SELECT COUNT(DISTINCT salary) 
	FROM employees b 
	WHERE b.salary <= a.salary) 
	ORDER BY a.salary DESC;

-- . Write a query to get nth max salaries of employees

	SELECT *
	FROM employees emp1
	WHERE (1) = (
	SELECT COUNT(DISTINCT(emp2.salary))
	FROM employees emp2
	WHERE emp2.salary > emp1.salary);



--------------------joins-------------------------


-- 1. Write a query to find the addresses 
-- (location_id, street_address, city, state_province, country_name) of all the departments
-- https://www.w3resource.com/mysql-exercises/join-exercises/index.php


	select location_id, street_address, city, state_province, country_name
	from locations natural join countries;
	where locations.country_id = countries.country_id;

	-- without join

	select location_id, street_address, city, state_province, country_name
	from locations, countries;
	where locations.country_id = countries.country_id;

--  Write a query to find the name (first_name, last name), department ID and 
-- name of all the employees.
	
	select FIRST_NAME, last_name, department_id, department_name
	from employees natural join departments;

-- 3. Write a query to find the name (first_name, last_name), job, 
-- department ID and name of the employees who works in London

	SELECT e.first_name, e.last_name, e.job_id, e.department_id, d.department_name 
	FROM employees e JOIN departments d ON (e.department_id = d.department_id) 
	JOIN locations l ON (d.location_id = l.location_id) 
	WHERE LOWER(l.city) = 'London';


-- 4. Write a query to find the employee id, name (last_name) 
-- along with their manager_id and name (last_name).

	SELECT e.employee_id 'Emp_Id', e.last_name 'Employee', 
	m.employee_id 'Mgr_Id', m.last_name 'Manager' 
	FROM employees e join employees m ON (e.manager_id = m.employee_id);














-----------------Dates---------------------------


-- Write a query to display the first day of the month (in datetime format) 
-- three months before the current month.

-- Sample current date : 2014-09-03
-- Expected result : 2014-06-01

	SELECT date(((PERIOD_ADD (EXTRACT(YEAR_MONTH FROM CURDATE()),-3)*100)+1));

-- Write a query to display the last day of the month (in datetime format) three 
-- months before the current month.

	SELECT (SUBDATE(ADDDATE	(CURDATE(),INTERVAL 1 MONTH),INTERVAL DAYOFMONTH(CURDATE())DAY)) 
            AS LastDayOfTheMonth;


/*
 * practice join
 https://www.guru99.com/joins.html
 */


 create table if not exists TABLEA (

 		EMP_id integer PRIMARY KEY AUTO_INCREMENT,
 		emp_name varchar(25),
 		dept_id integer not NULL,
 		foreign key (dept_id) references department(dept_id)
 	);


	insert into TABLEA (emp_name, dept_id) values
											("A", 1),
											("B", 2),
											("D", 4),
											("E", 5);



create table if not exists department(

 		dept_id integer primary key AUTO_INCREMENT,
 		dept_name varchar(20),
 		dept_location varchar(30) default NULL
 );


	-- TABLEA 		EMP_ID emp_name dept_id
	-- department dept_id dept_name dept_location

	insert into department (dept_name, dept_location) values
							("NAGPUR", "NAGPUR"),
							("Dhule", "dhule"),
							("DELHI", "DELHI"),
							("BEED", "BEED");


select *
from employee as e right join department as d
on e.dept_id = d.dept_id;


select *
from employee as e right join department as d
using (dept_id);




-- on vs using in joins

/*
USING clause can also be used for the same purpose. The difference 
with USING is it needs to have identical names for matched columns in both tables.

Apart from using ON and USING with JOINs you can use many
 other MySQL clauses like GROUP BY, WHERE and even functions like SUM, AVG, etc.

*/






select concat(first_name, ' ', last_name) as name, DEPARTMENT_id, DEPARTMENT_name
from employees join departments using (DEPARTMENT_ID);


-- Write a query to find the name (first_name, last_name), job, 
-- department ID and name of the employees who works in London.

select first_name, last_name, department_id, department_name
from employees e
join departments d
using (department_id)
join locations l
using (location_id)
where city ="London";


 -- Write a query to find the employee id, name (last_name) 
 -- along with their manager_id and name (last_name)



select e.employee_id, e.first_name, m.manager_id, m.first_name
from employees as e join employees as m on (e.employee_id = m.employee_id);



--5. Write a query to find the name (first_name, last_name) 
-- and hire date of the employees who was hired after 'Jones'.

	
	select FIRST_NAME, last_name, hire_date
	from employees as e1 
	where hire_date > (select hire_date from employees where last_name = 'Jones');

					or 

	SELECT e.first_name, e.last_name, e.hire_date 
	FROM employees e 
	JOIN employees davies 
	ON (davies.last_name = 'Jones') 
	WHERE davies.hire_date < e.hire_date;



-- Write a query to get the department name and number of employees in the department

	SELECT department_name AS 'Department Name', 
	COUNT(*) AS 'No of Employees' 
	FROM departments 
	INNER JOIN employees 
	ON employees.department_id = departments.department_id 
	GROUP BY departments.department_id, department_name 
	ORDER BY department_name;



-- Write a query to find the employee ID, job title, number of days between ending date 
-- and starting date for all jobs in department 90 from job history.

	select EMPLOYEE_ID, job_title, END_DATE - START_DATE as days
	from job_history natural join jobs
	where department_id = 90;


SELECT employee_id, job_title, end_date-start_date Days FROM job_history 
NATURAL JOIN jobs 
WHERE department_id=90;



-- select * from employees
-- into outfile 'C:\Users\Cs\Desktop\test.csv'
-- fields enclosed by '"'
-- Terminated by ';'
-- escaped by '"'
-- lines terminated by '\r\n';




-- 8. Write a query to display the department ID and name and first name of manager



	select departments.department_id, department_name, first_name
	from departments natural join employees on(departments.manager_id = employees.employee_id);


	select departments.department_id, department_name, first_name
	from departments natural join employees on (departments.manager_id = employees.employee_id);


	SELECT d.department_id, d.department_name, d.manager_id, e.first_name 
	FROM departments d 
	INNER JOIN employees e 
	ON (d.manager_id = e.employee_id);



-------------------Stored Procedures----------------------------
-- https://www.mysqltutorial.org/stored-procedures-parameters.aspx
-- https://www.javatpoint.com/mysql-procedure

	DELIMITER #
	CREATE PROCEDURE getAllEmployees()
		BEGIN			
			SELECT * FROM employees;
		END

-- Rename procedure (Drop and create new)


-- Parameterised procedure

	create PROCEDURE getEmployeeByID(in job_id varchar(20))

		begin

			select *
			from employees
			where employees.job_id = 'AC_MGR';
		end



	create PROCEDURE getEmployeeCountByID(in job_id varchar(30), out counts integer)

		begin

			select count(*) into counts
			from employees
			where employees.job_id = job_id;
		end

		-- call getEmployeeCountByID('ST_CLERK', @total)
		-- select total


/*
> SHOW PROCEDURE STATUS WHERE db = 'mystudentdb';  
check all stored procedures

*/

-- CREATE FUNCTION function_name [ (parameter datatype [, parameter datatype]) ]   
-- RETURNS return_datatype  
-- BEGIN  
-- Declaration_section  
-- Executable_section  
-- END;  


	DELIMITER #
	create function getEmployeeByID(job_id varchar(20)) returns int DETERMINISTIC
		begin
			declare emps integer;
			set emps = 0;

			select count(*) into emps
			from employees
			where employees.job_id = job_id;

			return emps;
		end#


DELIMITER #
create function employee_departments()
	returns table (

		EMPLOYEE_ID integer,
		FIRST_NAME varchar(30),
		department_name varchar(30))
	as 
	begin
		insert into @emp_depts
			select EMPLOYEE_ID, FIRST_NAME, department_name
			from employees, departments
			where employees.department_id = departments.department_id;
			returns emp_depts;
	end; #


	----------------Triggers---------------
/*
	In MySQL, a trigger is a stored program invoked automatically in response to an event 
	such as insert, update, or delete that occurs in the associated table. For example, 
	you can define a trigger that is invoked automatically before a new row is inserted 
	into a table.		MySQL supports triggers that are invoked in response to the 
	INSERT, UPDATE or DELETE event.		The SQL standard defines two types of triggers:
	row-level triggers and statement-level triggers.		
	A row-level trigger is activated for each row that is inserted, updated, or deleted. 
	For example, if a table has 100 rows inserted, updated, or deleted, the trigger is 		
	automatically invoked 100 times for the 100 rows affected.		
	A statement-level trigger is executed once for each transaction regardless of how 		
	many rows are inserted, updated, or deleted.

	
	MySQL supports only row-level triggers. It doesn’t support statement-level triggers.

*/









