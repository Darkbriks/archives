package vlc.ui;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class PlaylistPanel extends JPanel {
    // Playlist -> Nom, Auteur, Durée
    JScrollPane playlistScrollPane;
    PlaylistTree playlistJTree;

    class BottomPlaylistBar extends JPanel {
        private JButton addButton;
        private JToggleButton randomButton;
        private JToggleButton loopButton;

        JPanel buttonsPanel;
        JLabel nbElementPanel;

        JPanel searchPanel;
        JTextField textArea;
        JButton searchButton;

        BottomPlaylistBar() {
            super();

            setLayout(new BorderLayout());

            addButton = new JButton("+");
            randomButton = new JToggleButton("#");
            loopButton = new JToggleButton("<=>");

            buttonsPanel = new JPanel();
            buttonsPanel.add(addButton);
            buttonsPanel.add(randomButton);
            buttonsPanel.add(loopButton);
            add(buttonsPanel, BorderLayout.LINE_START);

            nbElementPanel = new JLabel("XX éléments");
            nbElementPanel.setHorizontalAlignment(SwingConstants.CENTER);
            add(nbElementPanel, BorderLayout.CENTER);

            searchPanel = new JPanel();
            searchPanel.setLayout(new BorderLayout());
            Border border = BorderFactory.createLoweredBevelBorder();
            searchPanel.setBorder(border);

            textArea = new JTextField();
            textArea.setMinimumSize(new Dimension(100, 25));
            textArea.setSize(100, 25);
            searchButton = new JButton("⌕");
            Font font = searchButton.getFont();
            searchButton.setFont(new Font(font.getName(),font.getStyle(), 20));
            searchPanel.add(searchButton, BorderLayout.LINE_START);
            searchPanel.add(textArea, BorderLayout.CENTER);
            add(searchPanel, BorderLayout.LINE_END);
        }
    }

    PlaylistPanel() {
        super();
        setLayout(new BorderLayout());
        setMinimumSize(new Dimension(600, 500));
        setBorder(BorderFactory.createLineBorder(Color.GRAY));

        playlistScrollPane = new JScrollPane();
        playlistScrollPane.setMinimumSize(new Dimension(600, 450));
        add(playlistScrollPane, BorderLayout.CENTER);

        playlistJTree = new PlaylistTree();
        playlistScrollPane.setViewportView(playlistJTree.getTree());

        add(new BottomPlaylistBar(), BorderLayout.PAGE_END);
    }
}
