package examples;

import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class MCastReceiver {
	public static void main(String[] args) {
		byte[] buffer = new byte[1024];
		DatagramPacket gift = new DatagramPacket(buffer, buffer.length);
		try {
			InetAddress address = InetAddress.getByName("225.0.0.1");
			MulticastSocket ms = new MulticastSocket(5000);
			ms.joinGroup(address);
			while (true) {
				ms.receive(gift);
				String present = new String(gift.getData(), 0, gift.getLength());
				System.out.println(present);
			}
		} catch (Exception e) {
		}
	}
}
