<%-- 
    Document   : operateEL
    Created on : 18 Oct, 2019, 11:11:41 AM
    Author     : c3
--%>
<%@ taglib uri = "http://java.sun.com/jsp/jstl/core" prefix = "c" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Operation Result</title>
    </head>
    <body>
        <%--<c:if test="${param.operation == 'add'}">
            Result: ${param.first + param.second}
        </c:if>
        <c:if test="${param.operation == 'sub'}">
            Result: ${param.first - param.second}
        </c:if>
        <c:if test="${param.operation == 'mul'}">
            Result: ${param.first * param.second}
        </c:if>--%>
        <c:choose>
            <c:when test="${!empty param.first && !empty param.second && param.operation == 'add'}">
                Result: ${param.first + param.second}
            </c:when>
            <c:when test="${!empty param.first && !empty param.second && param.operation == 'sub'}">
                Result: ${param.first - param.second}
            </c:when>
            <c:when test="${!empty param.first && !empty param.second && param.operation == 'mul'}">
                Result: ${param.first * param.second}
            </c:when>
            <c:otherwise>
                Enter all values
            </c:otherwise>
        </c:choose>
    </body>
</html>
