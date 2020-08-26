#include<iostream>
#include<cmath>
using namespace std;

void print(int i,int *arr,int n){
		if(i>=n)
			return;
		
		cout<<arr[i]<<" ";
		print(2*i+1,arr,n);
		print(2*i+2,arr,n);
		
 }
int main(){
	int h;
	cout<<"Enter height of the tree:";
	cin>>h;
	int n=(int)pow(2,h)-1;
	int *arr=new int[n];
	cout<<"Enter values of nodes"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int i=0;
	print(i,arr,n);
	return 0;
}