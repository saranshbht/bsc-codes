import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int largest = 0;
		int arr[][] = new int[6][6];
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				arr[i][j] = in.nextInt();
			}
		}
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				int sum = 0;
				for (int m = x; m < (x + 3); m++) {
					for (int n = y; n < (y + 3); y++) {
						if (m != (x + 1)) {
							sum += arr[m][n];
						} else if (n == (y + 1)) {
							sum += arr[m][n];
						}
					}
				}
				if (sum > largest) {
					largest = sum;
				}
			}
		}
		System.out.println(largest);
	}
}
