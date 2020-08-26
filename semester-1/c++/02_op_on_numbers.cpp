#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int n, num, sum = 0, a, b, num1, num2, sum1 = 0, sum2 = 0;
	double var = 0.0;
	cout << "How many numbers do you want to enter:";
	cin >> n;
	int *arr = new int[n];
	cout << endl << "Enter numbers:" << endl;

	for (int i = 1; i <= n; i++) {

		cin >> num;
		arr[i] = num;
		num1 = num * num;
		num2 = num * num * num;
		sum1 = sum1 + num1;
		sum2 = sum2 + num2;

		if (i == 1) {
			a = num;
			b = num;
		}
		sum = sum + num;

		if (num > a) {a = num; }
		if (num < b) {b = num; }
	}

	double avg;
	avg = (double(sum)) / n;
	cout << endl << "Sum of numbers:" << sum;
	cout << endl << "Maximum number:" << a;
	cout << endl << "Minimum number:" << b << endl;
	cout << endl << "Sum of squares:" << sum1 << endl;
	cout << "Sum of cubes:" << sum2 << endl;
	cout << "Average:" << avg << endl;

	for (int j = 1; j <= n; j++) {
		var = (var + (arr[j] - avg) * (arr[j] - avg));
	}

	var /= n;
	cout << "Variance:" << var << endl;
	cout << "Standard Deviation:" << sqrt(var) << endl;
	return 0;
}
