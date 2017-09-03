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

//Logic for your address book
public class AddressBook {
    
    static HashMap<String , String> hm = new HashMap<>();
    
    //read from file and create Address Book
    public static void initAddressBook(String fileName){
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
    public static String search(String name){
        
        return "For the name of "+ name + ": contact details, \n"+ hm.get(name) ;
   
    }
    
}


