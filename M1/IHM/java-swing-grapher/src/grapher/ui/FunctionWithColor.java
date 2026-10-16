package grapher.ui;

import java.awt.Color;
import grapher.fc.Function;

public class FunctionWithColor {
    private Function function;
    private Color color;

    public FunctionWithColor(Function function, Color color) {
        this.function = function;
        this.color = color;
    }

    public Function getFunction() {
        return function;
    }

    public void setFunction(Function function) {
        this.function = function;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public String getExpression() {
        return function.toString();
    }
}
