	#include<iostream>
	using namespace std;

	class Relation{
		bool **matrix;
		int n;
		
		public:
		Relation(int size){
			n=size;
			matrix=new bool*[n];
			for(int i=0;i<n;i++)
				matrix[i]=new bool[n];
		}

		Relation(Relation &r){
			n=r.n;
			matrix=new bool*[n];
			for(int i=0;i<n;i++)
				matrix[i]=new bool[n];			
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					matrix[i][j]=r.matrix[i][j];
		}
		
		void getElements(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cin>>matrix[i][j];
				}
			}
		}

		void display(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
					cout<<this->matrix[i][j]<<"  ";
				cout<<endl;
			}
		}
	
		bool isReflexive(){
			for(int i=0;i<n;i++){
				if(matrix[i][i]!=1)
					return false;
			}
			return true;	
		}
		
		bool isAntiSymmetric(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if((matrix[i][j]==1 && matrix[j][i]==1) && i!=j)
						return false;
				}
			}
			return true;
		}

		bool isSymmetric(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(matrix[i][j]!=matrix[j][i])
						return false;
				}
			}
			return true;
		}
		
		bool isTransitive(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					for(int k=0;k<n;k++){
						if(matrix[i][j]==1 && matrix[j][k]==1 && matrix[i][k]!=1)
							return false;
					}
				}
			}
			return true;
		}

		void ReflexiveClosure(){
			if(isReflexive()){
				cout<<"The given matrix is the Reflexive Closure of itself"<<endl;
				return;
			}

			Relation r(*this);
			for(int i=0;i<n;i++){
				if(r.matrix[i][i]!=1){
					r.matrix[i][i]=1;
				}
			}
			cout<<"The given relation"<<endl;
			display();
			
			cout<<"Reflexive Closure of the given relation"<<endl;
			r.display();
		}
							
		void SymmetricClosure(){
			if(isSymmetric()){
				cout<<"The given matrix is the Symmetric Closure of itself"<<endl;
				return;
			}

			Relation r(*this);
			
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(r.matrix[i][j]==1 && r.matrix[j][i]!=1){
						r.matrix[j][i]=1;
					}
				}
			}
			cout<<"The given relation"<<endl;
			display();
			
			cout<<"Symmetric Closure of the given relation"<<endl;
			r.display();
		}
		
		void TransitiveClosure(){
			if(isTransitive()){
				cout<<"The given matrix is the Transitive Closure of itself"<<endl;
				return;
			}
			Relation r(*this);
			
			for(int k=0;k<n;k++){
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if(r.matrix[i][j]==1 && r.matrix[j][k]==1 && r.matrix[i][k]!=1){
							r.matrix[i][k]=1;
						}
					}
				}
			}
			cout<<"The given relation"<<endl;
			display();
			
			cout<<"Transitive Closure of the given relation"<<endl;
			r.display();
		}
		
		~Relation(){
			for(int i=0;i<n;i++)
				delete[] matrix[i];
			delete[] matrix;
		}
	};

	int main(){
		int n;
		cout<<"Enter the order of the square matrix:";
		cin>>n;
		Relation new_r(n);
		cout<<"Enter elements of the matrix"<<endl;
		new_r.getElements();
		new_r.display();
		if(new_r.isReflexive())
			cout<<"The relation matrix entered is reflexive"<<endl;
		else
			cout<<"The relation matrix entered is not reflexive"<<endl;

		if(new_r.isSymmetric())
			cout<<"The relation matrix entered is symmetric"<<endl;
		else
			cout<<"The relation matrix entered is not symmetric"<<endl;
		
		if(new_r.isAntiSymmetric())
			cout<<"The relation matrix entered is anti-symmetric"<<endl;
		else
			cout<<"The relation matrix entered is not anti-symmetric"<<endl;

		if(new_r.isTransitive())
			cout<<"The relation matrix entered is transitive"<<endl;
		else
			cout<<"The relation matrix entered is not transitive"<<endl;
		new_r.ReflexiveClosure();
		new_r.SymmetricClosure();
		new_r.TransitiveClosure();

		return 0;
	}
