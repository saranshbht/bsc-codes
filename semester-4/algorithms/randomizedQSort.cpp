#include<bits/stdc++.h>
using namespace std;

int randpartition(int *arr, int p, int r, long long &comparisons){
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


void randQuickSort(int *arr, int p, int r, long long &comparisons){
	if(p < r){
		int q = randpartition(arr, p, r, comparisons);
		randQuickSort(arr, p, q - 1, comparisons);
		randQuickSort(arr, q + 1, r, comparisons);
	}
}

int main(){
	ifstream in("dataset.csv");		//dataSet already created with another file
	ofstream ofcomp("randqSortComp.csv", ios :: app);
	ofstream oftime("randqSortTime.csv", ios :: app);
	string s;
	int dataSize[11] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000};
	/*ofcomp << "Datasize,";
	oftime << "Datasize,";
	for(int i = 0; i < 11; i++){
		ofcomp << dataSize[i] << ",";
		oftime << dataSize[i] << ",";
	}*/
	ofcomp << endl << "Worst-Case Comparisons,";
	oftime << endl << "Worst-Case Time,";
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
		randQuickSort(arr, 0, dataSize[idx] - 1, comparisons);
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
