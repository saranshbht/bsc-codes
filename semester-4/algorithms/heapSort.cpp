#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int *arr, int i, int size, long long &comparisons){
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int max = i;
	if(left <= size && ++comparisons && arr[left] > arr[max])
		max = left;
	if(right <= size && ++comparisons && arr[right] > arr[max])
		max = right;
	if(max != i){
		swap(arr[i], arr[max]);
		maxHeapify(arr, max, size, comparisons);
	}
}

void buildMaxHeap(int *arr, int size, long long &comparisons){
	for(int i = (size - 1) / 2; i >= 0; i--)
		maxHeapify(arr, i , size, comparisons);
}

void heapSort(int *arr, int size, long long &comparisons){
	buildMaxHeap(arr, size, comparisons);
	for(int i = size; i > 0; i--){
		swap(arr[0], arr[i]);
		maxHeapify(arr, 0, i - 1, comparisons);
	}
}

int main(){
	ifstream in("dataset.csv");		//dataSet already created with another file
	ofstream ofcomp("hSortComp.csv", ios :: app);
	ofstream oftime("hSortTime.csv", ios :: app);
	string s;
	int dataSize[11] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000};
	/*ofcomp << "Datasize,";
	oftime << "Datasize,";
	for(int i = 0; i < 11; i++){
		ofcomp << dataSize[i] << ",";
		oftime << dataSize[i] << ",";
	}*/
	ofcomp << endl << "Decreasing-Ordered Data Comparisons,";
	oftime << endl << "Decreasing-Ordered Data Time,";
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
		heapSort(arr, dataSize[idx] - 1, comparisons);
		end = chrono::system_clock::now();
		chrono::duration<double> timeTaken = end - start; 
		cout << "Datasize: " << dataSize[idx] << endl;
		cout << "Time taken for heap sort: " << timeTaken.count() << endl;
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
