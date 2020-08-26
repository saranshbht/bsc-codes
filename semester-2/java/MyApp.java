import java.awt.*;
import java.applet.*;
public class MyApp extends Applet {
	public void init() {
		setBackground(Color.red);
	}
	public void paint(Graphics g) {
		g.drawString("A New String", 20, 20);
	}
}
/*
<applet code=MyApp width="300" height="300">
</applet>
*/
