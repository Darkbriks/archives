package fr.uga.im2ag.m1info.tp1;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Graph {
    private Map<Vertex, List<Edge>> vertexListMap;

    public Graph() {
        vertexListMap = new HashMap<>();
    }

    public void addVertex(Vertex vertex){
        if (vertexListMap.containsKey(vertex)) { return; }
        vertexListMap.put(vertex, new ArrayList<>());
    }

    public void addEdge(Vertex source, Vertex target, int weight){
        addVertex(source);
        addVertex(target);
        Edge edge = new Edge(source, target, weight);
        vertexListMap.get(source).add(edge);
    }

    public List<Edge> getEdgesFrom(Vertex vertex){
        return vertexListMap.get(vertex);
    }

    public List<Vertex> getVertices(){
        return vertexListMap.keySet().stream().toList();
    }

    public int getVertivesNumber() { return getVertices().size(); }

    public void printGraph(PrintStream out){
        StringBuilder output = new StringBuilder("digraph {\n");

        for (Map.Entry<Vertex, List<Edge>> entry : vertexListMap.entrySet()){
            if (entry.getValue().isEmpty()) { output.append("\n\t").append(entry.getKey()).append(";"); }
            else {
                for (Edge edge : entry.getValue()){
                    output.append("\n\t").append(edge).append(";");
                }
            }
        }

        output.append("\n}");
        out.println(output);
    }
}
