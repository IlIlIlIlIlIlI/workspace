<%--
  Created by IntelliJ IDEA.
  User: Innovation
  Date: 2018/2/20
  Time: 14:37
  To change this template use File | Settings | File Templates.
  --%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import ="java.sql.* " %>
<html>
<head>
  <title>Blog Example</title>
  <style type="text/css">
    p {
      color: red;
    }
  </style>
</head>
<body>
<%




  //声明Connection对象
  Connection con;
  //驱动程序名
  String driver = "com.mysql.jdbc.Driver";
  //URL指向要访问的数据库名login
  String url = "jdbc:mysql://localhost:3306/test";
  //MySQL配置时的用户名
  String user = "root";
  //MySQL配置时的密码
  String password = "123456";
  //遍历查询结果集

  try {
  //加载驱动程序
  Class.forName(driver);
  //1.getConnection()方法，连接MySQL数据库！！
  con = DriverManager.getConnection(url, user, password);

  if (!con.isClosed())
  System.out.println("Succeeded connecting to the Database!");
  //2.创建statement类对象，用来执行SQL语句！！
  Statement statement = con.createStatement();
  //要执行的SQL语句
  String sql = "select * from FleetFamily";    //从建立的login数据库的login——message表单读取数据
  //3.ResultSet类，用来存放获取的结果集！！
  ResultSet rs = statement.executeQuery(sql);
  System.out.println("-----------------");
  System.out.println("执行结果如下所示:");
  System.out.println("-----------------");
  System.out.println("SocietyName"+ '\t'+ '\t' + "department"+'\t'+'\t'  + "member" +'\t' +'\t'+  "grade");
  System.out.println("-----------------");
  String SocietyName;
  String dapartment;
  String member;
  String grade;

  while (rs.next()) {
  //获取stuname这列数据
  SocietyName = rs.getString("SocietyName");
  //获取stuid这列数据
  dapartment = rs.getString("dapartment");
  //获取stuname这列数据
  member = rs.getString("member");
  //获取stuid这列数据
  grade = rs.getString("grade");
  //首先使用ISO-8859-1字符集将name解码为字节序列并将结果存储新的字节数组中。
  //然后使用GB2312字符集解码指定的字节数组。
  member = new String(member.getBytes("ISO-8859-1"), "gb2312");
  //输出结果
  System.out.println(SocietyName + "\t\t\t" + dapartment + "\t\t\t" + member + "\t\t" + grade);
  }
  rs.close();
  con.close();
  } catch (ClassNotFoundException e) {
  //数据库驱动类异常处理
  System.out.println("Sorry,can`t find the Driver!");
  e.printStackTrace();
  } catch (SQLException e) {
  //数据库连接失败异常处理
  e.printStackTrace();
  } catch (Exception e) {
  // TODO: handle exception
  e.printStackTrace();
  } finally {
  System.out.println("数据库数据成功获取！！");
  }


%>
</body>
</html>