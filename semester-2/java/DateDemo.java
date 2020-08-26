class Date {
	int day, month, year;

	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	void showDate() {
		System.out.println("Date: " + day + "/" + month + "/" + year);
	}
	int daysSinceJan1() {
		int noOfDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		boolean leapYear = false;
		if ((year % 4) == 0) {
			if ((year % 100) == 0) {
				if ((year % 400) == 0) {
					leapYear = true;
				}
			}
		}

		int totalDays = day;
		for (int i = month - 1; i > 0; i--) {
			totalDays += noOfDays[i - 1];
		}

		if (leapYear) {
			if (month > 2) {
				totalDays++;
			}
		}

		return totalDays;
	}
}

class DateDemo {
	public static void main(String args[]) {
		Date d = new Date(28, 12, 2000);
		d.showDate();
		System.out.println("Number of days since January 1: " + d.daysSinceJan1());
	}
}