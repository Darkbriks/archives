/* notification.Main
 * (c) blanch@imag.fr 2025-                                                */


package notification.ui;

import javax.swing.SwingUtilities;

import notification.fc.Variable;


public class Main {
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() { 
				Window window = new Window();
				Variable variable = new Variable();

				new Thread(()->{
					while(true){
						window.valueChanged(variable.getValue());
					}
				});
			}
		});
		
	}
}
