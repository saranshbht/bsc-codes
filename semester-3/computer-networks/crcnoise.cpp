#include<iostream>
//#include<conio.h>
using namespace std;
class node
{ public:
	int pow;
	node *next;
};

class CRC
 { node *temp,*head,*tail,*temp1;
	int data[6],t,result[18];
	public:
	 CRC()
	  { head=tail=0;}
	 void get_details();
	 void insert(int);
	 int del();
	 int divide(CRC,CRC);
	 void Send();
	 void Receive();
 }dividend,divisor;

void CRC::get_details()
 {  cout<<"\n\tEnter the data to be transmitted(in binary six bits): ";
		for(int i=0;i<6;i++)
		{ cin>>data[i];}
		for(int i=0;i<6;i++)
		  {  if(data[i]==1)
				{ dividend.insert(i+12);}
		  }

	 divisor.insert(12);
	 divisor.insert(11);
	 divisor.insert(3);
	 divisor.insert(2);
	 divisor.insert(1);
	 divisor.insert(0);
 }

void CRC::insert(int el)
 { temp=new node;
	temp->pow=el;
	temp->next=NULL;
	 if(head==0)
	  { head=tail=temp;}
	 else if(temp->pow > head->pow)
	  { temp->next=head;
		 head=temp;
	  }
	 else if(temp->pow==head->pow)
	  { del(); }
	 else
	  { tail->next=temp;
		 tail=temp;
	  }
 }

int CRC::del()
{ int t;
  if(head==0)
	{t=0;}
  else if(head==tail)
		 { t=head->pow;
			head=tail=0;
		 }
  else
	 { temp=head;
		head=temp->next;
		t=temp->pow;
		delete temp;
	 }
  return t;
}

int CRC::divide(CRC dividend,CRC divisor)
 { int flag;
	while(dividend.head->pow >= 12)
		{   t=dividend.head->pow - 12;
			temp=divisor.head;
			while( temp!=0)
			{  dividend.insert(temp->pow + t);
				temp=temp->next;
			}
		}

	  for(int i=0;i<18;i++)
			{ result[i]=0;}

	 while(dividend.head!=0)
		 { t=dividend.del();
			 if(result[t]==1)
				 {result[t]=0;}
			 else
				 {result[t]=1;}
		 }

	 for(int i=0;i<18;i++)
	  { if(result[i]==1)
			{flag=0;
			 break;
			}
		 else
			{flag=1;}
	  }

	return flag;
 }

void CRC::Send()
{ int b;
	divide(dividend,divisor);
		for(int i=0;i<6;i++)
		 { result[i+12]=data[i];}
	cout<<"\n\n\n\n\tData Transmitted : ";
     for(int i=0;i<18;i++)
		{ cout<<result[i];}
	
	cout<<"\n\n\n\tEnter the bit in which noise is to be added :";
	cin>>b;
	 if(result[b]==1)
	  { result[b]=0;}
	 else
	  { result[b]=1;}
}

void CRC::Receive()
 {  int f;
	cout<<"\n\n\n\n\n\tData Received : ";
	  for(int i=0;i<18;i++)
		{ cout<<result[i];}
		CRC dividend;
	 for(int i=0;i<18;i++)
	  { if(result[i]==1)
			  { dividend.insert(i);}
	  }
	 f=divide(dividend,divisor);
	  if(f==1)
		{ cout<<"\n\n\n\n\tData Transfer Successful";}
	  else
		 { cout<<"\n\n\n\n\tData is corrupted.Send Again";}
 }


int main()
 { //int ch;
	dividend.get_details();
	dividend.Send();
	dividend.Receive();
	return 0;
 }
