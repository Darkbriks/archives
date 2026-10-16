package downloader.ui;

import java.awt.BorderLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

public class Main extends JFrame {
	private JPanel downloadContainer;
	private UrlBar urlBar;

    public Main(String title,String argv[]){
        super(title);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLayout(new BorderLayout());

		downloadContainer = new JPanel();
		downloadContainer.setLayout(new StackLayout());
        
        for(String url: argv) {
			addDownload(url);
		}

		add(downloadContainer, BorderLayout.CENTER);

		urlBar = new UrlBar(this);
		add(urlBar, BorderLayout.PAGE_END);

		pack();
    }

	public static void main(String[] argv){
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {new Main("Downloader",argv).setVisible(true);}
		});
	}

	public void addDownload(String url){
		Download downloadItem = new Download(url,this);
		downloadContainer.add(downloadItem);

		revalidate();
	}


	public void deleteDownload(Download download){
		remove(download);
		revalidate();
	}
}
