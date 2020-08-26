#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr){
	int n = arr.size();
	if(n == 0)
		return ;
	int b[n] = {0};
	int maxm = INT_MIN;
	for(int i = 0; i < n; i++)
		maxm = max(maxm, arr[i]);
	int c[maxm + 1] = {0};
	for(int i = 0; i < n; i++)
		c[arr[i]]++;
	for(int i = 1; i <= maxm; i++)
		c[i] += c[i - 1];
	for(int i = n - 1; i >= 0; i--){
		b[c[arr[i]] - 1] = arr[i];
		c[arr[i]]--;
	}
	for(int i = 0; i < n; i++)
		arr[i] = b[i];
}

void bucketSort(int *arr, int n){
	vector<vector<int> > b(n);
	int maxm = INT_MIN;
	for(int i = 0; i < n; i++)
		maxm = max(arr[i], maxm);
	maxm++;
	for(int i = 0; i < n; i++)
		b[floor((double)arr[i] / maxm * n)].push_back(arr[i]);
	for(int i = 0; i < n; i++)
		countSort(b[i]);
	int idx = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < b[i].size(); j++)
			arr[idx++] = b[i][j];

}

int main(){
	ifstream in("dataset.csv");	
	string s;
	int dataSize[11] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000};
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
		//sort(arr, arr + dataSize[idx], greater<int>());
		chrono::time_point<std::chrono::system_clock> start, end; 
		start = chrono::system_clock::now();
		
		//long long comparisons = 0;
		bucketSort(arr, dataSize[idx]);
		end = chrono::system_clock::now();
		chrono::duration<double> timeTaken = end - start; 
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
