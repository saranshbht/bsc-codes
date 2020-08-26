//Write a macro that swaps two numbers.WAP to use it.
#include<iostream>
using namespace std;
#define swap(a,b) {a=a+b; b=a-b; a=a-b;}
int main() {
	int x, y;
	cout << "Enter two numbers:" << endl;
	cin >> x >> y;
	cout << endl << "Numbers before swapping:" << endl;
	cout << x << "\t" << y;
	swap(x, y);
	cout << endl << "Numbers after swapping:" << endl;
	cout << x << "\t" << y << endl;
	return 0;
}
