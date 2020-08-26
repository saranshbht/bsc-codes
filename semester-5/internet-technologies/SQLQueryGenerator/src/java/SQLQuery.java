/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
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
@WebServlet(urlPatterns = {"/SQLQuery"})
public class SQLQuery extends HttpServlet {

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
        PrintWriter out = response.getWriter();
        try {
            /* TODO output your page here. You may use following sample code. */
            ArrayList<String> arr = new ArrayList<String>();
            String query;
            Cookie[] cookies = request.getCookies();
            String tableName = cookies[0].getValue();
            int noOfColumns = Integer.parseInt(cookies[1].getValue());
            String pKey = request.getParameter("pKey");
            for(int i = 0; i < noOfColumns; i++){
                String name = request.getParameter("column" + (i + 1) + "name");
                String type = request.getParameter("column" + (i + 1) + "type");
                String length = request.getParameter("column" + (i + 1) + "length");
                query = name + " " + type + "(" + length + ")";
                if(pKey.equals("column" + (i + 1)))
                    query += " " + "primary key";
                arr.add(query);
            }
            int n = arr.size() - 1;
            query = "create table " + tableName + " (";
            for(int i = 0; i < n; i++){
                query += arr.get(i) + ", ";
            }
            query += arr.get(n) + ");";
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet SQLQuery</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>" + query + "</h1>");
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
