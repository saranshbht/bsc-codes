 #include<iostream>
using namespace std;

int main(){
	int n,noOfOdds=0;
	bool flag=true;
	bool adjflag=true;
	bool **adjm;
	int **adjl;
	
	cout<<"Enter the number of vertices of the graph:";
	cin>>n;
	
	adjm=new bool*[n];
	adjl=new int*[n];
	
	for(int i=0;i<n;i++){
		adjm[i]=new bool[n];
	}
	
	for(int i=0;i<n;i++){
		adjl[i]=new int[n];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adjl[i][j]=-1;
			adjm[i][j]=0;
		}
	}
			
	cout<<endl<<"Enter the connections of the graph"<<endl;
		for(int i=0;i<n;i++){
			int d=0;
			cout<<"Enter degree of "<<i<<" vertex: ";
			cin>>d;
			cout<<i<<"-> ";
			for(int j=0;j<d;j++){
				cin>>adjl[i][j];
				adjm[i][adjl[i][j]]=1;
			}
			cout<<endl;
		}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adjm[i][j]!=adjm[j][i]){
				cout<<"The graph is not a valid graph"<<endl;
				return 0;
			}		
		}
	}

	
	cout<<endl<<"Adjacency Matrix for the graph"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adjm[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<n;i++){
		int noOfOnes=0;
		for(int j=0;j<n;j++){
			if(adjm[i][j])
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
