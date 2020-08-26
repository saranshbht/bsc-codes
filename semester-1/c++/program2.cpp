//WAP to reverse a number

#include<iostream>
using namespace std;

int main() {

	int number, rev_num = 0;
	cout << "Enter an integer:";
	cin >> number;
	int num = number;
	while (num != 0) {
		if (num < 0) {
			num *= -1;
		}
		rev_num = rev_num * 10 + num % 10;
		num /= 10;
	}
	if (number < 0) {
		rev_num *= -1;
	}
	cout << endl << "The reversed number is:" << rev_num << endl;
	return 0;
}
