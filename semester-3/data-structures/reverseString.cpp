#include<iostream>
using namespace std;

string reverseStr(const string &str, int size){
	if(size == 1)
		return string(1, str[size - 1]);
	else
		return str[size - 1] + reverseStr(str, size - 1);
	
}

int main(){
	string str;
	cout << "Enter string to reverse: ";
	getline(cin, str);
	cout << reverseStr(str, str.size()) << endl;
	return 0;
}
