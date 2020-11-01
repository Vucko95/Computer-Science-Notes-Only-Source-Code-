package hello.client;

import java.io.IOException;

import org.restlet.resource.ClientResource;
import org.restlet.resource.ResourceException;

public class HelloClient {
  public static void main(String[] args) {
    try {
      new ClientResource("http://localhost:8182/hello").get().write(System.out);
    } catch (ResourceException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}