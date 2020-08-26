#include<iostream>
#include<cmath>
using namespace std;


int sum(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}

	return sum;
}


double average(int arr[], int n) {
	double m = sum(arr, n);
	return (m / n);
}



int max(int array[], int size) {
	int max;
	max = array[0];
	for (int k = 0; k < size; k++) {
		if (max < array[k]) {
			max = array[k];
		}
	}
	return max;
}



int min(int array1[], int size) {
	int min;
	min = array1[0];
	for (int l = 0; l < size; l++) {

		if (array1[l] < min) {
			min = array1[l];
		}

	}
	return min;
}



double var(int arr[], int n) {
	double sum1 = 0.0;
	double p = average(arr, n);
	for (int x = 0; x < n; x++) {
		sum1 = sum1 + ((arr[x] - p) * (arr[x] - p));
	}
	return (sum1 / n);
}



double std_dev(int arr[], int n) {
	double o = var(arr, n);
	return (sqrt(o));
}



int sum_of_squares(int arr[], int n) {
	int sum2 = 0;

	for (int y = 0; y < n; y++) {
		sum2 += (arr[y] * arr[y]);
	}
	return sum2;
}



int sum_of_cubes(int arr[], int n) {
	int sum3 = 0;

	for (int z = 0; z < n; z++) {
		sum3 += (arr[z] * arr[z] * arr[z]);
	}
	return sum3;
}



int main() {
	int n;

	cout << "How many elements should be in the array?";
	cin >> n;
	int *arr = new int [n];
	cout << endl << "Enter array elements:" << endl;
	for (int j = 0; j < n; j++) {
		cin >> arr[j];
	}



	int choice;
	do {
		cout << endl << endl << "M E N U" << endl;
		cout << "1.Sum\n2.Average\n3.Maximum\n4.Minimum\n5.Variance\n6.Standard Deviation\n7.Sum of squares\n8.Sum of cubes\n0.Exit" << endl;
		cout << "Enter your choice:";
		cin >> choice;

		switch (choice) {
			case 1: cout << sum(arr, n) << endl;
				break;

			case 2: cout << average(arr, n) << endl;
				break;

			case 3:  cout << max(arr, n) << endl;
				break;

			case 4:  cout << min(arr, n) << endl;
				break;

			case 5:  cout << var(arr, n) << endl;
				break;

			case 6:  cout << std_dev(arr, n) << endl;
				break;

			case 7:  cout << sum_of_squares(arr, n) << endl;
				break;

			case 8:  cout << sum_of_cubes(arr, n) << endl;
				break;

			case 0:  break;


			default: cout << "Wrong input";
		}
	} while (choice != 0);

	return 0;
}
