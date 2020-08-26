import java.util.Scanner;
import java.lang.Math;
class Menu {
	static boolean checkPrime(int n) {
		if (n == 0 || n == 1) {
			return false;
		}
		if (n == 2) {
			return true;
		}
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if ((n % i) == 0) {
				return false;
			}
		}
		return true;
	}

	static int factorial(int n) {
		if (n == 0) {
			return 1;
		} else {
			return n * factorial(n - 1);
		}
	}

	static void decToBinary(int num) {
		if (num > 1) {
			decToBinary(num / 2);
			System.out.print(num % 2);
		} else {
			System.out.print(1);
			return;
		}
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int choice, n, num;

		System.out.print("Enter a number: ");
		num = sc.nextInt();
		System.out.print("What do you want to do?");
		System.out.println("1.Calculate Factorial");
		System.out.println("2.Check if prime");
		System.out.println("3.Convert to binary");
		System.out.print("Enter your choice: ");
		n = sc.nextInt();

		switch (n) {
			case 1: System.out.println("The factorial of " + num + " is " + factorial(num));
				break;

			case 2: if (checkPrime(num)) {
					System.out.println(num + " is prime");
				} else {
					System.out.println(num + " is not prime");
				}
				break;
			case 3: System.out.print(num + " in binary is ");
				decToBinary(num);
				break;

			default: System.out.println("Wrong Input!!");
		}

	}
}