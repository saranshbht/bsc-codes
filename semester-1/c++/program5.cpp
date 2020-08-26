//Write a function that checks whether a given string is Palindrome or not. Use this function
//to find whether the string entered by the user is Palindrome or not
#include<iostream>
#include<cstring>
using namespace std;

bool checkPalindrome(string s) {
	int i = s.length() - 1;
	for (int j = 0; j < (s.length() / 2); j++) {
		if (s[i--] != s[j]) {
			return false;
		}
	}
	return true;
}
int main() {

	string str;
	cout << "Enter a string:";
	getline(cin, str);
	if (checkPalindrome(str)) {
		cout << "The entered string is a Palindrome";
	} else {
		cout << "The entered string is not a Palindrome";
	}

	return 0;
}
