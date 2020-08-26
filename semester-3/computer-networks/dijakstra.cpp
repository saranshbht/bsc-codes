#include<iostream>
//#include<conio.h>
using namespace std;

 int m;
 char o;
class node
 { public:
	 char vertex;
	 char pred;
	 int weight;
	 node *next;
 };

class vertices
 { node *head,*tail,*temp,*temp1,*temp2;
	public:
	 vertices()
	  { head=tail=0;}
	 void insert(char,char,int);
	 char extract_min();
	 int isempty();
	 int search(char,char,int);
	 void showpath(char,char);
 }tentative,permanent;

void vertices::insert(char el,char el1,int el2)
{ temp=new node;
  temp->vertex=el;
  temp->pred=el1;
  temp->weight=el2;
  temp->next=NULL;
  if(head==0)
	 { head=tail=temp;}
  else
	 { temp1=head;
		 while(temp1)
		 { if(temp->weight<head->weight)
				  { temp->next=head;
					 head=temp;
					 break;
				  }
			else if(temp1->next==0)
					{ tail->next=temp;
					  tail=temp;
					  break;
					}
			else 
if(temp->weight>temp1->weight&&temp->weight<temp1->next->weight)
					{ temp->next=temp1->next;
					  temp1->next=temp;
					  break;
					}
			else
				  { temp1=temp1->next;}
		 }
	 }
}

char vertices::extract_min()
{  int n;
  if(head==0)
	 { n=0;
		cout<<"\n\tStack is empty";
	 }
  else if(head==tail)
	 { m=head->weight;
		n=head->vertex;
		o=head->pred;
		head=tail=0;
	 }
  else
	 { temp1=head;
		head=temp1->next;
		n=temp1->vertex;
		o=temp1->pred;
		m=temp1->weight;
		delete temp1;
	 }
  return n;
}


int vertices::isempty()
{ if(tail==0)
	 return 1;
  else
	 return 0;
}

int vertices::search(char el,char el2,int el1)
{ int flag=0;
  temp=head;
  temp1=permanent.head;
	while(temp1!=0)
	 { if(temp1->vertex==el)
		  { flag=1;
			 break;
		  }
		else
		  { temp1=temp1->next;}
	 }
	if(flag==0)
	 {
		while(temp!=0)
		 { if(temp->vertex==el)
			 { if(temp->weight>el1)
					 { temp->weight=el1;
					temp->pred=el2;
					 }
				flag=1;
				break;
			 }
			else
				{ temp=temp->next;}
		 }
	 }
	return flag;
}

 void vertices::showpath(char s,char d)
 {  char t[15],v;
	 int w,i=0;
	  v=d;
		  while(v!=s)
				{ temp=head;
					while(temp!=0)
					 { if(temp->vertex==d)
						  { w=temp->weight;}
						if(v==temp->vertex)
						  { t[i]=v;
						i++;
						v=temp->pred;
						break;
						  }
						temp=temp->next;
					 }
				 }
			 t[i]=s;
	 cout<<"\n\t\tThe shortest path from node "<<s<<" to node "<<d<<" is : ";
		 for(int j=i;j>=0;j--)
		  { cout<<t[j]<<" ";}
	  cout<<"\n\t\tThe total weight of the path is : "<<w;
  }

int main()
{ int v,e,weight[15],t;
  char vertices[15],from[15],to[15],root,node,dest;
  cout<<"\n\tEnter the no. of nodes : ";
  cin>>v;
  cout<<"\n\tEnter the nodes : ";
  for(int i=0;i<v;i++)
	{ cin>>vertices[i];}
//  clrscr();
  cout<<"\n\tEnter the no. of routes : ";
  cin>>e;
  cout<<"\n\tEnter the routes and their weights :\n";
  for(int i=0;i<e;i++)
	{ cin>>from[i]>>to[i]>>weight[i]; }
 // clrscr();
  cout<<"\n\tEnter the SOURCE node : ";
  cin>>root;
	 tentative.insert(root,0,0);
	while(!tentative.isempty())
	 {  node=tentative.extract_min();
		 permanent.insert(node,o,m);
		  for(int i=0;i<e;i++)
			{  if(from[i]==node){
		t=tentative.search(to[i],from[i],weight[i]+m);
					  if(t==0)						 {tentative.insert(to[i],from[i],weight[i]+m);}
					}
				if(to[i]==node)
					{
		t=tentative.search(from[i],to[i],weight[i]+m);
					  if(t==0){
			tentative.insert(from[i],to[i],weight[i]+m);}
					}
			}

	 }

	cout<<"\n\tEnter the destination node : ";
	cin>>dest;
	permanent.showpath(root,dest);
}
