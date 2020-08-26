#include<iostream>
using namespace std;

class UTMatrix{
	int size;
	int *arr;
	
	public:
		UTMatrix(int s = 0){
			if(s < 0)
				throw "Invalid Size";
			size = s;
			arr = new int[size * (size + 1) / 2]{0};
		}
		
		void set(int i, int j, int value){
			if(j < i){
				if(value != 0)
					throw "Invalid value for given indices";
				else 
					return;
			}
			
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for Upper Triangular Matrix";
			arr[(j * (j - 1) / 2) + (i - 1)] = value;		
		}
		
		int get(int i, int j){
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for Upper Triangular Matrix";
			if (j < i)
				return 0;
			return arr[(j * (j - 1) / 2) + (i - 1)];
		}
		
		void print(){
			for(int i = 1; i <= size; i++){
				for(int j = 1; j <= size; j++)
					cout << get(i, j) << " ";
				cout << "\n";
			}
		}
	
		
		~UTMatrix(){
			delete arr;
		}
};

int main(){
	int n;
	try{
		cout << "Enter size of the Upper triangular matrix: ";
		cin >> n;
		UTMatrix ltm(n);
		ltm.print();
		cout << endl;
		ltm.set(1, 1, 10);
		ltm.set(1, 2, 30);
		ltm.print();
		cout << endl;
		//ltm.set(2, 1, 20);
		//ltm.set(3, 1, 10);
		cout << "[1, 1]: " << ltm.get(1, 1) << "\n";
		cout << "[2, 1]: " << ltm.get(2 ,1) << "\n";
	}
	catch(const char* s){
		cout << s << endl;
	}
		return 0;
}
