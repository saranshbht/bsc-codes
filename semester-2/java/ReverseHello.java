class ReverseHello extends Thread {
	static int counter = 50;
	ReverseHello() {
		super();
		start();
	}

	public void run() {
		if (counter > 0) {
			new ReverseHello();
			try {
				counter--;
				Thread.sleep(counter * 100);
				System.out.println("Hello from " + this.getName());
			} catch (Exception e) {}
		}

	}
	public static void main(String args[]) {
		new ReverseHello();
	}
}
