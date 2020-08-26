	#include<iostream>
	using namespace std;
	//int a=0;
	
	swap(int &a,int &b){
		int temp=a;
		a=b;
		b=temp;
	}
	
	void sort(int *arr,int n){
		int start,pos,temp;
		for(int i=0;i<n-1;i++){
			start=arr[i];
			pos=i;
			for(int j=i+1;j<n;j++){
				if(arr[j]<start){
					start=arr[j];
					pos=j;
				}
			}
			temp=arr[pos];
			arr[pos]=arr[i];
			arr[i]=temp;
		}
	}
	
	void permute(int *arr,int n){
		int k,l,counter=0;
		for(int i=n-1;i>0;i--){
			if(arr[i]>arr[i-1]){
				k=i-1;
				counter++;
				break;
			}
		}
		if(counter==0)
			return;
		l=k+1;
		for(int i=k+1;i<n;i++){
			if(arr[i]>arr[k]){
				l=i;
				for(int j=i+1;j<n;j++){
					if(arr[j]<arr[i]&&arr[j]>arr[k])
						l=j;
				}
			}
		}
		//cout<<k<<" "<<l<<endl;
		swap(arr[k],arr[l]);
		/*cout<<"Array after swapping: ";
		for(int i=0;i<n;i++){
			cout<<arr[i]<<"\t";
		}
		cout<<endl;
		*/
		int count=1;
			for(int i=k+1;i<((k+1)+(n-(k+1))/2);i++){
				swap(arr[i],arr[n-count]);	
				count++;
			//	cout<<"A";
			}
		
		/*else{
			for(int i=k+1;i<=((k+1)+(n-k+1)/2);i++){
				int temp=arr[i];
				arr[i]=arr[n-count];
				arr[n-count]=temp;	
				count++;
			}
		}*/
		//cout<<++a<<" ";	
		for(int i=0;i<n;i++){
			cout<<arr[i]<<"\t";
		}
		cout<<endl;
		permute(arr,n);
	}
	
	
	int main(){
		int n,*arr;
		cout<<"Enter how many elements you want in the set:";
		cin>>n;
		arr=new int[n];
	
		cout<<"Enter elements:"<<endl;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		sort(arr,n);
		//cout<<++a<<" ";
		for(int i=0;i<n;i++){
			cout<<arr[i]<<"\t";
		}
		cout<<endl;
		
		permute(arr,n);
				
		return 0;
	}