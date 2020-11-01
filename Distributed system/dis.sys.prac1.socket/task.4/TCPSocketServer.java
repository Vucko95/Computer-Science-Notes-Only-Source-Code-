import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.InputStream;
import java.net.Socket;
import java.lang.Math.*;
import java.util.Random;
import java.util.*;
import java.io.*;
import java.net.*;

// making sure its a Thread
public class TCPSocketServer extends Thread {
  private int my_backlog = 5; // creating a backlog variable
  private ServerSocket my_serverSocket; // creating a server socket variable
  private DataInputStream inputStream; // creating an input stream vaiable
  private DataOutputStream outputStream; // creating an putput stream variable
  private Socket socket; // creating a socket based variable
  
  public TCPSocketServer(int a_port) {
    try {
      my_serverSocket = new ServerSocket(a_port, my_backlog); // creating a new server soclet obkect and assigning it the right port and backlog
      socket = my_serverSocket.accept(); // accepting the request form client
      inputStream = new DataInputStream(socket.getInputStream()); // assigning the datainputstream as well as the output stream
      outputStream = new DataOutputStream(socket.getOutputStream());
      System.out.println("TCP socket listening on port " + a_port);
      this.start(); // start the server
    } catch (IOException ioe) { // in case of errors
      ioe.printStackTrace();
    } catch (SecurityException se) { se.printStackTrace(); }
  }
  
  // Overided method
  public void run() {
    String recieved;
    String toReturn;
    while (true) {
      try {
        recieved = inputStream.readUTF(); // reading the byte code from input stream
        System.out.println("Client-> " + recieved); // confirmed
        if (recieved.equalsIgnoreCase("exit")) { // if recieved than clode and return
          System.out.println("Closing the Connection");
          this.socket.close();
          return;
        }
        String Calc = multiply(recieved); // passing the information from the recieve and sending it to multiply method
        outputStream.writeUTF("Server Response:" + Calc); // writting it
      } catch (Exception e) { e.printStackTrace(); }
    }
  }
  
  public String multiply(String msg) { // multiply method
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
      TCPSocketServer server = new TCPSocketServer(port); // TCP server socket
    } else {
      System.out.println("Usage: java TCPSocketServer <port>");
    }
  }
}
