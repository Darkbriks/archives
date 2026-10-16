package grapher.ui;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.util.function.Function;

import javax.swing.*;

public class MainMenu extends JMenuBar{
    protected FunctionContainer functionContainer = null;

    private class FunctionAction extends AbstractAction{
        private final Function<Void, Void> actionFunction;

        public FunctionAction(String name, Function<Void, Void> actionFunction){
            super(name);
            this.actionFunction = actionFunction;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            actionFunction.apply(null);
        }
    }


    public MainMenu(FunctionContainer functionContainer){
        this.functionContainer = functionContainer;

        int menuMask = Toolkit.getDefaultToolkit().getMenuShortcutKeyMaskEx();

        JMenu menu = new JMenu("Expression");

        JMenuItem addItem = new JMenuItem(new FunctionAction("Ajouter", (v) -> { functionContainer.addFunctionToList(); return null; }));
        JMenuItem removeItem = new JMenuItem(new FunctionAction("Supprimer", (v) -> { functionContainer.removeFunctionToList(); return null; }));

        addItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, menuMask));
        removeItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_BACK_SPACE, menuMask));

        removeItem.setEnabled(functionContainer.hasSelection());
        functionContainer.addSelectionChangeListener((has) -> removeItem.setEnabled(has));

        menu.add(addItem);
        menu.add(removeItem);

        add(menu);
    }
}
