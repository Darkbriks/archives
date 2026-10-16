package vlc.ui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BottomBar extends JPanel {
    private JButton backward;
    private JToggleButton playPause;
    private boolean isPaused; 
    private JButton forward;

    private JButton minVolume;
    private JSlider volumeSlider;
    private JButton maxVolume;

    private JButton controlButton;
    private JToggleButton manageButton;

    PlaylistPanel playlistPanel;

    public BottomBar(JFrame mainFrame) {
        super();
        setLayout(new BorderLayout());

        isPaused = true;

        backward = new JButton("|<");
        playPause = new JToggleButton("▶");
        forward = new JButton(">|");

        minVolume = new JButton("<");
        volumeSlider = new JSlider();
        maxVolume = new JButton("<))");

        controlButton = new JButton("#");
        manageButton = new JToggleButton("=");

        playPause.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if (isPaused){
                    playPause.setText("||");
                }
                else{
                    playPause.setText("▶");
                }

                isPaused = !isPaused;
            }
            
        });

        JPanel firstPanel = new JPanel();
        firstPanel.add(backward);
        firstPanel.add(playPause);
        firstPanel.add(forward);

        firstPanel.add(minVolume);
        firstPanel.add(volumeSlider);
        firstPanel.add(maxVolume);

        JPanel lastPanel = new JPanel();

        lastPanel.add(controlButton);
        lastPanel.add(manageButton);

        add(firstPanel, BorderLayout.LINE_START);
        add(lastPanel, BorderLayout.LINE_END);

        //----- Playlist Panel -----//

        playlistPanel = new PlaylistPanel();

        manageButton.addActionListener(e -> togglePlaylistPanel(mainFrame));
    }

    public void togglePlaylistPanel(JFrame mainFrame, boolean show) {
        if (show) {
            add(playlistPanel, BorderLayout.PAGE_END);
            mainFrame.setMinimumSize(new Dimension(600, 0));
            mainFrame.setMaximumSize(null);
        } else {
            remove(playlistPanel);
            mainFrame.setMinimumSize(new Dimension(600, 130));
            mainFrame.setMaximumSize(new Dimension(Integer.MAX_VALUE, 130));
        }
        mainFrame.revalidate();
        mainFrame.repaint();
        manageButton.setSelected(show);
    }

    private void togglePlaylistPanel(JFrame mainFrame) {
        if (manageButton.isSelected()) {
            mainFrame.setSize(new Dimension(600, 530));
            togglePlaylistPanel(mainFrame, true);
        } else {
            mainFrame.setSize(new Dimension(600, 130));
            togglePlaylistPanel(mainFrame, false);
        }
    }
}
