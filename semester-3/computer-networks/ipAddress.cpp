#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

void decimal(){
	string s;
	cout << "Enter IP Address\n";
		cin >> s;
	string temp = "";
	for(int i = 0; s[i] != '.'; i++)
		temp += s[i];

	const char *str = temp.c_str(); 
	int nwid = atoi(str);
	cout << "IP Addresss belongs to Class ";
	if(nwid >= 0 and nwid <= 127)
		cout << "A";
	else if(nwid <=191)
		cout << "B";
	else if(nwid <= 223)
		cout << "C";
	else if(nwid <= 239)
		cout << "D";
	else if(nwid <= 255)
		cout << "E";
	else
		cout << "Invalid IP Address";
	cout << "\n\n";
}

void binary(){
	string s;
	cout << "Enter IP Address\n";
		cin >> s;
		
	cout << "IP Addresss belongs to Class ";
	int i;
	for(i = 0; s[i] != '0' && i < 4; i++);
	if(i == 4)
		cout << "E";
	else
		cout << char('A' + i);
	cout << "\n\n";
}

int main(){
	string s;
	int choice;
	bool flag = true;
	do{
		cout << "Choose format for IP Address\n1.Decimal\n2.Binary\n0.Exit\n";
		cin >> choice;
		if(choice == 1)
			decimal();
		else if(choice == 2)
			binary();
		else if(choice == 0)
			flag = false;
		else
			cout << "Wrong choice" << endl; 
	}while(flag);
	
	return 0;
}
