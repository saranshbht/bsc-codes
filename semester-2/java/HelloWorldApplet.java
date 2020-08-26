import java.applet.*;
import java.awt.*;

public class HelloWorldApplet extends Applet {
	public void init() {
		setBackground(Color.red);
	}
	public void paint (Graphics g) {
		g.drawString ("Hello World", 25, 50);
	}
}

/*
<applet code = HelloWorldApplet.class width = "320" height = "120">
      If your browser was Java-enabled, a "Hello, World"
      message would appear here.
   </applet>
   */