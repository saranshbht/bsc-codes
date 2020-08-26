//WAP to compute the sum of the first n terms of the following series
//        S=1+2+3+4+5................
#include<iostream>
using namespace std;

int main() {

	int n;
	cout << "Enter the number of terms upto which you want to compute the sum of the series:" << endl;
	cout << "S=1+2+3+4+5..............    :";
	cin >> n;
	int sum = (n * (n + 1) / 2);
	cout << endl << "Sum of the series upto " << n << " terms is:" << sum << endl;
	return 0;
}
