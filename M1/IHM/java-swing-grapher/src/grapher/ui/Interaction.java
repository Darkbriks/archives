package grapher.ui;

import java.awt.*;
import java.awt.event.*;

public class Interaction implements MouseListener,
        MouseMotionListener,
        MouseWheelListener {

    enum State {
        IDLE, LEFT_PRESSED, RIGHT_PRESSED, LEFT_DRAGGED, RIGHT_DRAGGED
    }

    private final byte DRAG_THRESHOLD = 3;

    private State state = State.IDLE;
    private Grapher grapher = null;

    private Point point = null;

    public Interaction(Grapher grapher) {
        this.grapher = grapher;
        grapher.setInteraction(this);
    }

    @Override
    public void mouseClicked(MouseEvent e) {}

    @Override
    public void mousePressed(MouseEvent e) {
        //if (state != State.IDLE) return;
        point = e.getPoint();
        if (e.getButton() == MouseEvent.BUTTON1) {
            state = State.LEFT_PRESSED;
        } else if (e.getButton() == MouseEvent.BUTTON3) {
            state = State.RIGHT_PRESSED;
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        if (e.getButton() == MouseEvent.BUTTON1 && state == State.LEFT_PRESSED) {
            state = State.IDLE;
            grapher.zoom(e.getPoint(), 5);

        } else if (e.getButton() == MouseEvent.BUTTON3 && state == State.RIGHT_PRESSED) {
            state = State.IDLE;
            grapher.zoom(e.getPoint(), -5);
        } else if (e.getButton() == MouseEvent.BUTTON1 && state == State.LEFT_DRAGGED) {
            state = State.IDLE;
            grapher.setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
        } else if (e.getButton() == MouseEvent.BUTTON3 && state == State.RIGHT_DRAGGED) {
            state = State.IDLE;
            grapher.zoom(point, e.getPoint());
        }

    }

    @Override
    public void mouseEntered(MouseEvent e) {}

    @Override
    public void mouseExited(MouseEvent e) {}

    @Override
    public void mouseDragged(MouseEvent e) {
        if (state == State.LEFT_PRESSED && point.distance(e.getPoint()) > DRAG_THRESHOLD) {
            state = State.LEFT_DRAGGED;
            grapher.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
            grapher.translate(e.getX() - point.x, e.getY() - point.y);
            point = e.getPoint();
        } else if (state == State.LEFT_DRAGGED) {
            grapher.translate(e.getX() - point.x, e.getY() - point.y);
            point = e.getPoint();
        } else if (state == State.RIGHT_DRAGGED || (state == State.RIGHT_PRESSED && point.distance(e.getPoint()) > DRAG_THRESHOLD)) {
            state = State.RIGHT_DRAGGED;
            grapher.repaint();
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {}

    @Override
    public void mouseWheelMoved(MouseWheelEvent e) {
        grapher.zoom(e.getPoint(), e.getWheelRotation() * -5);
    }

    public void draw(Graphics2D g2) {
        if (state == State.RIGHT_DRAGGED && point != null) {
            Point p = grapher.getMousePosition();
            if (p != null) {
                Point upperLeft = new Point(Math.min(point.x, p.x), Math.min(point.y, p.y));
                Point lowerRight = new Point(Math.max(point.x, p.x), Math.max(point.y, p.y));
                g2.setStroke(Grapher.dash);
                g2.setColor(Color.BLACK);
                g2.drawRect(upperLeft.x, upperLeft.y, lowerRight.x - upperLeft.x, lowerRight.y - upperLeft.y);
            }
        }
    }
}
