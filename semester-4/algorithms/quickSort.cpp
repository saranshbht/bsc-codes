#include<bits/stdc++.h>
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
	ifstream in("dataset.csv");		//dataSet already created with another file
	ofstream ofcomp("qSortComp.csv", ios :: app);
	ofstream oftime("qSortTime.csv", ios :: app);
	string s;
	int dataSize[8] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000};
	/*ofcomp << "Datasize,";
	oftime << "Datasize,";
	for(int i = 0; i < 8; i++){
		ofcomp << dataSize[i] << ",";
		oftime << dataSize[i] << ",";
	}*/
	ofcomp << endl << "Best-Case Comparisons,";
	oftime << endl << "Best-Case Time,";
	for(int idx = 0; idx < 8; idx++){
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
		quickSort(arr, 0, dataSize[idx] - 1, comparisons);
		end = chrono::system_clock::now();
		chrono::duration<double> timeTaken = end - start; 
		cout << "Datasize: " << dataSize[idx] << endl;
		cout << "Time taken for quick sort: " << timeTaken.count() << endl;
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
