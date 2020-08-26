class MyThread extends Thread {
	public static void main(String [] args) {
		MyThread t = new MyThread();
		t.start();
		System.out.print("one. ");
//t.start();
		System.out.print("two. ");
	}
	public void run() {
		System.out.print("Thread ");
	}
}
