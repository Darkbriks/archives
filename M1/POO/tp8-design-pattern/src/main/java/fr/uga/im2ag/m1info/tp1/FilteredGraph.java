package fr.uga.im2ag.m1info.tp1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class FilteredGraph<T> implements Graph<T>{
    private final EdgeFilter<T> edgeFilter;
    private final VertexFilter<T> vertexFilter;
    private final Graph<T> origin;

    FilteredGraph(EdgeFilter<T> edgeFilter, VertexFilter<T> vertexFilter, Graph<T> graph) {
        this.edgeFilter = edgeFilter;
        this.vertexFilter = vertexFilter;
        this.origin = graph;
    }

    @Override
    public List<Edge<T>> getEdgesFrom(T vertex) {
        if (vertexFilter.filter(vertex)) { return Collections.emptyList(); }

        List<Edge<T>> edgeList = new ArrayList<>();
        for (Edge<T> edge : origin.getEdgesFrom(vertex)) {
            if (!edgeFilter.filter(edge) && !vertexFilter.filter(edge.getTarget())){
                edgeList.add(edge);
            }
        }
        return edgeList;
    }

    @Override
    public List<T> getVertices() {
        List<T> vertexList = new ArrayList<>();
        for (T vertex : origin.getVertices()) {
            if (!vertexFilter.filter(vertex)) {
                vertexList.add(vertex);
            }
        }
        return vertexList;
    }

    @Override
    public int getVertivesNumber() {
        return getVertices().size();
    }
}
