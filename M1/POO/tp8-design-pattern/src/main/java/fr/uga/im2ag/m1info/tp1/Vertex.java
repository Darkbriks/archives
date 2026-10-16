package fr.uga.im2ag.m1info.tp1;

import java.util.Objects;

public class Vertex {
    private final String label;

    public Vertex(String label) {
        if (label == null || label.isBlank()) {
            throw new IllegalArgumentException("Null or empty label");
        }
        this.label = label;
    }

    @Override
    public String toString(){ return label; }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Vertex vertex = (Vertex) o;
        return Objects.equals(label, vertex.label);
    }

    @Override
    public int hashCode() { return Objects.hashCode(label); }
}
