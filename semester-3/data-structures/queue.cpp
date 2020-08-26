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

/*int main(){
	int size;
	cout << "Enter size of Queue: ";
	cin >> size;
	Queue<int> queue(size);
	int choice;
	bool flag = true;
	int elem;
	while(true){
		cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cout << "Enter element to be added: ";
					cin >> elem;
					queue.enqueue(elem);
					break;
			
			case 2: cout << "Element removed: " << queue.dequeue() << endl;
					break;
				
			case 3: queue.display();
					break;
									
			case 0: flag = false;
					break;
			
			default: cout << "Wrong choice" << endl;
		}
		if(!flag)
			break;
	}
	catch(const char *s){
		cout << s << endl;
	}
	}
	return 0;
}*/
