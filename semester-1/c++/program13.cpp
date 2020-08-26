//WAP in which a function is passed address of two variables and then alter its contents
#include<iostream>
using namespace std;

void alter(int *a, int *b) {
	*a *= 2;
	*b -= 10;
}
int main() {
	int a, b;
	cout << "Enter two numbers:" << endl;
	cin >> a >> b;

	cout << "Values before altering:" << endl;
	cout << "First number:" << a << endl;
	cout << "Second number:" << b << endl;
	alter(&a, &b);
	cout << "Values after altering:" << endl;
	cout << "First number:" << a << endl;
	cout << "Second number:" << b << endl;

}
