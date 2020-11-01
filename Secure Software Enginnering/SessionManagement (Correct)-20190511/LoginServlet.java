
package ie.ucd.servlets;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.codec.digest.DigestUtils;

/**
 * Servlet implementation class LoginServlet
 */
@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private final String userID = "admin";
	//no longer using a password in clear
	private final String hashedPassword = "5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8";

	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {

		// get request parameters for userID and password
		String user = request.getParameter("user");
		String pwd = request.getParameter("pwd");

		System.out.println(DigestUtils.sha1Hex(pwd));
		System.out.println(hashedPassword);
		
		if(userID.equals(user) && DigestUtils.sha1Hex(pwd).equals(hashedPassword)){
			//get the old session and invalidate
            HttpSession oldSession = request.getSession(false);
            if (oldSession != null) {
                oldSession.invalidate();
            }
            //generate a new session
            HttpSession newSession = request.getSession(true);

			
			newSession.setAttribute("user", userID);
			
			//setting session to expiry in 30 mins
			newSession.setMaxInactiveInterval(30*60);
			
			Cookie userName = new Cookie("user", user);
			
			
			userName.setMaxAge(30*60);
			response.addCookie(userName);
			response.sendRedirect("LoginSuccess.jsp");
		}else{
			RequestDispatcher rd = getServletContext().getRequestDispatcher("/login.html");
			PrintWriter out= response.getWriter();
			out.println("<font color=red>Either user name or password is wrong.</font>");
			rd.include(request, response);
		}

	}

}
