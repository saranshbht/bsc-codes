//WAP to compute the sum of first n terms of the series
//S=1+1/2+1/3+1/4+....
#include<iostream>
using namespace std;
int main() {
	int n;
	double sum = 0.0;
	cout << "Series: 1+1/2+1/3+1/4+....";
	cout << endl << "Enter the number of terms upto which you want to find the sum:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += ((double)1 / i);
	}
	cout << endl << "Sum of the series upto first " << n << " terms is:" << sum << endl;
	return 0;
}
