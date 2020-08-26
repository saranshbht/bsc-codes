//WAP to find sum of n elements entered by the user. To write this program, allocate memory
//dynamically using malloc()/calloc() functions or new operator
#include<iostream>
using namespace std;
int main() {
	double *num = new double;
	double *sum = new double;
	int *n = new int;
	int*i = new int;
	*sum = 0;
	cout << "How many elements do you want to enter?:";
	cin >> (*n);
	for (*i = 0; *i < *n; (*i)++) {
		cin >> (*num);
		(*sum) += (*num);
	}
	cout << "The sum of the elements entered:" << (*sum);
	delete num;
	delete sum;
	delete n;
	delete i;

	return 0;
}
