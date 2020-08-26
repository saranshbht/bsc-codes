#include <iostream>
using namespace std;

struct Test{
	int a;
};

int main(){
	Test x, y;
	x.a = 10;
	y = x;
	cout << y.a << endl;
	x.a = 15;
	cout << y.a << endl;
	
	return 0;
}