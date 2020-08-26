#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int *arr, int n){
	bool swapped;
	for(int i = 0; i < n - 1; i++){
		swapped = false;
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}
}

void selectionSort(int *arr, int n){
	int min_i;
	for(int i = 0; i < n - 1; i++){
		min_i = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[min_i])
				min_i = j;
		}
		swap(arr[min_i], arr[i]);
	} 
}

void insertionSort(int *arr, int n){
	int j, val;
	for(int i = 1;i < n; i++){
		val = arr[i];
		j = i - 1;
		while(j >= 0 && val < arr[j]){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = val;
	} 
}

void merge(int *arr, int l, int c, int r){
	int b[r - l + 1];
	int i = l, j = c, k = 0;
	while(i < c && j <= r){
		if(arr[i] < arr[j])
			b[k++] = arr[i++];
		else
			b[k++] = arr[j++];
	}
	
	while(i < c)
		b[k++] = arr[i++];
	while(j <= r)
		b[k++] = arr[j++];
		
	for(int i = 0; i < k; i++)
		arr[i] = b[i];
}

void mergeSort(int *arr, int l, int r){
	if(l < r){
		int c = (r - l + 1) / 2;
		mergeSort(arr, l, c);
		mergeSort(arr, c + 1, r);
		merge(arr, l, c + 1, r);
	}
}

int partition(int *arr, int l, int r){
	int pivot = arr[r];
	int temp;
	int j = l - 1;
	for(int i = l; i < r; i++){
		if(arr[i] <= pivot){
			j++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	j++;
	temp = arr[j];
	arr[j] = arr[r];
	arr[r] = temp;
	return j;
}

void quickSort(int *arr, int l, int r){
	if(l < r){
		int p = partition(arr, l, r);
		
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, r);
	}
}


int binarySearch(int *arr, int n, int val){
	int start = 0, end = n - 1; 
	int mid;
	while(start <= end){
		mid = (start + end) / 2;
		if(val == arr[mid])
			return mid;
		else if(val > arr[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}

int linearSearch(int *arr, int n, int val){
	for(int i = 0; i < n; i++)
		if(arr[i] == val)
			return i;
	return -1;
}

void display(int *arr, int n){
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void input(int *&arr, int n){
	arr = new int[n];
	cout << "Enter array elements\n";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
}

int main()
{
	int n;
	int *arr;
	int choice;
	bool exit = false;
	int index, val;
	while(!exit){
		cout << "\n1.Enter array\n2.Bubble Sort\n3.Selection Sort\n4.Insertion Sort\n5.Merge Sort\n6.Quick Sort\n7.Binary Search\n8.Linear Search\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
	
	try{
		switch(choice){
			case 1: cout << "Enter size: ";
					cin >> n;
					input(arr, n);
					break;
					
			case 2: bubbleSort(arr, n);
					cout << "Array after sorting\n";
					display(arr, n);
					break;
					
			case 3: selectionSort(arr, n);
					cout << "Array after sorting\n";
					display(arr, n);
					break;
					
			case 4: insertionSort(arr, n);
					cout << "Array after sorting\n";
					display(arr, n);
					break;
				
			case 5: mergeSort(arr, 0, n - 1);
					cout << "Array after sorting\n";
					display(arr, n);
					break;
					
			case 6: quickSort(arr, 0, n - 1);
					cout << "Array after sorting\n";
					display(arr, n);
					break;
					
			case 7: cout << "Enter value to be searched: ";
					cin >> val;
					index = binarySearch(arr, n, val);
					if(index == -1)
						cout << val << " not found";
					else
						cout << val << " found at position " << index;
					cout << endl;
					break;
						
			case 8: cout << "Enter value to be searched: ";
					cin >> val;
					index = linearSearch(arr, n, val);
					if(index == -1)
						cout << val << " not found";
					else
						cout << val << " found at position " << index;
					cout << endl;
					break;			
			
			case 0: delete[] arr; 
					exit = true;
					break;
					
			default: cout << "Wrong choice" << endl;
		}
	}
	catch(const char *s){
		cout << s << endl;
	}
	}
	return 0;
}
