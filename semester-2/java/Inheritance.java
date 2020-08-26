class Person {
	protected String name;
	protected String address;

	public Person(String n, String addr) {
		name = n;
		address = addr;
	}

	public String getNAme() {	return name;	}
	public String getAddress() {		return address;	}
	public void setAddress(String addr) {
		address = addr;
	}

	public String toString() {
		return "Person[Name= " + name + ", Address= " + address + "]";
	}
}

class Student extends Person {
	private String program;
	private int year;
	private double fee;

	public Student(String n, String addr, String pg, int yr, double f) {
		super(n, addr);
		program = pg;
		year = yr;
		fee = f;
	}

	public String getProgram() {		return program;	}
	public void setProgram(String pg) {
		program = pg;
	}

	public int getYear() {	return year;	}
	public void setYear(int yr) {
		year = yr;
	}

	public double getFee() {		return fee;		}
	public void setFee(double f) {
		fee = f;
	}

	public String toString() {
		return "Student[Person[Name= " + name + ", Address= " + address + "], Program= " + program + ", Year= " + year + ", Fee=" + fee + "]";
	}
}

class Staff extends Person {
	private String school;
	private double pay;

	public Staff(String n, String addr, String sch, double p) {
		super(n, addr);
		school = sch;
		pay = p;
	}

	public String getSchool() {		return school;	}
	public void setSchool(String sch) {
		school = sch;
	}

	public double getPay() {		return pay;		}
	public void setPay(double p) {
		pay = p;
	}

	public String toString() {
		return "Staff[Person[Name= " + name + ", Address= " + address + "], School= " + school + ",` Pay= " + pay + "]";
	}
}