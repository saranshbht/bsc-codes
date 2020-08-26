#include<iostream>
using namespace std;

template<typename T>
class node{
	public:
		T data;
		int pri;
		node* next;
		node(T d = NULL, int p = 0){
			data = d;
			pri = p;
			next = NULL;
		}
};

template<typename T>
class PriorityQueue{
	protected:
		node<T> *front;
		node<T> *rear;
	
	public:
		PriorityQueue(){
			front = NULL;
			rear = NULL;
		}
		
		~PriorityQueue();
		
		node<T> enqueue(T, int);
		
		void display();
		
		node<T>* extractMinPri();
		
		node<T>* extractMaxPri();
		
		node<T>* getMinPri();
		
		node<T>* getMaxPri();
};

template<typename T>
PriorityQueue<T> :: ~PriorityQueue(){
	while(front != NULL)
		extractMinPri();
}

template<typename T>
void PriorityQueue<T> :: display(){
	if(front == NULL){
		cout << "Linked List is empty\n";
	}
	else{
		node<T> *p = front;
		while(p != rear){
			cout << "Data: " << p -> data << " Priority: " << p -> pri << endl;
			p = p -> next;
		}
		cout << "Data: " << p -> data << " Priority: " << p -> pri << "\n\n";
	}
}

template<typename T>
node<T>* PriorityQueue<T> :: extractMinPri(){
	if(front == NULL)
		throw "No element present in Queue";
	node<T> *temp = front;
	node<T> *p = new node<T>(temp -> data, temp -> pri);
	if(front == rear)
		front = rear = NULL;
	else
		front = front -> next;
	delete temp;
	return p;
}

template<typename T>
node<T>* PriorityQueue<T> :: extractMaxPri(){
	if(front == NULL)
		throw "No element present in Queue";
	node<T> *temp = rear;
	node<T> *p = new node<T>(temp -> data, temp -> pri);
	if(front == rear)
		front = rear = NULL;
	
	else{
		node<T> *tmp = front;
		while(tmp -> next != rear)
			tmp = tmp -> next;
		
		tmp -> next = NULL;
		rear = tmp;
	}
	
	delete temp;
	return p;
}

template<typename T>
node<T>* PriorityQueue<T> :: getMaxPri(){
	return rear;
}

template<typename T>
node<T>* PriorityQueue<T> :: getMinPri(){
	return front;
}

template<typename T>
node<T> PriorityQueue<T> :: enqueue(T x, int pr){
	node<T> *temp = new node<T>(x, pr);
	if(front == NULL)
		front = rear = temp;
	
	else if(front -> pri >= pr){
		temp -> next = front;
		front = temp;
	}
			
	else if(rear -> pri <= pr){
		rear -> next = temp;
		rear = temp;
	}	
	
	else{
		node<T> *p = front;
		while(p -> next -> pri < pr)
			p = p -> next;
		
		temp -> next = p -> next;
		p -> next = temp;
	}
}

int main(){
	PriorityQueue<int> pqueue;
	int choice;
	bool flag = true;
	node<int> *p;
	int elem, pri;
	while(true){
		cout << "\n1.Enqueue\n2.Extract Minimum Priority Element\n3.Extract Maximum Priority Element\n4.Minimum Priority Element\n5.Maximum Priority Element\n6.Display\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cout << "Enter element to be added\n";
					cout << "Data: ";
					cin >> elem;
					cout << "Priority: ";
					cin >> pri;
					pqueue.enqueue(elem, pri);
					break;
			
			case 2: p = pqueue.extractMinPri();
					cout << "Element removed\n";
					cout << "Data: " << p -> data << " Priority: " << p -> pri << endl;
					break;
				
			case 3: p = pqueue.extractMaxPri();
					cout << "Element removed\n";
					cout << "Data: " << p -> data << " Priority: " << p -> pri << endl;
					break;
					
			case 4: p = pqueue.getMinPri();
					cout << "Data: " << p -> data << " Priority: " << p -> pri << endl;
					break;
					
			case 5: p = pqueue.getMaxPri();
					cout << "Data: " << p -> data << " Priority: " << p -> pri << endl;
					break;
					
			case 6: pqueue.display();
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
}
