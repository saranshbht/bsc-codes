/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sampleproject;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author c3
 */
public class SampleProject {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        // TODO code application logic here
        Class.forName("com.mysql.jdbc.Driver");
        try(Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/sar4135", "root", "");
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery("Select * from student")){
            
            while (rs.next()) {
                System.out.print(rs.getInt(1) + " ");
                System.out.print(rs.getString("StudentName") + " ");
                System.out.println(rs.getString(3));
            }
        }
        catch(SQLException ex){
            System.out.println(ex.toString());
        }
        
    }
    
}
