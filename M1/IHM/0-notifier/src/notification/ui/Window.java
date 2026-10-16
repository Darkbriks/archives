/* notification.Window
 * (c) blanch@imag.fr 2025-                                                */


package notification.ui;

import javax.swing.JFrame;
import javax.swing.JLabel;


public class Window extends JFrame {
	private JLabel label = new JLabel("0123456789");
	
	Window() {
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		add(label);
		pack();
		setVisible(true);
	}

	public void valueChanged(double value){
		label.setText(Double.toString(value));
	}
}
