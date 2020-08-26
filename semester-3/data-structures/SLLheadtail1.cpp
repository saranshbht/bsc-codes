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
	node<T> *tail;
	public:
		static int size;
		SLL(){
			head = NULL;
			tail = NULL;
		}
		
		void addToTail(int);
		
		void addToHead(int);
		
		void addAtPos(int, T);
		
		void display();
};

template<typename T>int SLL<T> :: size = 0;
template<typename T>
void SLL<T> ::  addToTail(int data){
					node<T> *temp = new node<T>(data);
					size++;
					if(head == NULL){
						head = temp;
						tail = temp;
					}
					else{
						tail -> next = temp;
						tail = temp;
					}
				}

template<typename T>			
void SLL<T> ::  addToHead(int data){
					node<T> *temp = new node<T>(data);
					size++;
					if(head == NULL){
						head = temp;
						tail = temp;
					}
					else{
						temp -> next = head;
						head = temp;
					}
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
						while(index != pos - 1 && p != tail){
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
						while(p != tail){
							cout << p -> data << " -> ";
							p = p -> next;
						}
						cout << p -> data << "\n";
					}
				}
		
int main(){
	SLL<int> sll;
	int choice;
	bool flag = true;
	int elem;
	while(true){
		cout << "\n1.Add to Head\n2.Add to Tail\n3.Add at Position\n4.Display Size of Linked List\n5.Display Linked List\n0.Exit\n\n";
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
			
			case 3: int pos;
					cout << "Enter position where element is to be added: ";
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
				
			case 0: flag = false;
		}
		if(!flag)
			break;
	}
	return 0;
}
