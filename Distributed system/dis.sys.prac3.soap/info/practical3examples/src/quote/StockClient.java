package quote;
import java.net.URL;
import javax.xml.namespace.QName;
import javax.xml.ws.Service;
public class StockClient {
    public static void main(String[] args) throws Exception {
        URL wsdlUrl = new URL("http://localhost:9000/StockService/GetStockQuote?wsdl");
        QName qname = new QName("http://quote/", "StockImplService");
        Service service = Service.create(wsdlUrl, qname);
        StockService stockService = service.getPort(StockService.class);
        System.out.println(stockService.GetStockQuote("IBM"));
    }
}