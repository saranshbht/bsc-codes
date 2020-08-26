#include<iostream>
using namespace std;

void combination(int *b,int *a,int index,int n,int start,int c)
{
 if(index==n)
  {int sum=0;
    for(int i=0;i<n;i++)
      sum+=b[i];
   if(sum==c)
   { 
    for(int i=0;i<n;i++)
      cout<<b[i]<<"+";
     cout<<"\b= "<<c<<endl;
   }
   return;
}

for(int i=start;i<=c;i++)
 {b[index]=i;
  combination(b,a,index+1,n,i,c); 
 }
return;
}

 int main()
{
 int c,n,m;
 
 cout<<"Enter the value of constant : ";
 cin>>c;

 cout<<"\nEnter number of non-negative integer :";
 cin>>n;

 int *a=new int[c+1];
   
 for(int i=0;i<(c+1);i++)
   a[i]=i;

int *b=new int[n+1];

combination(b,a,0,n,0,c);


return 0;
}


