import java.awt.Toolkit;

class ToolkitExample {
	public static void main(String ...args) {
		Toolkit tk = Toolkit.getDefaultToolkit();
		System.out.println("Screen Resolution: " + tk.getScreenResolution());
		System.out.println("Height: " + tk.getScreenSize().height);
		System.out.println("Width: " + tk.getScreenSize().width);
		System.out.println(tk.getColorModel());
		System.out.println(tk.getMenuShortcutKeyMask());
	}
}