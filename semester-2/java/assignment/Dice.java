//Question 23

import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;
import java.util.Random;
public class Dice extends Applet implements MouseListener{
	int val,val1;
	Random random;
	int d;
	public void init(){
		addMouseListener(this);
		val=val1=1;
		d=5;
	}
		public void mouseClicked(MouseEvent e){
				random= new Random();
				val=1+random.nextInt(6);
				val1=1+random.nextInt(6);
					repaint();
		}
		
	
	public void mouseEntered(MouseEvent e) {}  
    public void mouseExited(MouseEvent e) {}  
    public void mousePressed(MouseEvent e) {}  
    public void mouseReleased(MouseEvent e) {}  
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
		drawDie(g,val,20,20);
		drawDie(g,val1,55,20);
	}
		
	
}
/*
<applet code=Dice width="100" height="100">
</applet>
*/