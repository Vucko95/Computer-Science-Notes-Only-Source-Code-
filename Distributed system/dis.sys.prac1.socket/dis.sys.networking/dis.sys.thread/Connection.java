public class Connection implements Runnable {
	private Socket socket;

	public Connection(Socket socket) {
		this.socket = socket;
	}

	public void run() {
		try {
			BufferedReader in = new BufferedReader(newInputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
			String message = in.readLine();
			while (message != null) {
				out.println(message);
				message = in.readLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}