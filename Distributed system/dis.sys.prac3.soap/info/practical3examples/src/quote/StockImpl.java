package quote;

import java.util.Random;

import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;
import javax.xml.ws.Endpoint;

@WebService(name="StockService")
@SOAPBinding(style = Style.RPC, use=Use.LITERAL)
public class StockImpl implements StockService {
    public static void main(String args[]) throws Exception {
        Endpoint.publish("http://localhost:9000/StockService/GetStockQuote", new StockImpl());
    }
    
    private Random random = new Random();

    @Override
    public double GetStockQuote(String StockName) {
        double val = 100+random.nextDouble()*100;
        System.out.println("Processed GetStockQuote(" + StockName + ")="+val);
        return val;
    }
}

