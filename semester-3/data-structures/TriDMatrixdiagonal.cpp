#include<iostream>
#include<cmath>
using namespace std;

class TriDMatrix{
	int size;
	int *arr;
	public:
		TriDMatrix(int s = 0){
			if(s < 0)
				throw "Invalid Size";
			size = s;
			arr = new int[3 * size - 2]{0};
		}
		
		void set(int i, int j, int value){
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for TriDiagonal Matrix";
				
			if(abs(i - j) > 1){ 
				if(value != 0)
					throw "Invalid value for given indices";
				else
					return;
			}
				
			arr[2 * (i - 1) + (j - 1)]  = value;		
		}
		
		int get(int i, int j){
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for TriDiagonal Matrix";
			if (abs(i - j) > 1)
				return 0;
			return arr[2 * (i - 1) + (j - 1)];
		}
		
		void print(){
			for(int i = 1; i <= size; i++){
				for(int j = 1; j <= size; j++)
					cout << get(i, j) << " ";
				cout << "\n";
			}
		}
	
		
		~TriDMatrix(){
			delete arr;
		}
};

int main(){
	int n;
	try{
		cout << "Enter size of the TriDiagonal Matrix: ";
		cin >> n;
		TriDMatrix td(n);
		td.print();
		cout << endl;
		td.set(1, 1, 10);
		//td.set(1, 3, 20);
		td.set(3, 3, 30);
		td.print();
		cout << endl;
		td.set(1, 2, 40);
		//td.set(3, 1, 20);
		cout << "[1, 1]: " << td.get(1, 1) << "\n";
		cout << "[3, 3]: " << td.get(3, 3) << "\n";
		cout << "[1, 2]: " << td.get(1 ,2) << "\n";
	}
	catch(const char* s){
		cout << s << endl;
	}
		return 0;
}
