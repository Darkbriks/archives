package downloader.ui;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JProgressBar;

import downloader.fc.Downloader;

public class Download extends JPanel{
    Downloader downloader;
    JProgressBar progressBar;
    JLabel urlField;
    JButton buttonToRemove;
    Main main;
    JButton buttonToPause;
    boolean isPaused;


    Download(String url, Main main){
        super();

        this.main = main;

        try{
            this.downloader = new Downloader(url);
        } catch (RuntimeException e) {
            main.deleteDownload(this);
            return;
        }

        
        progressBar = new JProgressBar(0);
        progressBar.setStringPainted(true);
        
        urlField = new JLabel(url);
        
        buttonToRemove = new JButton("×");
        
        buttonToRemove.addActionListener(new ActionListener() {
            
            @Override
            public void actionPerformed(ActionEvent e) {
                deleteDownload();
            }
            
        });

        isPaused = false;

        buttonToPause = new JButton("||");

        buttonToPause.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if (isPaused){
                    buttonToPause.setText("||");
                    downloader.unlock();
                }
                else{
                    buttonToPause.setText("▶︎");
                    downloader.lock();
                }
                isPaused = !isPaused;
            }
            
        });

        
        if (this.downloader != null){
            this.downloader.addPropertyChangeListener(new PropertyChangeListener() {
                public void propertyChange(PropertyChangeEvent evt) {
                    setProgress();
                }
            });
            downloader.execute();
        }

        setLayout(new BorderLayout());

        JPanel pansement = new JPanel();
        pansement.add(buttonToPause);
        pansement.add(buttonToRemove);

        add(urlField, BorderLayout.PAGE_START);
        add(progressBar, BorderLayout.CENTER);
        add(pansement, BorderLayout.LINE_END);
        

    }

    public void setProgress(){
        int value = downloader.getProgress();
        progressBar.setValue(value);
        progressBar.setString(Integer.toString(value)+" %");
    }


    public void deleteDownload(){
        downloader.cancel(true);
        Container parent = this.getParent();
        parent.remove(this);
        parent.repaint();
    }
}
