USE practical;

-- 1
SELECT Ename, Job_type, Hire_date, Eno
FROM EMPLOYEE
ORDER BY Eno;

-- 2 
SELECT DISTINCT Job_type
FROM EMPLOYEE;

-- 3
SELECT CONCAT(Ename, "," , Job_type) AS Query3
FROM EMPLOYEE;

-- 4
SELECT CONCAT
	(Eno, ",",
	 Ename, ",",
	 Job_type, ",",
	 SupervisionENO, ",",
	 Hire_date, ",",
	 Dno, ",",
	 Commission, ",",
	 Salary) AS THE_OUTPUT
FROM EMPLOYEE;

-- 5
SELECT Ename, Salary
FROM EMPLOYEE
WHERE Salary > 2850;

-- 6
SELECT Ename, Dno
FROM EMPLOYEE
WHERE Eno = 79;

-- 7
SELECT Ename, Salary
FROM EMPLOYEE
WHERE Salary < 1500 OR Salary > 2850;

-- 8
SELECT Ename, Dno
FROM EMPLOYEE
WHERE Dno = 10 OR Dno = 30
ORDER BY Ename;

-- 9
SELECT Ename, Hire_date
FROM EMPLOYEE
WHERE Hire_date LIKE '1981-__-__';

-- 10
SELECT Ename, Job_type
FROM EMPLOYEE
WHERE SupervisionENO IS NULL;

-- 11
SELECT Ename, Salary, Commission
FROM EMPLOYEE
WHERE Commission > 0.0;

-- 12
SELECT *
FROM EMPLOYEE
ORDER BY Salary DESC, Commission DESC;

-- 13
SELECT Ename
FROM EMPLOYEE
WHERE Ename LIKE '__A%';

-- 14
SELECT Ename
FROM EMPLOYEE
WHERE (Ename LIKE '%R%R%' OR Ename LIKE '%A%A%') AND
	   Dno = 30 OR SupervisionENO = '7788';

-- 15
SELECT Ename, Salary, Commission
FROM EMPLOYEE
WHERE Commission > (1.05*Salary);

-- 16
SELECT CURDATE(), DAYNAME(CURDATE()) AS DAYNAME;

-- 17
SELECT Ename, Hire_date, 
	   DATE_ADD(DATE_ADD(Hire_date, INTERVAL 6 MONTH),
				INTERVAL 8-WEEKDAY(DATE_ADD(Hire_date, INTERVAL 6 MONTH)) DAY)
				AS Salary_review_date
FROM EMPLOYEE;
	 
-- 18
SELECT Ename, 12*(YEAR(CURDATE())-YEAR(Hire_date))
				+(MONTH(CURDATE())-MONTH(Hire_date)) AS MONTHS
FROM EMPLOYEE
WHERE Dno IN (
	SELECT Dno 
	FROM DEPARTMENT 
	WHERE Dname = 'Purchase'
);

-- 19
SELECT CONCAT(Ename, ' earns ', Salary, ' monthly but wants ', 3*Salary)
		AS Dream_Salary
FROM EMPLOYEE;

-- 20
SELECT CONCAT(UCASE(SUBSTRING(Ename, 1, 1)), 
			  LCASE(SUBSTRING(Ename, 2, LENGTH(Ename)-1))) AS Name,
		LENGTH(Ename) AS LengthOfName
FROM EMPLOYEE
WHERE Ename RLIKE '^[JAM]';

-- 21
SELECT Ename, Hire_date, DAYNAME(Hire_date) AS Day
FROM EMPLOYEE;

-- 22
SELECT E.Ename, D.Dname, E.Dno
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE D.Dno = E.Dno;

-- 23
SELECT DISTINCT Job_type
FROM EMPLOYEE
WHERE Dno = 30;

-- 24
SELECT E.Ename, D.Dname
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE D.Dno = E.Dno AND E.Ename LIKE '%A%';

-- 25
SELECT E.Ename, E.Job_type, E.Dno, D.Dname
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE E.Dno = D.Dno AND D.Location = 'Dallas';

-- 26
SELECT A.Ename, A.Eno, B.Ename, A.SupervisionENO
FROM EMPLOYEE AS A, EMPLOYEE AS B
WHERE A.SupervisionENO = B.Eno;

-- 27
SELECT A.Ename, A.Dno, A.Salary
FROM EMPLOYEE AS A, EMPLOYEE AS B
WHERE A.Dno = B.Dno AND A.Salary = B.Salary AND 
		B.Commission > 0.0;

-- 28
SELECT Ename, REPEAT('*', (Salary/100)) AS Salary
FROM EMPLOYEE;

-- 29
SELECT MAX(Salary) AS Maximum, MIN(Salary) AS Minimum,
		AVG(Salary) AS Average
From EMPLOYEE;

-- 30
SELECT Job_type,COUNT(*) 
FROM EMPLOYEE 
GROUP BY Job_type;

-- 31
SELECT COUNT(DISTINCT SupervisionENO) AS SUPERVISORS
FROM EMPLOYEE;

-- 32
SELECT D.Dname, D.Location, COUNT(*), AVG(E.Salary)
FROM DEPARTMENT AS D, EMPLOYEE AS E
WHERE E.Dno = D.Dno
GROUP BY D.Dno;

-- 33
SELECT Ename, Hire_date
FROM EMPLOYEE
WHERE Dno IN (
	SELECT Dno FROM EMPLOYEE WHERE Ename = 'Blake');

-- 34
SELECT Eno, Ename
FROM EMPLOYEE
WHERE Salary > (SELECT AVG(Salary) FROM EMPLOYEE);

-- 35
SELECT Eno, Ename
FROM EMPLOYEE 
WHERE Dno IN (
	SELECT Dno FROM EMPLOYEE WHERE Ename LIKE '%T%');

-- 36
SELECT Ename, Salary
FROM EMPLOYEE
WHERE SupervisionENO = (
	SELECT Eno FROM EMPLOYEE WHERE Ename = 'King');

-- 37
SELECT  D.Dno, D.Dname, E.Job_type
FROM DEPARTMENT AS D, EMPLOYEE AS E
WHERE E.Dno = D.Dno AND D.Dname = 'Sales';

-- 38
SELECT E.Ename, D.Dname
FROM EMPLOYEE AS E, DEPARTMENT AS D
WHERE E.Dno = D.Dno AND YEAR(CURDATE())-YEAR(E.Hire_date) > 20;

-- 39
SELECT Location, COUNT(*)
FROM DEPARTMENT
GROUP BY(Location);

-- 40
SELECT T.Dname
FROM (
	SELECT D.Dname, COUNT(*) AS count_emp
	FROM EMPLOYEE AS E, DEPARTMENT AS D
	WHERE E.Dno = D.Dno
	GROUP BY D.Dno) as T
WHERE T.count_emp > 20;

-- 41
SELECT Ename
FROM EMPLOYEE
WHERE Eno NOT IN 
	( SELECT DISTINCT SupervisionENO FROM EMPLOYEE )
UNION
SELECT Ename
FROM EMPLOYEE
WHERE Eno IN
	(SELECT T.SupervisionENO 
	FROM (SELECT SupervisionENO, COUNT(*) AS spv_cnt
		  FROM EMPLOYEE
	 	  GROUP BY SupervisionENO) AS T
	WHERE T.spv_cnt > 5);

-- 42
SELECT Job_type AS Job_type_min_employee
FROM EMPLOYEE
GROUP BY Job_type
ORDER BY COUNT(*)
LIMIT 1;

SELECT Job_type AS Job_type_max_employee
FROM EMPLOYEE
GROUP BY Job_type
ORDER BY COUNT(*) DESC
LIMIT 1;
