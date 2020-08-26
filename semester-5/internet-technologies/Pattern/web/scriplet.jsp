<%-- 
    Document   : index
    Created on : 17 Oct, 2019, 3:39:27 PM
    Author     : c3
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Pattern Using Scriplet Tag</title>
    </head>
    <body>
        <form method="post">
            Enter a number: <input type="number" min="1" name="n" required><br>
            <input type="submit" value="Submit">
        </form>
        <%
            if(request.getParameter("n") != null){
                int n = Integer.parseInt(request.getParameter("n"));
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= i; j++){
                    out.print(j+"&nbsp;&nbsp;");
                    }
                    out.println("<br>");
                }
            }
        %>
    </body>
</html>
