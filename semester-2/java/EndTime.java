import java.util.Scanner;
class EndTime {
	public static void main(String args[]) {
		int hr, min, dur, choice;
		Scanner sc = new Scanner(System.in);
		do {

			System.out.println("Enter starting time");

			System.out.print("Starting Hours(0..23): ");
			hr = sc.nextInt();

			System.out.print("Starting Minutes(0..59): ");
			min = sc.nextInt();

			System.out.print("Enter duration(in minutes): ");
			dur = sc.nextInt();

			int end_min = min + dur;
			int end_hr = hr;
			while (end_min >= 60) {
				if (end_hr == 23) {
					end_hr = 0;
				} else {
					end_hr++;
				}

				end_min -= 60;
			}

			System.out.println("Ending Hours(0..23): " + end_hr);

			System.out.println("Ending Minutes(0..59): " + end_min);

			System.out.print("Do you want to enter another time?(Press 1 for 'yes'): ");
			choice = sc.nextInt();
		} while (choice == 1);

	}
}