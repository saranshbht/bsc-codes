/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bankaccount;

/**
 *
 * @author saransh
 */
public class BankAccount {

    /**
     * @param args the command line arguments
     */
    private int accNo; 
    private float balance;
    public BankAccount(int accNo, float balance){
        this.accNo = accNo;
        this.balance = balance;
    }
    
    public float deposit(float x) throws Exception{
        if(x < 0)
            throw new Exception("Deposit amount cannot be negative");
        balance += x;
        return balance;
    }
    
    public float withdraw(float x) throws Exception{
        if(x < 0)
            throw new Exception("Negative amount cannot be withdrawn");
        if(x > balance) 
            throw new Exception("Insufficient Balance");
        balance -= x;
        return balance;
    }
    
    public int getAccNo(){
        return accNo;
    }
    
    public float getBalance(){
        return balance;
    }
    
    public float taxDeduction(float x) throws Exception{
        if(x < 0)
            throw new Exception("Negative tax amount cannot be deducted");
        if(x > balance) 
            throw new Exception("Insufficient Balance");
        balance -= x;
        return balance;
    }
}
