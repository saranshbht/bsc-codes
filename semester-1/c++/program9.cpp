//WAP to print the stars as follows(take number of lines from the user)
/*            *
             ***
            *****
           *******
          *********                  */
#include<iostream>
using namespace std;

void spaces(int n, int j) {
	for (int k = (n - j); k > 0; k--) {
		cout << " ";
	}
}
void stars(int n) {
	for (int j = 0; j < (2 * n - 1); j++) {
		cout << "*";
	}
}

int main() {
	int num;
	cout << "Enter the number of lines:";
	cin >> num;
	cout << endl;
	for (int i = 1; i <= num; i++) {
		spaces(num, i);
		stars(i);
		spaces(num, i);
		cout << endl;
	}
	return 0;
}
