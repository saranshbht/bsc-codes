#include<iostream>
using namespace std;

template<typename T>
class Queue{
    protected:
        int front, rear;
        int size;
        T *q;
    
    public:
        Queue(int s = 0){
            size = s;
            q = new T[size];
            front = rear = -1;
        }
        
        bool isFull(){
            return (rear + 1) % size == front;
        }
        
        bool isEmpty(){
            return front == -1;
        }
        
        void enqueue(T x){
            if(isFull())
                throw "Queue Overflow!!!";
            if(isEmpty())
                front = rear = 0;
            else
                rear = (rear + 1) % size;
            q[rear] = x;
        }
        
        T dequeue(){
            if(isEmpty())
                throw "Queue Underflow!!!";
            T temp = q[front];
            if(front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
            return temp;
        }
        
        void display(){
            if(isEmpty())
                cout << "Queue Empty!!!";
            else{
                int i = front;
                while(i != rear){
                    cout << q[i] << " ";
                    i = (i + 1) % size;
                }
                cout << q[rear];
            }
            cout << endl;    
        }
        
        ~Queue(){
            delete[] q;
        }
};

