package quote;

@WebService(name = "StockService"); 
@SOAPBinding(style = Style.RPC, use = Use.LITERAL)

public class StockImpl implements StockService {
  public static void main(String args[]) throws Exception {
    // the url can be what ever you wnt it to be
    Endpoint.publish("http://localhost:9000/StockService/GetStockQuote", new StockImpl());
	}
	
	private Random random = new Random();
	
  @Override
  public double GetStockQuote(String StockName) {
    double val = 100 + random.nextDouble() * 100;
    System.out.println("Processed GetStockQuote(" + StockName + ")=" + val);
    return val;
  }
}

// WSDL http://localhost:9000/StockService/GetStockQuote?WSDL