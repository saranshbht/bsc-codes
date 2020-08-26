	#include<iostream>
	#include<cmath>
	using namespace std;

	int T1(int n){
		if(n==0)
			return 1;
		return T1(n-1)+n;
	}

	int T2(int n){
		if(n==0)
			return 1;
		return T2(n-1)+(int)pow(n,2);
	}

	int T3(int n){
		if(n==1)
			return 1;
		return 2*T3(n/2)+n;
	}

	int main(){
		cout<<"T1(n)=T1(n-1)+n\nT2(n)=T2(n)=T(n-1)+n^2\nT3(n)=2*T3(n/2)+n\n";
		cout<<"n\tT1\tT2\tT3\n";
		for(int i=1;i<=20;i++){
			cout<<i<<"\t";
			cout<<T1(i)<<"\t";
			cout<<T2(i)<<"\t";
			cout<<T3(i);
			cout<<endl;
		}
	}
