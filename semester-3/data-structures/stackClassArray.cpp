#include<iostream>
using namespace std;

template<typename T>
class stack{
    T *arr;
    int size;
    int top;
    public:
        stack(int s = 0){
            size = s;
            top = -1;
            arr = new T[size];
        }
        
        bool isEmpty(){
            return top == -1;
        }
        
        bool isFull(){
            return top == size - 1;
        }
        
        void push(T a){
            if(isFull())
                throw "Stack Overflow!!!";
            arr[++top] = a;
        }
        
        T pop(){
            if(isEmpty())
                throw "Stack Underflow!!!";
            return arr[top--];
        }
        
        void display(){
            if(top == -1)
                cout << "Stack is Empty!!!";
            for(int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        
        T stackTop(){
            if(top == -1)
                throw "Stack Empty!!!";
            return arr[top];
        }
        
        void clear(){
            top = -1;
        }
        
        ~stack(){
            delete[] arr;
        }
};
