/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author Gayan S. Thejawansha (E/13/366)
 */

@WebServlet(
        name = "Address Book",
        urlPatterns = "/search",
        initParams = {@WebInitParam(name= "filename" , value ="/addressBook.txt" )}
)
public class AddressBookServlet extends HttpServlet {
       
    String filename;
    //static AddressBook ab;
    String path ;
    HttpSession session;
    //Servlet initialization
    @Override
    public void init() throws ServletException {
                       
        ServletConfig config = getServletConfig();
        
        //get the value of the init-parameter
        filename = config.getInitParameter("filename");
        ServletContext sc = config.getServletContext();
        path = sc.getRealPath(filename);
        //ab = new AddressBook(path);
        
    }

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occur
     * @throws IOException if an I/O error occurs
     */
            
/**   
        protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String person = request.getParameter("name");
        response.setContentType("text/html;charset=UTF-8");
        
        //process request parameters and return details of searched name
               
        PrintWriter out = response.getWriter();
       
        out.println( ab.search(person));

        
    }*/

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException { 
            session=request.getSession();
            synchronized(this){
            if(session.getAttribute("AdrBook")==null)
                session.setAttribute("AdrBook",new AddressBook(path));
            } 
            String person = request.getParameter("name");
        response.setContentType("text/html;charset=UTF-8");
                       
        PrintWriter out = response.getWriter();
        AddressBook ab = (AddressBook) session.getAttribute("AdrBook");        
        out.println( ab.search(person));        
       //processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException { 
            session=request.getSession(); 
            synchronized(this){
            if(session.getAttribute("AdrBook")==null)            
                session.setAttribute("AdrBook",new AddressBook(path));
            }
            String name = request.getParameter("name2");
            String detail = request.getParameter("details");
                
            response.setContentType("text/html;charset=UTF-8");
            PrintWriter out = response.getWriter();
            
            try{
                AddressBook ab = (AddressBook) session.getAttribute("AdrBook");
                out.println(ab.newContact(name,detail, path ));
               } catch (Exception e){out.println(e);}        
           //processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {               
        return "Short description";
    }// </editor-fold>

}
