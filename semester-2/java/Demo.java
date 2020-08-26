interface A {
	int a = 12;
}

class B implements A {
	int a = 0;
}

class Demo {
	public static void main(String args[]) {
		//B b=new B();
		System.out.println(B.a);
		System.out.println(A.a);
	}
}