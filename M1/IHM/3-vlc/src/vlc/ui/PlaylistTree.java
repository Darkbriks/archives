package vlc.ui;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;

public class PlaylistTree {
    private final JTree tree;
    private DefaultMutableTreeNode rootNode;

    public PlaylistTree() {
        rootNode = new DefaultMutableTreeNode("Playlist");
        populateTree(rootNode);
        tree = new JTree(rootNode);
    }

    public JTree getTree() {
        return tree;
    }

    private void populateTree(DefaultMutableTreeNode root) {
        DefaultMutableTreeNode the_warning = new DefaultMutableTreeNode("The Warning");

        DefaultMutableTreeNode keep_me_fed = new DefaultMutableTreeNode("Keep Me Fed");
        // TODO: Title, Author, Duration only in tree columns, not in nodes
        keep_me_fed.add(new DefaultMutableTreeNode("Six feet deep"));
        keep_me_fed.add(new DefaultMutableTreeNode("Apologize"));
        keep_me_fed.add(new DefaultMutableTreeNode("Hell you call a dream"));
        keep_me_fed.add(new DefaultMutableTreeNode("Automatic sun"));
        the_warning.add(keep_me_fed);

        DefaultMutableTreeNode xxi_century_blood = new DefaultMutableTreeNode("XXI Century Blood");
        xxi_century_blood.add(new DefaultMutableTreeNode("XXI Century Blood"));
        xxi_century_blood.add(new DefaultMutableTreeNode("Breath"));
        xxi_century_blood.add(new DefaultMutableTreeNode("Black holes"));
        the_warning.add(xxi_century_blood);

        root.add(the_warning);

        DefaultMutableTreeNode linkin_park = new DefaultMutableTreeNode("Linkin Park");

        DefaultMutableTreeNode meteora = new DefaultMutableTreeNode("Meteora");
        meteora.add(new DefaultMutableTreeNode("Don't stay"));
        meteora.add(new DefaultMutableTreeNode("Somewhere I belong"));
        linkin_park.add(meteora);

        root.add(linkin_park);

    }
}
