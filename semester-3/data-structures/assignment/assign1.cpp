#include "SLLClass.cpp" 
#include "stackClass.cpp" 
#include "queueClass.cpp"
#define QQ "q2.enqueue(q1.dequeue())"
#define SQ "q2.enqueue(s.pop())"
#define QS "s.push(q1.dequeue())"

int main() {
    Queue<int> q1, q2;
    Stack<int> s;
    SLL<string> operations;
    int n, a, prev;
    cout << "Enter value of n: ";
    cin >> n;

    if(n < 0){
    	cout << "n cannot be negative\n";
    	return -1;
    }

    if(n == 0){
    		cout << "No operations\n";
    		return 0;
    }

    cout << "Enter any permutation of numbers from 1 to n:\n";
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a > n){
        	cout << "Values can only be between 1 and n(both inclusive)\n";
        	return -1;
        }
        q2.enqueue(a);
    }

		for(int i = 1; i <= n;i++)
			q1.enqueue(i);

    while(!q2.isEmpty()){
    	//cout << q2.front() << endl;
      if(!q1.isEmpty() && q2.front() == q1.front()){
      	operations.addToTail(QQ);
      	q1.dequeue();
      	prev = q2.dequeue();
      }

      else if(!s.isEmpty() && s.stackTop() == q2.front()){
      	operations.addToTail(SQ);
      	s.pop();
      	prev = q2.dequeue();
      }

      else{
      	if(!s.isEmpty() && q2.front() < s.stackTop())
      		break;

        else{
        	while(!q1.isEmpty() && q1.front() != q2.front()){
        		s.push(q1.dequeue());
        		operations.addToTail(QS);
        	}
        }
      }
    }

    if(!q2.isEmpty()){
        cout << "Invalid as after " << prev << " next value can only be ";
        if(!s.isEmpty() && !q1.isEmpty())
        	cout << s.stackTop() << " or " << q1.front();
        else if(!s. isEmpty())
        	cout << s.stackTop();
        else
        	cout << q1.front();
	cout << " for this case to be valid\n";
    }

    else{
    		cout << "Valid\nSequence of operations\n";
        operations.display();
    }

    return 0;
}

