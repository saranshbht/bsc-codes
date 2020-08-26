#include<iostream>
using namespace std;

template<typename T>
class stack{
	T *arr;
	int size;
	int top;
	public:
		stack(int s = 0){
			size = s;
			top = -1;
			arr = new T[size];
		}
		
		bool isEmpty(){
			return top == -1;
		}
		
		bool isFull(){
			return top == size - 1;
		}
		
		void push(T a){
			if(isFull())
				throw "Stack Overflow!!!";
			arr[++top] = a;
		}
		
		T pop(){
			if(isEmpty())
				throw "Stack Underflow!!!";
			return arr[top--];
		}
		
		void display(){
			if(top == -1)
				cout << "Stack is Empty!!!";
			for(int i = 0; i <= top; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
		
		T stackTop(){
			if(top == -1)
				throw "Stack Empty!!!";
			return arr[top];
		}
		
		~stack(){
			delete[] arr;
		}
};

/*int main(){
	int size;
	cout << "Enter size of stack: ";
	cin >> size;
	stack<char> s(size);
	int choice;
	bool flag = true;
	char elem;
	while(true){
		cout << "\n1.Push\n2.Pop\n3.Stack Top\n4.Is Empty\n5.Is Full\n6.Display\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cout << "Enter element to be added: ";
					cin >> elem;
					s.push(elem);
					break;
			
			case 2: cout << "Element popped: " << s.pop() << endl;
					break;
					
			case 3: cout << s.stackTop() << endl;
					break;
			
			case 4: if(s.isEmpty())
						cout << "Yes";
					else
						cout << "No";
					cout << endl;
					break;
					
			case 5: if(s.isFull())
						cout << "Yes";
					else
						cout << "No";
					cout << endl;
					break;
					
			case 6: s.display();
					break;
				
			case 0: flag = false;
			
			default: cout << "Wrong choice!!!" << endl;
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
*/
