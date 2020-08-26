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
class SLL{
	node<T> *head;
	public:
		static int size;
		SLL(){
			head = NULL;
		}
		
		void addToTail(T);
		
		void addToHead(T);
		
		void addAtPos(int, T);
		
		void display();
		
		void removeAtPos(int);
		
		void removeHavingValue(T);
};

template<typename T>int SLL<T> :: size = 0;

template<typename T>
void SLL<T> ::  addToTail(T data){
	node<T> *temp = new node<T>(data);
	size++;
	if(head == NULL)
		head = temp;
	else{
		node<T> *p = head;
		while(p -> next != NULL)
			p = p -> next;
		p -> next = temp;
	}
}

template<typename T>			
void SLL<T> ::  addToHead(T data){
	node<T> *temp = new node<T>(data);
	size++;
	temp -> next = head;
	head = temp;
}
			
template<typename T>
void SLL<T> ::  addAtPos(int pos, T data){
	node<T> *temp = new node<T>(data);
	if(pos == 1)
		addToHead(data);
	else{
		size++;
		int index = 1;
		node<T> *p = head;
		while(index != pos - 1){
			p = p -> next;
			index++;
		}
		temp -> next = p -> next;
		p -> next = temp;
	}
}
	
template<typename T>
void SLL<T> :: 	display(){
	if(head == NULL){
		cout << "Linked List is empty\n";
	}
	else{
		node<T> *p = head;
		while(p -> next != NULL){
			cout << p -> data << " -> ";
			p = p -> next;
		}
		cout << p -> data << "\n";
	}
}
				
template<typename T>
void SLL<T> :: removeHavingValue(T x){
	node<T> *temp = head;
	while(temp -> next != NULL){
		if(head -> data == x){
			head = head -> next;
			delete temp;
			temp = head;
			size--;
		}
		else if(temp -> next -> data == x){
				node<T> *p = temp -> next;
				temp -> next = p -> next;
				delete p;
				temp = temp -> next;
				size--;
			}
		else
			temp = temp -> next;
	}
}
		
template<typename T>
void SLL<T> :: removeAtPos(int pos){
	node<T> *temp = head;
	if(pos == 1){
		head = head -> next;
		delete temp;
	}
	else{
		int index = 1;
		while(index != pos - 1){
			temp = temp -> next;
			index++;
		}
		node<T> *p = temp -> next;
		temp -> next = p -> next;
		delete p;
	}
		size--;
}

int main(){
	SLL<int> sll;
	int choice;
	bool flag = true;
	int elem, pos;
	while(true){
		cout << "\n1.Add to Head\n2.Add to Tail\n3.Add at Position\n4.Display Size of Linked List\n5.Display Linked List\n6.Remove at Position\n7.Remove having Value\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch(choice){
		
			case 1: cout << "Enter element to be added: ";
					cin >> elem;
					sll.addToHead(elem);
					break;
			
			case 2: cout << "Enter element to be added: ";
					cin >> elem;
					sll.addToTail(elem);
					break;
			
			case 3: cout << "Enter position where element is to be added: ";
					cin >> pos;
					if(pos < 1 || pos > (sll.size)){
						cout << "Invalid Position\n";
						break;	
					}
					cout << "Enter element to be added: ";
					cin >> elem;
					sll.addAtPos(pos, elem);
					break;
			
			case 4: cout << "Linked List has " << sll.size << " element(s)\n";
					break;
					
			case 5: sll.display();
					break;
			
			case 6: cout << "Enter position where element is to be removed: ";
					cin >> pos;
					if(pos < 1 || pos > (sll.size)){
						cout << "Invalid Position\n";
						break;	
					}
					sll.removeAtPos(pos);
					break;
					
			case 7: cout << "Enter value to be deleted: ";
					cin >> elem;
					sll.removeHavingValue(elem);
					break;
					
			case 0: flag = false;
		}
		if(!flag)
			break;
	}
	return 0;
}
