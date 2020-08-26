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
	node *tail;
	
	public:
		SLL(){
			head = NULL;
			tail = NULL;
		}
		
		void addToTail(int data){
			node *temp = new node(data);
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
		}
		
		void addToHead(int data){
			node *temp = new node(data);
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				temp -> next = head;
				head = temp;
			}
		}
		
		void addAtPos(int data, int pos){
			int index = 1;
			node *temp = new node(data);
			node *p = head;
			while(index != pos - 1 && p != tail){
				p = p -> next;
				index++;
			}
			temp -> next = p -> next;
			p -> next = temp;
		}
			
		int size(){
			int count = 0;
			node *p = head;
			while(p != NULL){
				count++;
				p = p -> next;
			}
			return count;
		}
		
		void display(){
			node *p = head;
			while(p != tail){
				cout << p -> data << "->";
				p = p -> next;
			}
			cout << p -> data << "\n"; 
		}
};

int main(){
	SLL sll;
	sll.addToHead(3);
	sll.display();
	sll.addToTail(5);
	sll.addToTail(6);
	sll.addToHead(9);
	sll.display();
	sll.addAtPos(7, 4);
	sll.display();
	cout << sll.size();
	
	return 0;
}