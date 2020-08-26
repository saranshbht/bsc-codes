/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author saransh
 */
@WebServlet(urlPatterns = {"/ColumnDetails"})
public class ColumnDetails extends HttpServlet {

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
        response.setContentType("text/html;charset=UTF-8");
        response.addHeader("tableName", request.getParameter("tableName"));
        response.addHeader("noOfColumns", request.getParameter("noOfColumns"));
        PrintWriter out = response.getWriter();
        try {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet ColumnDetails</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<form action='SQLQuery' method='get'>");
            
            int noOfColumns = Integer.parseInt(request.getParameter("noOfColumns"));
            Cookie c1 = new Cookie("tableName", request.getParameter("tableName"));
            Cookie c2 = new Cookie("noOfColumns", request.getParameter("noOfColumns"));
            response.addCookie(c1);
            response.addCookie(c2);
            for(int i = 0; i < noOfColumns; i++){
                out.println("<h2>Column " + (i + 1) + ":</h2>");
                out.println("<h2>Name:</h2>");
                out.println("<input type='text' name='column" + (i + 1) + "name'>");
                out.println("<h2>Type:</h2>");
                out.println("<select name='column" + (i + 1) + "type'><option value='varchar'>Varchar</option>");
                out.println("<option value='int'>Int</option></select>");
                out.println("<h2>Length:</h2>");
                out.println("<input type='number' name='column" + (i + 1) + "length'><br><hr>");
            }
            
            out.println("<h2>Primary Key:<br>");
            for(int i = 0; i < noOfColumns; i++)
                out.println("<input type='radio' name='pKey' value='column" + (i + 1) + "'>Column " + (i + 1));
            out.println("</h2><br><input type='submit' value='Submit'>");
            out.println("</form>");
            out.println("</body>");
            out.println("</html>");
        } finally {
            out.close();
        }
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
