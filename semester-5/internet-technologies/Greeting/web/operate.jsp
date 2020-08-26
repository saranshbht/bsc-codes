<%-- 
    Document   : operate
    Created on : 18 Oct, 2019, 10:46:18 AM
    Author     : c3
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Operation Result</title>
    </head>
    <body>
        <% 
            if(request.getParameter("first").equals("") || request.getParameter("second").equals("") || request.getParameter("operation") == null)
                out.println("Enter all values");
            else{
                int first = Integer.parseInt(request.getParameter("first"));
                int second = Integer.parseInt(request.getParameter("second"));
                String operation = request.getParameter("operation");
                out.print("Result : ");
                if(operation.equals("add")){
                    out.print(first + second);
                }
                else if(operation.equals("sub")){
                    out.print(first - second);
                }
                else{
                    out.print(first * second);
                }
            }
        %>
    </body>
</html>
