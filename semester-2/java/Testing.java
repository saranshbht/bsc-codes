class Testing {
	public static void main(String args[]) {
		try {
			//int f=0;
			//if(f==0)
			throw new ArithmeticException();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}