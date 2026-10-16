package grapher.ui;

import java.awt.Color;
import java.awt.Component;
import javax.swing.AbstractCellEditor;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JTable;
import javax.swing.table.TableCellEditor;

public class ColorTableCellEditor extends AbstractCellEditor implements TableCellEditor {
    private Color currentColor;
    private JButton button;

    public ColorTableCellEditor() {
        button = new JButton();
        button.setBorderPainted(false);
        button.addActionListener(e -> {
            Color newColor = JColorChooser.showDialog(button, "Choisir une couleur", currentColor);
            if (newColor != null) {
                currentColor = newColor;
            }
            fireEditingStopped();
        });
    }

    @Override
    public Object getCellEditorValue() {
        return currentColor;
    }

    @Override
    public Component getTableCellEditorComponent(JTable table, Object value,
                                                  boolean isSelected, int row, int column) {
        currentColor = (Color) value;
        button.setBackground(currentColor);
        return button;
    }
}
