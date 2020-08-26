import java.awt.*;

class FrameTest extends Frame {
	FrameTest() {
		setSize(400, 400);
		setVisible(true);
	}

	public void paint(Graphics g) {
		g.drawString("abc", 50, 50);
	}

	public static void main(String args[]) {
		new FrameTest().repaint();
	}
}