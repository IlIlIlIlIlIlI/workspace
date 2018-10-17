<%--
  Created by IntelliJ IDEA.
  User: Innovation
  Date: 2018/3/3
  Time: 14:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="org.json.JSONObject" %>
<%@ page import="org.json.JSONArray" %>
<%@ page import="java.util.Iterator" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>get data</title>
</head>
<body>
<%
    String pageNum = request.getParameter("page");
    JSONArray jsonArray = com.bovink.example.GetCity.getCityArray(Integer.parseInt(pageNum));
%>
<table border="1">
    <tr>
        <td>country_code</td>
        <td>district</td>
        <td>name</td>
        <td>id</td>
        <td>population</td>
    </tr>
    <%
        for (int i = 0; i < jsonArray.length(); i++) {
    %>
    <tr>
        <%
            JSONObject jsonObject = jsonArray.getJSONObject(i);
            Iterator iterator = jsonObject.keys();
            while (iterator.hasNext()) {
        %>
        <td>
            <%
                System.out.print(jsonObject.getString(iterator.next().toString()));
            %>
        </td>
        <%
            }
        %>
    </tr>
    <%
        }
    %>
</table>
// action表示这个表单指向的JSP，当点击sumbit后，自动打开网页。
// 请求参数为表单中的标签值。
<form action="query.jsp">
    <input type="hidden" id="pageNum" name="page" value="<%
    System.out.println(pageNum);
    %>"/>
    <input type="submit" value="下一页" onclick="clickBtn()">
    <script>
        var page = document.getElementById("pageNum");
        // 点击submit时响应方法
        function clickBtn() {
            page.value = parseInt(page.value, 10) + 1 + "";
        }
    </script>
</form>
</body>
</html>