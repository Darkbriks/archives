package fr.uga.im2ag.m1info.tp1;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import static org.junit.jupiter.api.Assertions.*;

import java.util.List;

public class DirectedGraphTest {

    @Test
    public void testGraphNoEdges() {
        DirectedGraph<Vertex> g = new DirectedGraph<>();
        Vertex a = new Vertex("A");
        g.addVertex(a);
        List<Edge<Vertex>> edges = g.getEdgesFrom(a);
        assertTrue(edges.isEmpty());
    }

    @Test
    public void testGraphNoEdgesString() {
        DirectedGraph<String> g = new DirectedGraph<>();
        g.addVertex("A");
        List<Edge<String>> edges = g.getEdgesFrom("A");
        assertTrue(edges.isEmpty());
    }

    @Test
    public void testAddVertexAndEdges() {
        DirectedGraph<Vertex> g = new DirectedGraph<>();
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
        assertEquals(0, edgesFromB.size());
    }

    @Test
    public void testAddVertexAndEdgesString() {
        DirectedGraph<String> g = new DirectedGraph<>();

        g.addVertex("A");
        g.addVertex("B");
        g.addEdge("A", "B", 3);

        List<Edge<String>> edgesFromA = g.getEdgesFrom("A");
        assertEquals(1, edgesFromA.size());
        assertEquals("A", edgesFromA.get(0).getSource());
        assertEquals("B", edgesFromA.get(0).getTarget());
        assertEquals(3, edgesFromA.get(0).getWeight());

        List<Edge<String>> edgesFromB = g.getEdgesFrom("B");
        assertEquals(0, edgesFromB.size());
    }

    @Test
    public void testAddSameLabelVertex(){
        DirectedGraph<Vertex> g = new DirectedGraph<>();
        Vertex a1 = new Vertex("A");
        Vertex a2 = new Vertex("A");

        g.addVertex(a1);
        g.addVertex(a2);

        List<Vertex> vertices = g.getVertices();
        assertEquals(1, vertices.size());
    }

    @Test
    public void testAddSameLabelVertexString(){
        DirectedGraph<String> g = new DirectedGraph<>();

        g.addVertex("A");
        g.addVertex("A");

        List<String> vertices = g.getVertices();
        assertEquals(1, vertices.size());
    }
}