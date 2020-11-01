
package quote;
import javax.jws.WebMethod;
import javax.jws.WebService;

@WebService
public interface StockService {
  @WebMethod
  public double GetStockQuote(String StockName);
}

// @SOAPBinding(style = Style.RPC, use=Use.LITERAL)
