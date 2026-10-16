package fr.uga.im2ag.m1info.tp1;

import java.util.*;

public class DijkstraSolver {
    private final Graph graph;

    public DijkstraSolver(Graph graph) {
        this.graph = graph;
    }

    public Path solve(Vertex source, Vertex target) {
        // Initialisation
        Map<Vertex, Integer> dist = new HashMap<>(graph.getVertivesNumber());
        Map<Vertex, Vertex> prev = new HashMap<>(graph.getVertivesNumber());
        List<Vertex> queue = new ArrayList<>(graph.getVertivesNumber());

        for(Vertex vertex : graph.getVertices()) {
            dist.put(vertex, Integer.MAX_VALUE);
            prev.put(vertex, null);
            queue.add(vertex);
        }

        dist.replace(source, 0);

        while (!queue.isEmpty()) {
            Vertex u = minDist(dist, queue);
            queue.remove(u);

            for(Edge edge : graph.getEdgesFrom(u)) {
                Vertex v = edge.getTarget();
                if (!queue.contains(v)) { continue; }

                int alt = dist.get(u) + edge.getWeight();
                if (alt < dist.get(v)) {
                    dist.replace(v, alt);
                    prev.replace(v, u);
                }
            }
        }

        return findPath(prev, target, source);
    }

    private Vertex minDist(Map<Vertex, Integer> dist, List<Vertex> queue) {
        Vertex minVertex = null;
        int minDist = Integer.MAX_VALUE;

        for (Vertex vertex : queue) {
            int d = dist.get(vertex);
            if (d < minDist) {
                minDist = d;
                minVertex = vertex;
            }
        }

        return minVertex;
    }

    private Path findPath(Map<Vertex, Vertex> prev, Vertex target, Vertex source) {
        List<Edge> edges = new ArrayList<>();
        Vertex u = target;
        if (prev.containsKey(u)) {
            while (u != null) {
                Vertex v = prev.get(u);
                if (v == null) { break; }
                for (Edge e : graph.getEdgesFrom(v)) {
                    if (e.getTarget() == u) {
                        edges.add(e);
                        break;
                    }
                }
                u = v;
            }
        }

        Path path = new Path(source);
        for (int i = edges.size()-1; i >= 0; i--){
            path = new Path(path, edges.get(i));
        }

        return path;
    }
}
