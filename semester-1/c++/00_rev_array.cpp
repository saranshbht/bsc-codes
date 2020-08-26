//Reverse elements of array without using new array.
#include<iostream>
using namespace std;
int main() {
	int n, temp;
	cout << "How many elements should be in the array?:";
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cout << endl;
	}
	cout << endl << "Array before reversing:" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	int m = n;
	for (int j = 0; j <= (m / 2); j++) {
		temp = a[j];
		a[j] = a[m - 1];
		a[m - 1] = temp;
		m--;
	}

	cout << endl << "Array after reversing:" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	return 0;
}

