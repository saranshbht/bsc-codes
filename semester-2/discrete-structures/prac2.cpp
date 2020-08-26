	#include<iostream>
	#include<cmath>
	using namespace std;

	class Set{

	    public:
		char *arr;
		int c;

		Set(int i){
       			c=i;
        		arr=new char[c];
      		}

		void getElements(){
			cout<<"\nEnter array elements:\n";
			for(int i=0;i<c;i++)
				cin>>arr[i];
		}

		void removeDuplicates(){
			for(int i=0;i<c;i++){
				for(int j=(i+1);j<c;j++){
					if(arr[i]==arr[j]){
						for(int k=j;k<(c-1);k++)
							arr[k]=arr[k+1];
						c--;
						j--;
					}

				}
			}
		}
		
		bool ismember(char ch){
			for(int i=0;i<c;i++)
				if(arr[i]==ch)
				    return true;
			return false;
		}

		void display(){
			cout<<"\nSet:";
			for(int i=0;i<c;i++)
			    cout<<arr[i]<<"\t";
			cout<<endl;
		}

		Set SetUnion(Set &s);
		Set SetIntersection(Set &s);
		Set SetDifference(Set &s);
		Set SetSymDifference(Set &s);
		bool Subset(Set &s);
    		void C_Product(Set &s);
	
		~Set(){
			delete[] arr;
		}
	};
	
	Set Set::SetUnion(Set &s){  
		Set temp(c+s.c);
		int k=0;
		for(int i=0;i<c;i++)
			temp.arr[k++]=arr[i];
		for(int j=0;j<s.c;j++)
			temp.arr[k++]=s.arr[j];
		temp.c=k;
		temp.removeDuplicates();
		return temp;
	}
   
	Set Set::SetIntersection(Set &s){
		Set temp((c<s.c)?c:s.c);
		int k=0;
		for(int i=0;i<c;i++){
			for(int j=0;j<s.c;j++){
				if(arr[i]==s.arr[j])
				   temp.arr[k++]=arr[i];
			}
		}		
		temp.c=k;
		temp.removeDuplicates();
		return temp;
	}
   
	Set Set::SetDifference(Set &s){
		Set temp(c);
		int k=0;
		for(int i=0;i<c;i++){ 
			int flag=0;
			for(int j=0;j<s.c;j++){
				if(arr[i]==s.arr[j]){
				  flag=1;
				  break;
				}
			}
			if(flag==0)
			temp.arr[k++]=arr[i];
		}
		temp.c=k;
		temp.removeDuplicates();
		return temp;
	}
   
	Set Set::SetSymDifference(Set &s){   
		Set temp1=SetUnion(s);
		Set temp2=SetIntersection(s);
		Set temp=temp1.SetDifference(temp2);
		return temp;
	}

	bool Set::Subset(Set &s){
		if(c==0)
			return true;
			   
		bool flag=false;
		for(int i=0;i<c;i++){  
			if(s.ismember(arr[i])) 
				flag=true;
			else{     
			   flag=false;
			   break;
			}
		}
		return flag;
	}

	void Set::C_Product(Set &s){
		for(int i=0;i<c;i++)
			for(int j=0;j<s.c;j++)
				cout<<"("<<arr[i]<<","<<s.arr[j]<<")"<<"\t";
		cout<<endl;		
 	}

	int main(){
		int num1,num2,n;
		char choice;
		  cout<<"\nEnter how many elements do you want in the first set(A):";
		  cin>>num1;
		Set s1(num1);
		s1.getElements();
		  cout<<"\nEnter how many elements do you want in the second set(B):";
		  cin>>num2;
		Set s2(num2);
		s2.getElements();
	do{
		  cout<<"\n1.Union\n2.Intersection\n3.Set Difference\n4.Symmetric Difference\n5.Subset\n6.Cartesian Product\n";
		  cout<<"\nEnter your choice:";
		  cin>>n;

		switch(n){
			
			case 1:	{
					Set UnionSet=s1.SetUnion(s2);
					UnionSet.display();
					break;
				}
			case 2:	{
					Set IntersectSet=s1.SetIntersection(s2);
					IntersectSet.display();
					break;
				}
			case 3:	{      
					int choice;
                          		cout<<"1.A-B\n2.B-A\n";
                         		cin>>choice;
					if(choice==1){
						Set DiffSet1=s1.SetDifference(s2);
						DiffSet1.display();
						break;
					}
					else if(choice==2){
						Set DiffSet2=s2.SetDifference(s1);
						DiffSet2.display();
						break;
					}
				}
			case 4:	{
					Set SymDiffSet=s1.SetSymDifference(s2);
					SymDiffSet.display();
					break;
				}
			case 5:	{     if(s1.Subset(s2)||s2.Subset(s1)){
					if(s1.Subset(s2)){
						cout<<"A is a subset of B\n";
					}
					if(s2.Subset(s1)){ 
						cout<<"B is a subset of A\n";
					}
					break;
				      }
					else{
						cout<<"No subset\n";
						break;
					}
				}
			case 6:	{	
					int choice;
                          		cout<<"1.AXB\n2.BxA\n";
                         		cin>>choice;
					if(choice==1){
						s1.C_Product(s2);
						break;
					}
					if(choice==2){
						s2.C_Product(s1);
						break;
					}
				}
			default:	cout<<"Wrong Input!!";
		}
		
		cout<<"Do you want to perform another operation?(Press 'Y' for yes):";
		cin>>choice;
		}while(choice=='y'||choice=='Y');
 
	return 0;
      }

