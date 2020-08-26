class Test {
	public int aa = 1;
	public Test (int i) {
		aa += i;
	}
}
class Sample extends Test {
	public Sample (int i) {
		super(i); aa += i;
	}
}
class E {
	public static void main (String argv[]) {
		Test ar[] = new Test[2];
		ar[0] = new Test(1);
		ar[1] = new Sample(2);
		System.out.println(ar[0].aa + ar[1].aa);
	}
}
