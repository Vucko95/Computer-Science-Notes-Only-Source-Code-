package examples;

import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class MCastSender {
	public static void main(String[] args) {
		byte[] giftData = "Santa has got you a new bike".getBytes();
		try {
			// Join a multicast group
			MulticastSocket ms = new MulticastSocket();
			InetAddress address = InetAddress.getByName("225.0.0.1");
			ms.joinGroup(address);
			ms.setTimeToLive(1);

			// Send some data
			ms.send(new DatagramPacket(giftData, giftData.length, address, 5000));

			// Leave the group
			ms.leaveGroup(address);
			ms.close();
		} catch (Exception e) {
		}
	}
}
