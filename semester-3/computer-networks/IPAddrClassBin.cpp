#include<iostream>
using namespace std;

int main(){
	string s;
	cout << "Enter IP Address: ";
	cin >> s;
	cout << "IP Addresss belongs to Class ";
	int i;
	for(i = 0; s[i] != '0' && i < 4; i++);
	if(i == 4)
		cout << "E";
	else
		cout << char('A' + i);
	return 0; 
}
