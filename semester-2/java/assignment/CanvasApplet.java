//Question 18

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class CanvasApplet extends Applet{
	public void init(){
		Choice c=new Choice();
		Choice c1=new Choice();
		c.add("Red");
		c.add("Blue");
		c.add("Green");
		c1.add("Small");
		c1.add("Medium");
		c1.add("Large");
		add(c);
		add(c1);
		add(new MyCanvas(c,c1));
		setSize(400,400);
		setLayout(new FlowLayout());
	}
}

class MyCanvas extends Canvas implements MouseListener{
	int x,y,diameter;
	Color clr;
	Choice c,c1;
	MyCanvas(Choice c,Choice c1){
		setSize(300,300);
		setBackground(Color.gray);
		addMouseListener(this);
		this.c=c;
		this.c1=c1;
	}
		
	public void paint(Graphics g){
		g.setColor(clr);
		g.fillOval(x,y,diameter,diameter);
	}
		
		
			public void mouseClicked(MouseEvent e){
				x=e.getX();
				y=e.getY();
				
				String s=c.getItem(c.getSelectedIndex());
				if(s=="Red")
					clr=Color.red;
				else if(s=="Blue")
					clr=Color.blue;
				else
					clr=Color.green;
				
				String s1=c1.getItem(c1.getSelectedIndex());
				if(s1=="Small")
					diameter=20;
				else if(s1=="Medium")
					diameter=50;
				else
					diameter=100;
				repaint();
			}
	public void mouseEntered(MouseEvent e) {}  
    public void mouseExited(MouseEvent e) {}  
    public void mousePressed(MouseEvent e) {}  
    public void mouseReleased(MouseEvent e) {}  
}

/*
<applet code=CanvasApplet height="400" width="400">
</applet>
*/