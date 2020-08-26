//WAP to print a triangle of stars as follows(take number of lines from user)
/*          *
           ***
          *****
         *******
        *********            */
#include<iostream>
using namespace std;
void spaces(int num, int n) {
	for (int i = 1; i <= (num - n); i++) {
		cout << " ";
	}
	return;
}
void stars(int n) {
	for (int j = 1; j <= ((2 * n) - 1); j++) {
		cout << "*";
	}
	return;
}

int main() {
	int num;
	cout << "Enter number of lines:";
	cin >> num;
	for (int i = 1; i <= num; i++) {
		spaces(num, i);
		stars(i);
		spaces(num, i);
		cout << endl;
	}

	return 0;
}
