package util;

import java.rmi.RemoteException;
import org.apache.juddi.v3.client.UDDIConstants;
import org.uddi.api_v3.AuthToken;
import org.uddi.api_v3.BusinessInfo;
import org.uddi.api_v3.BusinessList;
import org.uddi.api_v3.FindBusiness;
import org.uddi.api_v3.FindQualifiers;
import org.uddi.api_v3.FindService;
import org.uddi.api_v3.GetAuthToken;
import org.uddi.api_v3.GetServiceDetail;
import org.uddi.api_v3.Name;
import org.uddi.api_v3.ServiceDetail;
import org.uddi.api_v3.ServiceList;
import org.uddi.v3_service.DispositionReportFaultMessage;
import org.uddi.v3_service.UDDIInquiryPortType;
import org.uddi.v3_service.UDDISecurityPortType;

public class WebServicesClientHelper {
	public static String getAuthKey(UDDISecurityPortType security, String username, String password) {
		try {
			GetAuthToken getAuthTokenRoot = new GetAuthToken();
			getAuthTokenRoot.setUserID(username);
			getAuthTokenRoot.setCred(password);
			AuthToken rootAuthToken = security.getAuthToken(getAuthTokenRoot);
			return rootAuthToken.getAuthInfo();
		} catch (Exception ex) {
			System.out.println("Could not authenticate with the provided credentials " + ex.getMessage());
		}
		return null;
	}

	public static BusinessList partialBusinessNameSearch(UDDIInquiryPortType inquiry, String token, String partialName)
			throws Exception {
		FindBusiness fb = new FindBusiness();
		fb.setAuthInfo(token);
		org.uddi.api_v3.FindQualifiers fq = new org.uddi.api_v3.FindQualifiers();
		fq.getFindQualifier().add(UDDIConstants.APPROXIMATE_MATCH);
		fb.setFindQualifiers(fq);
		Name searchname = new Name();
		searchname.setValue(partialName);
		fb.getName().add(searchname);
		return inquiry.findBusiness(fb);
	}

	public static ServiceList partialServiceNameSearch(UDDIInquiryPortType inquiry, String token, String partialName)
			throws Exception {
		FindBusiness fb = new FindBusiness();
		FindService fs = new FindService();
		fs.setAuthInfo(token);
		org.uddi.api_v3.FindQualifiers fq = new org.uddi.api_v3.FindQualifiers();
		fs.getFindQualifiers().getFindQualifier().add(UDDIConstants.EXACT_MATCH);
		fs.getName().add(new Name("QuotationService", "en"));
		ServiceList findService = inquiry.findService(fs);
		System.out.println("In web service" + findService);
		return findService;
	}

	public static void ServiceLookUpByName(UDDIInquiryPortType inquiry, String token, String partialName) throws Exception {
		System.out.println("Helooooo");
		FindService fs = new FindService();
		fs.setFindQualifiers(new FindQualifiers());
		fs.getFindQualifiers().getFindQualifier().add(UDDIConstants.EXACT_MATCH);
		fs.getName().add(new Name("QuotationService", "en"));
		ServiceList findService = inquiry.findService(fs);
		System.out.println(findService);
		GetServiceDetail gsd = new GetServiceDetail();
		
		for (int i = 0; i < findService.getServiceInfos().getServiceInfo().size(); i++) {
			System.out.println("In loop");
			gsd.getServiceKey().add(findService.getServiceInfos().getServiceInfo().get(i).getServiceKey());
		}
		ServiceDetail serviceDetail = inquiry.getServiceDetail(gsd);
		System.out.println(serviceDetail);
	}

	public static ServiceDetail getServiceDetail(UDDIInquiryPortType inquiry, String token, BusinessInfo info)
			throws Exception {
		GetServiceDetail gsd = new GetServiceDetail();
		for (int k = 0; k < info.getServiceInfos().getServiceInfo().size(); k++) {
			gsd.getServiceKey().add(info.getServiceInfos().getServiceInfo().get(k).getServiceKey());
		}
		gsd.setAuthInfo(token);
		return inquiry.getServiceDetail(gsd);
	}
}
