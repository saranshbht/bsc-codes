#include<iostream>
using namespace std;

double avg(int *arr, int n){
	if(n == 1)
		return arr[n - 1];
	return (arr[n - 1] + (n - 1) * avg(arr, n - 1)) / n;
}
int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements\n";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << avg(arr, n) << endl;
	return 0;
}
