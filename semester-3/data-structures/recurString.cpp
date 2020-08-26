#include<iostream>
using namespace std;

bool isPresent(string& s, int size, char c){
	if(size == -1)
		return False;
	if(s[size - 1] == c)
		return True;
	return isPresent(s, size - 1, c);
}

int occurrences(string &s, int size, char c){
	if(size == -1)
		return 0;
	if(s[size - 1] == c)
		return 1 + occurrences(s, size - 1, c);
	else	
		return occurrences(s, size - 1, c);
}

string removeOccurrences(string &s, size, c){
	if(size == 0)
		return '';
	if(s[size - 1] == c)
		return 
}
int main(){
	int choice;
	bool exit = false;
	string str;
	while(!exit){
		cout << "\n1.Enter string\n2.Check if a character is in a string.\n3.Count all occurrences of a character in a string.\n4.Remove all occurrences of a character from a string.\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cin >> str;
					
			case 2: cout << "Enter character to be searched: ";
					cin >> c;
					if(isPresent(str, str.size(), c))
						cout << c << " is present in " << str;
					else
						cout << c << " is not present in " << str;
					cout << endl;
					break;
					
			case 3: cout << "Enter character: ";
					cin >> c;
					cout << occurrences(str, str.size(), c) << endl;
					break;
					
			case 4: cout << "Enter character: ";
					cin >> c;
					cout << "String after removing character: " << removeOccurrences(str, str.size(), c) << endl;
					break;
			
			case 5: exit = true;
					break;
					
			default: cout << "Wrong choice" << endl;
		}
	}
	catch(const char *s){
		cout << s << endl;
	}
	}
	return 0;
}
