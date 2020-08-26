public class avc {
	public static void main(String args[]) {
		// some other stuff
		try {
			// Some monitored code
			throw new Derived();
		} catch (Base b)     {
			System.out.println("Caught base class exception");
		} catch (Derived d)  {
			System.out.println("Caught derived class exception");
		}
	}
}
