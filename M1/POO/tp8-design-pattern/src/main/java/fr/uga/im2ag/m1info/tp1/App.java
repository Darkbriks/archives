package fr.uga.im2ag.m1info.tp1;

public class App {
    /*public static void main(String[] args) {
        GraphImplementation<String> g = new DirectedGraph<>();
        String a = "A";
        String b = "B";
        String c = "C";
        String d = "D";
        String e = "E";
        String f = "F";

        g.addVertex(a);
        g.addVertex(b);
        g.addVertex(c);
        g.addVertex(d);
        g.addVertex(e);
        g.addVertex(f);

        // A
        g.addEdge(a, b, 7);
        g.addEdge(a, c, 9);
        g.addEdge(a, d, 14);

        // B
        g.addEdge(b, a, 7);
        g.addEdge(b, c, 10);
        g.addEdge(b, e, 15);

        // C
        g.addEdge(c, a, 9);
        g.addEdge(c, b, 10);
        g.addEdge(c, d, 2);
        g.addEdge(c, e, 11);

        // D
        g.addEdge(d, a, 14);
        g.addEdge(d, c, 2);
        g.addEdge(d, f, 9);

        // E
        g.addEdge(e, b, 15);
        g.addEdge(e, c, 11);
        g.addEdge(e, f, 6);

        // F
        g.addEdge(f, d, 9);
        g.addEdge(f, e, 6);

        g.printGraph(System.out);

        DijkstraSolver<String> solver = new DijkstraSolver<>(g);
        Path<String> path = solver.solve(a, f);
        System.out.println(path);
    }*/

    public static void main(String[] args) {
        GraphImplementation<String> g = new UnidirectedGraph<>();
        String a = "A";
        String b = "B";
        String c = "C";
        String d = "D";
        String e = "E";
        String f = "F";

        g.addVertex(a);
        g.addVertex(b);
        g.addVertex(c);
        g.addVertex(d);
        g.addVertex(e);
        g.addVertex(f);

        // A
        g.addEdge(a, b, 7);
        g.addEdge(a, c, 9);
        g.addEdge(a, d, 14);

        // B
        g.addEdge(b, c, 10);
        g.addEdge(b, e, 15);

        // C
        g.addEdge(c, d, 2);
        g.addEdge(c, e, 11);

        // D
        g.addEdge(d, f, 9);

        // E
        g.addEdge(e, f, 6);

        g.printGraph(System.out);

        DijkstraSolver<String> solver = new DijkstraSolver<>(g);
        Path<String> path = solver.solve(a, f);
        System.out.println(path);

        System.out.println("===== Filtered Graph =====");
        FilteredGraph<String> filteredGraph = new FilteredGraph<>(
                edge -> !(edge.getWeight() < 10),
                vertex -> false,
                g
        );

        DijkstraSolver<String> filteredSolver = new DijkstraSolver<>(filteredGraph);
        Path<String> filteredPath = filteredSolver.solve(a, f);
        System.out.println(filteredPath);
    }
}
