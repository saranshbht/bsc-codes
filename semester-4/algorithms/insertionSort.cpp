#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream in("dataset.csv");		//dataSet already created with another file
	ofstream ofcomp("iSortComp.csv", ios :: app);
	ofstream oftime("iSortTime.csv", ios :: app);
	string s;
	int dataSize[12] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000};
	/*ofcomp << "Datasize,";
	oftime << "Datasize,";
	for(int i = 0; i < 11; i++){
		ofcomp << dataSize[i] << ",";
		oftime << dataSize[i] << ",";
	}*/
	ofcomp << "Best-Case Comparisons,";
	oftime << "Best-Case Time,";
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
		int key, j;
		long long comparisons = 0;
		for(int i = 1; i < dataSize[idx]; i++){
			key = arr[i];
			j = i - 1;
			while(j >= 0 && ++comparisons && arr[j] > key){
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
		end = chrono::system_clock::now();
		chrono::duration<double> timeTaken = end - start; 
		cout << "Datasize: " << dataSize[idx] << endl;
		cout << "Time taken for insertion sort: " << timeTaken.count() << endl;
		cout << "No of comparisons: " << comparisons << endl << endl;
		//cout << "No of swaps: " << swaps << endl;
		ofcomp << comparisons << ",";
		oftime << timeTaken.count() << ",";
	}
	ofcomp << endl;
	oftime << endl;
	oftime.close();
	ofcomp.close();
	in.close();
	return 0;
}
