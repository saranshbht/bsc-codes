#include<iostream>
using namespace std;

int main(){
	bool **adj;
	int n,noOfOdds=0;
	cout<<"Enter number of vertices:";
	cin>>n;
	adj=new bool*[n];
	for(int i=0;i<n;i++)
		adj[i]=new bool[n];

	cout<<"Enter adjacency matrix for the graph"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>adj[i][j];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adj[i][j]!=adj[j][i]){
				cout<<"Invalid graph"<<endl;
				return 0;
			}
		}
	}
				
	for(int i=0;i<n;i++){
		int noOfOnes=0;
		for(int j=0;j<n;j++){
			if(adj[i][j])
				noOfOnes++;
		}
		if(noOfOnes%2!=0)
			noOfOdds++;
		
	}
	if(noOfOdds==0)
		cout<<"Euler circuit exists in the graph"<<endl;
	else if(noOfOdds==2)
		cout<<"Euler path exists in the graph"<<endl;
	else
		cout<<"Neither Euler Circuit nor Euler Path exists"<<endl;
	
	return 0;
}
