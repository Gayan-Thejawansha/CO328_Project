// UDPClient.java: A simple UDP client program.

import java.net.*;
import java.io.*;

public class UDPClient {

    final static String data = "Hello TJ!";
    final static int PORT = 1234;
    final static int BUFSIZE = 1024;
    static int nOfPack = 10000;
    public static void main(String args[]) {

    long start=0,end=0;
    for (int i=0;i<nOfPack;i++)
        try ( DatagramSocket aSocket = new DatagramSocket();) {
            InetAddress aHost = InetAddress.getByName(args[0]);
            
            byte[] dataArray = data.getBytes();
            DatagramPacket requestPacket = new DatagramPacket(dataArray, dataArray.length, aHost, PORT);
            aSocket.send(requestPacket);
            if(i==0) start=System.currentTimeMillis();
            if(i==nOfPack-1) end=System.currentTimeMillis();
    


            //byte[] buffer = new byte[BUFSIZE];
            //DatagramPacket recievePacket = new DatagramPacket(buffer, buffer.length);
            //aSocket.receive(recievePacket);
           // System.out.println("Reply:" + new String(recievePacket.getData()));
           // System.out.println("Time (ms): " + (end-start)+" ");
        } catch (Exception e) {
            System.out.println("Socket: " + e.getMessage());
        }
            //System.out.println("Reply:" + new String(recievePacket.getData()));
            ///System.out.println(start);
            
            System.out.println("Time (ms): " + (end-start)+" ");
            System.out.println("Throughput : "+ (nOfPack/(end-start))*1000000 + "Packets for Second");

        
    }
}
