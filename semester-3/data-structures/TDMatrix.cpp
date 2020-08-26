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
				
			if(i < 0 || j < 0 || i >= size || j >= size)
				throw "Invalid Indices for Diagonal Matrix";
			arr[i] = value;		
		}
		
		int get(int i, int j){
			if(i < 0 || j < 0 || i >= size || j >= size)
				throw "Invalid Indices for Diagonal Matrix";
			if (j != i)
				return 0;
			return arr[i];
		}
		
		void print(){
			for(int i = 0; i < size; i++){
				for(int j = 0; j < size; j++){
					if(j != i){
						cout << 0 << " ";
						continue;
					}
					cout << arr[i] << " ";
				}
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
		d.set(0, 0, 10);
		d.set(2, 2, 30);
		d.print();
		cout << endl;
		//d.set(0, 1, 20);
		d.set(0, 1, 0);
		cout << "[0, 0]: " << d.get(0, 0) << "\n";
		cout << "[2, 2]: " << d.get(2, 2) << "\n";
		cout << "[0, 1]: " << d.get(0 ,1) << "\n";
	}
	catch(const char* s){
		cout << s << endl;
	}
		return 0;
}
