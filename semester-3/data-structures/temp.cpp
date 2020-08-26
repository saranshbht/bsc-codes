#include "SLLheadtail.cpp"

template<typename T>
class SSLL : private SLL<T> {
		/*node<T> *head;
		node<T> *tail;*/
	public:
		/*SSLL(){
			head = NULL;
			tail = NULL;
		}
		*/
		using SLL<T> :: display;
		using SLL<T> :: reverse;
		using SLL<T> :: removeFromHead;
		using SLL<T> :: removeFromTail;
		using SLL<T> :: removeAtPos;
		using SLL<T> :: removeHavingValue;

		void insert(T);
};

template<typename T>
void SSLL<T> :: insert(T x) {
	node<T> *temp = new node<T>(x);
	if (this -> head == NULL) {
		this -> addToHead(x);
	}

	else if (this -> head -> data >= x) {
		this -> addToHead(x);
	}

	else if (this -> tail -> data <= x) {
		this -> tail -> next = temp;
		this -> tail = temp;
	}

	else {
		node<T> *p = this -> head;
		while (p -> next -> data < x) {
			p = p -> next;
		}

		temp -> next = p -> next;
		p -> next = temp;
	}
	this -> size++;
}

int main() {
	try {
		SSLL<int> ll;
		//ll.display();
		ll.insert(1);
		ll.insert(4);
		ll.insert(50);
		ll.insert(5);
		ll.insert(2);
		ll.insert(20);
		ll.insert(15);
		ll.display();
		ll.reverse();
		ll.display();
		ll.removeFromHead();
		ll.display();
		ll.removeFromTail();
		ll.display();
		ll.removeAtPos(2);
		ll.display();
		ll.removeHavingValue(5);
		ll.display();
	} catch (const char *s) {
		cout << s << endl;
	}
	return 0;
}


