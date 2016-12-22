package com.mutiplevalues;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class MutipleValuesSingleParamServlet
 */
@WebServlet("/multiplevalues.do")
public class MutipleValuesSingleParamServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String[] favorieFruits =request.getParameterValues("favoriteFruit");
		
		PrintWriter out = response.getWriter();
		response.setContentType("text/html");
		out.print("<html><body>");
		out.print("<h1>Your Favorite Fruits are</h1>");
		out.print("<ul>");
		for (String fruit: 	favorieFruits){
			out.print("<li>"+fruit+"</li>");
		}
		out.print("<ul>");
		out.print("</body></html>");
	}

}
