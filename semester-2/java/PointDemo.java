import java.lang.Math;
class Point {
	int X, Y;
	Point(int a, int b) {
		X = a;
		Y = b;
	}

	int getX() { return X;}

	int getY() { return Y;}

	void setX(int a) {  X = a;}

	void setY(int b) {  Y = b;}


	double distance(Point p) {
		double dist = Math.sqrt((p.X - X) * (p.X - X) + (p.Y - Y) * (p.Y - Y));
		return dist;
	}
}

class PointDemo {
	public static void main(String args[]) {
		Point p1 = new Point(0, 0);
		Point p2 = new Point(3, 4);
		p1.setX(5);
		p1.setY(6);
		System.out.println("The distance between the points (" + p1.getX() + "," + p1.getY() + ") and (" + p2.getX() + "," + p2.getY() + ") is " + p1.distance(p2));
	}
}



