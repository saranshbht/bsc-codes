class Dieter {
	final double calorie_gained = 590.0;
	final double calorie_burned = 93.5;

	int nPizzas;


	Dieter(int noP) {
		nPizzas = noP;
	}

	double Calculate() {
		double calorie_consumed = nPizzas * calorie_gained;
		double miles_to_burn = calorie_consumed / calorie_burned;
		return miles_to_burn;
	}
}

class DieterDemo {
	public static void main(String args[]) {
		Dieter d1 = new Dieter(0);
		System.out.println("Calories to burn:" + d1.Calculate());
		Dieter d2 = new Dieter(1);
		System.out.println("Calories to burn:" + d2.Calculate());
		Dieter d3 = new Dieter(3);
		System.out.println("Calories to burn:" + d3.Calculate());
		Dieter d4 = new Dieter(9);
		System.out.println("Calories to burn:" + d4.Calculate());
	}
}
