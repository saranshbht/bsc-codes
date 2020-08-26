#include "SLLClass.cpp"

template<typename T>
class Queue{
	SLL<T> sll;
	public:
		
		bool isEmpty(){
			return sll.getHead() == NULL;
		}

		void enqueue(T x){
			sll.addToTail(x);
		}

		T dequeue(){
			return sll.removeFromHead();
		}

		void display(){
			node<T> *temp = sll.getHead();
			if(temp == NULL)
				cout << "Queue Empty!!!";
			else{
				while(temp){
					cout << temp -> data << " ";
					temp = temp -> next;
				}
			}
			cout << endl;
		}
		
		T front(){
			node<T> *temp = sll.getHead();	
			if(temp == NULL)
				throw "Queue Empty!!!";
			else
				return temp -> data;
		}
		
		T back(){
			node<T> *temp = sll.getTail();
			if(temp == NULL)
					throw "Queue Empty!!!";
			else
				return temp -> data;
		}		
};
				

