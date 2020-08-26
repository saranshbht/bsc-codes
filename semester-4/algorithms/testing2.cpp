#include<iostream>
using namespace std;

void merge(int *arr, int l, int mid, int r, long long &comparisons){
	int a[mid - l + 2];
	int b[r - mid + 1];
	
	for(int i = l; i <= mid; i++)
		a[i - l] = arr[i];
	a[mid - l + 1] = INT_MAX;
	
	for(int i = mid + 1; i <= r; i++)
		b[i - mid - 1] = arr[i];
	b[r - mid] = INT_MAX;
	
	int x = 0, y = 0;
	for(int i = l; i <= r; i++){
		if(++comparisons && a[x] < b[y])
			arr[i] = a[x++];
		else
			arr[i] = b[y++];
	}
}

void mergeSort(int *arr, int l, int r, long long &comparisons){
	if(l < r){
		int mid = (l + r) / 2;
		mergeSort(arr, l, mid, comparisons);
		mergeSort(arr, mid + 1, r, comparisons);
		merge(arr, l, mid, r, comparisons);
	}
}

int main(){
	long long comparisons = 0;
	int arr[] = {23, 0, -2, 34, 12, 54, 3};
	mergeSort(arr, 0, 6, comparisons);
	for(int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl << comparisons << endl;
	return 0;
}
