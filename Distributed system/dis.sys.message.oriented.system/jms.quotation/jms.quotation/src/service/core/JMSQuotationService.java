package service.core;

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

public abstract class JMSQuotationService extends AbstractQuotationService {
	public JMSQuotationService(String id) {
		try {
			ConnectionFactory factory = (ConnectionFactory) new ActiveMQConnectionFactory(
					ActiveMQConnection.DEFAULT_BROKER_URL);
			Connection connection = factory.createConnection();
			connection.setClientID(id);
			Session session = connection.createSession(false, Session.CLIENT_ACKNOWLEDGE);

			// Link to the QUOTATIONS topic
			Destination destination = session.createTopic("QUOTATIONS");
			MessageConsumer consumer = session.createConsumer(destination);

			// Link to the QUOTATION queue
			Queue queue = session.createQueue("QUOTATION");
			MessageProducer quotationProducer = session.createProducer(queue);
			connection.start();

			Thread thread = new Thread(new Runnable() {
				@Override
				public void run() {
					while (true) {
						try {
							Message message = consumer.receive();
							if (message instanceof ObjectMessage) {
								// Parse incoming message
								ObjectMessage objectMessage = (ObjectMessage) message;
								ClientInfo info = (ClientInfo) objectMessage.getObject();

								// Generate quotation
								Quotation quotation = generateQuotation(info);

								// Send Reply
								ObjectMessage quotationMessage = session.createObjectMessage(quotation);
								quotationProducer.send(quotationMessage);

								// Acknowledge initial message
								message.acknowledge();
							}
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

}
