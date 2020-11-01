package examples;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server2 {
	public static final int BACKLOG = 5;

	public static void main(String[] args) {
		new Server2(7788).listen();
	}

	private ServerSocket serverSocket;

	public Server2(int port) {
		try {
			serverSocket = new ServerSocket(7788, BACKLOG);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void listen() {
		while (true) {
			try {
				Socket socket = serverSocket.accept();
				BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
				String message = in.readLine();
				out.println(message);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
