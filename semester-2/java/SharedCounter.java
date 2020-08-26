class SharedCounter extends Thread {
	static int counter = 0;
	public void run() {
		for (int i = 0; i < 10; i++) {
			counter++;
		}
	}

	public static void main(String args[]) {
		SharedCounter[] sc = new SharedCounter[10];
		for (int i = 0; i < 10; i++) {
			sc[i] = new SharedCounter();
			sc[i].start();
		}

		try {
			for (int i = 0; i < 10; i++) {
				sc[i].join();
				//System.out.println(counter);
			}
		} catch (Exception e) {}
		System.out.println(counter);
	}
}