#include<iostream>
using namespace std;

bool conjunction(bool a,bool b){
	if(!a) return false;
	else{
		if(!b) return false;
		else return true;
	}
}

bool disjunction(bool a,bool b){
	if(a) return true;
	else{
		if(b) return true;
		else return false;
	}
}

bool exclusiveOR(bool a,bool b){
	if(a){
		if(!b) return true;
		else return false;
	}
	else{
		if(b) return true;
		else return false;
	}
}

bool Conditional(bool a,bool b){
	if(!a) return true;
	else{
		if(!b) return false;
		else return true;
	}
}

bool biconditional(bool a,bool b){
	if(a){
		if(b) return true;
		else return false;
	}
	else{
		if(!b) return true;
		else return false;
	}
}


int main(){
	bool x,y;
	cout<<"Enter truth value of X:";
	cin>>x;
	cout<<"Enter truth value of Y:";
	cin>>y;
	
	
		cout<<"\n1.X && Y : "<<conjunction(x,y);
		cout<<"\n2.X || Y : "<<disjunction(x,y);
		cout<<"\n3.X ^ Y : "<<exclusiveOR(x,y);
		cout<<"\n4.X => Y : "<<Conditional(x,y);
		cout<<"\n5.X <=> Y : "<<biconditional(x,y);


return 0;
}
