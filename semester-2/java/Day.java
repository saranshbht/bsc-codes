enum Day {
	Mon, Tue, Wed, Thu, Fri, Sat, Sun;

	public static void main(String args[]) {
		for (Day d : Day.values()) {
			System.out.println(d.ordinal() + " " + d);
		}
	}
}