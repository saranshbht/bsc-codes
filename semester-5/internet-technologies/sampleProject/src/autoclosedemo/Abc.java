/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package autoclosedemo;

/**
 *
 * @author c3
 */
public class Abc implements AutoCloseable{
    public Abc(){
        System.out.println("Creating Abc");
    }

    @Override
    public void close() throws Exception {
        System.out.println("Closing Abc"); //To change body of generated methods, choose Tools | Templates.
        
    }
}
