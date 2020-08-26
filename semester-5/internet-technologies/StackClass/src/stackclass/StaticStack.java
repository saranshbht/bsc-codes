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
public class StaticStack extends AbstractStack {
    int stack[];
    int top;
    public StaticStack(){
        stack = new int[10];
        top = -1;
    }
    public void push(int elem){
        if(top == 9)
            System.out.println("Stack full!! No more elements can be inserted");
        else{
            stack[++top] = elem;
            System.out.println("Element inserted");
        }
    }
    public void pop(){
        if(top == -1){
            System.out.println("No element in stack!!");
        }
        else{
            System.out.println("Element popped : " + stack[top--]);
        }
    }
    public void display(){
        if(top == -1)
            System.out.println("No element in stack");
        else{
            for(int i = top; i >= 0; i--)
                System.out.println(stack[i]);
        }
    }
}
