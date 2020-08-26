//Write a function that checks whether a string is palindrome or not. Use this function to find whether the string entered by th user is palindrome or not.
#include<iostream>
#include<cstring>
using namespace std;
bool checkPalindrome(char *s) {
	int j = strlen(s) - 1;
	for (int i = 0; i < (strlen(s) / 2);)\
	{
		if (s[i++] != s[j--]) {
			return false;
		}
	}
	return true;
}
int main() {
	int j = 10;
	char a[j] = {'\0'};
	cout << "Enter a string:";
	cin.getline(a, j);
	if (checkPalindrome(a)) {
		cout << endl << "The string is a palindrome" << endl;
	} else {
		cout << endl << "The string is not a palindrome" << endl;
	}
	return 0;
}
