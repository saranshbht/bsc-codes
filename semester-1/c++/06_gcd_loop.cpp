#include<iostream>
using namespace std;
int main() {
	unsigned x, y, gcd;
	cout << "Enter the numbers whose greatest common divisor you want to find" << endl;
	cin >> x >> y;
	while (y >= 0) {
		if (y == 0) {
			gcd = x;
			break;
		} else {
			x = y;
			y = x % y;
		}
	}
	cout << endl << "The Greatst Common Divisor of the numbers is:" << gcd << endl;
	return 0;
}

