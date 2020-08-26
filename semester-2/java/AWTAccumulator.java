import java.awt.*;
import java.awt.event.*;

class AWTAccumulator {
	public static void main(String args[]) {
		Frame f = new Frame("AWT Accumulator");
		Label l1 = new Label("Enter an integer and press enter");
		Label l2 = new Label("The accumulated sum is");
		TextField tf = new TextField(String.valueOf(0));
		TextField tf1 = new TextField(String.valueOf(0));
		tf1.setEditable(false);
		f.add(l1);
		f.add(tf);
		f.add(l2);
		f.add(tf1);
		f.setLayout(new FlowLayout());
		f.setSize(400, 400);
		f.setVisible(true);
		tf.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int c = Integer.parseInt(tf.getText());
				int d = Integer.parseInt(tf1.getText());
				tf1.setText(String.valueOf(c + d));
			}
		});
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				f.dispose();
			}
		});
	}
}