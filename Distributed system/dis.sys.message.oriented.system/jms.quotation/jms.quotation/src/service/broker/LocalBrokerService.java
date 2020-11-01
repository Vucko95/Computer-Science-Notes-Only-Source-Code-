package service.broker;

import java.util.LinkedList;
import java.util.List;

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

import client.Main;
import service.core.BrokerService;
import service.core.ClientInfo;
import service.core.Quotation;

/**
 * Implementation of the broker service that uses the Service Registry.
 * 
 * @author Rem
 *
 */
public class LocalBrokerService implements BrokerService {
	private Session session;
	private MessageProducer messageProducer;
	private MessageConsumer consumer;
	private MessageConsumer brokerConsumer;
	private MessageProducer replyProducer;
	
	public LocalBrokerService() {
		ConnectionFactory connectionFactory = new ActiveMQConnectionFactory(ActiveMQConnection.DEFAULT_BROKER_URL);
		try {
			Connection connection = connectionFactory.createConnection();
			connection.setClientID("test-client");
			session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
			
			Destination destination = session.createTopic("QUOTATIONS");
			messageProducer = session.createProducer(destination);
			
			Queue queue = session.createQueue("QUOTATION");
			consumer = session.createConsumer(queue);

			queue = session.createQueue("BROKER");
			brokerConsumer = session.createConsumer(queue);
			
			queue = session.createQueue("REPLY");
			replyProducer = session.createProducer(queue);
			connection.start();
			
			Thread thread = new Thread(new Runnable() {
				@Override
				public void run() {
					while (true) {
						try {
							Message message = brokerConsumer.receive();
							if (message instanceof ObjectMessage) {
								Object object = ((ObjectMessage) message).getObject();
								List<Quotation> quotations = getQuotations((ClientInfo) object);
								Message replyMessage = session.createObjectMessage(quotations.toArray(new Quotation[quotations.size()]));
								replyProducer.send(replyMessage);
							}
							message.acknowledge();
						} catch (JMSException e) {
							e.printStackTrace();
						}
					}
				}
			});
			thread.start();
		} catch (JMSException e) {
			e.printStackTrace();
		}
	}
	
	public List<Quotation> getQuotations(ClientInfo info) {
		List<Quotation> quotations = new LinkedList<Quotation>();
		
		try {
			ObjectMessage objectMessage = session.createObjectMessage(Main.clients[0]);
			messageProducer.send(objectMessage);
	
			long time = System.currentTimeMillis();
			while ((System.currentTimeMillis()-time) < 1000) {
				Message message = consumer.receiveNoWait();
				if (message instanceof ObjectMessage) {
					objectMessage = (ObjectMessage) message;
					Object object = objectMessage.getObject();
					if (object instanceof Quotation) {
						quotations.add((Quotation) object);
					}
				}
			}
		} catch (JMSException e) {
			e.printStackTrace();
		}
		
		return quotations;
	}
}
