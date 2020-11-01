package ie.ucd.sse.tutorial1.servlet;

import java.io.IOException;



import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(urlPatterns = { "/feedback" })
public class FeedbackServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
    public FeedbackServlet() {
        super();
    }
 
    // Show Feedback page.
    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
 
        // Forward to /WEB-INF/views/feedbackView.jsp
        // (Users can not access directly into JSP pages placed in WEB-INF)
        RequestDispatcher dispatcher //
                = this.getServletContext().getRequestDispatcher("/WEB-INF/views/feedbackView.jsp");
 
        dispatcher.forward(request, response);
 
    }
 
    // When the user enters feedback, and click Submit.
    // This method will be executed.
    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String feedback = request.getParameter("feedbackText");
        String feedbackFile = request.getParameter("feedbackFile");
        Process process =null;
        String[] cmd = {"","","echo \""+feedback+"\" >> "+feedbackFile};
        
       // if it is a windows platform
        boolean isWindows = System.getProperty("os.name")
        		  .toLowerCase().startsWith("windows");
        if(isWindows) {
        	 cmd[0] ="cmd.exe";
        	 cmd[1] ="/c";
        } else {
        	cmd[0] = "/bin/sh";
       	 	cmd[1] = "-c";
        }
        
        process = Runtime.getRuntime().exec(cmd);
        System.out.println(cmd[0] + " "+cmd[1]+" "+cmd[2]);
        
        int exitVal = 0;
		try {
			exitVal = process.waitFor();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
       
        if(exitVal ==0)
        	response.sendRedirect(request.getContextPath() + "/home");
	} 
         
    
 
}