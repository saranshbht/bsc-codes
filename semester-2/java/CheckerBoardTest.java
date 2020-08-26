//Question 26

import java.awt.*;
import java.applet.*;
import java.awt.event.*;

class Canvas1 extends Canvas {
	int counter;
	boolean flag;
	static int color;
	CheckerBoardTest c;
	public Canvas1(CheckerBoardTest c) {
		this.c = c;
		setSize(c.x / 8, c.y / 8);
		color++;
		if (color % 2 == 0) {
			setBackground(Color.black);
		} else {
			setBackground(Color.white);
		}
		addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				counter++;
				if (counter % 2 != 0) {
					flag = true;
				} else {
					flag = false;
				}
				repaint();
			}
		});
		counter = 0;
		flag = false;
	}

	public void paint(Graphics g) {
		if (flag) {
			g.setColor(Color.yellow);
			for (int i = 0; i < 3; i++) {
				g.drawRect(i, i, getWidth() - (2 * i), getHeight() - (2 * i));
			}
		}
	}
}

public class CheckerBoardTest extends Applet {
	Dimension d;
	int x, y;
	public void init() {
		d = getSize();
		x = d.width;
		y = d.height;
		for (int i = 0; i <= (x - x / 8); i += (x / 8)) {
			for (int j = 0; j <= (y - y / 8); j += (y / 8)) {
				Canvas c = new Canvas1(this);
				add(c);
				c.setLocation(i, j);
			}
			Canvas1.color--;
		}
		setLayout(null);
	}
}
/*
<applet code=CheckerBoardTest width="400" height="400">
</applet>
*/