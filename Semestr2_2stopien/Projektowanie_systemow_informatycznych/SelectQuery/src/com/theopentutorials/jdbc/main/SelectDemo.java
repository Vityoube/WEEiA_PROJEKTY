package com.theopentutorials.jdbc.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLException;
import java.text.SimpleDateFormat;

import com.theopentutorials.jdbc.dao.EmployeeDAO;
import com.theopentutorials.jdbc.to.Employee;

public class SelectDemo {
	public static void main(String[] args) {
		// 1. Get Employee
		getEmployee();
	}

	private static void getEmployee() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the EmployeeID:");
		try {
			int employeeId = Integer.parseInt(br.readLine());
			EmployeeDAO empDao = new EmployeeDAO();
			Employee employee = empDao.getEmployee(employeeId);
			if (employee != null)
				displayEmployee(employee);
			else
				System.out.println("No Employee with Id: " + employeeId);
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	private static void displayEmployee(Employee employee) {
		System.out.println("Employee ID:" + employee.getEmpId());
		System.out.println("Employee Name:" + employee.getEmpName());
		SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");
		String dob = format.format(employee.getDob());
		System.out.println("DOB:" + dob);
		System.out.println("Salary:" + employee.getSalary());
		System.out.println("Department ID:" + employee.getDeptId());
		System.out.println();
	}
}
