//Swap two numbers using pointers.
#include<iostream>
using namespace std;
void my_swap(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main() {
	int a, b;
	cout << "Enter the value of 'a':";
	cin >> a;
	cout << endl << "Enter the value of 'b':";
	cin >> b;
	cout << endl << "Before swapping" << endl << "a=" << a << endl << "b=" << b << endl;
	my_swap(a, b);
	cout << endl << "After swapping" << endl << "a=" << a << endl << "b=" << b << endl;


	return 0;
}
