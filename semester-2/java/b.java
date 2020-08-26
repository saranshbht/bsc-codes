interface aa {
	int a = 10;
}

class b implements aa {
	int a = 12;
	b() {
		.a = 13;
	}
	public static void main(String args[]) {
		b abc = new b();
		System.out.println(aa.a);
	}
}