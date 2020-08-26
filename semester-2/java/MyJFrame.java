import javax.swing.*;
import java.awt.event.*;
import java.awt.Color;

class MyJFrame extends JFrame {
	JButton jb;
	JLabel jl;
	JTextArea ta;
	JTextField tf;
	JPasswordField jp;
	MyJFrame() {

		jb = new JButton("Click Me");
		jb.setBounds(40, 300, 120, 30);
		jb.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tf.setText(new String(jp.getPassword()));
				ta.setText("Enter some text here");
			}
		});
		jl = new JLabel("Enter text here:");
		jl.setBounds(40, 30, 100, 30);
		ta = new JTextArea();
		ta.setBounds(40, 80, 250, 100);
		tf = new JTextField();
		tf.setBounds(40, 200, 250, 30);
		jp = new JPasswordField();
		jp.setBounds(40, 250, 70, 30);
		add(jb);
		add(jl);
		add(ta);
		add(tf);
		add(jp);
		getContentPane().setBackground(Color.yellow);
		setSize(400, 400);
		setLayout(null);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public static void main(String args[]) {
		new MyJFrame();
	}
}