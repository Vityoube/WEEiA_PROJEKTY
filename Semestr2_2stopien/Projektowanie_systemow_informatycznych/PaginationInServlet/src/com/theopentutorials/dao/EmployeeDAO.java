package com.theopentutorials.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.theopentutorials.db.ConnectionFactory;
import com.theopentutorials.to.Employee;

public class EmployeeDAO {
	Connection connection;
	Statement smt;
	private int noOfRecords;
	
	public EmployeeDAO(){
		
	}
	
	private static Connection getConnection() throws SQLException{
		Connection con = ConnectionFactory.getInstance().getConnection();
		return con;
	}
	
	public List<Employee> viewAllEmployees(int offset, int noOfRecords){
		String query ="select SQL_CALC_FOUND_ROWS * from employee limit "+offset+", "+noOfRecords;
		List<Employee> list = new ArrayList<Employee>();
		Employee employee = null;
		try{ 
			connection =getConnection();
			smt =connection.createStatement();
			ResultSet rs =smt.executeQuery(query);
			while(rs.next()){
				employee=new Employee();
				employee.setEmployeeId(rs.getInt("emp_id"));
				employee.setEmployeeName(rs.getString("emp_name"));
				employee.setSalary(rs.getDouble("salary"));
				employee.setDeptName(rs.getString("dept_name"));
				list.add(employee);
			}
			rs.close();
			
			rs=smt.executeQuery("SELECT FOUND_ROWS();");
			if (rs.next())
				this.noOfRecords=rs.getInt(1);
		} catch(SQLException e){
			e.printStackTrace();
		} finally{
			try{
			if (smt!=null)
				smt.close();
			if (connection!=null)
				connection.close();
			} catch(SQLException e){
				e.printStackTrace();
			}
			
		}
		return list;
	}
	
	public int getNoOfRecords(){
		return noOfRecords;
	}
}