import java.awt.*;
import java.applet.*;
//import javax.swing.BorderFactory;

public class Canvas1 extends Canvas implements MouseListener {
	int counter;
	boolean flag;
	public Canvas1() {
		setSize(20, 20);
		setBackground(Color.white);
		addMouseListener(this);
		counter = 0;
		flag = false;
	}
	public void mouseClicked(MouseEvent e) {
		counter++;
		if (counter % 2 != 0) {
			flag = true;
		} else {
			flag = false;
		}
		repaint();
	}
	public void mouseExited(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	public void paint(Graphics g) {
		if (flag) {
			g.setColor(Color.blue);
			g.drawRect(0, 0, getWidth() - 1, getHeight() - 1);
		}
	}
}

public class CanvasApp extends Applet {
	public void init() {
		add(new Canvas1());
	}
}