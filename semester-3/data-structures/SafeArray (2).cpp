#include <iostream>
#include<cstdlib>
using namespace std;

template<class T>
class SafeArray{
	T *arr;
	public:
		int length;
		
		SafeArray(int n){
			arr = new T[n];
			length = n;
		}
		
		T &operator[](int i){
			if(i >= length){
				cout << "Array Index out of bounds" << endl;
				exit(1);
			}
			return arr[i];
		}
		
		~SafeArray(){
			delete arr;
		}
};

int main()
{
	int n;
	cout << "Enter no. of elements u want in your array: ";
	cin >> n;
	SafeArray<char> sa(n);
	sa[0] = 68;
	sa[n - 1] = 89;
	cout << sa[0] << sa[n - 1] << endl;
	cout << sa.length;
	return 0;
}
