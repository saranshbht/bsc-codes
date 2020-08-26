#pragma once
#include<iostream>
using namespace std;

//template for a node of Linked List
template<typename T>
class node{
	T data;
	node* next;
	public:
		node(T d = NULL){
			data = d;
			next = NULL;
		}
		template<typename U> friend class SLL;
		template<typename U> friend class Stack;
		template<typename U> friend class Queue;
};

//template for Linked List
template<typename T>
class SLL{
	protected:
  	node<T> *head;
        node<T> *tail;

  public:
    SLL(){
      head = NULL;
      tail = NULL;
    }
    node<T> *getHead(){ return head; }
    node<T> *getTail(){ return tail; }
    bool isEmpty(){ return head == NULL; }
    void addToTail(T);
    void addToHead(T);
    void display();
    T removeFromHead();
    T removeFromTail();
    void removeHavingValue(T);
    void sortEvenOdd();
};



template<typename T>
void SLL<T> :: addToTail(T data){
	node<T> *temp = new node<T>(data);
	if(head == NULL)
		head = tail = temp;
	else{
		tail -> next = temp;
	  tail = temp;
	}
}


template<typename T>
void SLL<T> :: addToHead(T data){
	node<T> *temp = new node<T>(data);
	if(head == NULL)
		head = tail = temp;
	else{
		temp -> next = head;
		head = temp;
	}
}


template<typename T>
void SLL<T> :: display(){
	if(head == NULL)
		cout << "List is empty\n";
	else{
		node<T> *p = head;
		while(p){
			cout << p -> data << "\n";
			p = p -> next;
		}
	}
}


template<typename T>
void SLL<T> :: removeHavingValue(T x){
	if(head == NULL)
		throw "Deletion not possible as Linked List is empty";
	if(head -> data == x)
		removeFromHead();
	else{
		node<T> *temp = head -> next;
		node<T> *prev = head;
		while(temp != NULL && temp -> data != x){
			prev = temp;
			temp = temp -> next;
		}
		if(temp == NULL)
			throw "Element not present!!!";
		if(temp == tail)
			removeFromTail();
		else{
			prev -> next = temp -> next;
			delete temp;
		}
	}
}


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
	return temp;
}


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
	return temp;
}


template<typename T>
void SLL<T> :: sortEvenOdd(){
	node<T> *e = NULL;
	node<T> *p = head;
	node<T> *prev = NULL;
	while(p){
		if(p -> data & 1){
			prev = p;
			p = p -> next;
		}
		else{
			if(e == prev){
				e = p;
				prev = p;
				p = p -> next;
				continue;
			}
			else if(!e){
				if(p == tail)
					tail = prev;
				prev -> next = p -> next;
				p -> next = head;
				head = p;
				e = head;
			}
			else{
				if(p == tail)
					tail = prev;
				prev -> next = p -> next;
				p -> next = e -> next;
				e -> next = p;
				e = p;
			}
			p = prev -> next;
		}
	}
}
