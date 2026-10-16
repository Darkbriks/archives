package fr.uga.im2ag.m1info.tp1;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class UnidirectedGraphTest {

    @Test
    public void testGraphNoEdges() {
        UnidirectedGraph<Vertex> g = new UnidirectedGraph<>();
        Vertex a = new Vertex("A");
        g.addVertex(a);
        List<Edge<Vertex>> edges = g.getEdgesFrom(a);
        assertTrue(edges.isEmpty());
    }

    @Test
    public void testAddVertexAndEdges() {
        UnidirectedGraph<Vertex> g = new UnidirectedGraph<>();
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");

        g.addVertex(a);
        g.addVertex(b);
        g.addEdge(a, b, 3);

        List<Edge<Vertex>> edgesFromA = g.getEdgesFrom(a);
        assertEquals(1, edgesFromA.size());
        assertEquals(a, edgesFromA.get(0).getSource());
        assertEquals(b, edgesFromA.get(0).getTarget());
        assertEquals(3, edgesFromA.get(0).getWeight());

        List<Edge<Vertex>> edgesFromB = g.getEdgesFrom(b);
        assertEquals(1, edgesFromB.size());
        assertEquals(b, edgesFromB.get(0).getSource());
        assertEquals(a, edgesFromB.get(0).getTarget());
        assertEquals(3, edgesFromB.get(0).getWeight());
    }

    @Test
    public void testAddSameLabelVertex(){
        UnidirectedGraph<Vertex> g = new UnidirectedGraph<>();
        Vertex a1 = new Vertex("A");
        Vertex a2 = new Vertex("A");

        g.addVertex(a1);
        g.addVertex(a2);

        List<Vertex> vertices = g.getVertices();
        assertEquals(1, vertices.size());
    }

    @Test
    public void testGraphNoEdgesString() {
        UnidirectedGraph<String> g = new UnidirectedGraph<>();
        g.addVertex("A");
        List<Edge<String>> edges = g.getEdgesFrom("A");
        assertTrue(edges.isEmpty());
    }

    @Test
    public void testAddVertexAndEdgesString() {
        UnidirectedGraph<String> g = new UnidirectedGraph<>();

        g.addVertex("A");
        g.addVertex("B");
        g.addEdge("A", "B", 3);

        List<Edge<String>> edgesFromA = g.getEdgesFrom("A");
        assertEquals(1, edgesFromA.size());
        assertEquals("A", edgesFromA.get(0).getSource());
        assertEquals("B", edgesFromA.get(0).getTarget());
        assertEquals(3, edgesFromA.get(0).getWeight());

        List<Edge<String>> edgesFromB = g.getEdgesFrom("B");
        assertEquals(1, edgesFromB.size());
        assertEquals("B", edgesFromB.get(0).getSource());
        assertEquals("A", edgesFromB.get(0).getTarget());
        assertEquals(3, edgesFromB.get(0).getWeight());
    }

    @Test
    public void testAddSameLabelVertexString(){
        UnidirectedGraph<String> g = new UnidirectedGraph<>();

        g.addVertex("A");
        g.addVertex("A");

        List<String> vertices = g.getVertices();
        assertEquals(1, vertices.size());
    }
}