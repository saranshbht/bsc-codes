#include "SLLClass.cpp"

//sortEvenOdd() definition in SLLClass.cpp

/*
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
*/

int main(){
	SLL<int> sll;
	int a;
	cout << "Enter values(Enter a non-numeric value(char/string) to stop inputting values)\n";
	while(1){
		cin >> a;
		if(cin.fail())
			break;
		sll.addToTail(a);
	}

	cout << "\nList before sorting\n";
	sll.display();
	sll.sortEvenOdd();

	cout << "\nList after sorting\n";
	sll.display();

	return 0;
}

