#include<iostream>
using namespace std;

class DMatrix{
	int size;
	int *arr;
	public:
		DMatrix(int s = 0){
			if(s < 0)
				throw "Invalid Size";
			size = s;
			arr = new int[size]{0};
		}
		
		void set(int i, int j, int value){
			if(i != j){
				if(value != 0)
					throw "Invalid value for given indices";
				else
					return;
			}
				
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for Diagonal Matrix";
			arr[i - 1] = value;		
		}
		
		int get(int i, int j){
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for Diagonal Matrix";
			if (j != i)
				return 0;
			return arr[i - 1];
		}
		
		void print(){
			for(int i = 1; i <= size; i++){
				for(int j = 1; j <= size; j++)
					cout << get(i, j) << " ";
				cout << "\n";
			}
		}
	
		
		~DMatrix(){
			delete arr;
		}
};

int main(){
	int n;
	try{
		cout << "Enter size of the Diagonal Matrix: ";
		cin >> n;
		DMatrix d(n);
		d.print();
		cout << endl;
		d.set(1, 1, 10);
		d.set(3, 3, 30);
		d.print();
		cout << endl;
		//d.set(1, 2, 20);
		d.set(1, 2, 0);
		cout << "[1, 1]: " << d.get(1, 1) << "\n";
		cout << "[3, 3]: " << d.get(3, 3) << "\n";
		cout << "[1, 2]: " << d.get(1 ,2) << "\n";
	}
	catch(const char* s){
		cout << s << endl;
	}
		return 0;
}
