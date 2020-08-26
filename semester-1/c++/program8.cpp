//Write a macro that swaps two numbers. WAP to use it
#include<iostream>
#define SWAP(a,b) {  int temp=a; \
                     a=b; \
                     b=temp;}

using namespace std;

int main() {
	int a, b;
	cout << "Enter two numbers:" << endl;
	cin >> a >> b;
	cout << endl << "Values before swapping";
	cout << endl << "First number:" << a;
	cout << endl << "Second number:" << b;

	SWAP(a, b);
	cout << endl << "Values after swapping";
	cout << endl << "First number:" << a;
	cout << endl << "Second number:" << b;

	return 0;
}
