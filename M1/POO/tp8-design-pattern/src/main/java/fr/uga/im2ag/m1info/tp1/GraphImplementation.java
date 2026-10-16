package fr.uga.im2ag.m1info.tp1;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public abstract class GraphImplementation<T> implements Graph<T>{
    private final Map<T, List<Edge<T>>> vertexListMap;

    protected GraphImplementation() {
        this.vertexListMap = new HashMap<>();
    }

    public void addVertex(T vertex){
        if (vertex == null) { throw new IllegalArgumentException(); }
        if (vertexListMap.containsKey(vertex)) { return; }
        vertexListMap.put(vertex, new ArrayList<>());
    }

    public void addEdge(T source, T target, int weight){
        addVertex(source);
        addVertex(target);
        Edge<T> edge = new Edge<>(source, target, weight);
        vertexListMap.get(source).add(edge);
    }

    @Override
    public List<Edge<T>> getEdgesFrom(T vertex){
        if (vertex == null) { throw new IllegalArgumentException(); }
        return vertexListMap.get(vertex);
    }

    @Override
    public List<T> getVertices(){
        return vertexListMap.keySet().stream().toList();
    }

    @Override
    public int getVertivesNumber() { return getVertices().size(); }

    public void printGraph(PrintStream out){
        StringBuilder output = new StringBuilder("digraph {\n");

        for (Map.Entry<T, List<Edge<T>>> entry : vertexListMap.entrySet()){
            if (entry.getValue().isEmpty()) { output.append("\n\t").append(entry.getKey()).append(";"); }
            else {
                for (Edge<T> edge : entry.getValue()){
                    output.append("\n\t").append(edge).append(";");
                }
            }
        }

        output.append("\n}");
        out.println(output);
    }
}
