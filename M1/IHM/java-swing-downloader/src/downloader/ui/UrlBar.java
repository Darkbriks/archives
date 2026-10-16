package downloader.ui;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UrlBar extends JPanel {
    JButton buttonToAdd;
    JTextField urlField;
    Main main;
    
    UrlBar(Main main){
        super();

        this.main = main;

        urlField = new JTextField();
        buttonToAdd = new JButton("add");

        setLayout(new BorderLayout());

        buttonToAdd.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                main.addDownload(getUrlField());
                urlField.setText("");
            }
            
        });


        add(urlField, BorderLayout.CENTER);
        add(buttonToAdd, BorderLayout.LINE_END);
    }

    public String getUrlField(){
        return this.urlField.getText();
    }

}
