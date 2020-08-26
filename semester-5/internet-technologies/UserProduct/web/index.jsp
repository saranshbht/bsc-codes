<%-- 
    Document   : index
    Created on : 8 Nov, 2019, 10:38:27 AM
    Author     : c3
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>User Product</title>
    </head>
    <body>
        <form method="post" action="product.jsp">
            Enter your name: <input name="name" type="text" required><br>
            Enter your age: <input type="number" name="age" required><br>
            <input type="submit" value="Submit">
        </form>
    </body>
</html>
