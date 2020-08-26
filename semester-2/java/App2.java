import java.awt.*;
import java.awt.event.*;

public class App2 extends java.applet.Applet {
	public void init() {
		addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				showStatus("Mouse Clicked");
			}
		});

		addMouseMotionListener(new MouseMotionAdapter() {
			public void mouseDragged(MouseEvent e) {
				showStatus("Mouse Dragged");
			}
		});

		addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e) {
				showStatus("Key Pressed");
			}

			public void keyReleased(KeyEvent e) {
				showStatus("Key Released");
			}
		});
	}
}

/*
<applet code=App2 width="400" height="400">
</applet>
*/