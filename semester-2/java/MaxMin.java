import java.util.Scanner;
class MaxMin {
	public static void main(String args[]) {
		int count = 0, min, max, num;
		int choice1, choice2 = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("//Sentinel value is the value which when entered will stop the reading of integers");
		do {
			System.out.print("Enter a sentinel value(integer only):");

			int sentinel = sc.nextInt();

			System.out.println();
			System.out.println("Enter the integers:");


			num = sc.nextInt();
			max = min = num;

			while (true) {
				num = sc.nextInt();
				count++;

				if (num == sentinel) {
					break;
				}

				else {
					if (max < num) {
						max = num;
					}
					if (min > num) {
						min = num;
					}
				}
			}

			if (count == 0) {
				System.out.println("No values have been entered");
			} else {
				System.out.println("The smallest value is " + min + " and the largest value is " + max);
			}

			System.out.println();
			System.out.println("Do you want to do it again?(Press 1 for 'yes':");
			choice1 = sc.nextInt();
		} while (choice1 == 1);
	}
}
