class Mystery {
	int result;
	void init() {
		int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		result = WhatIsThis(a, a.length);
		System.out.println("Result is: " + result);
	}
	int WhatIsThis(int b[], int size) {
		if (size == 1) {
			return b[0];
		} else {
			return b[size - 1] + WhatIsThis(b, size - 1);
		}
	}
	public static void main(String args[]) {
		new Mystery().init();
	}
}