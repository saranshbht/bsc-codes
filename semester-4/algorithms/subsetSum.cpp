#include<bits/stdc++.h>
using namespace std;

int isSum(int *arr, int n, int sum){
	int subsum[n + 1][sum + 1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			if(i == 0 || j == 0)
				subsum[i][j] = 0;
			else if(arr[i] > j)
				subsum[i][j] = subsum[i - 1][j];
			else
				subsum[i][j] = max(subsum[i - 1][j], arr[i] + subsum[i - 1][j - arr[i]]);
		}
	}
	return subsum[n][sum];
}
int main(){
	int sum;
	int n;
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	int arr[n + 1];
	arr[0] = 0;
	cout << "Enter elements(non-negative integers): ";
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << "Enter the sum: ";
	cin >> sum;
	if(isSum(arr, n, sum) == sum)
		cout << "There is a subset of the array with sum equal to the given sum";
	else
		cout << "There is no subset of the array with sum equal to the given sum";
	cout << endl;
	return 0;
}
