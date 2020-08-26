#include<bits/stdc++.h>
using namespace std;
#define SIZE 500000
int main(){
	srand(time(0));
	ofstream ds("dataset.csv");
	if(ds){
		for(int i = 0; i < SIZE; i++){
			ds << rand() % SIZE + 1 << endl;
		}
	}
	ds.close();
	return 0;
}
