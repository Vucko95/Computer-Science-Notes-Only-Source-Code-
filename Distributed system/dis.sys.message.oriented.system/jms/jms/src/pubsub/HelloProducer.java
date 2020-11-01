package pubsub;

import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.MessageProducer;
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
                Destination destination = session.createTopic("MYTOPIC");
                MessageProducer messageProducer = session.createProducer(destination);

                TextMessage textMessage = session.createTextMessage("Hello World");
                messageProducer.send(textMessage);
            } catch (JMSException e) { e.printStackTrace(); }
		
	}
}
