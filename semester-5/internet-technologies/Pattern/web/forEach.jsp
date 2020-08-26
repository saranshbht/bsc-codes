<%-- 
    Document   : forEach
    Created on : 17 Oct, 2019, 3:44:10 PM
    Author     : c3
--%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib uri = "http://java.sun.com/jsp/jstl/core" prefix = "c" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Pattern Using forEach</title>
    </head>
    <body>
        <form method="post">
            Enter a number: <input type="number" min="1" name="n" required><br>
            <input type="submit" value="Submit">
        </form>
        <c:forEach var="i" begin="1" end="${param.n}">
            <c:forEach var="j" begin="1" end="${i}">
                <c:out value="${j}"/>&nbsp;&nbsp;
            </c:forEach>
            <br>
        </c:forEach>
    </body>
</html>
