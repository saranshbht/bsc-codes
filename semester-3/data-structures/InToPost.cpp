#include "stack.cpp"

string inToPost(string exp){
	stack<char> s(exp.size());
	string post = "";
	for(int i = 0; i < exp.size(); i++){
		switch(exp[i]){
			case '+':	
			case '-':	while(!s.isEmpty() && s.stackTop() != '(')
								post += s.pop();
						s.push(exp[i]);
						break;
						
			case '*':	
			case '/':	while(!s.isEmpty() && s.stackTop() != '(' && s.stackTop() != '+' && s.stackTop() != '-')
							post += s.pop();
						s.push(exp[i]);
						break;
						
			case '^':	
			case '(':	s.push(exp[i]);
						break;
						
			case ')':	while(s.stackTop() != '(')
							post += s.pop();
						s.pop();
						break;
						
			default:	post += exp[i];
		}
	}
	while(!s.isEmpty())
		post += s.pop();
	
	return post;
}

int main(){
	string exp;
	cout << "Enter infix expression to be converted: ";
	cin >> exp;
	try{
		cout << inToPost(exp);
	}
	catch(const char *s){
		cout << "Invalid Expression";
	}
	cout << endl;

	return 0;
}