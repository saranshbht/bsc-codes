#include<iostream>
using namespace std;

int factorial(unsigned int n) {
	if (n == 0) {
		return 1;
	} else {
		return (n * factorial(n - 1));
	}
}
int main() {

	unsigned int a;
	cout << endl << "Enter a number:";
	cin >> a;
	cout << endl << "The factorial of the number is:" << factorial(a);

	return 0;
}
