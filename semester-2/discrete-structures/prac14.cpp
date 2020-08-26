#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int d,x,sum=0;
	cout<<"Enter degree of polynomial:";
	cin>>d;
	
	int d_copy=d;
	int *coeff=new int[d+1];
	
	cout<<"Enter the coefficients:"<<endl;
	for (int i=0;i<(d+1);i++)
		cin>>coeff[i];
	
	
	cout<<endl<<"Polynomial:"<<endl;
	cout<<"f(x)= ";
	for(int i=0;i<d;i++){
		cout<<" "<<coeff[i]<<"x^"<<d_copy--<<" ";
		if(coeff[i+1]==0){
			d_copy--;
			i++;
		}
		if(coeff[i+1]>0)
			cout<<"+";
		
	}	
	cout<<" "<<coeff[d]<<endl;
	
	d_copy=d;
	cout<<"Enter x:";
	cin>>x;
	
	for(int i=0;i<(d+1);i++)
		sum+=coeff[i]*pow(x,d_copy--);
		
	cout<<"f("<<x<<")= "<<sum;
	
	delete[] coeff;
	return 0;
}