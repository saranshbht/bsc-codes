//WAP that swaps two numbers using pointers
#include<iostream>
using namespace std;

void swapping(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int a, b;
	cout << "Enter two numbers:" << endl;
	cin >> a >> b;
	cout << "Values before swapping:" << endl;
	cout << "First number:" << a << endl;
	cout << "Second number:" << b << endl;
	swapping(&a, &b);
	cout << "Values after swapping:" << endl;
	cout << "First number:" << a << endl;
	cout << "Second number:" << b << endl;

}
