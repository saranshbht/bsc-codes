#include<iostream>
using namespace std;

class Array1D{
	int size;
	int *arr;
	
	public:
		Array1D(int n = 0){
			if(n < 0)
				throw "Invalid Size";
			size = n;
			if(size == 0)
				arr = NULL;
			else 
				arr = new int[size];
		}
		
		Array1D(const Array1D &OneD){
			size = OneD.size;
			arr = new int[size];
			for(int i = 0; i < size; i++)
				arr[i] = OneD.arr[i];
		}
		
		int length(){
			return size;
		}
		
		Array1D &operator=(const Array1D &OneD){
			if(this == &OneD)
			    return *this;
			if(size != OneD.size){
				delete[] arr;
				size = OneD.size;
				arr = new int[size];
			}
			
			for(int i = 0; i < size; i++)
				arr[i] = OneD.arr[i];
			
			return *this;
		}
		
		int &operator[](int i){
			if(i < 0 || i >= size)
				throw "Invalid Index";
			return arr[i];
		}
		
		Array1D operator+(Array1D &OneD){
		    Array1D a(size + OneD.size);
		    for(int i = 0; i < size; i++)
		        a.arr[i] = arr[i];
		    for(int i = size; i < (size + OneD.size); i++)
		        a.arr[i] = OneD.arr[i - size];
		    return a;
		}
		
		void resize(int n){
			if(size < 0)
				throw "Invalid Size";
			if(size != n){ 
				size = n;
				delete[] arr;
				arr = new int[size];
			}
		}
		
		friend istream &operator>>(istream &is, Array1D &OneD);
		friend ostream &operator<<(ostream &os, Array1D &OneD);	

		~Array1D(){
			delete[] arr;
		}
};

istream &operator>>(istream &is, Array1D &OneD){
			for(int i = 0; i < OneD.size; i++)
				is >> OneD.arr[i];
			return is;
}
		
ostream &operator<<(ostream &os, Array1D &OneD){
			for(int i = 0; i < OneD.size; i++)
				os << OneD.arr[i] << " ";
			os << endl;
			return os;
}

int main(){
	try{
		//Array1D a(-2);
		Array1D a1(4);
		Array1D a2(5);
		cin >> a1 >> a2;
		cout << a1 << a2;
		cout << a1.length() << endl;
		//cout << a1[-1];
		cout << a1[3];
		a1[2] = 10;
		cout << a1 << a2;
		Array1D a3 = a1 + a2;
		cout << a3;
		Array1D a4;
		a4 = a1;
		cout << a4;
	}
	catch(char const *s){
		cout << s << endl;
	}
	
	return 0;
}
