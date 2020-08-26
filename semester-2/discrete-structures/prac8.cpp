	#include<iostream>
	using namespace std;

	void ToH(char a,char b,char c,int n){
		if(n<=0)
			return;
		ToH(a,c,b,n-1);
		cout<<"Transfer disk "<<n<<" from "<<a<<" to "<<c<<endl;
		ToH(b,a,c,n-1);
	}

	int main(){
		char a='A',b='B',c='C';
		int n;
		cout<<"Enter number of disks:";
		cin>>n;
		cout<<"Steps to Transfer all disks from "<<a<<" to "<<c<<" following rules of Tower of Hanoi"<<endl;
		ToH(a,b,c,n);
		
		return 0;
	}
