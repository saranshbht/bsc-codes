import java.awt.*;
import java.awt.event.*;

class SampleFileDialog extends Frame {
	Button b;
	String s = "";
	//SampleFileDialog sfd;
	FileDialog fd;
	SampleFileDialog() {
		setSize(400, 400);
		fd = new FileDialog(this);
		fd.setDirectory("D:/javapg practice/");
		s = fd.getDirectory();
		b = new Button("Click Me");
		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fd.setVisible(true);
			}
		});
		add(b);
		setLayout(new FlowLayout());
		setVisible(true);
	}

	public void paint(Graphics g) {
		g.drawString(s, 100, 100);
	}

	public static void main(String args[]) {
		new SampleFileDialog();
	}
}