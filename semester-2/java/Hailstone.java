import java.util.Scanner;
class Hailstone {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int choice;
		do {
			System.out.print("Enter a number:");

			int num = sc.nextInt();

			System.out.println("Hailstone sequence for " + num + " is:-");

			int count = 0;
			while (num > 1) {
				if ((num % 2) == 0) {
					System.out.println(num + " is even, so I take half = " + num / 2);
					num /= 2;
					count++;
				} else {
					System.out.println(num + " is odd, so I make 3n+1 = " + (num * 3 + 1));
					num = num * 3 + 1;
					count++;
				}
			}
			System.out.println();
			System.out.println("The process took " + count + " steps to reach 1.");

			System.out.print("Do you want to enter another number?(Press 1 for 'yes'): ");
			choice = sc.nextInt();
		} while (choice == 1);
	}
}