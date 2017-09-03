
import java.io.*;
import java.net.*;
import java.nio.file.*;
import java.util.logging.Logger;

public class WebServer extends Thread {
    static final int PORT = 8888;
    Socket socket;
    
    public static void main(String[] args) throws IOException {
        while (!Thread.interrupted())
        try(ServerSocket ss = new ServerSocket(PORT);) {
            new WebServer(ss.accept()).start();
        } 
    }

    WebServer(Socket s) {
        socket = s;
    }        

    @Override
    public void run() {
        //OutputStream out;
        try( OutputStream out = socket.getOutputStream();
                InputStream in = socket.getInputStream() ) {
            
            //TODO
        } catch (IOException e) {
            //out.write("400 ERROR".getBytes());
            Logger.getGlobal().severe(e.getMessage());
        }
    }

}