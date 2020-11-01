package ws.calc;

import java.net.URL;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import javax.xml.namespace.QName;
import javax.xml.ws.Service;

import quote.StockService;

public class Client {
	public static void main(String[] args) throws Exception {
		URL wsdlUrl = new URL("http://localhost:9000/calc?wsdl");
		QName qname = new QName("http://calc.ws/", "CalculatorImplService");
		Service service = Service.create(wsdlUrl, qname);
		Calculator calc = service.getPort(new QName("http://calc.ws/", "CalculatorServicePort"), Calculator.class);
		System.out.println("Test: " + calc.add(2, 4));
	}
}
