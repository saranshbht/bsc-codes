import javax.swing.*;
import java.awt.Color;
import java.awt.event.*;

class CheckComboButton extends JFrame {
	CheckComboButton ccb;
	JCheckBox c1, c2;
	JRadioButton r1, r2;
	ButtonGroup jbg;
	JComboBox<String> jcm;
	JLabel jl;
	JTable jt;
	JList<String> jlist;
	JScrollBar jsb;
	CheckComboButton() {
		getContentPane().setBackground(Color.yellow);

		r1 = new JRadioButton("Java");
		r2 = new JRadioButton("C++");

		r1.setBounds(50, 10, 100, 30);
		r2.setBounds(50, 50, 100, 30);

		jbg = new ButtonGroup();
		jbg.add(r1);
		jbg.add(r2);

		c1 = new JCheckBox("PHP", true);
		c2 = new JCheckBox("Python");

		c1.setBounds(50, 90, 100, 30);
		c2.setBounds(50, 130, 100, 30);

		jl = new JLabel("Others:");
		jl.setBounds(50, 170, 100, 30);

		String clang[] = {"Ada", "Pascal", "Brainfuck", "Perl", "Ruby"};

		jcm = new JComboBox<String>(clang);
		jcm.setBounds(50, 210, 100, 30);

		String col[] = {"RollNo", "Name"};
		String content[][] = {{"1", "Saransh"}, {"2", "Naveen"}, {"3", "Himanshu"}};

		jt = new JTable(content, col);
		jt.setCellSelectionEnabled(true);
		jt.setBounds(50, 250, 200, 50);

		DefaultListModel<String> list = new DefaultListModel<>();
		list.addElement("Something");
		list.addElement("Anything");
		list.addElement("Everything");
		list.addElement("A Thing");

		jlist = new JList<>(list);
		jlist.setBounds(50, 310, 100, 100);

		jsb = new JScrollBar();
		jsb.setBounds(370, 0, 20, 400);

		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				int option = JOptionPane.showConfirmDialog(ccb, "Are you sure?");
				if (option == JOptionPane.YES_OPTION) {
					setDefaultCloseOperation(EXIT_ON_CLOSE);
				}
			}
		});

		add(jsb);
		add(jlist);
		add(jt);
		add(jcm);
		add(jl);
		add(c1);
		add(c2);
		add(r1);
		add(r2);

		setSize(400, 400);
		setLayout(null);
		setVisible(true);
		setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
	}

	public static void main(String args[]) {
		new CheckComboButton();
	}
}