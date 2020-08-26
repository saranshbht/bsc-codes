//WAP to print the sum and product of digits of an integer
#include<iostream>
using namespace std;
int main() {
	int sum = 0, prod = 1, num;
	cout << "Enter an integer:";
	cin >> num;
	if (num > 0) {
		while (num > 0) {
			sum += num % 10;
			prod *= num % 10;
			num = num / 10;
		}
	} else if (num < 0) {
		num *= -1;
		while (num != 0) {
			sum += num % 10;
			prod *= num % 10;
			num = num / 10;
			if (num < 10) {
				num *= -1;
			}
		}
	} else {
		sum = 0;
		prod = 0;
	}
	cout << endl << "Sum of digits of the interger:" << sum;
	cout << endl << "Product of digits of the integer:" << prod << endl;
	return 0;
}
