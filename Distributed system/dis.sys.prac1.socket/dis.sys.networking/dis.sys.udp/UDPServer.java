import java.net.DatagramPacket;
import java.net.DatagramSocket;
/**
 * UDPServer
 */
public class UDPServer {
  public static void main(String[] args) {
    DatagramSocket serverSocket = new DataGramSocket(new byte[1028], 1024);

    while (true) { // wait for thepacket
      DatagramPacket recievePacket = new DataGramSocket(new byte[1028], 1024);
      servverSocket.recieve(recievePacket); // process the recieved dat 
      String senten = new String(receivePacket.getData()); 
      System.out.println("recieved: " senten);
      byte[] sendData = senten.toUpperCase().getBytes(); 
      DatagramPacket sendPacket = new dataGramPacket(sendData, sendData.length, recievePacket.getAddress(), receivePacket.getPort());
      serverSocket.send(sendPacket);
    }
  }
}
