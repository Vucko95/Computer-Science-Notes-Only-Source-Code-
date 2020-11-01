public class ThreadedEchoServer {
  public static final int BACKLOG = 5;
  public static void main(String[] args) {
    newThreadedEchoServer(7788).listen();
  } 
  private ServerSocket serverSocket;
  public ThreadedEchoServer(int port) {
    try {
      serverSocket = newServerSocket(7788, BACKLOG);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
  public void listen() {
    while (true) {
      try {
        newThread(new Connection(serverSocket.accept())).start();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }
}