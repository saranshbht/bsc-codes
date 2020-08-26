import java.awt.*;
import java.awt.event.*;

class AWTCounter {
	public static void main(String args[]) {
		Frame f = new Frame("AWT Counter");
		Label l1 = new Label("Counter");
		Button b = new Button("Count");
		TextField tf = new TextField(String.valueOf(0));
		tf.setEditable(false);
		f.add(l1);
		f.add(tf);
		f.add(b);
		f.setLayout(new FlowLayout());
		f.setSize(400, 400);
		f.setVisible(true);
		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int c = Integer.parseInt(tf.getText());
				tf.setText(String.valueOf(++c));
			}
		});
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				f.dispose();
			}
		});
	}
}