import java.util.Scanner;
class ArrayClass {
	int arr[] = new int[10];
	void getElements() {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();

			if (arr[i] > 50 || arr[i] < 1) {
				System.out.println("Invalid number!! Enter another number");
				i--;
			}
		}
	}

	int count(int n) {
		int count = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == n) {
				count++;
			}
		}
		return count;
	}
}

class ArrayClassDemo {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		ArrayClass ar = new ArrayClass();
		System.out.println("Enter 10 integers(between 1-50):");
		ar.getElements();
		System.out.println("Enter a number(between 1-50):");
		int no = sc.nextInt();
		if (no > 50 || no < 1) {
			System.out.println("Invalid number!! Enter another number");
			no = sc.nextInt();
		}

		System.out.println("The number " + no + " is found " + ar.count(no) + " time(s)");
	}
}
