package client;

import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageConsumer;
import javax.jms.MessageProducer;
import javax.jms.ObjectMessage;
import javax.jms.Queue;
import javax.jms.Session;

import org.apache.activemq.ActiveMQConnection;
import org.apache.activemq.ActiveMQConnectionFactory;

import service.auldfellas.AFQService;
import service.core.Quotation;
import service.dodgydrivers.DDQService;
import service.girlpower.GPQService;

public class QSTest {
	public static void main(String[] args) {
		new AFQService();
		new DDQService();
		new GPQService();
		
		ConnectionFactory connectionFactory = new ActiveMQConnectionFactory(ActiveMQConnection.DEFAULT_BROKER_URL);
		try {
			Connection connection = connectionFactory.createConnection();
			connection.setClientID("test-client");
			Session session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
			
			Destination destination = session.createTopic("QUOTATIONS");
			MessageProducer messageProducer = session.createProducer(destination);
			
			Queue queue = session.createQueue("QUOTATION");
			MessageConsumer consumer = session.createConsumer(queue);
			connection.start();

			ObjectMessage objectMessage = session.createObjectMessage(Main.clients[0]);
			messageProducer.send(objectMessage);


			while (true) {
				Message message = consumer.receive();
				if (message instanceof ObjectMessage) {
					objectMessage = (ObjectMessage) message;
					Object object = objectMessage.getObject();
					if (object instanceof Quotation) {
						System.out.println("Quotation: " + object);
					}
				}
			}
		} catch (JMSException e) {
			e.printStackTrace();
		}

	}

}
