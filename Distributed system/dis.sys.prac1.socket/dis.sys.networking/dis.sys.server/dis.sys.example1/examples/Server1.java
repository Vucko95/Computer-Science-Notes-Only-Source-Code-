package examples;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server1 {
	public static void main(String[] args) {
		try {// server based system 
			ServerSocket serverSocket = new ServerSocket(80); // socket new based system  // comunication server 
			Socket socket = serverSocket.accept(); // acepting the state of the socket // provides a load of methods. like scanner 
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())); // read and write method 
			PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
			String message = in.readLine();
			out.println(message);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
