package grapher.ui;

import java.awt.Color;
import java.awt.Component;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.table.TableCellRenderer;

public class ColorTableCellRenderer extends JLabel implements TableCellRenderer {
    
    public ColorTableCellRenderer() {
        setOpaque(true);
    }

    @Override
    public Component getTableCellRendererComponent(JTable table, Object value,
                                                   boolean isSelected, boolean hasFocus,
                                                   int row, int column) {
        Color color = (Color) value;
        setBackground(color);
        setText("");
        
        if (isSelected) {
            setBorder(javax.swing.BorderFactory.createLineBorder(Color.BLACK, 2));
        } else {
            setBorder(javax.swing.BorderFactory.createLineBorder(Color.GRAY, 1));
        }
        
        return this;
    }
}
