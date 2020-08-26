	#include<iostream>	
	#include<cmath>
	using namespace std;

	class Set{
    		char *arr;
    		int c;

      	     public:
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

       		int cardinality(){
         		return c;
        	}

        	void display(){
            		cout<<"Set: [";
            		for(int i=0;i<c;i++)
                		cout<<arr[i]<<" ";
			cout<<"]";
        	}
        	~Set(){
        		delete[] arr;
      		}
		void Powerset();
	};

   	void Set::Powerset(){
    		for(int i=0;i<pow(2,c);i++){ 
			int r=i;
      			if(r==0){
           			cout<<"[ Empty Set ]\n";
           			continue;
			 }
			cout<<"[ ";

      			for(int j=0;j<c;j++){  
				if(r%2)  
					cout<<arr[j]<<" ";
           			r/=2;
			}
     			cout<<" ]\n";
   		}
	}



	int main(){ 
    		int num;  
    		char ch;
     		cout<<"Enter the number of elements you want in the set:";
     		cin>>num;
    		Set s(num);

    		s.getElements();
    		s.display();
		s.removeDuplicates();
    		cout<<"\nSet after removing duplicates:\n";
    		s.display();

    		cout<<"\nCardinality of the set:"<<s.cardinality();
    
    		cout<<"\nPowerset:\n";
    		s.Powerset();

    		cout<<"\nEnter the element whose membership you want to check:";
    		cin>>ch;

    		if(s.ismember(ch)) cout<<"\nThe element is a member of the set\n";
    		else cout<<"\nThe element is not a member of the set\n";
    		return 0;
	}
