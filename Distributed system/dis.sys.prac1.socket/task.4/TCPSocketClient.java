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



public class TCPSocketClient {
  public static void main(String[] args) {
  String host = null;  // creating a host string
  int port = 0; // creating a port and assigning 0 
  String message = null; // starting a message but assigning it null 
  if (args.length == 2) { // staying true to the arg length ( parameters that are past )
  host = args[0]; // assigning the right host to the first arg
  try {  // befinn of try 
  port = Integer.valueOf(args[1]); // getting the first value of the second arg and putting it to the port
  Socket socket = new Socket(host, port); // creating a socket and passing it the host and port 
  DataInputStream inputStream = new DataInzwputStream(socket.getInputStream()); // input and output datastream 
  DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream()); // passing socket 
  Scanner sc = new Scanner(System.in); // scanner system to read input 
  for(int i=0;i<100;i++) { // trying to start for loop to multiply a 100 times 
  int num1 = (int)(Math.random() * 100) + 1;// numbers with random function
  int num2 = (int)(Math.random() * 100) + 1; // numbers with random function
  outputStream.writeUTF(Integer.toString(num1) + "/" + Integer.toString(num2)); // writing these numbers to bytecode 
  String received = inputStream.readUTF(); // creating variable recieved to gather input stream material as well as the byte code
  System.out.println(received); // printing out the code 
  }
  outputStream.writeUTF("exit");
  System.out.println("Closing Connection");
  socket.close(); // closing the socket and all other stream material 
  inputStream.close(); 
  outputStream.close();
  sc.close();
  } catch (Exception nfe) { // in case of errors
  System.err.println(
  "The value provided for the port is not an integer");
  nfe.printStackTrace();
  }
  } else {
  System.out.println("Usage: java TCPSocketClient <host> <port> <message>");
  }
  }
}
