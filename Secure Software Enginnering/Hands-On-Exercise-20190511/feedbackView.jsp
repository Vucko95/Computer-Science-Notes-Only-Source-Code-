<%@ page language="java" contentType="text/html; charset=UTF-8"
 pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
 <head>
    <meta charset="UTF-8">
    <title>Feedback</title>
 </head>
 <body>
 
    <jsp:include page="_header.jsp"></jsp:include>
    <jsp:include page="_menu.jsp"></jsp:include>
 
    <h3>Feedback Page</h3>
      
 
 
      <form method="POST" action="${pageContext.request.contextPath}/feedback">
         <table border="1">
            <tr>
               <td>Feedback</td>
               <td><input type="text" name="feedbackText" value= "${feedback.value}" /> </td>
               <td><input type="hidden" id="feedbackFile" name="feedbackFile" value="/Users/liliana1/feedback.txt" /></td>
            </tr>
            <tr>
               <td colspan ="2">
                  <input type="submit" value= "Submit" />
                  <a href="${pageContext.request.contextPath}/home">Cancel</a>
               </td>
            </tr>
         </table>
      </form>
 
    <jsp:include page="_footer.jsp"></jsp:include>
 
 </body>
</html>