import java.util.Scanner;

class SumThread extends Thread {
	private int lo, hi;
	private int[] arr;
	private int ans;

	public SumThread(int[] arr, int lo, int hi) {
		this.lo = lo;
		this.hi = hi;
		this.arr = arr;
	}


	public void run() {
		for (int i = lo; i < hi; i++) {
			ans += arr[i];
		}
	}

	/**
	 * Sum the elements of an array.
	 *
	 * parameter arr array to sum
	 * return sum of the array's elements
	 * throws InterruptedException shouldn't happen
	 */
	public static int sum(int[] arr) throws InterruptedException {
		int len = arr.length;
		int ans;

		// Create and start 4 threads.
		SumThread[] ts = new SumThread[4];
		for (int i = 0; i < 4; i++) {
			ts[i] = new SumThread(arr, (i * len) / 4, ((i + 1) * len / 4));
			ts[i].start();
		}

		// Wait for the threads to finish and sum their results.
		for (int i = 0; i < 4; i++) {
			ts[i].join();
			ans += ts[i].ans;
		}
		return ans;
	}
}

class TestSumThread {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		try {
			System.out.println("Sum: " + SumThread.sum(arr));
		} catch (Exception e) {}
	}
}