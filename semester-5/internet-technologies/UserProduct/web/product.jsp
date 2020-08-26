<%-- 
    Document   : product
    Created on : 8 Nov, 2019, 10:41:59 AM
    Author     : c3
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib uri = "http://java.sun.com/jsp/jstl/core" prefix = "c" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <c:set var="name" value="${param.name}" scope="session" />
        Hello ${name}
        <form method="post" action="display.jsp">
            Enter the products you would like to buy<br>    
            <input type="text" name="product" required><br>
            <input type="submit" value="Submit">
        </form>
    </body>
</html>
