#include<iostream>
using namespace std;

class Array2Dptr{
	int row, col;
	int *arr;
	
	public:
		Array2Dptr(int r = 0, int c = 0){
			if(r < 0 || c < 0)
				throw "Invalid Size";
			row = r;
			col = c;
			if(r == 0 || c == 0)
				arr = NULL;
			else
				arr = new int[r * c];
		}
		
		Array2Dptr(const Array2Dptr &TwoD){
			row = TwoD.row;
			col = TwoD.col;
			arr = new int[row * col];
			for(int i = 0; i < row; i++)
				for(int j = 0; j < col; j++)
				arr[i * col + j] = TwoD.arr[i * col + j];
		}
		
		Array2Dptr &operator=(const Array2Dptr &TwoD){
			if(row * col != TwoD.row * TwoD.col){
				delete[] arr;
				row = TwoD.row;
				col = TwoD.col;
				arr = new int[row * col];
			}
			
			for(int i = 0; i < row; i++)
				for(int j = 0; j < col; j++)
				arr[i * col + j] = TwoD.arr[i * col + j];
			
			return *this;
		}
		
		int &operator()(int i, int j){
			if(i < 0 || i >= row || j < 0 || j >= col)
				throw "Invalid Index";
			return arr[i * col + j];
		}
		
		friend istream &operator>>(istream &is, Array2Dptr &TwoD);
		friend ostream &operator<<(ostream &os, Array2Dptr &TwoD);	

		~Array2Dptr(){
			delete[] arr;
		}
};

istream &operator>>(istream &is, Array2Dptr &TwoD){
			for(int i = 0; i < TwoD.row; i++)
				for(int j = 0; j < TwoD.col; j++)
					is >> TwoD.arr[i * TwoD.col + j];
			return is;
}
		
ostream &operator<<(ostream &os, Array2Dptr &TwoD){
			for(int i = 0; i < TwoD.row; i++){
				for(int j = 0; j < TwoD.col; j++)
					os << TwoD.arr[i * TwoD.col + j] << " ";
				os << endl;
			}
			return os;
}

int main(){
	try{
		//Array2Dptr a(-1, 3);
		Array2Dptr a1(2, 3);
		cin >> a1;
		cout << a1;
		cout << a1(0, 1) << endl;
		a1(1, 2) = 50;
		//a1(2, 2) = 50;
		cout << a1;
		Array2Dptr a2(a1);
		cout << a1 << a2;
		a1(0, 0) = 50;
		cout << a1 << a2;
		
	}
	catch(const char *s){
		cout << s << endl;
	}
	return 0;
}