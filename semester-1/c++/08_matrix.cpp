#include<iostream>
using namespace std;

int check(int r, int c, int m, int n) {
	if ((r == m) && (c == n)) {
		return 1;
	}
}

int check1(int r, int c, int m, int n) {
	if (c == m) {
		return 2;
	}
}

void addition(int **i, int **j, int r, int l) {
	int **c = new int *[r];
	for (int i = 0; i < r; i++) {
		c[i] = new int[l];
	}

	for (int a = 0; a < r; a++) {
		for (int b = 0; b < l; b++) {
			c[a][b] = i[a][b] + j[a][b];
			cout << c[a][b] << "\t";
		}
		cout << "\n";
	}
}

void subtraction(int **i, int **j, int r, int l) {
	int **c = new int *[r];
	for (int i = 0; i < r; i++) {
		c[i] = new int[l];
	}

	for (int a = 0; a < r; a++) {
		for (int b = 0; b < l; b++) {
			c[a][b] = i[a][b] - j[a][b];
			cout << c[a][b] << "\t";
		}
		cout << "\n";
	}
}

void multiplication(int **i, int **j, int r, int l, int m, int n) {
	int **c = new int *[r];
	for (int i = 0; i < r; i++) {
		c[i] = new int[n];
	}

	for (int a = 0; a < r; a++) {
		for (int b = 0; b < n; b++) {
			for (int k = 0; k < l; k++) {
				c[a][b] = c[a][b] + i[a][k] * j[k][b];
			}
			cout << c[a][b] << "\t";
		}
		cout << "\n";
	}
}

void transpose(int **i, int r, int l) {
	int **c = new int *[l];
	for (int i = 0; i < r; i++) {
		c[i] = new int[r];
	}

	for (int a = 0; a < l; a++) {
		for (int b = 0; b < r; b++) {
			c[a][b] = i[b][a];
			cout << c[a][b] << "\t";
		}
		cout << "\n";
	}
}


int main() {
	int choice;
	int r, c, m, n;
	cout << "How many rows do you want in the first matrix?:";
	cin >> r;
	cout << endl << "How many columns do you want in the first matrix?:";
	cin >> c;
	int **a = new int *[r];
	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
	}
	cout << endl << "How many rows do you want in the second matrix?:";
	cin >> m;
	cout << endl << "How many columns do you want in the second matrix?:";
	cin >> n;
	int **b = new int *[m];
	for (int j = 0; j < m; j++) {
		b[j] = new int[n];
	}

	cout << endl << "Enter elements of first matrix:" << endl;
	for (int k = 0; k < r; k++) {
		for (int l = 0; l < c; l++) {
			cin >> a[k][l];
			cout << "\t";
		}
		cout << "\n";
	}

	cout << endl << "Enter elements of second matrix:" << endl;
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			cin >> b[x][y];
			cout << "\t";
		}
		cout << "\n";
	}

	do {

		cout << "M E N U" << endl;
		cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n0.Exit" << endl;
		cout << "Enter your choice:";
		cin >> choice;

		switch (choice) {
			case 1:  if (check(r, c, m, n) == 1) {
					addition(a, b, r, c);
				} else {
					cout << endl << "The matrices cannot be added";
				}
				break;

			case 2:  if (check(r, c, m, n) == 1) {
					subtraction(a, b, r, c);
				} else {
					cout << endl << "The matrices cannot be subtracted";
				}
				break;

			case 3:  if (check1(r, c, m, n) == 2) {
					multiplication(a, b, r, c, m, n);
				} else {
					cout << endl << "The matrices cannot be multiplied";
				}
				break;

			case 4:  {
					int x;
					cout << endl << "Of which matrix do you want the transpose(Either 1 or 2):";
					cin >> x;
					if (x == 1) {
						transpose(a, r, c);
					} else if (x == 2) {
						transpose(b, m, n);
					}
				}

			case 0:   break;

			default : cout << "Wrong choice!!";
		}

	} while (choice != 0);

	return 0;
}


