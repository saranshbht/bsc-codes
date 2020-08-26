#include<bits/stdc++.h>
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
	ifstream in("dataset.csv");		//dataSet already created with another file
	ofstream ofcomp("mSortComp.csv", ios :: app);
	ofstream oftime("mSortTime.csv", ios :: app);
	string s;
	int dataSize[12] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000};
	/*ofcomp << "Datasize,";
	oftime << "Datasize,";
	for(int i = 0; i < 11; i++){
		ofcomp << dataSize[i] << ",";
		oftime << dataSize[i] << ",";
	}*/
	ofcomp << endl << "Best-Case Comparisons,";
	oftime << endl << "Best-Case Time,";
	for(int idx = 0; idx < 11; idx++){
		in.clear();
		in.seekg(0, ios :: beg);
		int arr[dataSize[idx]];
		int index = 0;
		int counter = dataSize[idx];	
		if(in){
			while(counter--){
				getline(in, s);
				arr[index++] = stoi(s);
			}
		}
		sort(arr, arr + dataSize[idx], greater<int>());
		chrono::time_point<std::chrono::system_clock> start, end; 
		start = chrono::system_clock::now();
		
		long long comparisons = 0;
		mergeSort(arr, 0, dataSize[idx] - 1, comparisons);
		end = chrono::system_clock::now();
		chrono::duration<double> timeTaken = end - start; 
		cout << "Datasize: " << dataSize[idx] << endl;
		cout << "Time taken for merge sort: " << timeTaken.count() << endl;
		cout << "No of comparisons: " << comparisons << endl << endl;
		//cout << "No of swaps: " << swaps << endl;
		oftime << timeTaken.count() << ",";
		ofcomp << comparisons << ",";
	}
	ofcomp.close();
	oftime.close();
	in.close();
	return 0;
}
