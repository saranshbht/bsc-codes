//WAP that prints a table indicating the number of occurrences of each alphabet in the text entered
//as command-line arguments
#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
	cout << "Alphabet=>Number of occurrences" << endl;
	for (int k = 65; k < 91; k++) {
		int count = 0;
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j] != 0; j++) {
				if (argv[i][j] == (char)(k) || argv[i][j] == (char)(k + 32)) {
					count++;
				}
			}
		}
		cout << (char)k << "=>" << count << endl;
	}
	return 0;
}
