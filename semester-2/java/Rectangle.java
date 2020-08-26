import java.lang.Math;

class Rectangle {
	private int xCoordinate;
	private int yCoordinate;
	private int height;
	private int width;
	private String color;

	public Rectangle(int x, int y, int h, int w) {
		xCoordinate = x;
		yCoordinate = y;
		height = h;
		width = w;
		color = "#000000";
	}

	public void setXCoordinate(int newX) {	xCoordinate = newX;	}
	public void setYCoordinate(int newY) {	yCoordinate = newY;	}
	public int getHeight() {		return height;	}
	public int getWidth() {		return width;	}
	public String getColor() {		return color;	}
	public int getXCoordinate() {	return xCoordinate;	}
	public int getYCoordinate() {	return yCoordinate;	}

	public double Calculate() {
		double diag = Math.sqrt(width * width + height * height);
		return diag;
	}

}