#pragma once
#include<iostream>
using namespace std;

//template for a node of Linked List
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

//template for Linked List
template<typename T>
class SLL{
	protected:
		node<T> *head;
		node<T> *tail;
	
	public:
		static int size;
		SLL(){
			head = NULL;
			tail = NULL;
		}
		
		~SLL();
		
		node<T> *getHead(){
			return head;
		}
		
		node<T> *getTail(){
			return tail;
		}
		
		void addToTail(T);
		
		void addToHead(T);
		
		void addAtPos(int, T);
		
		void display();
		
		void reverse();
		
		T removeFromHead();
		
		T removeFromTail();
		
		void removeAtPos(int);
		
	  void removeHavingValue(T);
};

template<typename T>int SLL<T> :: size = 0;

//destructor
template<typename T>
SLL<T> :: ~SLL(){
	while(head != NULL)
		removeFromHead();
}

//member function to add an element at the end of Linked List
template<typename T>
void SLL<T> ::  addToTail(T data){
	node<T> *temp = new node<T>(data);
	size++;
	if(head == NULL)
		head = tail = temp;
	else{
		tail -> next = temp;
		tail = temp;
	}
}

//member function to add an element at the front of Linked List
template<typename T>			
void SLL<T> ::  addToHead(T data){
	node<T> *temp = new node<T>(data);
	size++;
	if(head == NULL){
		head = tail = temp;
	}
	else{
		temp -> next = head;
		head = temp;
	}
}

//member function to add an element at the specified position in the Linked List			
template<typename T>
void SLL<T> ::  addAtPos(int pos, T data){
	node<T> *temp = new node<T>(data);
	if(pos == 1)
		addToHead(data);
	else if(pos == size)
		addToTail(data);
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

//member function to display the Linked List	
template<typename T>
void SLL<T> :: display(){
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

//member function to delete all elements having the specified value from the Linked List				
template<typename T>
void SLL<T> :: removeHavingValue(T x){
	if(head == NULL)
		throw "Deletion not possible as Linked List is empty";
	if(head -> data == x)
		removeFromHead();
	else if(tail -> data == x)
		removeFromTail();
	else{
		node<T> *temp = head -> next;
		node<T> *prev = head;
		while(temp != NULL && temp -> data != x){
			prev = temp;
			temp = temp -> next;
		}
		if(temp == NULL)
			throw "Element not present!!!";
		else{
			prev -> next = temp -> next;
			delete temp;
		}
	}
	size--;
}

//member function to remove element at the specified position from the Linked List		
template<typename T>
void SLL<T> :: removeAtPos(int pos){
	if(pos < 1 || pos > size)
		throw "Invalid Position";
	
	node<T> *temp = head;
	if(pos == 1)
		removeFromHead();
	else if(pos == size)
		removeFromTail();
	else{
		int index = 1;
		while(index != pos - 1){
			temp = temp -> next;
			index++;
		}
		node<T> *p = temp -> next;
		temp -> next = p -> next;
		delete p;
		size--;
	}
}

//member function to remove an element from the front of the Linked List
template<typename T>
T SLL<T> :: removeFromHead(){
	if(head == NULL)
		throw "Deletion not Possible as Linked List is empty.";
	T temp = head -> data;
	if(head == tail){
		delete head;
		head = tail = NULL;
	}
	else{
		node<T> *temp = head;
		head = head -> next;
		delete temp;
	}
	size--;
	return temp;
}

// member function to remove an element from the end of the Linked List
template<typename T>
T SLL<T> :: removeFromTail(){
	if(head == NULL)
		throw "Deletion not Possible as Linked List is empty.";
	T temp = tail -> data;
	if(head == tail){
		delete head;
		head = tail = NULL;
	}
	
	else{
		node<T> *temp = head;
		while(temp -> next != tail)
			temp = temp -> next;
		
		temp -> next = NULL;
		delete tail;
		tail = temp;
	}
	size--;
	return temp;
}

//member function to reverse the Linked List
template<typename T>
void SLL<T> :: reverse(){
	if(head == NULL || head == tail)
		return;
	node<T> *p1 = head;
	node<T> *p2 = p1 -> next;
	node<T> *p3 = p2 -> next;
	
	while(p3 != NULL){
		p2 -> next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3 -> next;
	}
	
	//cout << tail == p2;
	p2 -> next = p1;
	head -> next = NULL;
	node<T> *temp = tail;
	tail = head;
	head = temp;
}

