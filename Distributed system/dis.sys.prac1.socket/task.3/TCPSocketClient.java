import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.Math.*;
import java.net.Socket;
import java.util.Random;

public class TCPSocketClient {
	public String my_serverHost;
	public int my_serverPort;
	public TCPSocketClient(String the_serverHost, int the_serverPort) {
		my_serverHost = the_serverHost;
		my_serverPort = the_serverPort;
	}

	public void sendMessage(String a_message) {
		try {
			Socket toServer = new Socket(my_serverHost, my_serverPort);
			InputStream inStream = toServer.getInputStream();
			InputStreamReader inStrRead = new InputStreamReader(inStream);
			BufferedReader buffRead = new BufferedReader(inStrRead);
			PrintWriter out = new PrintWriter(toServer.getOutputStream(), true);
			out.println(a_message);
			String mess = buffRead.readLine();
			System.out.println("From the server multiplication answer is : " + mess);
			out.close();
			toServer.close();
		} catch (IOException ioe) { ioe.printStackTrace(); } catch (SecurityException se) {
			se.printStackTrace();
		}
	}

	public static void main(String[] args) {
		String host = null;
		int port = 0;
		String message = null;
		if (args.length == 2) {
			host = args[0];
			for (int i = 0; i < 100; i++) {
				try {
					port = Integer.valueOf(args[1]);
				} catch (NumberFormatException nfe) {
					System.err.println("The value provided for the port is not an integer");
					nfe.printStackTrace();
				}
				int num1 = (int)(Math.random() * 100) + 1;
				int num2 = (int)(Math.random() * 100) + 1;
				String messagenum = Integer.toString(num1) + "/" + Integer.toString(num2);
				TCPSocketClient client = new TCPSocketClient(host, port);
				client.sendMessage(messagenum);
			}
		} else {
			System.out.println("Usage: java TCPSocketClient <host> <port> <message>");
		}
	}
}
