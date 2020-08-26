<%-- 
    Document   : index
    Created on : 7 Nov, 2019, 1:53:56 PM
    Author     : c3
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix = "fn" uri = "http://java.sun.com/jsp/jstl/functions" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Odd Even Game</title>
    </head>
    <body>
        <form method="post">
             <input type="hidden" name="submitted" value="true">
            Enter a word: <input type="text" name="n" method="post" required><br>
            <input type="radio" name="selection" value="odd" required>Odd<br>
            <input type="radio" name="selection" value="even">Even<br>
            <input type="submit" value="Submit">
        </form>
        <c:if test="${param.submitted}">
            <c:set var="len" value="${fn:length(param.n)}" />
            <c:set var="vowels" value="aeiou" />
            <c:set var="flag" value="true" />
            <c:choose>
                <c:when test="${param.selection == 'odd'}">
                    <c:forEach var="i" begin="0" end="${len - 1}" step="2">
                        <c:if test="${not fn:contains(vowels, param.n.charAt(i))}">
                            <c:set var="flag" value="false" />
                        </c:if>
                    </c:forEach>
                    <c:if test="${flag}">
                        You win
                    </c:if>
                    <c:if test="${not flag}">
                        You lose
                    </c:if>
                </c:when>
                <c:otherwise>
                    <c:forEach var="i" begin="1" end="${len - 1}" step="2">
                        <c:if test="${not fn:contains(vowels, param.n.charAt(i))}">
                            <c:set var="flag" value="false" />
                        </c:if>
                    </c:forEach>
                    <c:if test="${flag}">
                        You win
                    </c:if>
                    <c:if test="${not flag}">
                        You lose
                    </c:if>
                </c:otherwise>
            </c:choose>
        </c:if>
    </body>
</html>
