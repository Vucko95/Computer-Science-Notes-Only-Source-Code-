package ie.ucd.sse.tutorial1.servlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import ie.ucd.sse.tutorial1.beans.Product;
import ie.ucd.sse.tutorial1.beans.UserAccount;
import ie.ucd.sse.tutorial1.dbconn.DBUtils;
import ie.ucd.sse.tutorial1.utils.SessionUtils;



@WebServlet(urlPatterns = { "/searchProduct" })
public class ProductSearchServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
    public ProductSearchServlet() {
        super();
    }
 
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    	 // Forward to /WEB-INF/views/loginView.jsp
        // (Users can not access directly into JSP pages placed in WEB-INF)
        RequestDispatcher dispatcher //
                = this.getServletContext().getRequestDispatcher("/WEB-INF/views/searchProductView.jsp");
 
        dispatcher.forward(request, response);
    }
 
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    	 String code = request.getParameter("name");
        
         List<Product> products = null;
         boolean hasError = false;
         String errorString = null;
  
         if (code == null || code.length() ==0 ) {
             hasError = true;
             errorString = "Required code!";
         } else {
             Connection conn = SessionUtils.getStoredConnection(request);
             try {
                 // Find the user in the DB.
                 products = DBUtils.queryProducts(conn, code);
  
                 if (products == null) {
                     hasError = true;
                     errorString = "Name  invalid";
                 }
             } catch (SQLException e) {
                 e.printStackTrace();
                 hasError = true;
                 errorString = e.getMessage();
             }
         }
         // If error, forward to /WEB-INF/views/login.jsp
         if (hasError) {
             
  
             // Store information in request attribute, before forward.
             request.setAttribute("errorString", errorString);
             
  
             // Forward to /WEB-INF/views/login.jsp
             RequestDispatcher dispatcher //
                     = this.getServletContext().getRequestDispatcher("/WEB-INF/views/searchProductView.jsp");
  
             dispatcher.forward(request, response);
         }
         // If no error
         // Store user information in Session
         // And redirect to userInfo page.
         else {
             
        	// Store info in request attribute, before forward to views
             request.setAttribute("errorString", errorString);
             request.setAttribute("productList", products);
              
             // Forward to /WEB-INF/views/productListView.jsp
             RequestDispatcher dispatcher = request.getServletContext()
                     .getRequestDispatcher("/WEB-INF/views/productListView.jsp");
             dispatcher.forward(request, response);
         }
    }
 
}