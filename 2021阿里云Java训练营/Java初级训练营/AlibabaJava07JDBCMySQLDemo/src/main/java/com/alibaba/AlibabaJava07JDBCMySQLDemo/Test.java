package com.alibaba.AlibabaJava07JDBCMySQLDemo;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Connection;
import java.sql.SQLException;

public class Test{

 public static void main(String[] args) throws ClassNotFoundException, SQLException {
  System.out.println("Hello World!");

  // 1.加载驱动 JSP连接MySQL
  Class.forName("com.mysql.jdbc.Driver");
  // 2.连接数据
  String url = "jdbc:mysql://localhost:3306/taobao?useUnicode=true&characterEncoding=utf-8&useSSL=false";
  String username = "root";
  String password = "990312";
  Connection con = DriverManager.getConnection(url, username, password);
  // 3.SQL命令
  String sql = "select * from users order by Id";
  java.sql.Statement statement = con.createStatement();
  // 4.执行SQL命令
  ResultSet result = statement.executeQuery(sql);
  // 5.结果处理
  while (result.next()) {
   String id = result.getString("id");
   String name = result.getString("name");
   String psw = result.getString("password");
   System.out.println(id+" : "+ name + " : " + psw);
  }
  // 6.结束运行
  result.close();
  statement.close();
  con.close();
 }

}