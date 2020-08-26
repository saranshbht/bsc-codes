#include "stack.cpp"

string inToPre(string exp){
	stack<char> s(exp.size());
	string pre = "";
	for(int i = exp.size() - 1; i > -1; i--){
		switch(exp[i]){
			case '+':	
			case '-':	while(!s.isEmpty() && s.stackTop() != ')' && s.stackTop() != '+' && s.stackTop() != '-')
								pre = s.pop() + pre;
						s.push(exp[i]);
						break;
						
			case '*':	
			case '/':	while(!s.isEmpty() && s.stackTop() != ')' && s.stackTop() == '^')
							pre = s.pop() + pre;
						s.push(exp[i]);
						break;
						
			case '^':	
			case ')':	s.push(exp[i]);
						break;
						
			case '(':	while(s.stackTop() != ')')
							pre = s.pop() + pre;
						s.pop();
						break;
						
			default:	pre = exp[i] + pre;
		}
	}
	while(!s.isEmpty())
		pre = s.pop() + pre;
	
	return pre;
}

int main(){
	string exp;
	cout << "Enter infix expression to be converted: ";
	cin >> exp;
	try{
		cout << inToPre(exp);
	}
	catch(const char *s){
		cout << "Invalid Expression";
	}
	cout << endl;

	return 0;
}