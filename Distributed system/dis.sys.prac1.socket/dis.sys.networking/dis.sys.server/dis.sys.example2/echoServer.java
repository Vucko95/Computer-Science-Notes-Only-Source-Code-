import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
public class echoServer {
	public static void main(String[] args) {
		try {
			ServerSocket serverSocket = new ServerSocket(7788);
			Socket socket = serverSocket.accept();
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
			String message = in.readLine();
			out.println(message);
			serverSocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
