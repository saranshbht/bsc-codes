#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int p, int r, long long &comparisons){
	int random = p + rand() % (r - p + 1);
	int x = arr[random];
	int i = p - 1;
	for(int j = p; j < random; j++){
		if(++comparisons && arr[j] < x){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[random]);
	return i + 1;
}


void quickSort(int *arr, int p, int r, long long &comparisons){
	if(p < r){
		int q = partition(arr, p, r, comparisons);
		quickSort(arr, p, q - 1, comparisons);
		quickSort(arr, q + 1, r, comparisons);
	}
}

int main(){
	long long comparisons = 0;
	int arr[] = {1, 2, 10, 8, 6};
	quickSort(arr, 0, 4, comparisons);
	for(int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
