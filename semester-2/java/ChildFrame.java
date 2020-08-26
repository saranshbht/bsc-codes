import java.awt.event.*;
import java.awt.*;

public class ChildFrame extends Frame {
	Button b;
	Frame f;
	String msg = "", cmsg = "";

	ChildFrame() {
		b = new Button("Click Me");
		f = new Frame("Child Frame") {
			public void paint(Graphics g) {
				super.paint(g);
				g.drawString(cmsg, 50, 50);
			}
		};

		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				f.setVisible(true);
			}
		});

		add(b);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});

		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				f.setVisible(false);
			}
		});

		f.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				cmsg = "Mouse Entered Child Frame";
				f.repaint();
			}

			public void mouseExited(MouseEvent e) {
				cmsg = "Mouse Exited Child Frame";
				f.repaint();
			}
		});

		addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				msg = "Mouse Entered Parent Frame";
				repaint();
			}

			public void mouseExited(MouseEvent e) {
				msg = "Mouse Exited Parent Frame";
				repaint();
			}
		});

		f.setLocation(200, 200);
		f.setSize(300, 300);
		b.setBounds(150, 185, 100, 30);
		setTitle("Parent Frame");
		setSize(400, 400);
		setLayout(null);
		setVisible(true);
	}

	public void paint(Graphics g) {
		super.paint(g);
		g.drawString(msg, 50, 50);
	}

	public static void main(String args[]) {
		new ChildFrame();
	}
}
