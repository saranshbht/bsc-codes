#include<iostream>
using namespace std;

int sum(int *arr, int n){
	if(n == 1)
		return arr[n - 1];
	return arr[n - 1] + sum(arr, n - 1);
}
int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements\n";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << sum(arr, n) << endl;
	return 0;
}
