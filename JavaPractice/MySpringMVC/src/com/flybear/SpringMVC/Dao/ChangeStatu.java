package com.flybear.SpringMVC.Dao;


import org.springframework.stereotype.Repository;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

@Repository
public class ChangeStatu {
    private Connection con; //声明Connection对象
    private String driver = "com.mysql.jdbc.Driver";//驱动程序名
    private String url = "jdbc:mysql://localhost:3306/lxdjb?useUnicode=true&characterEncoding=utf8";//URL指向要访问的数据库名mydata
    private String user1 = "root";
    private String password = "hyggbgb";//MySQL配置时的密码

    public String open(){
        String result="";
        String sql="update admin set statu=1";
        try {
            //加载驱动程序
            Class.forName(driver);
            //1.getConnection()方法，连接MySQL数据库！！
            con = DriverManager.getConnection(url, user1, password);
            if (!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            //2.创建statement类对象，用来执行SQL语句！！

            Statement statement = con.createStatement();


            int a =statement.executeUpdate(sql);
            result=(a>0)?"打开成功！":"打开失败！";

            statement.close();
            con.close();
        }catch (ClassNotFoundException e) {
            System.out.println("Sorry,can`t find the Driver!");
            e.printStackTrace();
        } catch (SQLException e) {
            //数据库连接失败异常处理
            e.printStackTrace();
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }

        return result;
    }

    public String close(){
        String result="";
        String sql="update admin set statu=0";
        try {
            //加载驱动程序
            Class.forName(driver);
            //1.getConnection()方法，连接MySQL数据库！！
            con = DriverManager.getConnection(url, user1, password);
            if (!con.isClosed())
                System.out.println("Succeeded connecting to the Database!");
            //2.创建statement类对象，用来执行SQL语句！！

            Statement statement = con.createStatement();


            int a =statement.executeUpdate(sql);
            result=(a>0)?"关闭成功！":"关闭失败！";

            statement.close();
            con.close();
        }catch (ClassNotFoundException e) {
            System.out.println("Sorry,can`t find the Driver!");
            e.printStackTrace();
        } catch (SQLException e) {
            //数据库连接失败异常处理
            e.printStackTrace();
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }

        return result;
    }


}
