package service.dodgydrivers;
import org.restlet.Component;
import org.restlet.data.Protocol;
import service.auldfellas.AFApplication;
import service.core.AbstractQuotationService;
import service.core.ClientInfo;
import service.core.Quotation;
import service.core.QuotationService;
public class DDQService extends AbstractQuotationService implements QuotationService {
    
    public static final String PREFIX = "DD";
    public static final String COMPANY = "Dodgy Drivers Corp.";
    public static void main(String[] args) throws Exception {
        Component component = new Component();
        component.getServers().add(Protocol.HTTP, 9020);
        component.getDefaultHost().attach("", new DDQApplication());
        component.start();
    }

    @Override
    public Quotation generateQuotation(ClientInfo info) {
        double price = generatePrice(800, 200);
        int discount = (info.points > 3) ? 5 * info.points : -50;
        discount += getNoClaimsDiscount(info);
        return new Quotation(COMPANY, generateReference(PREFIX), (price * (100 - discount)) / 100);
    }
    private int getNoClaimsDiscount(ClientInfo info) {
        return 10 * info.noClaims;
    }
}
