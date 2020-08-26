#include<bits/stdc++.h>
using namespace std;

void countSort(pair<int, int> *arr, int n){
	pair<int, int> b[n];
	int maxm = INT_MIN;
	for(int i = 0; i < n; i++)
		maxm = max(maxm, arr[i].second);
	int c[maxm + 1] = {0};
	for(int i = 0; i < n; i++)
		c[arr[i].second]++;
	for(int i = 1; i <= maxm; i++)
		c[i] += c[i - 1];
	for(int i = n - 1; i >= 0; i--){
		b[c[arr[i].second] - 1].first = arr[i].first;
		b[c[arr[i].second] - 1].second = arr[i].second;
		c[arr[i].second]--;
	}
	for(int i = 0; i < n; i++){
		arr[i].first = b[i].first;
		arr[i].second = b[i].second;
	}
}

int main(){
	int size = 10, a;
	pair<int, int> arr[10];
	for(int i = 0; i < 10; i++){
		cin >> a;
		arr[i].second = a;
		arr[i].first = i;
	}
	countSort(arr, 10);
	for(int i = 0; i < 10; i++)
		cout << arr[i].second << " " << arr[i].first << endl;
	return 0;
}
