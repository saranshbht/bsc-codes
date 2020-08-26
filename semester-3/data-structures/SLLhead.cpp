#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int d = 0){
			data = d;
			next = NULL;
		}
};

class SLL{
	node *head;
	
	public:
		SLL(){
			head = NULL;
		}
		
		void addToTail(int);
		
		void addToHead(int);
		
		void addAtPos(int, int);
			
		int size();
		
		void display();
};

//template<typename T>
void SLL ::  addToTail(int data){
					node *temp = new node(data);
					if(head == NULL)
						head = temp;
					
					else{
						node *p = head;
						while(p -> next != NULL)
							p = p -> next;
						p -> next = temp;
					}
				}

//template<typename T>			
void SLL ::  addToHead(int data){
					node *temp = new node(data);
					temp -> next = head;
					head = temp;
				}
			
//template<typename T>
void SLL ::  addAtPos(int pos, int data){
					node *temp = new node(data);
					if(head == NULL){
						head = temp;
					}
					else{
						int index = 1;
						node *p = head;
						while(index != pos - 1 && p -> next != NULL){
							p = p -> next;
							index++;
						}
						temp -> next = p -> next;
						p -> next = temp;
					}
			 }
			
//template<typename T>
int SLL ::   size(){
					int count = 0;
					node *p = head;
					while(p != NULL){
						count++;
						p = p -> next;
					}
					return count;
				}
			
//template<typename T>
void SLL :: 	display(){
					if(head == NULL){
						cout << "Linked List is empty\n";
					}
					else{
						node *p = head;
						while(p -> next != NULL){
							cout << p -> data << " -> ";
							p = p -> next;
						}
						cout << p -> data << "\n";
					}
				}
		
int main(){
	SLL sll;
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
					if(pos < 1){
						cout << "Invalid Position\n";
						break;	
					}
					cout << "Enter element to be added: ";
					cin >> elem;
					sll.addAtPos(pos, elem);
					break;
			
			case 4: cout << "Linked List has " << sll.size() << " element(s)\n";
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
