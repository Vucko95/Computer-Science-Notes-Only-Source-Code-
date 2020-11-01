//package client;
//
//import org.apache.juddi.v3.client.config.UDDIClerk;
//import org.apache.juddi.v3.client.config.UDDIClient;
//
//public class Delete {
//	
//	static UDDIClient uddiClient;
//	
//	public void deleteBusiness(UDDIClerk clerk) {
//		clerk.unRegisterBusiness("uddi:uddi.joepublisher.com:business_wsdl-business");
//	}	
//	
//	public void deleteWSDL(UDDIClerk clerk) {
//		clerk.unRegisterWsdls();
//	}
//
//	public static void main (String args[]) {
//		
//		Delete sp = new Delete();
//		try {
//			uddiClient = new UDDIClient("META-INF/wsdl2uddi-uddi.xml");
//			UDDIClerk clerk = uddiClient.getClerk("joe");
//			
//			sp.deleteWSDL(clerk);
//			sp.deleteBusiness(clerk);
//			
//		} catch (Exception e) {
//			e.printStackTrace();
//		}
//	}
//	
//	
//}