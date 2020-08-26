//WAP to reverse a number
#include<iostream>
using namespace std;
int main() {
	int num, rev = 0, b;
	cout << "Enter an integer:";
	cin >> num;
	if (num > 0) {
		while (num > 0) {
			b = num % 10;
			rev = rev * 10 + b;
			num /= 10;
		}
	} else if (num < 0) {
		num *= -1;
		while (num > 0) {
			b = num % 10;
			rev = rev * 10 + b;
			num /= 10;
		}
		rev *= -1;
	} else {
		rev = 0;
	}
	cout << endl << "Reverse of the number is:" << rev << endl;
	return 0;
}
