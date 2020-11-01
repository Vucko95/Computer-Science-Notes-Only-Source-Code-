package examples;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

class UDPServer {
	public static void main(String args[]) throws Exception {
		DatagramSocket serverSocket = new DatagramSocket(9876);

		while (true) {
			// Wait for a packet
			DatagramPacket receivePacket = new DatagramPacket(new byte[1024], 1024);
			serverSocket.receive(receivePacket); // Blocking Method

			// Process the received data
			String sentence = new String(receivePacket.getData());
			System.out.println("RECEIVED: " + sentence);

			// Generate response and transmit
			byte[] sendData = sentence.toUpperCase().getBytes();
			DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, receivePacket.getAddress(),
					receivePacket.getPort());
			serverSocket.send(sendPacket);
		}
	}
}
