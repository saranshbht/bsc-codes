<%-- 
    Document   : index
    Created on : 7 Nov, 2019, 3:06:51 PM
    Author     : c3
--%>
<%@taglib uri="/WEB-INF/tlds/tagLibrary" prefix="h" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Custom Tags</title>
    </head>
    <body>
        <h:hw />
        <h:hello name="Saransh" /><br>
        <h:choco texture="Chewy" /><br>
        <h:choco texture="Crunchy" /><br>
        <h:substring input="hello World" start="1" end="7" /><br>
        <h:reverse input="hello World" /><br>
        <h:today />
    </body>
</html>
