package util;

import java.rmi.RemoteException;

import org.apache.juddi.v3.client.UDDIConstants;
import org.uddi.api_v3.AuthToken;
import org.uddi.api_v3.BusinessInfo;
import org.uddi.api_v3.BusinessList;
import org.uddi.api_v3.FindBusiness;
import org.uddi.api_v3.GetAuthToken;
import org.uddi.api_v3.GetServiceDetail;
import org.uddi.api_v3.Name;
import org.uddi.api_v3.ServiceDetail;
import org.uddi.v3_service.DispositionReportFaultMessage;
import org.uddi.v3_service.UDDIInquiryPortType;
import org.uddi.v3_service.UDDISecurityPortType;

public class WebServicesClientHelper {
	/**
	 * Gets a UDDI style auth token, otherwise, appends credentials to the ws
	 * proxies (not yet implemented)
	 *
	 * @param username
	 * @param password
	 * @param style
	 * @return
	 */
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

	public static BusinessList partialBusinessNameSearch(UDDIInquiryPortType inquiry, String token, String partialName) throws Exception {
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

	public static ServiceDetail getServiceDetail(UDDIInquiryPortType inquiry, String token, BusinessInfo info) throws Exception {
		GetServiceDetail gsd = new GetServiceDetail();
		for (int k = 0; k < info.getServiceInfos().getServiceInfo().size(); k++) {
			gsd.getServiceKey().add(info.getServiceInfos().getServiceInfo().get(k).getServiceKey());
		}
		gsd.setAuthInfo(token);
		return inquiry.getServiceDetail(gsd);
	}
}
