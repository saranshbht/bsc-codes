class ThreadJoin extends Thread {

	ThreadJoin() {
		super();
	}

	public void run() {
		try {
			for (int i = 4; i >= 0; i--) {
				System.out.println(i);
				Thread.sleep(100);
			}
		} catch (Exception e) {
			System.out.println("" + getName() + " interrupted.");
		}
	}

	public static void main(String args[]) {
		ThreadJoin a, b;
		a = new ThreadJoin();
		b = new ThreadJoin();
		a.start();
		try {
			a.join();
		} catch (Exception e) {
			System.out.println("" + Thread.currentThread().getName() + " interrupted");
		}
		b.start();
	}
}