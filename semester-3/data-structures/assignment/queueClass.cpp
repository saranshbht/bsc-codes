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
			if(sll.getHead() == NULL)
				cout << "Queue Empty!!!";
			else
				sll.display();
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
