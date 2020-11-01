package service.auldfellas;
import service.core.AbstractQuotationService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;

public class AFQService extends AbstractQuotationService implements QuotationService {
  public static final String PREFIX = "AF";
  public static final String COMPANY = "Auld Fellas Ltd.";

  @Override
  public Quotation generateQuotation(ClientInfo info) {
    double price = generatePrice(600, 600);
    int discount = (info.gender == ClientInfo.MALE) ? 30 : 0;
    discount += (info.age > 60) ? (2 * (info.age - 60)) : 0;
    discount += getPointsDiscount(info);
    return new Quotation(COMPANY, generateReference(PREFIX), (price * (100 - discount)) / 100);
  }

  private int getPointsDiscount(ClientInfo info) {
    if (info.points < 3) return 20;
    if (info.points <= 6) return 0;
    return -50;
  }
}
