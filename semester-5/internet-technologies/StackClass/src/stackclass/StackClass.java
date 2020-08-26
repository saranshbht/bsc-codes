/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stackclass;

/**
 *
 * @author c3
 */
public class StackClass {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        StaticStack ss = new StaticStack();
        for(int i = 0; i < 11; i++)
            ss.push(i);
        ss.pop();
        ss.display();
        
        DynamicStack ds = new DynamicStack();
        for(int i = 0; i < 15; i++)
            ds.push(i);
        ds.pop();
        ds.display();
        
    }
    
}
