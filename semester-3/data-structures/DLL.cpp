#include<iostream>
using namespace std;

template<typename T>
class node{
	T data;
	node<T> *next;
	node<T> *prev;
	public:
		node(T d = NULL, node *p = NULL, node *n = NULL){
			data = d;
			prev = p;
			next = n;
		}
	template<typename U> friend class DLL;
};

template<typename T>
class DLL{
	node<T> *head;
	node<T> *tail;
	public:
		DLL(){
			head = NULL;
			tail = NULL;
		}
		
		void addToHead(T);
		
		void addToTail(T);
		
		//void addAtPos(int, T);
		
		void display();
		
		int removeFromHead();
		
		int removeFromTail();
		
		int removeByValue(T);
		
		void reverse();
};

template<typename T>
void DLL<T> :: addToHead(T x){
	node<T> *temp = new node<T>(x, NULL, head);
	if(head == NULL)
		head = tail = temp;
	else{
		head -> prev = temp;
		head = temp;
	}
}

template<typename T>
void DLL<T> :: addToTail(T x){
	node<T> *temp = new node<T>(x, tail, NULL);
	if(head == NULL)
		head = tail = temp;
	else{
		tail -> next = temp;
		tail = temp;
	}
}

template<typename T>
int DLL<T> :: removeFromHead(){
	if(head == NULL)
		throw "Linked List is empty";
	node<T> *temp = head;
	int x = head -> data;
	if(head == tail)
		head = tail = NULL;
	else{
		head = head -> next;
		head -> prev = NULL;
	}
	delete temp;
	return x;
}

template<typename T>
int DLL<T> :: removeFromTail(){
	if(head == NULL)
		throw "Linked List is empty";
	node<T> *temp = tail;
	int x = tail -> data;
	if(head == tail)
		head = tail = NULL;
	else{
		tail = tail -> prev;
		tail -> next = NULL;
	}
	delete temp;
	return x;
}

template<typename T>
int DLL<T> :: removeByValue(T x){
	if(head == NULL)
		throw "Linked List is empty";
	if(head -> data == x)
		removeFromHead();
	else{
		node<T> *temp = head -> next;
		int x;
		while(temp != NULL && temp -> data != x)
			temp = temp -> next;
		if(temp == NULL)
			throw "Element not found";
		if(temp == tail)
			removeFromTail();
		else{
			temp -> next -> prev = temp -> prev;
			temp -> prev -> next = temp -> next;
			x = temp -> data;
			delete temp;
			return x;
		}
	}
}

template<typename T>
void DLL<T> :: reverse(){
	node<T> *p = head;
	node<T> *q = tail;
	while(q -> next != p && q != p){
		T temp = p -> data;
		p -> data = q -> data;
		q -> data = temp;
		p = p -> next;
		q = q -> prev;
	}
}

template<typename T>
void DLL<T> :: display(){
	if(head == NULL)
		cout << "Linked List is empty";
	else{
		node<T> *temp = head;
		while(temp != tail){
			cout << temp -> data << " -> ";
			temp = temp -> next;
		}
		cout << temp -> data << endl;
	}
}

int main(){
	DLL<int> dll;
	int choice;
	bool flag = true;
	int elem;
	while(true){
		cout << "\n1.Add to Head\n2.Add to Tail\n3.Display Linked List\n4.Remove from Head\n5.Remove from Tail\n6.Remove having Value\n7.Reverse Linked List\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cout << "Enter element to be added: ";
					cin >> elem;
					dll.addToHead(elem);
					break;
			
			case 2: cout << "Enter element to be added: ";
					cin >> elem;
					dll.addToTail(elem);
					break;
					
			case 3: dll.display();
					break;
			
			case 4: cout << "Element removed: " << dll.removeFromHead() << endl;
					break;
					
			case 5: cout << "Element removed: " << dll.removeFromTail() << endl;
					break;
					
			case 6: cout << "Enter element to be removed: ";
					cin >> elem; 
					dll.removeByValue(elem);
					break;
					
			case 7: dll.reverse();
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
