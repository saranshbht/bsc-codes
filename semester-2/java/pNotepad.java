import javax.swing.*;
import java.awt.event.*;

class pNotepad extends JFrame implements ActionListener {
	JMenuItem cut, copy, paste, selectAll;
	JMenuBar jmb;
	JMenu file, edit, help;
	JTextArea jta;
	JSeparator jsp, jsp1, jsp2;
	JCheckBoxMenuItem jcmi;
	JPopupMenu pop;
	pNotepad() {
		setTitle("Partial Notepad");
		jta = new JTextArea();
		jta.setBounds(0, 0, 400, 400);
		add(jta);
		cut = new JMenuItem("Cut");
		copy = new JMenuItem("Copy");
		paste = new JMenuItem("Paste");
		selectAll = new JMenuItem("Select All");
		file = new JMenu("File");
		file.setMnemonic(KeyEvent.VK_SHIFT);
		edit = new JMenu("Edit");
		help = new JMenu("Help");
		jsp = new JSeparator();
		jsp1 = new JSeparator(); jsp2 = new JSeparator();
		jcmi = new JCheckBoxMenuItem("Something");
		jcmi.setMnemonic(KeyEvent.VK_S);
		file.add(jcmi);
		edit.add(cut);
		edit.add(jsp);
		edit.add(copy);
		edit.add(jsp1);
		edit.add(paste);
		edit.add(jsp2);
		edit.add(selectAll);
		jmb = new JMenuBar();
		pop = new JPopupMenu();
		pop.add(cut);
		pop.add(copy);
		pop.add(paste);
		jta.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				pop.show(jta, e.getX(), e.getY());
			}
		})	;

		jmb.add(file);
		jmb.add(edit);
		jmb.add(help);
		add(jmb);
		setJMenuBar(jmb);
		cut.addActionListener(this);
		copy.addActionListener(this);
		paste.addActionListener(this);
		selectAll.addActionListener(this);
		setSize(400, 400);
		setLayout(null);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == cut) {
			jta.cut();
		}
		if (e.getSource() == copy) {
			jta.copy();
		}
		if (e.getSource() == paste) {
			jta.paste();
		}
		if (e.getSource() == selectAll) {
			jta.selectAll();
		}
	}

	public static void main(String args[]) {
		new pNotepad();
	}
}