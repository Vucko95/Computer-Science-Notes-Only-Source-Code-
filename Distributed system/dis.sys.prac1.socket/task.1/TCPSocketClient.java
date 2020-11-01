import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.InputStream;
import java.net.Socket;

public class TCPSocketClient {
  public String host;
  public int port;
  
  public TCPSocketClient(String host, int port) {
    host = host;
    port = port;
  }
  
  public void sendMessage(String sendMessageMess) {
    try {
      
      Socket socket = new Socket(host, port); // we need a socket to start
      InputStream inStream = socket.getInputStream(); // then we need an input stream on the client side
      InputStreamReader inStrRead = new InputStreamReader(inStream); // the in read stram will read from the in stream
      BufferedReader buffRead = new BufferedReader(inStrRead); // the buffer also needs to take in an input of inStreamRead
      PrintWriter outPrint = new PrintWriter(socket.getOutputStream(), true); // the output stream will be the print writer
      outPrint.println(sendMessageMess); // winting the message to be send
      String mess = buffRead.readLine(); // creading a message from the buffer read . read line
      System.out.println(mess); // printing the sockets message
      System.out.println("Message received from the server : " + mess);
      outPrint.close(); // closing the print writter
      socket.close(); // closing the socket
    } catch (IOException ioe) { // in case of errors
      ioe.printStackTrace();
    } catch (SecurityException se) { se.printStackTrace(); }
  }
  
  public static void main(String[] args) {
    String host = null; // taking a hsot as null for now
    int port = 0; // and setting 0 to the port
    String message = null; // creating a string message and setting it to nu;;
    if (args.length == 3) {
      host = args[0]; // taking the first argument as host
      try {
        port = Integer.valueOf(args[1]); // taking the second value and assigning it to the post
      } catch (NumberFormatException nfe) {
        System.err.println("The value provided for the port is not an integer");
        nfe.printStackTrace(); 
      } 

      message = args[2];
      TCPSocketClient client = new TCPSocketClient(host, port);
      client.sendMessage(message);
    } else {
      System.out.println("Usage: java TCPSocketClient <host> <port> <message>");
    }
  }
}
