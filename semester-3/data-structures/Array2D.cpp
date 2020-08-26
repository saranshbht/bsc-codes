#include<iostream>
using namespace std;

class Array2D{
	int row, col;
	int **arr;
	
	public:
		Array2D(int r = 0, int c = 0){
			if(r < 0 || c < 0)
				throw "Invalid Size";
			row = r;
			col = c;
			if(r == 0 || c == 0)
				arr = NULL;
			else{ 
				arr = new int*[r];
				for(int i = 0; i < r; i++)
					arr[i] = new int[c];
			}
		}
		
		Array2D(const Array2D &TwoD){
			row = TwoD.row;
			col = TwoD.col;
			arr = new int*[row];
			for(int i = 0; i < row; i++)
				arr[i] = new int[col];
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++)
					arr[i][j] = TwoD.arr[i][j];
			}
		}
		
		Array2D &operator=(const Array2D &TwoD){
			if(this == &TwoD)
			    return *this;
			if(row != TwoD.row || col != TwoD.col){
				for(int i = 0; i < row; i++)
					delete[] arr[i];
				delete[] arr;
				row = TwoD.row;
				col = TwoD.col;
				arr = new int*[row];
				for(int i = 0; i < row; i++)
					arr[i] = new int[col];
			}
			
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++)
					arr[i][j] = TwoD.arr[i][j];
			}
			
			return *this;
		}
		
		int &operator()(int i, int j){
			if(i < 0 || i >= row || j < 0 || j >= col)
				throw "Invalid Index";
			return arr[i][j];
		}
		
		friend istream &operator>>(istream &is, Array2D &TwoD);
		friend ostream &operator<<(ostream &os, Array2D &TwoD);	

		~Array2D(){
			for(int i = 0; i < row; i++)
				delete[] arr[i];
			delete[] arr;
		}
};

istream &operator>>(istream &is, Array2D &TwoD){
			for(int i = 0; i < TwoD.row; i++)
				for(int j = 0; j < TwoD.col; j++)
					is >> TwoD.arr[i][j];
			return is;
}
		
ostream &operator<<(ostream &os, Array2D &TwoD){
			for(int i = 0; i < TwoD.row; i++){
				for(int j = 0; j < TwoD.col; j++)
					os << TwoD.arr[i][j]<< " ";
				os << endl;
			}
			return os;
}

int main(){
	try{
		//Array2D a(-1, 3);
		Array2D a1(2, 3);
		cin >> a1;
		cout << a1;
		cout << a1(0, 1) << endl;
		a1(1, 2) = 50;
		//a1(2, 2) = 50;
		cout << a1;
		Array2D a2;
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