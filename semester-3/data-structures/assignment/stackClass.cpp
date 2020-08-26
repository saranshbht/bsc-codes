#include "SLLClass.cpp" 
template<typename T>
class Stack{
	SLL<T> sll;
	public:
		bool isEmpty(){
			return sll.getHead() == NULL;
		}

		void push(T x){
			sll.addToHead(x);
		}
		
		T pop(){
			return sll.removeFromHead();
		}

		void display(){
			node<T> *temp = sll.getHead();
			if(temp == NULL)
				cout << "Stack Empty!!!";
			else
				sll.display();
		}	

		T stackTop(){
			node<T> *temp = sll.getHead();
			if(temp == NULL)
				throw "Stack Empty!!!";
			else
				return temp -> data;
		}
};
