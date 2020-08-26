	#include<iostream>
	using namespace std;
	int bin_search_rec(int *a,int start,int end,int elem){
		if(end>=start){		
			int middle=(start+end)/2;
			if(elem==a[middle])
				return middle;
			else if(elem>a[middle])
				return bin_search_rec(a,middle+1,end,elem);
			else
				return bin_search_rec(a,start,middle-1,elem);
		}
		else 
			return -1;
	}

	int bin_search(int *a,int start,int end,int elem){
		while(end>=start){
			int middle=(start+end)/2;
			if(elem==a[middle])
				return middle;
			else if(elem>a[middle])
				start=middle+1;
			else
				end=middle-1;
		}
			return -1;
	}
	
	int main(){

		int n,elem;
		cout<<"Enter how many elements you want in the array:";
		cin>>n;
		if(n<=0){
			cout<<"Invalid input!!"<<endl;
			return 0;
		}
		int *arr=new int[n];
		cout<<"Enter array elements(in ascending order):\n";
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<"Enter the element you want to search:";
		cin>>elem;
		int index=bin_search_rec(arr,0,n-1,elem);
		if(index>=0)
			cout<<"Element found at position "<<index+1<<endl;
		else
			cout<<"Element not found"<<endl;
		
		return 0;
	}
		
