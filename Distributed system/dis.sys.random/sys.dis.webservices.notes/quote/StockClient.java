package quote;

public class StockClient {

  public static void main(String[] args) throws Exception {

		// 1,2,3,4,5 neeeded 
		URL wsdlUrl = new URL("http://localhost:9000/StockService/GetStockQuote?wsdl"); // will check on the xml 
		
    QName qname = new QName("http://quote/", "StockImplService");
	
		Service service = Service.create(wsdlUrl, qname);

		StockService stockService = service.getPort(StockService.class);
		
		System.out.println(stockService.GetStockQuote("IBM"));
  }
}
