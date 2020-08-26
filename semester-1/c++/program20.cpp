//WAP to calculate GCD of two numbers (i)using recursion, (ii)without recursion
#include<iostream>
using namespace std;
int gcd_rec(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd_rec(b, a % b);
	}
}

int gcd_wo_rec(int a, int b) {
	while (b >= 0) {
		if (b == 0) {
			return a;
		}
		int temp = a;
		a = b;
		b = temp % b;
	}
}
int main() {

	int a, b;
	cout << "Enter two positive integers:" << endl;
	cin >> a >> b;
	cout << "Greatest Common Divisor of the two numbers is:" << endl;
	if (a > b) {
		//Using recursion
		cout << gcd_rec(a, b);

		//Without using recursion
		cout << endl << gcd_wo_rec(a, b);
	} else {
		//Using recursion
		cout << gcd_rec(b, a);

		//Without using recursion
		cout << endl << gcd_wo_rec(b, a);
	}
	return 0;
}
