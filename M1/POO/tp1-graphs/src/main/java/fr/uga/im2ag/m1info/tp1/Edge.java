package fr.uga.im2ag.m1info.tp1;

import java.util.Objects;

public class Edge {
    private final Vertex source;
    private final Vertex target;
    private final int weight;

    public Edge(Vertex source, Vertex target, int weight) {
        this.source = source;
        this.target = target;
        this.weight = weight;
    }

    public Vertex getSource() {
        return source;
    }

    public Vertex getTarget() {
        return target;
    }

    public int getWeight() {
        return weight;
    }

    @Override
    public String toString(){
        return String.format("%s -> %s [ label=%d ]", source, target, weight);
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Edge edge = (Edge) o;
        return weight == edge.weight && Objects.equals(source, edge.source) && Objects.equals(target, edge.target);
    }

    @Override
    public int hashCode() {
        return Objects.hash(source, target, weight);
    }
}
