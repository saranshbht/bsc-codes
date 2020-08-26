import java.util.Scanner;
class StringCompare {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of strings you want to enter:");

		int n = sc.nextInt();
		String arr[] = new String[n];

		System.out.println("Enter strings:");

		for (int i = 0; i < n; i++) {
			arr[i] = sc.next();
		}

		int pos;
		String start, temp;

		for (int i = 0; i < n - 1; i++) {
			start = arr[i];
			pos = i;

			for (int j = i + 1; j < n; j++) {
				if (arr[j].charAt(0) < arr[i].charAt(0)) {
					start = arr[j];
					pos = j;
				}
			}
			temp = arr[i];
			arr[i] = arr[pos];
			arr[pos] = temp;
		}

		System.out.println("Strings in ascending order(A..Z):");

		for (String i : arr) {
			System.out.print(i + "    ");
		}

		System.out.println();
	}
}
