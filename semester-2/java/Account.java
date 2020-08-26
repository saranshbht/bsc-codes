class Account {
	private String id;
	private String name;
	int balance;

	public Account(String ID, String NAME) {
		id = ID;
		name = NAME;
		balance = 0;
	}

	public Account(String ID, String NAME, int bal) {
		id = ID;
		name = NAME;
		balance = bal;
	}

	public String getId() {		return id;	}
	public String getName() {		return name;	}
	public int getBalance() {		return balance;	}
	public int credit(int amount) {
		balance += amount;
		return balance;
	}

	public int debit(int amount) {
		if (amount <= balance) {
			balance -= amount;
		} else {
			System.out.println("Amount exceeded balance.");
		}
		return balance;
	}

	public int transferTo(Account ac, int amount) {
		if (amount <= balance) {
			ac.credit(amount);
		} else {
			System.out.println("Amount exceeded balance.");
		}
		return balance;
	}

	public String toString() {
		return "Account[id= " + id + ", name= " + name + ", balance= " + balance + "]";
	}
}