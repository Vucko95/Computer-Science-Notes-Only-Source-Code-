public class EchoClient3 {
  private String host;
  private int port;
  private Socket mySocket;
  private BufferedReader in;
	private PrintWriter out;
	
  public EchoClient3(String host, int port) {
    this.host = host;
    this.port = port;
  }
  public void connect() {
     try {
      mySocket = new Socket(host, port);
      in = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
      out = new PrintWriter(mySocket.getOutputStream(), true);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
  public void sendMessage(String message) {
    try {
      out.println(message);
      System.out.println(in.readLine());
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
  public void close() {
    try {
      in.close();
      out.close();
      mySocket.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
  public static void main(String[] args) {
    EchoClient3 client = new EchoClient3("localhost", 7788);
    client.connect();
    for (inti = 0; i < 10; i++) {
      client.sendMessage("Hello World");
    }
    client.close();
  }
}
