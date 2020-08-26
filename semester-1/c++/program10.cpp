//WAP to perform following actions on an array entered by the user
/*1)Print the even-valued elements
  2)Print the odd-valued elements
  3)Calculate and print the sum and the average of the elements of the array
  4)Print the maximum and minimum elements of the array
  5)Remove the duplicates from the array
  6)Print the array in reverse order*/

//The program should present a menu to the user and ask for one of the options. The menu
//should also include options to re-enter array and to quit the program
#include<iostream>
using namespace std;
void even_elements(int *arr, int num) {
	cout << endl << "Even-valued elements:" << endl;
	for (int j = 0; j < num; j++) {
		if (arr[j] % 2 == 0) {
			cout << arr[j] << "\t";
		}
	}
}
void odd_elements(int *arr, int num) {
	cout << endl << "Odd-valued elements:" << endl;
	for (int l = 0; l < num; l++) {
		if (arr[l] % 2 != 0) {
			cout << arr[l] << "\t";
		}
	}
}
void sum_average(int *arr, int num) {
	int sum = 0;
	for (int m = 0; m < num; m++) {
		sum += arr[m];
	}
	cout << endl << "Sum of the elements:" << sum;
	cout << endl << "Average of the elements:" << (double)sum / num;

}
void max_min(int *arr, int num) {
	int max = arr[0];
	int min = arr[0];
	for (int n = 1; n < num; n++) {
		if (arr[n] > max) {
			max = arr[n];
		}
		if (arr[n] < min) {
			min = arr[n];
		}
	}
	cout << endl << "Maximum-valued element:" << max;
	cout << endl << "Minimum-valued element:" << min;

}
void remove_dup(int *arr, int &num) {
	for (int o = 0; o < num; o++) {
		int elem = arr[o];
		for (int p = o + 1; p < num; p++) {
			if (arr[p] == elem) {
				for (int q = p; q < num; q++) {
					arr[q] = arr[q + 1];
				}
				num--;
			}
		}
	}
	cout << endl << "Array after removing duplicate elements:" << endl;
	for (int r = 0; r < num; r++) {
		cout << arr[r] << "\t";
	}

}
void rev_array(int *arr, int num) {
	cout << endl << "Array in reverse order:" << endl;
	for (int s = num - 1; s >= 0; s--) {
		cout << arr[s] << "\t";
	}
}
void re_enter(int *arr[], int &num) {
	int n;
	cout << "Enter how many elements you want in the array:";
	cin >> n;
	num = n;
	*arr = new int[num];
	cout << endl << "Enter array elements:" << endl;
	for (int i = 0; i < num; i++) {
		cin >> (*arr)[i];
	}
	cout << endl << "New array:" << endl;
	for (int k = 0; k < num; k++) {
		cout << (*arr)[k] << "\t";
	}

}

int main() {
	int num;

	cout << "Enter how many elements you want in the array:";
	cin >> num;
	int *arr = new int[num];
	cout << endl << "Enter array elements:" << endl;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	cout << endl << "Original array:" << endl;
	for (int k = 0; k < num; k++) {
		cout << arr[k] << "\t";
	}

	int choice;
	do {
		cout << endl << "M E N U";
		cout << endl << "1)Re-enter array\n2)Print the even-valued elements\n3)Print the odd-valued elements\n4)Print the sum and the average of the elements of the array\n5)Print the maximum and minimum elements of the array\n6)Remove the duplicates from the array\n7)Print the array in reverse order\n0)Exit";
		cout << endl << "Enter your choice:";
		cin >> choice;


		switch (choice) {
			case 1: re_enter(&arr, num);
				break;
			case 2: even_elements(arr, num);
				break;
			case 3: odd_elements(arr, num);
				break;
			case 4: sum_average(arr, num);
				break;
			case 5: max_min(arr, num);
				break;
			case 6: remove_dup(arr, num);
				break;
			case 7: rev_array(arr, num);
				break;
			case 0: break;

		}
	} while (choice != 0);
	delete[] arr;
	return 0;
}
