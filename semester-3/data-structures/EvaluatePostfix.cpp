#include "stack.cpp"
#include<string>
#include<cmath>

int evaluate(string exp){
	int a, b;
	stack<int> s((exp.size() + 1) / 2);
	for(int i = 0; i < exp.size(); i++){
		switch(exp[i]){
			case '+':	b = s.pop();
						a = s.pop();
						s.push(a + b);
						break;
						
			case '-':	b = s.pop();
						a = s.pop();
						s.push(a - b);
						break;
						
			case '*':	b = s.pop();
						a = s.pop();
						s.push(a * b);
						break;
							
			case '/':	b = s.pop();
						a = s.pop();
						s.push(a / b);
						break;
						
			case '^':	b = s.pop();
						a = s.pop();
						s.push((int)pow(a, b));
						break;
					
			default:	s.push(exp[i] - '0');
						break;
		}
	}
	a = s.pop();
	if(!s.isEmpty())
		throw "Invalid";
	return a;
}

int main(){
	string exp;
	cout << "Enter the postfix expression to be evaluated: ";
	cin >> exp;
	try{
		cout << evaluate(exp);
	}
	catch(const char *s){
		cout << "Invalid Expression";
	}
	cout << endl;
	return 0;
}