#include "queue.cpp"
#define addToRear enqueue
#define deleteFromFront dequeue
template<typename T>
class Deque : private Queue<T>{
	public:
		using Queue<T> :: addToRear;
		using Queue<T> :: deleteFromFront;
		using Queue<T> :: display;
		
		Deque(int s = 0) : Queue<T>(s){}
		void addToFront(T x){
			if(this -> isFull())
				throw "Queue Overflow!!!";
			if(this -> isEmpty())
				this -> front = this -> rear = 0;
			else{
				if(this -> front == 0)
					this -> front = this -> size - 1;
				else
					this -> front--;
			}
			this -> q[this -> front] = x;
				
		}
		
		T deleteFromRear(){
			if(this -> isEmpty())
				throw "Queue Underflow!!!";
			T temp = this -> q[this -> rear];
			if(this -> front == this -> rear)
				this -> front = this -> rear = -1;
			else{
				if(this -> rear == 0)
					this -> rear = this -> size - 1;
				else
					this -> rear--;
			}
			return temp;
		}
};

int main(){
	int size;
	cout << "Enter size of Deque: ";
	cin >> size;
	Deque<int> deque(size);
	int choice;
	bool flag = true;
	int elem;
	while(true){
		cout << "\n1.Add To Front\n2.Add To Rear\n3.Delete From Front\n4.Delete From Rear\n5.Display\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cout << "Enter element to be added: ";
					cin >> elem;
					deque.addToFront(elem);
					break;
			
			case 2: cout << "Enter element to be added: ";
					cin >> elem;
					deque.addToRear(elem);
					break;
					
			case 3: cout << "Element removed: " << deque.deleteFromFront() << endl;
					break;
					
			case 4: cout << "Element removed: " << deque.deleteFromRear() << endl;
					break;
				
			case 5: deque.display();
					break;
									
			case 0: flag = false;
					break;
			
			default: cout << "Wrong choice" << endl;
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


