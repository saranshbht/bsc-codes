#include "Array1D.cpp"
#include<iostream>
using namespace std;

class Array12D{
	int row, col;
	Array1D *arr;
	
	public:
		Array12D(int r = 0, int c = 0){
			if(r < 0 || c < 0)
				throw "Invalid Size";
			row = r;
			col = c;
			if(r == 0 || c == 0)
				arr = NULL;
			else{
				arr = new Array1D[r];
				for(int i = 0; i < r; i++)
					arr[i].resize(c);
			}
		}
		
		Array12D(const Array12D &TwoD){
			row = TwoD.row;
			col = TwoD.col;
			arr = new Array1D[row];
			for(int i = 0; i < row; i++)
				arr[i].resize(col);
			
			for(int i = 0; i < row; i++)
				for(int j = 0; j < col; j++)
					arr[i][j] = TwoD.arr[i][j];
		}
		
		Array1D &operator[](int i){
			if(i < 0 || i >= row)
				throw "Invalid Index";
			return arr[i];
		}
		
		Array12D &operator=(const Array12D &TwoD){
			if(this == &TwoD)
			    return *this;
			if(row != TwoD.row || col != TwoD.col){
				delete[] arr;
				row = TwoD.row;
				col = TwoD.col;
				arr = new Array1D[row];
				for(int i = 0; i < row; i++)
					arr[i].resize(col);
			}
			
			for(int i = 0; i < row; i++)
				for(int j = 0; j < col; j++)
					arr[i][j] = TwoD.arr[i][j];
			
			return *this;
		}
		
		friend istream &operator>>(istream &is, Array12D &TwoD);
		friend ostream &operator<<(ostream &os, Array12D &TwoD);	

		~Array12D(){
			delete[] arr;
		}
};

istream &operator>>(istream &is, Array12D &TwoD){
			for(int i = 0; i < TwoD.row; i++)
				for(int j = 0; j < TwoD.col; j++)
					is >> TwoD.arr[i][j];
			return is;
}
		
ostream &operator<<(ostream &os, Array12D &TwoD){
			for(int i = 0; i < TwoD.row; i++){
				for(int j = 0; j < TwoD.col; j++)
					os << TwoD.arr[i][j] << " ";
				os << endl;
			}
			return os;
}

int main(){
	try{
		//Array12D a(-1, 3);
		Array12D a1(2, 3);
		cin >> a1;
		cout << a1;
		cout << a1[0][1] << endl;
		a1[1][2] = 50;
		//a1[2][2] = 50;
		cout << a1;
		Array12D a2;
		a2 = a1;
		cout << a1 << a2;
		a1[0][0] = 50;
		cout << a1 << a2;
		
	}
	catch(const char *s){
		cout << s << endl;
	}
	return 0;
}