<%@taglib uri="http://java.sun.com/jsp/jstl/sql" prefix="sql"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	start
	<sql:setDataSource var="db1" driver="oracle.jdbc.OracleDriver"
		url="jdbc:oracle:thin:@212.51.216.168:1521:hw64" user="scott"
		password="tiger" />
	<c:set var="select1"
		value="select ename, sal, empno from emp order by 1" />
	<c:out value="${select1}" />
	<br>
	<sql:query var="query1" dataSource="${db1}" sql="${select1}"
		startRow="0" maxRows="15" />

	<table border="1">
		<tr>
			<th>Nazwisko</th>
			<th>Pensja</th>
			<th>Numer</th>
			<th>Kasuj</th>
		</tr>
		<c:forEach var="row" items="${query1.rows}">
			<tr>
				<td><c:out value="${row.ename}" /></td>
				<td><c:out value="${row.sal}" /></td>
				<td><c:out value="${row.empno}" /></td>
				<td><a href="kasuj.jsp?x=${row.empno}">kasuj</a></td>
			</tr>
		</c:forEach>
	</table>
	stop
</body>
</html>