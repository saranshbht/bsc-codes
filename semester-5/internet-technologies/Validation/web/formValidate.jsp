<%-- 
    Document   : formValidate
    Created on : 18 Oct, 2019, 12:11:31 PM
    Author     : c3
--%>
<%@ taglib uri = "http://java.sun.com/jsp/jstl/core" prefix = "c" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Validation</title>
    </head>
    <body>
        Enter your details<br>
        <form method="post">
            <input type="hidden" name="submitted" value="true">
                Name<br><input type="text" name="name"><br>
            <c:if test="${param.submitted && empty param.name}">
                <span style="color: red">Please enter your Name</span><br>
            </c:if>
                DOB<br><input type="date" name="dob"><br>
            <c:if test="${param.submitted && empty param.dob}">
                <span style="color: red">Please enter your DOB</span><br>
            </c:if>
                Email ID<br><input type="email" name="email"><br>
            <c:if test="${param.submitted && empty param.email}">
                <span style="color: red">Please enter your Email</span><br>
            </c:if>
                Lucky Number<br><input type="number" name="luckyNum"><br>
            <c:if test="${param.submitted && empty param.luckyNum}">
                <span style="color: red">Please enter your Lucky Number</span><br>
            </c:if>
                Favourite Food<br><input type="text" name="favFood"><br>
            <c:if test="${param.submitted && empty param.favFood}">
                <span style="color: red">Please enter your Favourite Food</span><br>
            </c:if>
                <input type="submit" value="Submit">
            <c:if test="${param.submitted && !empty param.name && !empty param.dob && !empty param.email && !empty param.luckyNum && !empty param.favFood}">
                <br><br>Entered Values<br>
                Name: ${param.name}<br>
                DOB: ${param.dob}<br>
                Email ID: ${param.email}<br>
                Lucky Number: ${param.luckyNum}<br>
                Favourite Food: ${param.favFood}<br>
            </c:if>
    </body>
</html>
