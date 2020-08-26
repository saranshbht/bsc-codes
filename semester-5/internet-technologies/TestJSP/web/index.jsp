<%-- 
    Document   : index
    Created on : 20 Oct, 2019, 12:07:12 PM
    Author     : saransh
--%>

<%@page import="java.text.SimpleDateFormat"%>
<%@page import="java.util.Calendar"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Using JSTL Functions</title>
    </head>
    <body>
    <c:set var="string1" value="This is first String." />
    <c:set var="string2" value="This <b>is second String.</b>" />
    <p>With escapeXml() Function:</p>
    <p>string(1):${fn:escapeXml(string1)}</p>
    <p>string(2):${fn:escapeXml(string2)}</p>
    <p>Without escapeXml() Function:</p>
    <p>string(1):${string1}</p>
    <p>string(2):${string2}</p>
    <%=addDays("2019-11-10", 25)%>
    <%!  
        String addDays(String s, int days) throws Exception{
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
            Calendar c = Calendar.getInstance();
            c.setTime(sdf.parse(s));
            c.add(Calendar.DATE, days);  // number of days to add
            s = sdf.format(c.getTime());
            return s;
    }
    %>
    </body>
</html>
