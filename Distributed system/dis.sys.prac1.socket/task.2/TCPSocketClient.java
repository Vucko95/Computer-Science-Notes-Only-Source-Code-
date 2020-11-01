import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.InputStream;
import java.net.Socket;

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
      System.out.println(mess);
      System.out.println("Message received from the server : " + mess);
      out.close();
      toServer.close();
    } catch (IOException ioe) {
      ioe.printStackTrace();
    } catch (SecurityException se) {
      se.printStackTrace();
    }
  }

  public static void main(String[] args) {
    String host = null;
    int port = 0;
    String message = null;
    if (args.length == 4) {
      host = args[0];
      try {
        port = Integer.valueOf(args[1]);
      } catch (NumberFormatException nfe) {
        System.err.println("The value provided for the port is not an integer");
        nfe.printStackTrace();
      }
      String messagenum = args[2] + "/" + args[3];
      TCPSocketClient client = new TCPSocketClient(host, port);
      client.sendMessage(messagenum);
    } else {
      System.out.println("Usage: java TCPSocketClient <host> <port> <message>");
    }
  }
}
