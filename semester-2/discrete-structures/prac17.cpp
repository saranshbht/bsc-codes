 #include<iostream>
using namespace std;

int main(){
	int n;
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
		for(int j=0;j<(i+1);j++){
			if(i==j && adjm[i][j]==1){
				flag=false;
				break;
			}
			if(i!=j && adjm[i][j]!=1){
				flag=false;
				break;
			}
		}
		if(flag==false)
			break;
	}
	
	if(flag)
		cout<<endl<<"The graph is a complete graph"<<endl;
	else
		cout<<endl<<"The graph is not a complete graph"<<endl;
	
	for(int i=0;i<n;i++)
		delete[] adjm[i];
	delete[] adjm;
	
	for(int i=0;i<n;i++)
		delete[] adjl[i];
	delete[] adjl;

	return 0;
}
				
					
