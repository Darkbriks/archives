package fr.uga.im2ag.m1info.tp1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Path<T> implements Comparable<Path<T>> {
    private final List<T> vertices;
    private final int pathWeight;

    Path(T vertex){
        if (vertex == null) { throw new IllegalArgumentException(); }
        vertices = new ArrayList<>();
        vertices.add(vertex);
        pathWeight = 0;
    }

    Path(Path<T> path, Edge<T> edge){
        if (path.vertices.get(path.vertices.size()-1) != edge.getSource()){
            throw new RuntimeException("Last vertex of path different of edge source");
        }

        vertices = path.vertices;
        vertices.add(edge.getTarget());
        pathWeight = path.pathWeight + edge.getWeight();
    }

    public List<T> getVertices() {
        return Collections.unmodifiableList(vertices);
    }

    public int getPathWeight() {
        return pathWeight;
    }

    @Override
    public String toString(){
        StringBuilder output = new StringBuilder("path {\n");

        for (T vertex : vertices){
            output.append("\n\t").append(vertex);
        }

        output.append("\n\t[ weight=").append(pathWeight).append(" ]\n}");
        return output.toString();
    }

    @Override
    public int compareTo(Path path) {
        if (pathWeight != path.pathWeight) {
            return pathWeight < path.pathWeight ? -1 : 1;
        }
        if (vertices.size() != path.vertices.size()) {
            return vertices.size() < path.vertices.size() ? -1 : 1;
        }
        for(int i = 0; i < vertices.size(); i++) {
            int r = vertices.get(i).toString().compareTo(path.vertices.get(i).toString());
            if (r != 0) { return r; }
        }
        return 0;
    }
}
