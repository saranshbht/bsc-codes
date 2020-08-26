import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.applet.Applet;
import java.awt.*;

public class ExampleEventHandling extends Applet implements MouseListener {
	StringBuffer strBuffer;
	int a = 0;
	public void init() {
		addMouseListener(this);
		strBuffer = new StringBuffer();
		addItem("initializing the apple ");
	}

	public void start() {
		addItem("starting the applet ");
	}

	public void stop() {
		addItem("stopping the applet ");
	}

	public void destroy() {
		addItem("unloading the applet");
	}

	void addItem(String word) {
		System.out.println(word);
		strBuffer.append(word);
		repaint();
	}

	public void paint(Graphics g) {
		// Draw a Rectangle around the applet's display area.
		if (a == 1) {
			g.setColor(Color.pink);
			g.drawRect(0, 0,
			           getWidth() - 1,
			           getHeight() - 1);
		}
		// display the string inside the rectangle.
		g.setColor(Color.black);
		g.drawString(strBuffer.toString(), 10, 20);
	}


	public void mouseEntered(MouseEvent event) {
	}
	public void mouseExited(MouseEvent event) {
	}
	public void mousePressed(MouseEvent event) {
	}
	public void mouseReleased(MouseEvent event) {
	}
	public void mouseClicked(MouseEvent event) {
		a = 1;
		repaint();;
		//addItem("mouse clicked! ");
	}
}
/*
<applet code=ExampleEventHandling width="400" height="400">
</applet>
*/