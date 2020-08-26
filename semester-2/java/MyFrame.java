import java.awt.*;
import java.awt.event.*;

class MyFrame extends Frame {
	MyFrame() {
		setBackground(Color.yellow);

		Button b = new Button("Submit");
		b.setBounds(30, 100, 80, 30);
		add(b);
		setSize(300, 300);
		setLayout(null);
		setVisible(true);
		addWindowListener(new WindowAdapter() {
			public void windowIconified(WindowEvent e) {
				Button c = new Button("Iconified");
				c.setBounds(50, 300, 80, 30);
				add(c);
			}

			public void windowDeiconified(WindowEvent e) {
				Button d = new Button("Deiconified");
				d.setBounds(50, 500, 80, 30);
				add(d);
			}
		});

	}

	public static void main(String args[]) {
		new MyFrame();
	}
}

