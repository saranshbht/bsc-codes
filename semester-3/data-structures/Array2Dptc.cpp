#include<iostream>
using namespace std;

class Array2Dptc{
	int row, col;
	int *arr;
	
	public:
		Array2Dptc(int c = 0, int r = 0){
			if(r < 0 || c < 0)
				throw "Invalid Size";
			row = r;
			col = c;
			if(r == 0 || c == 0)
				arr = NULL;
			else
				arr = new int[r * c];
		}
		
		Array2Dptc(const Array2Dptc &TwoD){
			row = TwoD.row;
			col = TwoD.col;
			arr = new int[row * col];
			for(int i = 0; i < col; i++)
				for(int j = 0; j < row; j++)
				arr[i * row + j] = TwoD.arr[i * row + j];
		}
		
		Array2Dptc &operator=(const Array2Dptc &TwoD){
			if(this == &TwoD)
			    return *this;
			if(row != TwoD.row || col != TwoD.col){
				delete[] arr;
				row = TwoD.row;
				col = TwoD.col;
				arr = new int[row * col];
			}
			
			for(int i = 0; i < col; i++)
				for(int j = 0; j < row; j++)
				arr[j * col + i] = TwoD.arr[i * row + j];
			
			return *this;
		}
		
		int &operator()(int i, int j){
			if(i < 0 || i >= row || j < 0 || j >= col)
				throw "Invalid Index";
			return arr[i * col + j];
		}
		
		friend istream &operator>>(istream &is, Array2Dptc &TwoD);
		friend ostream &operator<<(ostream &os, Array2Dptc &TwoD);	

		~Array2Dptc(){
			delete[] arr;
		}
};

istream &operator>>(istream &is, Array2Dptc &TwoD){
			for(int i = 0; i < TwoD.col; i++)
				for(int j = 0; j < TwoD.row; j++)
					is >> TwoD.arr[i * TwoD.row + j];
			return is;
}
		
ostream &operator<<(ostream &os, Array2Dptc &TwoD){
			for(int i = 0; i < TwoD.col; i++){
				for(int j = 0; j < TwoD.row; j++)
					os << TwoD.arr[i * TwoD.row + j] << " ";
				os << endl;
			}
			return os;
}

int main(){
	try{
		//Array2Dptc a(-1, 3);
		Array2Dptc a1(2, 3);
		cin >> a1;
		cout << a1;
		cout << a1(0, 1) << endl;
		a1(1, 2) = 50;
		//a1(2, 2) = 50;
		cout << a1;
		Array2Dptc a2;
		a2 = a1;
		cout << a1 << a2;
		a1(0, 0) = 50;
		cout << a1 << a2;
		
	}
	catch(const char *s){
		cout << s << endl;
	}
	return 0;
}