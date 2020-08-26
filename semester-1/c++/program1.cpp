//WAP to print the sum and product of digits of an integer.

#include<iostream>
using namespace std;

int main()
{
   int a;
   int sum=0,prod=1;
   cout<<"Enter an integer:";
   cin>>a;
   if(a==0)
{
    sum=0;
    prod=0;
}
  if(a<0)
{  a*=-1;

     while(a!=0)
    {
        sum+=a%10;
        prod*=a%10;
        a/=10;
        if(a<10)
            a*=-1;
    }
}
   else
   {
     while(a>0)
    {
        sum+=a%10;
        prod*=a%10;
        a/=10;
   }
}

   cout<<endl<<"Sum of digits of the number:"<<sum;
   cout<<endl<<"Product of digits of the number:"<<prod<<endl;
 return 0;

 }
