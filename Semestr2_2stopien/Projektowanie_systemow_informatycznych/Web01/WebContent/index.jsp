<%@page import="java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<B>Adrian Jędrzejczak Łódź</B>
<HR>
<%  
String x;
x = new Date().toString();
//out.println("Dzisiaj mamy: "+x);
%>
<HR>
<%= "Dzisiaj mamy: "+x %>
<%-- 
<%out.println(x); %>
 --%>
 <HR>
 
 <jsp:scriptlet>
 String y;
 y = new Date().toString();
 out.println("Dzisiaj mamy: "+x);
 </jsp:scriptlet>
 <HR>
  <jsp:expression>
 x
 </jsp:expression>
 <HR>
 <%=new Date().toString()%>
 <HR>  Nasza zmienna =
 <%= request.getParameter("name") %>
 

</body>
</html>