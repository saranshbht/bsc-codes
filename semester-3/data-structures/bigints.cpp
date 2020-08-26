#include<iostream>
#include<string>
using namespace std;

class node{
	int data;
	node *next;
	node *prev;
	public:
		node(int d = 0, node *p = NULL, node *n = NULL){
			data = d;
			prev = p;
			next = n;
		}
	friend class LL;
};

class LL{
	node *head;
	node *tail;
	public:
		LL(){
			head = NULL;
			tail = NULL;
		}

		void display();
		
		void addToTail(int);
		
		void addToHead(int);
		
		LL operator+(const LL&);
		
		LL operator-(const LL&);
};

void LL :: display(){
	if(head == NULL)
		cout << "Linked List is empty";
	else{
		node *temp = head;
		while(temp != tail){
			cout << temp -> data;
			temp = temp -> next;
		}
		cout << temp -> data << endl;
	}
}

void DLL :: addToHead(int x){
	node *temp = new node(x, NULL, head);
	if(head == NULL)
		head = tail = temp;
	else{
		head -> prev = temp;
		head = temp;
	}
}

void DLL :: addToTail(int x){
	node *temp = new node(x, tail, NULL);
	if(head == NULL)
		head = tail = temp;
	else{
		tail -> next = temp;
		tail = temp;
	}
}

LL LL :: operator+(const LL & ll){
	LL temp;
	int carry = 0, t;
	node *p = tail;
	node *q = ll.tail;
	while(p != NULL && q != NULL){
		t = (p -> data + q -> data) % 9999;
		temp.addToHead(t + carry);
		carry = p -> data + q -> data - t;
		p = p -> prev;
		q = q -> prev;
	}
	
	while(p != NULL){
		t = p -> data;
		temp.addToHead(carry + t);
		carry  = 0;
		p = p -> prev;
	}
	
	while(q != NULL){
		t = q -> data;
		temp.addToHead(carry + t);
		carry  = 0;
		q = q -> prev;
	}
	
	return temp;
}

LL LL :: operator-(const LL & ll){
	LL temp;
	int carry = 0, t;
	node *p = tail;
	node *q = ll.tail;
	while(p != NULL && q != NULL){
		t = (p -> data + q -> data) % 9999;
		temp.addToHead(t + carry);
		carry = p -> data + q -> data - t;
		p = p -> prev;
		q = q -> prev;
	}
	
	while(p != NULL){
		t = p -> data;
		temp.addToHead(carry + t);
		carry  = 0;
		p = p -> prev;
	}
	
	while(q != NULL){
		t = q -> data;
		temp.addToHead(carry + t);
		carry  = 0;
		q = q -> prev;
	}
	
	return temp;
}

int main(){
	string s1, s2;
	cout << "Enter two numbers\n";
	cin >> s1;
	cin >> s2;
	LL l1, l2;
	int n = s1.size();
	int m = s2.size();
	int i = 0;
	while(i < n || i < m){
		string str1 = "", str2 = "";
		for(int j = i; j < i + 4; j++){
			if(j < n)
				str1 += s1[j];
			if(j < m)
				str2 += s2[j];
		}
		l1.addToTail(stoi(str1));
		l2.addToTail(stoi(str2));
		i += 4;
	}
	LL l3 = l1 + l2;
	LL l4 = l1 - l2;
}
