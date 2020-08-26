//Write a function to find whether a given number is prime or not. Use this function to generate the prime numbers less than 100.
#include<iostream>
#include<cmath>
using namespace std;
bool checkPrime(unsigned int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	unsigned int num;
	cout << "Prime numbers less than 100 are:" << endl;
	for (int i = 1; i < 100; i++) {
		if (checkPrime(i)) {
			cout << i << endl;
		}
	}
	return 0;
}
