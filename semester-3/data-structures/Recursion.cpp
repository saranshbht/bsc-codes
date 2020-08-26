#include<bits/stdc++.h>
using namespace std;

void recursion(){
	char a;
	a = getchar();
	if(a != '\n')
		recursion();
	cout << a;
}

int main(){
	recursion();
	//cout << endl;
	return 0;
}
