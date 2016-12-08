<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<jsp:scriptlet>
	Object dane = request.getAttribute("dane");
				if (dane != null){
				dane = dane.toString();
				}else {
					dane = "brak danych";
				}
	</jsp:scriptlet>
	
	<jsp:expression>
	dane
	</jsp:expression>
	
	<jsp:expression>
	request.getAttribute("dane").toString()
	</jsp:expression>
</body>
</html>