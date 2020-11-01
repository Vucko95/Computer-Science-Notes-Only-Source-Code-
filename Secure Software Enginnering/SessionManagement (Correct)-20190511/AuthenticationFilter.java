package ie.ucd.servlets;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


public class AuthenticationFilter implements Filter {

    private ServletContext context;
    

    public void init(FilterConfig fConfig) throws ServletException {
        this.context = fConfig.getServletContext();
        this.context.log("AuthenticationFilter initialized");
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {

        HttpServletRequest req = (HttpServletRequest) request;
        HttpServletResponse res = (HttpServletResponse) response;

        HttpSession session = req.getSession(false);
        
        String path = req.getRequestURI();
        if(path.endsWith("login.html") || session !=null ||req.getServletPath().equals("/LoginServlet"))
        	// pass the request along the filter chain
            chain.doFilter(request, response);
        else {
        	if (session == null ) {   //checking whether the session exists
        		this.context.log("Unauthorized access request");
        		res.sendRedirect("login.html");
        	} 
        }
    }

    public void destroy() {
        //close any resources here
    }
}