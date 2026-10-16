package grapher.ui;

import java.awt.Color;
import java.util.ArrayList;
import java.util.List;
import javax.swing.table.AbstractTableModel;
import grapher.fc.Function;
import grapher.fc.FunctionFactory;

public class FunctionTableModel extends AbstractTableModel {
    private final List<FunctionWithColor> functions;
    private final String[] columnNames = {"Expression", "Couleur"};
    private final Grapher grapher;

    public FunctionTableModel(Grapher grapher) {
        this.functions = new ArrayList<>();
        this.grapher = grapher;
    }

    @Override
    public int getRowCount() {
        return functions.size();
    }

    @Override
    public int getColumnCount() {
        return columnNames.length;
    }

    @Override
    public String getColumnName(int column) {
        return columnNames[column];
    }

    @Override
    public Class<?> getColumnClass(int columnIndex) {
        if (columnIndex == 0) {
            return String.class;
        } else {
            return Color.class;
        }
    }

    @Override
    public boolean isCellEditable(int rowIndex, int columnIndex) {
        return true;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        FunctionWithColor fwc = functions.get(rowIndex);
        if (columnIndex == 0) {
            return fwc.getExpression();
        } else {
            return fwc.getColor();
        }
    }

    @Override
    public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
        FunctionWithColor fwc = functions.get(rowIndex);
        
        if (columnIndex == 0) {
            String newExpression = (String) aValue;
            try {
                Function newFunction = FunctionFactory.createFunction(newExpression);
                fwc.setFunction(newFunction);
                fireTableCellUpdated(rowIndex, columnIndex);
                grapher.repaint();
            } catch (Exception e) {}
        } else if (columnIndex == 1) {
            fwc.setColor((Color) aValue);
            fireTableCellUpdated(rowIndex, columnIndex);
            grapher.repaint();
        }
    }

    public void addFunction(FunctionWithColor fwc) {
        functions.add(fwc);
        grapher.addFunction(fwc);
        fireTableRowsInserted(functions.size() - 1, functions.size() - 1);
    }

    public void removeFunction(int index) {
        grapher.removeFunction(functions.get(index));
        functions.remove(index);
        fireTableRowsDeleted(index, index);
    }

    public FunctionWithColor getFunctionAt(int index) {
        return functions.get(index);
    }
}
