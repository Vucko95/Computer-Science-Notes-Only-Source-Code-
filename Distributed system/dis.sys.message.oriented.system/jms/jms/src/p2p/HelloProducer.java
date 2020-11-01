package p2p;

import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.JMSException;
import javax.jms.MessageProducer;
import javax.jms.Queue;
import javax.jms.Session;
import javax.jms.TextMessage;

import org.apache.activemq.ActiveMQConnection;
import org.apache.activemq.ActiveMQConnectionFactory;

public class HelloProducer {
	public static void main(String[] args) {
        ConnectionFactory connectionFactory =
                new ActiveMQConnectionFactory(ActiveMQConnection.DEFAULT_BROKER_URL);
            try {
                Connection connection = connectionFactory.createConnection();
                connection.setClientID("sender");
                Session session = connection.createSession(false,
                    Session.AUTO_ACKNOWLEDGE);
                Queue queue = session.createQueue("TESTQUEUE");
                MessageProducer messageProducer = session.createProducer(queue);

                TextMessage textMessage = session.createTextMessage("Hello World");
                messageProducer.send(textMessage);
            } catch (JMSException e) { e.printStackTrace(); }
		
	}
}
