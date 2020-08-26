//Given two ordered arrays of integers,write a program to merge the two arrays to get an
//ordered array
#include<iostream>
using namespace std;

int main() {
	int num, num1, choice;
	cout << "Specify order of elements in arrays:";
	cout << endl << "\n1)Ascending\n2)Descending" << endl;
	cin >> choice;
	cout << "Enter how many elements you want in the first array:";
	cin >> num;
	int *arr = new int[num];
	cout << endl << "Enter array elements:" << endl;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	cout << "Enter how many elements you want in the second array:";
	cin >> num1;
	int *arr1 = new int[num1];
	cout << endl << "Enter array elements:" << endl;
	for (int j = 0; j < num1; j++) {
		cin >> arr1[j];
	}

	int *new_arr = new int[num + num1];
	int k = 0;

	if (choice == 1) {
		int x = 0, y = 0;
		while (x < num && y < num1) {

			if (arr[x] < arr1[y]) {
				new_arr[k++] = arr[x++];
			} else {
				new_arr[k++] = arr1[y++];
			}
		}
		if (x < num) {
			while (x < num) {
				new_arr[k++] = arr[x++];
			}
		} else if (y < num1) {
			while (y < num) {
				new_arr[k++] = arr1[y++];
			}
		}
	} else if (choice == 2) {
		int x = 0, y = 0;
		while (x < num && y < num1) {

			if (arr[x] > arr1[y]) {
				new_arr[k++] = arr[x++];
			}
			// cout<<endl<<new_arr[k];
			else {
				new_arr[k++] = arr1[y++];
			}
			//cout<<endl<<new_arr[k];
		}
		if (x < num) {
			while (x < num) {
				new_arr[k++] = arr[x++];
			}
		}
		//cout<<endl<<new_arr[k];
		else if (y < num1) {
			while (y < num1) {
				new_arr[k++] = arr1[y++];
			}
		}
		//cout<<endl<<new_arr[k];
	}
	cout << "Array generated after merging the two arrays:" << endl;
	for (int z = 0; z < (num + num1); z++) {
		cout << new_arr[z] << "\t";
	}
	delete[] arr;
	delete[] arr1;
	delete[] new_arr;
	return 0;
}
