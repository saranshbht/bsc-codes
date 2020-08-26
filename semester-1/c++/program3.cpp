//WAP to compute the sum of the first n terms of the following series
//              S=1+1/2+1/3+1/4+..............
#include<iostream>
using namespace std;

int main() {
	int n, i = 1;
	cout << "Enter the number of terms upto which you want to compute the sum of the series:" << endl;
	cout << "S=1+1/2+1/3+1/4+..............    :";
	cin >> n;
	double sum = 0.0;
	while (i <= n) {
		sum += ((double)1 / i);
		i++;
	}
	cout << endl << "Sum of the series upto " << n << " terms is:" << sum << endl;
	return 0;
}

