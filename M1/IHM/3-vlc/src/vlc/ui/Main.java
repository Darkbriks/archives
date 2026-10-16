/* notification.Main
 * (c) blanch@imag.fr 2025-                                                */


package vlc.ui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;

public class Main extends JFrame implements ComponentListener {
    private final BottomBar bottomBar;

    public Main(String title,String argv[]) {
        super(title);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        setMinimumSize(new Dimension(600, 130));
        setMaximumSize(new Dimension(Integer.MAX_VALUE, 130));

        JPanel readerPanel = new JPanel();
        readerPanel.setLayout(new BorderLayout());

        readerPanel.add(new TopBar(), BorderLayout.PAGE_START);

        bottomBar = new BottomBar(this);
        readerPanel.add(bottomBar, BorderLayout.PAGE_END);

        add(readerPanel, BorderLayout.PAGE_START);

        addComponentListener(this);

        pack();
    }

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() { new Main("Clone-VLC", args).setVisible(true); }
		});
	}

    @Override
    public void componentResized(ComponentEvent componentEvent) {
        bottomBar.togglePlaylistPanel(this, this.getSize().height > 250);
    }

    @Override
    public void componentMoved(ComponentEvent componentEvent) {

    }

    @Override
    public void componentShown(ComponentEvent componentEvent) {

    }

    @Override
    public void componentHidden(ComponentEvent componentEvent) {

    }
}
