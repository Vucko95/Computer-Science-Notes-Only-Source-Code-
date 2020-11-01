<%@ page language="java" contentType="text/html; charset=UTF-8"
   pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
   <head>
      <meta charset="UTF-8">
      <title>Search</title>
   </head>
   <body>
      <jsp:include page="_header.jsp"></jsp:include>
      <jsp:include page="_menu.jsp"></jsp:include>
 
      <h3>Search Product Page</h3>
      <p style="color: red;">${errorString}</p>
 
 
      <form method="POST" action="${pageContext.request.contextPath}/searchProduct">
         <table border="1">
            <tr>
               <td>Product Code</td>
               <td><input type="text" name="name" value= "${product.name}" /> </td>
            </tr>
           
            <tr>
               <td colspan ="2">
                  <input type="submit" value= "Search" />
                  <a href="${pageContext.request.contextPath}/">Cancel</a>
               </td>
            </tr>
         </table>
      </form>
 
      
      <jsp:include page="_footer.jsp"></jsp:include>
   </body>
</html>