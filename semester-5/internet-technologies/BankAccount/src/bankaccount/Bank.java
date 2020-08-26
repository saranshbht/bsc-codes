/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bankaccount;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

/**
 *
 * @author saransh
 */
public class Bank {
    private static ArrayList<BankAccount> bank;
    private static int count;
    public Bank(){
        bank = new ArrayList<BankAccount>();
    }
    
    public static void addAccount(BankAccount ba) throws Exception{
        if(ba.getAccNo() < 1)
            throw new Exception("Negative account numbers not allowed");
        if(ba.getBalance() < 0)
            throw new Exception("Can't add account with negative intital balance");
        int n = bank.size();
        for(int i = 0; i < n; i++)
            if(bank.get(i).getAccNo() == ba.getAccNo())
                throw new Exception("Account Number already exists");
        bank.add(ba);
    }
    
    public void updateList() throws ClassNotFoundException, SQLException{
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/bank", "root", "");
        Statement stmt = conn.createStatement();
        String query = "Select * from bank";
        ResultSet rs = stmt.executeQuery(query);
        while(rs.next()){
            bank.add(new BankAccount(rs.getInt(1), rs.getFloat(2)));
            count++;
        }
        rs.close();
        stmt.close();
        conn.close();
    }
    
    public void updateDb() throws ClassNotFoundException, SQLException{
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/sar4135", "root", "");
        PreparedStatement stmt = conn.prepareStatement("insert into bank values(?, ?)");
        int n = bank.size();
        for(int i = count; i < n; i++){
            stmt.setInt(1, bank.get(i).getAccNo());
            stmt.setFloat(2, bank.get(i).getBalance());
            stmt.executeUpdate();
        }
        stmt.close();
        conn.close();
    }
    
    public static float getTotalBalance(){
        float sum = 0.0f;
        int n = bank.size();
        for(int i = 0; i < n; i++)
            sum += bank.get(i).getBalance();
        return sum;
    }
    
    public static int getMaxBalanceAcc() throws Exception{
        int n = bank.size();
        if(n == 0)
            throw new Exception("No accounts in bank");
        int max = bank.get(0).getAccNo();
        float maxBal = bank.get(0).getBalance();
        for(int i = 1; i < n; i++)
            if(bank.get(i).getBalance() > maxBal){
                maxBal = bank.get(i).getBalance();
                max = bank.get(i).getAccNo();
            } 
        return max;
    }
    
    public static int getMinBalanceAcc() throws Exception{
        int n = bank.size();
        if(n == 0)
            throw new Exception("No accounts in bank");
        int min = bank.get(0).getAccNo();
        float minBal = bank.get(0).getBalance();
        for(int i = 1; i < n; i++)
            if(bank.get(i).getBalance() < minBal){
                minBal = bank.get(i).getBalance();
                min = bank.get(i).getAccNo();
            } 
        return min;
    }
    
    public static BankAccount findAccount(int accNo) throws Exception{
        int n = bank.size();
        for(int i = 0; i < n; i++)
            if(bank.get(i).getAccNo() == accNo)
                return bank.get(i);
        throw new Exception("No such account in bank");
    }
    
    public static int accsWithBal(float balance){
        int count = 0;
        int n = bank.size();
        for(int i = 0; i < n; i++)
            if(bank.get(i).getBalance() >= balance)
                count++;
        return count;
    }
}
