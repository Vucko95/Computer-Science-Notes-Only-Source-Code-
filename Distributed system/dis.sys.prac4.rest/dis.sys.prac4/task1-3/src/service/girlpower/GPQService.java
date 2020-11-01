package service.girlpower;
import org.restlet.Component;
import org.restlet.data.Protocol;

import service.core.AbstractQuotationService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;

public class GPQService extends AbstractQuotationService implements QuotationService {
  public static final String PREFIX = "GP";
  public static final String COMPANY = "Girl Power Inc.";

  public static void main(String[] args) throws Exception {
    Component component = new Component();
    component.getServers().add(Protocol.HTTP, 9010);
    component.getDefaultHost().attach("", new GPQApplication());
    component.start();
  }

  @Override
  public Quotation generateQuotation(ClientInfo info) {
    double price = generatePrice(600, 400);
    int discount = (info.gender == ClientInfo.FEMALE) ? 50 : 0;
    discount += getPointsDiscount(info);
    discount += getNoClaimsDiscount(info);
    return new Quotation(COMPANY, generateReference(PREFIX), (price * (100 - discount)) / 100);
  }

  private int getNoClaimsDiscount(ClientInfo info) { return 5 * info.noClaims; }

  private int getPointsDiscount(ClientInfo info) {
    if (info.points == 0) return 20;
    if (info.points < 3) return 15;
    if (info.points < 6) return 0;
    return -100;
  }
}
