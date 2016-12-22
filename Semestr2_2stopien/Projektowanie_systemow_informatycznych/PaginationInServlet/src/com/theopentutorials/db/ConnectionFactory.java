package com.theopentutorials.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionFactory {

	private static ConnectionFactory instance =new ConnectionFactory();
	String url ="jdbc:mysql://localhost/employee_example?autoReconnect=true&useSSL=false";
	String user="root";
	String password="WmGkywJA";
	String driverClass="com.mysql.jdbc.Driver";
	
	private ConnectionFactory(){
		try{
			Class.forName(driverClass);
		} catch(ClassNotFoundException e){
			e.printStackTrace();
		}
	}
	
	public static ConnectionFactory getInstance(){
		return instance;
	}
	
	public Connection getConnection() throws SQLException{
		Connection connection =DriverManager.getConnection(url,user,password);
		return connection;
	}
}
