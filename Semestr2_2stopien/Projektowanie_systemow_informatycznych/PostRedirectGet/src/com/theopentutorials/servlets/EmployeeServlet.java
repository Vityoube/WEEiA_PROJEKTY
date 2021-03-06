package com.theopentutorials.servlets;

import java.io.IOException;
import java.util.List;

import javax.annotation.Resource;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.sql.DataSource;

import com.theopentutorials.dao.EmployeeDAO;
import com.theopentutorials.exception.ApplicationException;
import com.theopentutorials.to.Employee;

import jdk.nashorn.internal.ir.RuntimeNode.Request;

/**
 * Servlet implementation class EmployeeServlet
 */
@WebServlet("/employee.do")
public class EmployeeServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	@Resource(name = "jdbc/employeedb")
	DataSource ds;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public EmployeeServlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		RequestDispatcher view = request.getRequestDispatcher("displayEmployee.jsp");
		view.forward(request, response);
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		String empName = req.getParameter("employeeName");
		String deptName = req.getParameter("deptName");
		double salary = Double.parseDouble(req.getParameter("salary"));

		Employee employee = new Employee();
		employee.setEmployeeName(empName);
		employee.setDeptName(deptName);
		employee.setSalary(salary);

		EmployeeDAO empDAO = new EmployeeDAO(ds);
		
		int rows;
		int success =0;
		try{
			rows=empDAO.addEmployees(employee);
			if (rows>0)
				success=1;
		} catch(ApplicationException e){
			req.setAttribute("error", e.getMessage());
		}
		resp.sendRedirect("displayEmployee.do?s="+success);
		
	}

}
