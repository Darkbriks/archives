package fr.uga.im2ag.m1info.tp1;

import java.util.List;

public interface Graph<T> {
    List<Edge<T>> getEdgesFrom(T vertex);
    List<T> getVertices();
    int getVertivesNumber();
}
