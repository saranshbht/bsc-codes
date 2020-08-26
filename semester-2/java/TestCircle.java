interface GeometricObject {
	double getPerimeter();
	double getArea();
}

class Circle implements GeometricObject {
	protected double radius;
	Circle(double r) {
		radius = r;
	}
	public double getPerimeter() {
		return 2 * 3.14 * radius;
	}
	public double getArea() {
		return 3.14 * radius * radius;
	}
}

class TestCircle {
	public static void main(String args[]) {
		Circle c = new Circle(2.345);
		System.out.printf("Radius: %.3f", c.radius);
		System.out.println();
		System.out.printf("Perimeter: %.3f", c.getPerimeter());
		System.out.println();
		System.out.printf("Area: %.3f", c.getArea());
		System.out.println();
	}
}
