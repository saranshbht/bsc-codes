//WAP to calculate factorial of a number (i)using recursion (ii)using iteration
#include<iostream>
using namespace std;

int factorial_rec(int n) {
	if (n == 0) {
		return 1;
	} else {
		return n * factorial_rec(n - 1);
	}
}
int factorial_loop(int n) {
	int prod = 1;
	for (int i = 2; i <= n; i++) {
		prod *= i;
	}
	return prod;
}
int main() {
	int n;
	cout << "Enter a positive integer:";
	cin >> n;
	cout << "Factorial of the number:" << endl;

	//Using recursion
	cout << factorial_rec(n);
	cout << endl;

	//Using loop
	cout << factorial_loop(n);
	return 0;
}
