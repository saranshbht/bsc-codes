interface Resizable {
	void resize(int percent);
}
class ResizableCircle extends Circle implements Resizable {
	ResizableCircle(double radius) {
		super(radius);
	}
	public void resize(int percent) {
		radius = percent / 100.0 * radius;
	}
}
class TestResizableCircle {
	public static void main(String args[]) {
		ResizableCircle rc = new ResizableCircle(2.45);
		System.out.println("Before resizing");
		System.out.printf("Radius: %.3f", rc.radius);
		System.out.println();
		System.out.printf("Perimeter: %.3f", rc.getPerimeter());
		System.out.println();
		System.out.printf("Area: %.3f", rc.getArea());
		System.out.println();
		rc.resize(75);
		System.out.println("After resizing");
		System.out.printf("Radius: %.3f", rc.radius);
		System.out.println();
		System.out.printf("Perimeter: %.3f", rc.getPerimeter());
		System.out.println();
		System.out.printf("Area: %.3f", rc.getArea());
		System.out.println();
	}
}
