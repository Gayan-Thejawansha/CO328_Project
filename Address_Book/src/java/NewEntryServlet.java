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

/**
 *
 * @author e13366
 */
@WebServlet(
        name = "New Entry"
        ,urlPatterns = "/new"
        ,initParams = {@WebInitParam(name= "filename" , value ="/addressBook.txt" )}
)
public class NewEntryServlet extends HttpServlet {

    private static final long serialVersionUID = 1L;
    
    AddressBook ab;
    String filename;
    String path;
        //Servlet initialization
    @Override
    public void init() throws ServletException {
        
        ServletConfig config = getServletConfig();
        
        //get the value of the init-parameter
        filename = config.getInitParameter("filename");
        ServletContext sc = config.getServletContext();
        path = sc.getRealPath(filename);
        ab = new AddressBook(path);
        
    }
    
    

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
                String name = request.getParameter("name");
                String detail = request.getParameter("details");
                
            response.setContentType("text/html;charset=UTF-8");
            PrintWriter out = response.getWriter();
                   //try{ AddressBookServlet.ab.newContact(name, detail);} catch (Exception e){out.println(e);}
                       
                    //out.println((name+ " " +detail + " " + path  ));
                    try{out.println(ab.newContact(name,detail, path ));
                    } catch (Exception e){out.println(e);}
        
        

    }

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
        processRequest(request, response);
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
        processRequest(request, response);
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
