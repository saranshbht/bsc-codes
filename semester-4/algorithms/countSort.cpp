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
	ifstream in("dataset.csv");		//dataSet already created with another file
	/*ofstream ofcomp("cSortComp.csv", ios :: app);
	ofstream oftime("cSortTime.csv", ios :: app);
	string s;
	int dataSize[11] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000};
	ofcomp << "Datasize,";
	oftime << "Datasize,";
	for(int i = 0; i < 11; i++){
		ofcomp << dataSize[i] << ",";
		oftime << dataSize[i] << ",";
	}
	ofcomp << endl << "Decreasing-Ordered Data Comparisons,";
	oftime << endl << "Decreasing-Ordered Data Time,";*/
	string s;
	int dataSize[12] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000};
	for(int idx = 0; idx < 11; idx++){
		in.clear();
		in.seekg(0, ios :: beg);
		pair<int, int> arr[dataSize[idx]];
		int index = 0;
		int counter = dataSize[idx];	
		if(in){
			while(counter--){
				getline(in, s);
				arr[index].first = index;
				arr[index++].second = stoi(s);
				
			}
		}
		//sort(arr, arr + dataSize[idx], greater<int>());
		chrono::time_point<std::chrono::system_clock> start, end; 
		start = chrono::system_clock::now();
		
		//long long comparisons = 0;
		countSort(arr, dataSize[idx]);
		end = chrono::system_clock::now();
		chrono::duration<double> timeTaken = end - start;
		for(int i = 0; i < dataSize[idx] && dataSize[idx] == 100; i++)
			cout << arr[i].second << " " << arr[i].first << endl; 
		cout << "Datasize: " << dataSize[idx] << endl;
		cout << "Time taken for count sort: " << timeTaken.count() << endl;
		//cout << "No of comparisons: " << comparisons << endl << endl;
		//cout << "No of swaps: " << swaps << endl;
		/*oftime << timeTaken.count() << ",";
		ofcomp << comparisons << ",";*/
	}
	/*ofcomp.close();
	oftime.close();*/
	in.close();
	return 0;
}
