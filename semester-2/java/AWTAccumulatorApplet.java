import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class AWTAccumulatorApplet extends Applet implements ActionListener {
	int a, b;
	Label l;
	TextField tf;
	public void paint(Graphics g) {
		l = new Label("Enter an integer");
		//l.setText();
		tf = new TextField(String.valueOf(0));
		tf.addActionListener(this);
		add(l);
		add(tf);
		setLayout(new FlowLayout());
		showStatus(String.valueOf(b));
		tf.setEditable(true);
	}
	public void actionPerformed(ActionEvent e) {

		a = Integer.parseInt(tf.getText());
		b += a;
		repaint();

	}

}
/*
<applet code=AWTAccumulatorApplet width=400 height=400>
</applet>
*/
