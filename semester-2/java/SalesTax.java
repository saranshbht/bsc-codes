package com.sct.account;
import com.sct.calculate.MyCalculation;

class SalesTax {
	public static void main(String args[]) {
		MyCalculation myc = new MyCalculation();
		int interestAmount = myc.calculateInterest(1000, 8);
		System.out.println("Interest Amount = " + interestAmount);
		int intAmount2 = myc.calculateInterest(900, 8);
		System.out.println("Interest Amount2= " + intAmount2);
	}
}

