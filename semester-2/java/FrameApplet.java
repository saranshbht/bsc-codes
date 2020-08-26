import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class FrameApplet extends Applet {
	Frame f;
	int flag;

	public void init() {
		f = new Frame();
		f.setSize(200, 200);
		f.setVisible(true);
		f.setLocation(0, 0);
		f.addMouseListener(new MouseListener() {

			public void mouseClicked(MouseEvent e) {
				flag = 1;
				repaint();
			}

			public void mouseExited(MouseEvent e) {
				flag = 2;
				repaint();
			}

			public void mouseEntered(MouseEvent e) {
				flag = 3;
				repaint();
			}

			public void mousePressed(MouseEvent e) {
				flag = 4;
				repaint();
			}

			public void mouseReleased(MouseEvent e) {
				flag = 5;
				repaint();
			}
		});
	}

	public void paint(Graphics g) {
		switch (flag) {

			case 1:		g.drawString("Mouse Clicked On Frame!!", 250, 250);
				break;

			case 2:		g.drawString("Mouse Exited Frame!!", 250, 250);
				break;

			case 3:		g.drawString("Mouse Entered Frame!!", 250, 250);
				break;

			case 4:		g.drawString("Mouse Pressed !!", 250, 250);
				break;

			case 5:		g.drawString("Mouse Released!!", 250, 250);
				break;
		}
	}
}
/*
<applet code=FrameApplet width="400" height="400">
</applet>
*/