package fr.uga.im2ag.m1info.tp1;

import java.util.Objects;

public class Edge<T> {
    private final T source;
    private final T target;
    private final int weight;

    public Edge(T source, T target, int weight) {
        if (source == null) { throw new IllegalArgumentException(); }
        if (target == null) { throw new IllegalArgumentException(); }
        this.source = source;
        this.target = target;
        this.weight = weight;
    }

    public T getSource() {
        return source;
    }

    public T getTarget() {
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
        if (!(o instanceof Edge<?> edge)) return false;
        return weight == edge.weight && Objects.equals(source, edge.source) && Objects.equals(target, edge.target);
    }

    @Override
    public int hashCode() {
        return Objects.hash(source, target, weight);
    }
}
