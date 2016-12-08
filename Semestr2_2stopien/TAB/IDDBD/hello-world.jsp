<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Hello World</title>
</head>
<body>
<%-- Dane takie jak w formularzu --%>
<%
	String person = "?";
	String user = request.getParameter("user");
	if (user != null)
		person = user;
%>
Witamy na zajęciach, <%=person%>!

<BR>
<%-- Dane zmienione w stosunku do formularza --%>
<%
String dane = "";
Object dane1 = request.getAttribute("login");
if (dane1 != null)
	dane = dane1.toString();
%>
Witamy na zajęciach, <%=dane%>!

</body>
</html>