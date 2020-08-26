import javax.swing;
import java.awt.event.*;

class MyJFrame extends JFrame {
	public static void main(String args[]) {
		JButton jb = new JButton("Click Me");
		jb.setBounds(40, 40, 80, 30);
		add(jb);
		setSize(400, 400);
		setLayout(null);
		setVisible(true);
	}
}