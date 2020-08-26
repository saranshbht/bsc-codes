#include "stack.cpp"
#include<iostream>
#include<string>
using namespace std;

bool isExprValid(string s){
	stack<char> stk(s.size());
	bool flag = true;
	for(int i = 0; i < s.size(); i++){
		switch(s[i]){
			case '(':
			case '{':
			case '[': 	stk.push(s[i]);
						break;
			
			case ')': 	if(stk.isEmpty() || stk.pop() != '(')
							flag = false;
						break;
			
			case '}': 	if(stk.isEmpty() || stk.pop() != '{')
							flag = false;
						break;
			
			case ']': 	if(stk.isEmpty() || stk.pop() != '[')
							flag = false;
							break;
			
			default: flag = false;
		}
		if(!flag)
			break;
	}
	if(!stk.isEmpty())
		flag = false;
	return flag;
}

int main(){
	string s;
	cout << "Enter the expression: ";
	cin >> s;
	if(isExprValid(s))
		cout << "Valid Expression";
	else
		cout << "Invalid Expression";
	cout << endl;
	return 0;
}
