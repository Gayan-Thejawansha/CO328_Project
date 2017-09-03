/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Gayan S. Thejawansha (E/13/366)
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

//Logic for your address book
public class AddressBook {
    
     HashMap<String , String> hm = new HashMap<>();
    
    //read from file and create Address Book
    public AddressBook(String fileName){
       String line ;
       try {
           BufferedReader br =new BufferedReader(new FileReader(fileName));
           while ((line = br.readLine()) != null) {
           String [] details = line.split(",");
           hm.put(details[0],"Tel No: "+ details[1]+ " and the e-mail is: "+ details[2] );
           }
           
       }catch(Exception exception){
           System.out.println(exception);
       }
        
        
    }
    
    //search details of the requested contact in the address book
    public  String search(String name){
        
        return "For the name of "+ name + ": contact details, \n"+ hm.get(name) ;
   
    }
    
    public void newContact (String name , String info , String file ) throws Exception {
        
        //String [] details = info.split(",");
        //System.out.println(details );
        //hm.put(name ,"Tel No: "+ details[0]+ " and the e-mail is: "+ details[1] );   
        String content =name +","+ info ;
		try (BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {


			bw.write(content);
			
		} catch (IOException e) {

			

		}
        
    }
    
}


