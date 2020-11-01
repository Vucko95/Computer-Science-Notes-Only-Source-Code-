package ws.calc;

import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;
import javax.jws.soap.SOAPBinding.Use;
import javax.xml.ws.Endpoint;

@WebService(name="CalculatorService")
@SOAPBinding(style = Style.RPC, use=Use.LITERAL)
public class CalculatorImpl implements Calculator {
    public static void main(String args[]) throws Exception {
        Endpoint.publish("http://localhost:9000/calc", new CalculatorImpl());
    }

	@Override
	public long add(long a, long b) {
		return a+b;
	}

	@Override
	public long subtract(long a, long b) {
		return a-b;
	}

	@Override
	public long multiply(long a, long b) {
		return a*b;
	}

	@Override
	public long divide(long a, long b) {
		return a/b;
	}

	@Override
	public long modulo(long a, long b) {
		return a % b;
	}

}
