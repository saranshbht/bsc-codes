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
public class Demo {
    public static void main(String[] args) {
        try(Abc a = new Abc();
            Xyz x = new Xyz()){
            //Class.forName("Hi");
        }
        catch(Exception e){
            System.out.println("Exception Found");
        }
    }  
}
