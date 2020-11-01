import java.net.MulticastSocket;

/**
 * MCastSender
 */

public class MCastSender {
	public static void main(String[] args) {
		byte giftData = "Santa has got you a new bike".getBytes(); 

		try{	// join multicast 
			MulticastSocket ms = new MulticastSocket(); 
			InetAddress address = InetAddress.getbyName("225.0.0.1"); 
			ms.joinGroup(address);
			ms.setTimeToLive(1); //! what does this do? 	// send some data 
			ms.send(new DatagramPacket(giftData, giftData.length, address));	// leave the group // look up 
			ms.leaveGroup(address);
			ms.close();

		} catch (Exception e ){}
	}
}