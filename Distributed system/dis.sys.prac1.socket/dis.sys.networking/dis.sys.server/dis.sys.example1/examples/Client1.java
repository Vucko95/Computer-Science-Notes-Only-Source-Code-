package examples;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

public class Client1 {
	public static void main(String[] args) {

		try {
			Socket mySocket = null;
			int i = 0;
			while (i < 20) {
				mySocket = new Socket("www.csmoodle.ucd.ie/", 80); // can be changed to local host 
				System.out.println("i= " + i);
				i++;
			}

			InputStream is = mySocket.getInputStream(); // input streamc
			OutputStream os = mySocket.getOutputStream();// loads of mehtods with java 
			BufferedReader in = new BufferedReader(new InputStreamReader(is)); // input streams
			PrintWriter out = new PrintWriter(os, true); // send a string to the server
			out.println("GET /index.html"); // Print out the response
			String line = null;
			while ((line = in.readLine()) != null) {
				System.out.println(line);
			}
			in.close();
			out.close();
			mySocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
// Eoins Version >>
// import java.util.stream.*;
// import java.io.IOException;
// import java.io.PrintWriter;
// import java.net.ServerSocket;
// import java.net.Socket;
// import java.io.*;
// public class Client1 {
//     public static void main(String[] args) {
//         try {
//             Socket mySocket = new Socket("www.csmoodle.ucd.ie", 80);
//             InputStream is = mySocket.getInputStream();
//             OutputStream os = mySocket.getOutputStream();
//             BufferedReader in = 
//                 new BufferedReader(new InputStreamReader(is));
//             PrintWriter out = new PrintWriter(os, true);
//             // send a string to the server
//             out.println("GET /index.html");
//             // Print out the response
//             String line = null;
//             while ((line = in.readLine()) != null) {
//                 System.out.println(line);
//             }
//             in.close(); out.close(); mySocket.close();
//         } catch (IOException e) { e.printStackTrace(); }
//     }
// }