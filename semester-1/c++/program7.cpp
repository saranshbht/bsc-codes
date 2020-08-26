//WAP to compute the factors of a given number
#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter a number:";
	cin >> n;
	cout << endl << "The factors of the number are:" << endl;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cout << i << "\t" << -i << endl;
		}
	}
	return 0;
}

