	#include<iostream>
	using namespace std;
	int permutation(int n,int r){
		if(r==0)
			return 1;
		else return n*permutation(n-1,r-1);
	}
	
	int combination(int n,int r){
		if(r==0||r==n)
			return 1;
		else return n*combination(n-1,r-1)/r;
	}
	
	int main(){
		int n,r;
		cout<<"Enter n:";
		cin>>n;
		cout<<"Enter r:";
		cin>>r;
		if(n<0||r<0){
			cout<<"n and r must be positive"<<endl;
			return 0;
		}
		if(n<r){
			cout<<"n must be greater than r"<<endl;
			return 0;
		}
		cout<<"P(n,r):"<<permutation(n,r)<<endl;
		cout<<"C(n,r):"<<combination(n,r)<<endl;

		return 0;
		}
		


