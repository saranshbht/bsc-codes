import java.awt.*;
import java.applet.*;

public class App extends Applet {
	public void paint(Graphics g) {
		g.setColor(Color.red);
		g.drawString("Displaying a String", 50, 50);
		g.setColor(Color.cyan);
		g.drawRect(0, 0, 20, 20);
		g.fillRect(0, 0, 20, 20);
		g.setColor(Color.blue);
		g.drawOval(30, 0, 10, 40);
		g.fillOval(30, 0, 10, 40);
		g.setColor(Color.pink);
		g.drawLine(5, 5, 35, 5);
		g.drawArc(60, 60, 30, 130, 30, 270);
		//g.fillArc(60,60,30,30,30,270);
	}
}

/*
<applet code="App" width=500 height=500>
</applet>

*/