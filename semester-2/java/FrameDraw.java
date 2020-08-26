import java.awt.*;
import java.awt.event.*;

class FrameDraw {
	public static void main(String ... args) {
		Frame f = new Frame();
		f.setSize(300, 300);
		f.setLayout(null);
		f.addMouseMotionListener(new MouseMotionAdapter() {
			public void mouseMoved(MouseEvent e) {
				Graphics g = f.getGraphics();
				g.setColor(Color.yellow);
				g.fillOval(e.getX(), e.getY(), 10, 10);
			}
		});
		f.setVisible(true);
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}
}