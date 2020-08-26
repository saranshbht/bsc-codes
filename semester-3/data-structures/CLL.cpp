#include<iostream>
using namespace std;

template<typename T>
class node{
	public:
		T data;
		node* next;
		node(T d = NULL){
			data = d;
			next = NULL;
		}
};

template<typename T>
class CLL{
	node<T> *tail;
	public:
		CLL(){
			tail = NULL;
		}
		
		void addToTail(T);
		
		void addToHead(T);
		
		//void addAtPos(int, T);
		
		T removeFromHead();
		
		T removeFromTail();
		
		void display();
		
		void JosephsGame(int);
};

template<typename T>
void CLL<T> :: addToTail(T x){
	node<T> *temp = new node<T>(x);
	if(tail == NULL){
		tail = temp;
		tail -> next = tail;
	}
	else{
		temp -> next = tail -> next;
		tail -> next = temp;
		tail = temp;
	}
}

template<typename T>
void CLL<T> :: addToHead(T x){
	node<T> *temp = new node<T>(x);
	if(tail == NULL){
		tail = temp;
		tail -> next = tail;
	}
	else{
		temp -> next = tail -> next;
		tail -> next = temp;
	}
}

template<typename T>
T CLL<T> :: removeFromHead(){
	if(tail == NULL)
		throw "Linked List is empty";
	if(tail -> next == tail){
		delete tail;
		tail = NULL;
	}
	else{
		node<T> *temp = tail -> next;
		tail -> next = temp -> next;
		T x = temp -> data;
		delete temp;
		return x;
	}
}

template<typename T>
T CLL<T> :: removeFromTail(){
	if(tail == NULL)
		throw "Linked List is empty";
	T x;
	if(tail -> next == tail){
		x = tail -> data;
		delete tail;
		tail = NULL;
	}
	else{
		node<T> *temp = tail -> next;
		while(temp -> next != tail){
			temp = temp -> next;
		}
		node<T> *p = tail;
		temp -> next = tail -> next;
		x = tail -> data;
		delete tail;
		tail = temp;
	}
	return x;
}

template<typename T>
void CLL<T> :: display(){
	if(tail == NULL)
		cout << "Linked List is Empty" << endl;
	else{
		node<T> *temp = tail -> next;
		while(temp != tail){
			cout << temp -> data << " -> ";
			temp = temp -> next;
		}
		cout << temp -> data << endl;
	}
}

template<typename T>
void CLL<T> :: JosephsGame(int n){
	if(tail == NULL)
		throw "List Empty!!!";
	if(tail -> next == tail)
		cout << "Last element: " << tail -> data;
	else{
		cout << tail -> data << endl;
		int count;
		node<T> *prev = tail;
		node<T> *temp = tail -> next;
		while(tail -> next != tail){
			count = 1;
			while(count != n){
				prev = temp;
				temp = temp -> next;
				count++;
			}
			prev -> next = temp -> next;
			cout << temp -> data << " ";
			if(temp == tail)
				tail = tail -> next;
			delete temp;
			temp = prev -> next;
			
		}
		cout << endl << "Last element: " << tail -> data;
	}
	cout << endl;
}

int main(){
	CLL<int> cll;
	int choice;
	bool flag = true;
	int elem;
	while(true){
		cout << "\n1.Add to Head\n2.Add to Tail\n3.Display Linked List\n4.Remove from Head\n5.Remove from Tail\n6.Joseph's Game\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cout << "Enter element to be added: ";
					cin >> elem;
					cll.addToHead(elem);
					break;
			
			case 2: cout << "Enter element to be added: ";
					cin >> elem;
					cll.addToTail(elem);
					break;
					
			case 3: cll.display();
					break;
			
			case 4: cout << "Element removed: " << cll.removeFromHead() << endl;
					break;
					
			case 5: cout << "Element removed: " << cll.removeFromTail() << endl;
					break;
					
			case 6: cout << "Enter key: ";
					int key;
					cin >> key;
					cll.JosephsGame(elem);
					break;
	
			case 0: flag = false;
			
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
