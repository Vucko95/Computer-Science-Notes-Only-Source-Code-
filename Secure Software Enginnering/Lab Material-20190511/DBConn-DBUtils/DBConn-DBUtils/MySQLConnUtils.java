package ie.ucd.sse.tutorial1.dbconn;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MySQLConnUtils {
	
	public static Connection getMySQLConnection() throws ClassNotFoundException, SQLException{
		
		//Note change the connection parameters according to your configuration
		String hostName = "localhost";
		String dbName = "shop";
		String userName = "root";
		String password = "";
		return getMySQLConnection(hostName, dbName, userName, password);
	}
	
	private static Connection getMySQLConnection(String host, String db, String user, String pwd) throws SQLException, ClassNotFoundException {
		Class.forName("com.mysql.cj.jdbc.Driver");
		// URL Connection for MySQL:
	    // Example: 
	    // jdbc:mysql://localhost:3306/your_database_name
	    String connectionURL = "jdbc:mysql://" + host + ":3306/" + db;
	  
	    Connection conn = null;
		try {
			conn = DriverManager.getConnection(connectionURL, user, pwd);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	     return conn;
	}
	
	

}
