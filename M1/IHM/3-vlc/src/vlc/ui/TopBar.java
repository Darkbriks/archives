package vlc.ui;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class TopBar extends JPanel {

    class MainControll extends JPanel {
        private JButton backButton;
        private JButton forwardButton;
        private JToggleButton actionButton;

        MainControll() {
            backButton = new JButton("<<");
            forwardButton = new JButton(">>");
            actionButton = new JToggleButton(">");

            actionButton.setMinimumSize(new Dimension(70, 40));
            actionButton.setPreferredSize(new Dimension(70, 40));

            add(backButton);
            add(actionButton);
            add(forwardButton);
        }
    }

    class ReaderControll extends JPanel {
        private JLabel titleLabel;
        private JLabel timeLabel;
        private JPanel titleTimePanel;
        private JSlider timeSlider;

        ReaderControll() {
            setLayout(new BorderLayout());

            Border border = BorderFactory.createLoweredBevelBorder();
            setBorder(border);

            titleLabel = new JLabel("Lecteur multimédia VLC");
            timeLabel = new JLabel("00:00");
            titleTimePanel = new JPanel();
            titleTimePanel.setLayout(new BorderLayout());
            titleTimePanel.add(titleLabel, BorderLayout.LINE_START);
            titleTimePanel.add(timeLabel, BorderLayout.LINE_END);
            add(titleTimePanel, BorderLayout.PAGE_START);

            timeSlider = new JSlider();
            add(timeSlider, BorderLayout.CENTER);
        }
    }

    public TopBar() {
        super();
        setLayout(new BorderLayout());
        add(new MainControll(), BorderLayout.LINE_START);
        add(new ReaderControll(), BorderLayout.CENTER);
    }
}
