/* grapher.ui.Main
 * (c) blanch@imag.fr 2021–2025                                            */

package grapher.ui;

import java.awt.Color;
import grapher.fc.*;

import javax.swing.JFrame;
import javax.swing.JSplitPane;
import javax.swing.SwingUtilities;


// main that launch a grapher.ui.Grapher

public class Main extends JFrame {
	Main(String title, String[] expressions) {
		super(title);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		Grapher grapher = new Grapher();
        Interaction interaction = new Interaction(grapher);

        grapher.addMouseListener(interaction);
        grapher.addMouseMotionListener(interaction);
        grapher.addMouseWheelListener(interaction);

		FunctionContainer functionContainer = new FunctionContainer(grapher);

		for(String expression: expressions) {
			try {
				Function f = FunctionFactory.createFunction(expression);
				Color color = Color.getHSBColor((float)Math.random(), 0.8f, 0.8f);
				FunctionWithColor fwc = new FunctionWithColor(f, color);
				functionContainer.getTableModel().addFunction(fwc);
			} catch (Exception e) {
				System.err.println("Expression invalide : " + expression);
			}
		}

		JSplitPane separation = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, functionContainer, grapher);
        separation.setDividerLocation(250);

		add(separation);

        MainMenu mainMenu = new MainMenu(functionContainer);
        setJMenuBar(mainMenu);

		pack();
	}

	public static void main(String[] argv) {
		final String[] expressions = argv;
		SwingUtilities.invokeLater(new Runnable() {
			public void run() { 
				new Main("grapher", expressions).setVisible(true); 
			}
		});
	}
}
