#include<iostream>
using namespace std;

class test{
	public:
		int n;
		test(int a = 0){
			n = a;
		}
};

int main(){
	test t;
	cout << t.n;
	
	return 0;
}