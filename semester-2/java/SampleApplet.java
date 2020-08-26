import java.applet.*;
import java.awt.*;

public class SampleApplet extends JApplet {
	public void init() {
		setBackground(Color.blue);
	}
	public void paint(Graphics g) {
		g.drawString("A Sample Applet", 20, 20);
	}
}

/*
<applet code="SampleApplet" width="400" height="400">
</applet>
*/