import java.applet.*;
import java.awt.*;

public class bannerDemo extends Applet implements Runnable {
	Thread t;
	String msg = "Ankit Virparia (ankit.co)";
	public void init() {
		t = new Thread(this);
		t.start();
	}

	public void run() {
		try {
			while (true) {
				t.sleep(100);
				char c = msg.charAt(0);
				String tmp = msg.substring(1, msg.length());
				msg = tmp + c;
				repaint();
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}

	public void paint(Graphics g) {
		Font f = new Font("Arial", Font.BOLD, 44);
		g.setFont(f);
		g.drawString(msg, 0, 75);
	}

}

/*
<applet code="bannerDemo" width="500" height="150"></applet>
*/