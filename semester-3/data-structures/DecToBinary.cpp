#include "stack.cpp"
#include<cmath>

string decToBinary(int n){
	stack<int> s((int)(log2(n) + 1));
	string str = "";
	while(n > 0){
		s.push(n % 2);
		n /= 2;
	}
	
	while(!s.isEmpty())
		str += s.pop() + '0';
	
	return str;
}
int main(){
	int n;
	cout << "Enter number to be converted: ";
	cin >> n;
	cout << decToBinary(n) << endl;
	return 0;
}