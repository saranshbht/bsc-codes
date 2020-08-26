//WAP to display Fibonacci series (i)using recursion, (ii)using iteration

#include<iostream>
using namespace std;

int fibonacci_loop(int n) {
	if ((n == 0) || (n == 1)) {
		return n;
	}
	int a = 0, b = 1, c;
	for (int i = 0; i <= n - 2; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int fibonacci_rec(int n) {
	if ((n == 0) || (n == 1)) {
		return n;
	} else {
		return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
	}
}
int main() {
	int n;
	cout << "Enter the number of terms of the Fibonacci series you want to see:";
	cin >> n;
	cout << "Fibonacci series upto " << n << " terms:" << endl;

	//Using recursion
	for (int i = 0; i < n; i++) {
		cout << fibonacci_rec(i) << "\t";
	}
	cout << endl;

	//Using loop
	for (int i = 0; i < n; i++) {
		cout << fibonacci_loop(i) << "\t";
	}

	return 0;

}
