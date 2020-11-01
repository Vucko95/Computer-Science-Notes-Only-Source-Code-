package pubsub;

import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageConsumer;
import javax.jms.Queue;
import javax.jms.Session;
import javax.jms.TextMessage;

import org.apache.activemq.ActiveMQConnection;
import org.apache.activemq.ActiveMQConnectionFactory;

public class HelloConsumer2 {
    public static void main(String[] args) {
        try {
            ConnectionFactory factory = (ConnectionFactory) 
                new ActiveMQConnectionFactory(ActiveMQConnection.DEFAULT_BROKER_URL);
            Connection connection = factory.createConnection();
            connection.setClientID("receiver2");
            Session session = connection.createSession(false,
                Session.CLIENT_ACKNOWLEDGE);
            Destination destination = session.createTopic("MYTOPIC");
            MessageConsumer consumer = session.createConsumer(destination);
            connection.start();
            Message message = consumer.receive();
            if (message instanceof TextMessage) {
                System.out.println("Received: " + ((TextMessage) message).getText());
                message.acknowledge();
            }
            connection.close();
        } catch (JMSException e) { e.printStackTrace(); }
    }

}
