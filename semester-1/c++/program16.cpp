//Write a menu-driven program to perform the following operations on string:
/*1)Show address of each character of string
  2)Concatenate two strings without using strcat function
  3)Concatenate two strings using strcat function
  4)Compare two strings
  5)Calculate length of the string(use pointers)
  6)Convert all lowercase characters to uppercase
  7)Convert all uppercase characters to lowercase
  8)Calculate number of vowels
  9)Reverse the string*/
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

void address() {
	char *s = new char[20]();
	cout << "Enter a string:";
	cin.ignore();
	cin.getline(s, 20);
	cout << endl << "String:" << s;
	cout << endl << "Address of each character of the string:";
	for (int i = 0; i < strlen(s); i++) {
		cout << endl << s[i] << "=>" << (void*)&s[i];
	}
	delete[] s;
}
void concat() {
	char *s = new char[20]();
	cout << "Enter first string:";
	cin.ignore();
	cin.getline(s, 20);
	char *str = new char[20]();
	char *concatString = new char[20]();
	cout << endl << "Enter second string:";
	cin.getline(str, 20);
	int i = 0;
	while (s[i] != 0) {
		concatString[i] = s[i];
		i++;
	}
	int j = i; i = 0;
	while (str[i] != 0) {
		concatString[j] = str[i];
		i++;
		j++;
	}
	cout << endl << "Concatenation of strings:" << concatString;
	delete[] s; delete[] str; delete[] concatString;
}
void concat_strcat() {
	char *s = new char[20]();
	cout << "Enter first string:";
	cin.ignore();
	cin.getline(s, 20);
	char *str = new char[20]();
	cout << endl << "Enter second string:";
	cin.getline(str, 20);
	cout << endl << "Concatenation of strings:" << strcat(s, str);
	delete[] s;
}
void compare() {
	char *s = new char[20]();
	cout << "Enter first string:";
	cin.ignore();
	cin.getline(s, 20);
	char *str = new char[20]();
	cout << endl << "Enter second string:";
	cin.getline(str, 20);
	if (strcmp(s, str) == 0) {
		cout << endl << "Strings are equal";
	} else {
		cout << endl << "Strings are not equal";
	}
	delete[] s; delete[] str;
}
void str_length() {
	char *s = new char[20]();
	cout << "Enter a string:";
	cin.ignore();
	cin.getline(s, 20);
	cout << endl << "String:" << s;
	int count = 0;
	int i = 0;
	while (s[i] != '\0') {
		count++;
		i++;
	}
	cout << endl << "Length of string:" << count;
	delete[] s;
}
void lower_case() {
	char *s = new char[20]();
	cout << "Enter a string:";
	cin.ignore();
	cin.getline(s, 20);

	cout << endl << "Original String:" << s;
	cout << endl << "New String:";
	int i = 0;
	while (s[i] != '\0') {
		cout << (char)tolower(s[i]);
		i++;
	}
	delete[] s;
}
void upper_case() {
	char *s = new char[20]();
	cout << "Enter a string:";
	cin.ignore();
	cin.getline(s, 20);

	cout << endl << "Original String:" << s;
	cout << endl << "New String:";
	int i = 0;
	while (s[i] != '\0') {
		cout << (char)toupper(s[i]);
		i++;
	}
	delete[] s;
}
void count_vowels() {
	char *s = new char[20]();
	cout << "Enter a string:";
	cin.ignore();
	cin.getline(s, 20);
	cout << endl << "String:" << s;
	int count = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
			count++;
		}
	}
	cout << endl << "Number of vowels:" << count;
	delete[] s;
}

void rev_string() {
	char *s = new char[20]();
	cout << "Enter a string:";
	cin.ignore();
	cin.getline(s, 20);
	cout << endl << "Original String:" << s;
	int j = strlen(s) - 1;
	for (int i = 0; i < strlen(s) / 2; i++) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		j--;
	}
	cout << endl << "New String:" << s;
	delete[] s;
}
int main() {

	int choice;
	do {
		cout << endl << "M E N U";
		cout << endl << "1)Show address of each character of string\n2)Concatenate two strings without using strcat function\n3)Concatenate two strings using strcat function\n4)Compare two strings\n5)Calculate length of the string\n6)Convert all lowercase characters to uppercase\n7)Convert all uppercase characters to lowercase\n8)Calculate number of vowels\n9)Reverse the string\n0)Exit";
		cout << endl << "Enter your choice:";
		cin >> choice;


		switch (choice) {
			case 1: address();
				break;
			case 2: concat();
				break;
			case 3: concat_strcat();
				break;
			case 4: compare();
				break;
			case 5: str_length();
				break;
			case 6: upper_case();
				break;
			case 7: lower_case();
				break;
			case 8: count_vowels();
				break;
			case 9: rev_string();
				break;
			case 0: break;

		}
	} while (choice != 0);
	return 0;
}
