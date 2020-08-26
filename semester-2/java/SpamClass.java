import java.util.Scanner;

class SpamClass {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		while (t-- > 0) {
			int n = sc.nextInt();
			int spam = 0;
			int nspam = 0;
			int minX = sc.nextInt();
			int maxX = sc.nextInt();
			int w[] = new int[n];
			int b[] = new int[n];

			for (int i = 0; i < n; i++) {
				w[i] = sc.nextInt();
				b[i] = sc.nextInt();
			}

			while (minX <= maxX) {

				int total = w[0] * minX + b[0];
				for (int i = 1; i < n; i++) {
					total = (w[i] * total + b[i]);
				}

				minX++;
				if (total % 2 == 0) {
					nspam++;
				} else {
					spam++;
				}
			}

			System.out.println(nspam + " " + spam);
		}
	}
}