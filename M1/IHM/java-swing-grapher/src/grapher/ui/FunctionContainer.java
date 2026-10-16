package grapher.ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.function.Consumer;

import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JToolBar;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import grapher.fc.Function;
import grapher.fc.FunctionFactory;

public class FunctionContainer extends JPanel {
    private Grapher grapher = null;
    private JTable functionTable;
    private FunctionTableModel tableModel;
    private JButton addButton = new JButton("+");
    private JButton removeButton = new JButton("-");
    private Random random = new Random();

    private final List<Consumer<Boolean>> selectionListeners = new ArrayList<>();

    public FunctionContainer(Grapher grapher){
        this.grapher = grapher;
        
        tableModel = new FunctionTableModel(grapher);

        functionTable = new JTable(tableModel);
        functionTable.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);

        functionTable.getColumnModel().getColumn(1).setCellRenderer(new ColorTableCellRenderer());
        functionTable.getColumnModel().getColumn(1).setCellEditor(new ColorTableCellEditor());

        functionTable.getColumnModel().getColumn(0).setPreferredWidth(120);
        functionTable.getColumnModel().getColumn(1).setPreferredWidth(80);
        functionTable.getColumnModel().getColumn(1).setMaxWidth(80);

        functionTable.getSelectionModel().addListSelectionListener(selectionListener);

        JToolBar mainToolBar = new JToolBar();
        
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addFunctionToList();
            }
        });
        mainToolBar.add(addButton);

        removeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                removeFunctionToList();
            }
        });
        removeButton.setEnabled(false);
        mainToolBar.add(removeButton);

        JScrollPane scrollPane = new JScrollPane(functionTable);

        BorderLayout borderLayout = new BorderLayout();
        setLayout(borderLayout);
        add(scrollPane, BorderLayout.CENTER);
        add(mainToolBar, BorderLayout.PAGE_END);
    }

    ListSelectionListener selectionListener = new ListSelectionListener() {
		@Override
        public void valueChanged(ListSelectionEvent e) {
            if (e.getValueIsAdjusting()) return;
            
            boolean hasSelection = functionTable.getSelectedRowCount() > 0;
            removeButton.setEnabled(hasSelection);

            for (Consumer<Boolean> l : selectionListeners) {
                try {
                    l.accept(hasSelection);
                } catch (Exception ex) {}
            }

            // Mettre à jour les fonctions sélectionnées dans le grapher
            List<FunctionWithColor> selectedFuncs = new ArrayList<>();
            int[] selectedRows = functionTable.getSelectedRows();
            for (int row : selectedRows) {
                selectedFuncs.add(tableModel.getFunctionAt(row));
            }
            grapher.setSelectedFunctions(selectedFuncs);
            grapher.repaint();
        }
	};

    public void addSelectionChangeListener(Consumer<Boolean> listener) {
        selectionListeners.add(listener);
    }

    public boolean hasSelection() {
        return functionTable.getSelectedRowCount() > 0;
    }

    public void addFunctionToList(){
        String expression = (String) JOptionPane.showInputDialog(
            this,
            "Nouvelle expression :",
            "Input",
            JOptionPane.PLAIN_MESSAGE
        );

        if (expression != null){
            try {
                Function f = FunctionFactory.createFunction(expression);
                Color randomColor = generateRandomColor();
                FunctionWithColor fwc = new FunctionWithColor(f, randomColor);
                tableModel.addFunction(fwc);
                grapher.repaint();
            } catch (Exception e) {
                JOptionPane.showMessageDialog(this, "Fonction invalide", "Erreur", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    public void removeFunctionToList(){
        int[] selectedRows = functionTable.getSelectedRows();
        for (int i = selectedRows.length - 1; i >= 0; i--) {
            tableModel.removeFunction(selectedRows[i]);
        }
        grapher.repaint();
    }

    private Color generateRandomColor() {
        float hue = random.nextFloat();
        float saturation = 0.7f + random.nextFloat() * 0.3f;
        float brightness = 0.7f + random.nextFloat() * 0.3f;
        return Color.getHSBColor(hue, saturation, brightness);
    }

    public FunctionTableModel getTableModel() {
        return tableModel;
    }
}
