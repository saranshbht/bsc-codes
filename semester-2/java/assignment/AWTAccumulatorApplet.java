//Question 22

import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class AWTAccumulatorApplet extends Applet implements ActionListener{
	int a,b;
	Label l;
	TextField tf;
	public void start(){
		l=new Label("Enter an integer");
		tf=new TextField(String.valueOf(0));
		tf.addActionListener(this);
		add(l);
		add(tf);
		setLayout(new FlowLayout());
		tf.setEditable(true);
	}
	public void paint(Graphics g){
		showStatus("The accumulated sum is:"+String.valueOf(b));
	}
	public void actionPerformed(ActionEvent e){
		
		a=Integer.parseInt(tf.getText());
		b+=a;
		repaint();
	}
	
}
/*
<applet code=AWTAccumulatorApplet width=400 height=400>
</applet>
*/
