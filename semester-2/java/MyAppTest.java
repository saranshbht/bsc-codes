import java.awt.*;
public class MyAppTest extends java.applet.Applet {
	public void paint(Graphics g) {
		g.drawString(g.getClass().getName(), 100, 100);
		g.drawString(getParameter("alt"), 100, 150);
	}
}

/*
<applet code=MyAppTest width="400" height="400">
<param name="alt" value="Class implementing Graphics">
</applet>
*/