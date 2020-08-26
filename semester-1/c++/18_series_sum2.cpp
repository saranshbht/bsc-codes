//WAP to find the sum of the first n terms of the series
//S=1-2+3-4+5-.....
#include<iostream>
using namespace std;
int main() {
	int n;
	int sum = 0, flag = 1;
	cout << "Series: 1-2+3-4+5-.....";
	cout << endl << "Enter the number of terms upto which you want to find the sum:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (flag == 1) {
			sum += i;
		} else if (flag == -1) {
			sum -= i;
		}
		flag *= -1;
	}
	cout << endl << "Sum of the series upto first " << n << " terms is:" << sum << endl;
	return 0;
}
