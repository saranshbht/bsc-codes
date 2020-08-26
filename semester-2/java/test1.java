import java.util.Scanner;
class test1 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		/*String a[]={"Hello","Bye"};
		String b="Bye";
		System.out.println(a.length);*/
		int arr[] = new int[4];
		for (int i = 0; i < 4; i++) {
			arr[i] = sc.nextInt();
		}
		for (int i : arr) {
			System.out.println(i);
		}
	}
}
