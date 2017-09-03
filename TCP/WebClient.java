import java.io.*;
import java.net.*;

public class WebClient{
	public static void main(String[] args) throws IOException {
		String ip = args[0];
		String port = args[1];
		Socket socket = new Socket(ip,Integer.parseInt(port));
		//WebServer ws = new WebServer(socket);
		PrintWriter out = new PrintWriter(socket.getOutputStream(),true);
		out.println("Hello TCP");
		out.close();
		socket.close();
	}
}
