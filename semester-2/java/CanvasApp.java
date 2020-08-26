import java.awt.*;
import java.applet.*;
import java.awt.event.*;

class Canvas1 extends Canvas implements MouseListener {
	int counter;
	boolean flag;
	static int color;
	public Canvas1() {
		setSize(20, 20);
		color++;
		if (color % 2 == 0) {
			setBackground(Color.black);
		} else {
			setBackground(Color.white);
		}
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
	public void mouseEntered(MouseEvent e) {}
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e) {}
	public void paint(Graphics g) {
		if (flag) {
			g.setColor(Color.pink);
			g.drawRect(0, 0, getWidth() - 1, getHeight() - 1);
		}
	}
}

public class CanvasApp extends Applet {
	public void init() {
		for (int i = 0; i <= 140; i += 20) {
			for (int j = 0; j <= 140; j += 20) {
				Canvas c = new Canvas1();
				add(c);
				c.setLocation(i, j);
			}
			Canvas1.color--;
		}
		setLayout(null);
	}
}
/*
<applet code=CanvasApp width="160" height="160">
</applet>
*/