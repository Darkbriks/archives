package fr.uga.im2ag.m1info.tp1;

import java.util.*;

/**
 * Implementation of Dijkstra's algorithm to find the shortest path in a graph.
 *
 * @param <T> the type of the vertices in the graph, must implement equals and hashCode
 */
public class DijkstraSolver<T> {
    private final Graph<T> graph;

    public DijkstraSolver(Graph<T> graph) {
        this.graph = graph;
    }

    public Path<T> solve(T source, T target) {
        if (source == null || !graph.getVertices().contains(source)) { throw new IllegalArgumentException(); }
        if (target == null || !graph.getVertices().contains(source)) { throw new IllegalArgumentException(); }

        // Initialisation
        Map<T, Integer> dist = new HashMap<>(graph.getVertivesNumber());
        Map<T, T> prev = new HashMap<>(graph.getVertivesNumber());
        List<T> queue = new ArrayList<>(graph.getVertivesNumber());

        for(T vertex : graph.getVertices()) {
            dist.put(vertex, Integer.MAX_VALUE);
            prev.put(vertex, null);
            queue.add(vertex);
        }

        dist.replace(source, 0);

        while (!queue.isEmpty()) {
            T u = minDist(dist, queue);

            if (u == null) {
                System.out.println("Warning: remaining vertices are unreachable from source");
                break;
            }

            queue.remove(u);

            for(Edge<T> edge : graph.getEdgesFrom(u)) {
                T v = edge.getTarget();
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

    private T minDist(Map<T, Integer> dist, List<T> queue) {
        T minVertex = null;
        int minDist = Integer.MAX_VALUE;

        for (T vertex : queue) {
            int d = dist.get(vertex);
            if (d < minDist) {
                minDist = d;
                minVertex = vertex;
            }
        }

        return minVertex;
    }

    private Path<T> findPath(Map<T, T> prev, T target, T source) {
        List<Edge<T>> edges = new ArrayList<>();
        T u = target;
        if (prev.containsKey(u)) {
            while (u != null) {
                T v = prev.get(u);
                if (v == null) { break; }
                for (Edge<T> e : graph.getEdgesFrom(v)) {
                    if (e.getTarget() == u) {
                        edges.add(e);
                        break;
                    }
                }
                u = v;
            }
        }

        Path<T> path = new Path<>(source);
        for (int i = edges.size()-1; i >= 0; i--){
            path = new Path<>(path, edges.get(i));
        }

        return path;
    }
}
