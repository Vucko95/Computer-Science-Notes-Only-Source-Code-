package examples;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

class UDPClient {
	public static void main(String args[]) throws Exception {
		DatagramSocket clientSocket = new DatagramSocket();

		// Read User Input (and convert to byte array for transmission)
		BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
		byte[] sendData = inFromUser.readLine().getBytes();

		// Send the packet
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, InetAddress.getByName("localhost"), 9876);
		clientSocket.send(sendPacket);

		// Wait for a response�
		DatagramPacket receivePacket = new DatagramPacket(new byte[1024], 1024);
		clientSocket.receive(receivePacket);

		// Display the output
		System.out.println("FROM SERVER:" + new String(receivePacket.getData()));
		clientSocket.close();
	}
}
