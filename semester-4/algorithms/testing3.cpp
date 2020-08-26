#include<iostream>
using namespace std;

int partition(int *arr, int p, int r, long long &comparisons){
	int x = arr[r];
	int i = p - 1;
	for(int j = p; j < r; j++){
		if(++comparisons && arr[j] < x){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
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
	int arr[] = {23, 0, -2, 34, 12, 54, 3};
	quickSort(arr, 0, 6, comparisons);
	for(int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl << comparisons << endl;
	return 0;
}
