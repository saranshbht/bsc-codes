//Question 25

import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;
import java.util.Random;
//import javax.swing.BoxLayout;
public class Dice2 extends Applet{
	
	MyCanvas1 c;
	Button b;
	Random random;
	public void init(){
		c=new MyCanvas1();
		b=new Button("Roll");
		setSize(150,150);
		add(c);
		add(b);
		setLayout(new FlowLayout());

		b.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				random= new Random();
				c.val=1+random.nextInt(6);
				c.val1=1+random.nextInt(6);
				c.repaint();
			}
		});
	}
}	
	class MyCanvas1 extends Canvas{
		int val,val1;
		int d;
		MyCanvas1(){
			val=val1=1;
			setSize(150,100);
			setBackground(Color.black);
			d=5;

		}
		public void drawDie(Graphics g,int val,int x,int y){
			g.setColor(Color.red);
			g.fillRect(x,y,25,25);
			g.setColor(Color.black);
			switch(val){
			
			case 5:		g.fillOval(x+17,y+3,d,d);
						g.fillOval(x+3,y+17,d,d);
			
			case 3:		g.fillOval(x+3,y+3,d,d);
						g.fillOval(x+17,y+17,d,d);
			
			case 1:		g.fillOval(x+10,y+10,d,d);
						break;
		
			case 6:		g.fillOval(x+3,y+10,d,d);
						g.fillOval(x+17,y+10,d,d);
								
			case 4:		g.fillOval(x+17,y+3,d,d);
						g.fillOval(x+3,y+17,d,d);
						
			case 2:		g.fillOval(x+3,y+3,d,d);
						g.fillOval(x+17,y+17,d,d);
						break;
		}
	}
	
		public void paint(Graphics g){
			drawDie(g,val,33,37);
			drawDie(g,val1,91,37);
		}
		
	
}
/*
<applet code=Dice2 width="150" height="150">
</applet>
*/