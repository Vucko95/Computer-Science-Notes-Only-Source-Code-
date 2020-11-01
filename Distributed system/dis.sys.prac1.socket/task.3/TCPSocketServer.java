import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.PrintWriter;
import java.util.Random;
import java.lang.Math.*;

public class TCPSocketServer {
  private int my_backlog = 5;
  private ServerSocket my_serverSocket;
  public TCPSocketServer(int a_port) {
    try {
      my_serverSocket = new ServerSocket(a_port, my_backlog);
      System.out.println("TCP socket listening on port " + a_port);
    } catch (IOException ioe) { ioe.printStackTrace(); } catch (SecurityException se) {
      se.printStackTrace();
    }
  }
  public void listen() {
    while (true) {
      try {
        Socket socket = my_serverSocket.accept();
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String msg = in.readLine();
        String Calc = multiply(msg);
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        System.out.println("From the client multiplication answer is :" + Calc);
        out.println(Calc);
        in.close();
        socket.close();
      } catch (IOException ioe) { ioe.printStackTrace(); } catch (SecurityException se) {
        se.printStackTrace();
      }
    }
  }
  public String multiply(String msg) {
    String[] numbers = msg.split("/");
    String num1 = numbers[0];
    String num2 = numbers[1];
    int new1 = Integer.parseInt(num1);
    int new2 = Integer.parseInt(num2);
    int res = new1 * new2;
    return Integer.toString(res);
  }
  public static void main(String[] args) {
    int port = 0;
    if (args.length == 1) {
      try {
        port = Integer.valueOf(args[0]);
      } catch (NumberFormatException nfe) {
        System.err.println("The value provided for the port is not an integer");
        nfe.printStackTrace();
      }
      TCPSocketServer server = new TCPSocketServer(port);
      server.listen();
    } else {
      System.out.println("Usage: java TCPSocketServer <port>");
    }
  }
}
