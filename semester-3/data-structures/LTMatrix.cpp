#include<iostream>
using namespace std;

class LTMatrix{
	int size;
	int *arr;
	
	public:
		LTMatrix(int s = 0){
			if(s < 0)
				throw "Invalid Size";
			size = s;
			arr = new int[size * (size + 1) / 2]{0};
		}
		
		void set(int i, int j, int value){
			if(j > i){
				if(value != 0)
					throw "Invalid value for given indices";
				else 
					return;
			}
			
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for Lower Triangular Matrix";
			arr[(i * (i - 1) / 2) + (j - 1)] = value;		
		}
		
		int get(int i, int j){
			if(i < 1 || j < 1 || i > size || j > size)
				throw "Invalid Indices for Lower Triangular Matrix";
			if (j > i)
				return 0;
			return arr[(i * (i - 1) / 2) + (j - 1)];
		}
		
		void print(){
			for(int i = 1; i <= size; i++){
				for(int j = 1; j <= size; j++){
					if(j > i){
						cout << 0 << " ";
						continue;
					}
					cout << get(i, j) << " ";
				}
				cout << "\n";
			}
		}
	
		
		~LTMatrix(){
			delete arr;
		}
};

int main(){
	int n;
	try{
		cout << "Enter size of the Lower triangular matrix: ";
		cin >> n;
		LTMatrix ltm(n);
		ltm.print();
		cout << endl;
		ltm.set(1, 1, 10);
		ltm.set(2, 1, 30);
		ltm.print();
		cout << endl;
		ltm.set(1, 0, 20);
		ltm.set(1, 2, 0);
		cout << "[1, 1]: " << ltm.get(1, 1) << "\n";
		cout << "[1, 2]: " << ltm.get(1 ,2) << "\n";
	}
	catch(const char* s){
		cout << s << endl;
	}
		return 0;
}
