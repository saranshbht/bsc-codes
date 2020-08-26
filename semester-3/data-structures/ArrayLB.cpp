#include<iostream>
using namespace std;

class ArrayBounds{
	int ub, lb;
	int *arr;
	
	public:
		ArrayBounds(int l = 0, int u = 0){
			if (l > u)
				throw "Invalid bounds";
			
			ub = u;
			lb = l;
			arr = new int[u - l + 1];
				
		}
		
		ArrayBounds(const ArrayBounds &OneD){
			ub = OneD.ub;
			lb = OneD.lb;
			arr = new int[ub - lb + 1];
			for(int i = lb; i <= ub; i++)
				arr[i - lb] = OneD.arr[i - lb];
		}
		
		int length(){
			return (ub - lb + 1);
		}
		
		int &operator[](int i){
			if(i < lb || i > ub)
				throw "Invalid Index";
			return arr[i - lb];
		}
		
		ArrayBounds &operator=(const ArrayBounds &OneD){
			if(this == &OneD)
			    return *this;
			if((ub - lb) != (OneD.ub - OneD.lb)){
				delete[] arr;
				arr = new int[OneD.ub - OneD.lb + 1];
			}
			
			ub = OneD.ub;
			lb = OneD.lb;
			
			for(int i = lb; i <= ub; i++)
				arr[i - lb] = OneD.arr[i - lb];
			
			return *this;
		}
		
		/*ArrayBounds operator+(ArrayBounds &OneD){
		    ArrayBounds a();
		    for(int i = lb; i <= ub; i++)
		        a.arr[i - lb] = arr[i - lb];
		    int j = 0;
			for(int i = ub + 1; i < a.length(); i++)
		        a.arr[i] = OneD.arr[j++];
		    return a;
		}*/
		
		friend istream &operator>>(istream &is, ArrayBounds &OneD);
		friend ostream &operator<<(ostream &os, ArrayBounds &OneD);	

		~ArrayBounds(){
			delete[] arr;
		}
};

istream &operator>>(istream &is, ArrayBounds &OneD){
			for(int i = OneD.lb; i <= OneD.ub; i++)
				is >> OneD.arr[i - OneD.lb];
			return is;
		}
		
ostream &operator<<(ostream &os, ArrayBounds &OneD){
			for(int i = OneD.lb; i <= OneD.ub; i++)
				os << OneD.arr[i - OneD.lb] << " ";
			os << endl;
			return os;
		}

int main(){
	try{
		//ArrayBounds a(-2, -3);
		ArrayBounds a1(2, 5);
		ArrayBounds a2(3, 7);
		cin >> a1 >> a2;
		cout << a1 << a2;
		cout << a1.length() << endl;
		cout << a1[5] << endl;
		//cout << a1[1] << endl;
		a1[2] = 10;
		cout << a1;
		ArrayBounds a4;
		a4 = a1;
		cout << a1 << a4;
		a4[3] = 90;
		cout << a1 << a4;
		ArrayBounds25 a3 = a2;
		cout << a2 << a3;
		a3[7] = 80;
		cout << a2 << a3;
	}
	catch(char const *s){
		cout << s << endl;
	}
	
	return 0;
}
