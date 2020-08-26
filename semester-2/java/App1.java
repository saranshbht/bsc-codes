import java.awt.*;
import java.awt.event.*;

public class App1 extends java.applet.Applet {
	public void init() {
		addMouseListener(new MyAdapter());
		addMouseMotionListener(new MyMotionAdapter());
	}

	class MyAdapter extends MouseAdapter {
		public void mouseClicked(MouseEvent e) {
			showStatus("Mouse Clicked");
		}
	}

	class MyMotionAdapter extends MouseMotionAdapter {
		public void mouseDragged(MouseEvent e) {
			showStatus("Mouse Dragged");
		}
	}
}

/*
<applet code=App1 width="400" height="400">
</applet>
*/