import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class AppletKey extends Applet implements KeyListener {
	int flag;
	public void init() {
		addKeyListener(this);
	}

	public void keyPressed(KeyEvent e) {
		flag = 1;
		repaint();
	}

	public void keyReleased(KeyEvent e) {
		flag = 2;
		repaint();
	}

	public void keyTyped(KeyEvent e) {
		flag = 3;
		repaint();
	}

	public void paint(Graphics g) {
		switch (flag) {

			case 1:		g.drawString("Key Pressed!!", 180, 200);
				break;

			case 2:		g.drawString("Key Released!!", 180, 200);
				break;

			case 3:		g.drawString("Key Typed!!", 180, 200);
				break;
		}
	}
}
/*
<applet code=AppletKey width="400" height="400">
</applet>
*/