#include<iostream>
using namespace std;
int gcd(unsigned int a, unsigned int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}
int main() {
	unsigned int x, y;
	cout << "Enter the numbers whose greatest common divisor you want to find" << endl;
	cin >> x >> y;
	cout << endl << "The Greatest Common Divisor of the numbers is:" << gcd(x, y) << endl;
	return 0;
}

