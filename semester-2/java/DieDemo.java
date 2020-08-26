import java.util.Random;
import java.util.Scanner;
class Die {

	int sideUp;
	Die() {
		sideUp = 1;
	}

	int getSideUp() {
		return sideUp;
	}

	void roll() {
		Random randomNumber = new Random();
		sideUp = 1 + randomNumber.nextInt(6);
	}
}

class DieDemo {
	public static void main(String args[]) {
		Die d1 = new Die();
		Die d2 = new Die();
		Scanner sc = new Scanner(System.in);
		int choice;
		do {
			d1.roll();
			d2.roll();

			System.out.println("Side up of the first die: " + d1.getSideUp());
			System.out.println("Side up of the second die: " + d2.getSideUp());
			System.out.println("Sum of the two sides up: " + (d1.getSideUp() + d2.getSideUp()));
			System.out.print("Do you want to roll the dice again?(Press 1 for 'yes'): ");
			choice = sc.nextInt();
		} while (choice == 1);
	}
}