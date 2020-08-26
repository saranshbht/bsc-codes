//Write a function to find whether a number is prime or not. Use the function to generate
//prime numbers less than 100
#include <iostream>
#include<cmath>
using namespace std;

bool checkPrime(int n) {
	if (n == 2) {
		return true;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	cout << "Prime numbers upto 100:" << endl;
	for (int i = 1; i <= 100; i++) {
		if (checkPrime(i)) {
			cout << i << endl;
		}
	}
	return 0;
}
