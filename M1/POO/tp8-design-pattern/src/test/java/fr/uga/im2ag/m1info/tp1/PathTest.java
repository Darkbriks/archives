package fr.uga.im2ag.m1info.tp1;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class PathTest {
    @Test
    public void testPathVertexConstruct() {
        Vertex a = new Vertex("A");
        Path<Vertex> p = new Path<>(a);
        assertEquals(1, p.getVertices().size());
        assertEquals(0, p.getPathWeight());
        assertEquals(a, p.getVertices().get(0));
    }

    @Test
    public void testPathVertexConstructString() {
        Path<String> p = new Path<>("A");
        assertEquals(1, p.getVertices().size());
        assertEquals(0, p.getPathWeight());
        assertEquals("A", p.getVertices().get(0));
    }

    @Test
    public void testPathEdgeConstruct() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Edge<Vertex> e = new Edge<>(a, b, 3);
        Path<Vertex> p1 = new Path<>(a);
        Path<Vertex> p2 = new Path<>(p1, e);

        assertEquals(2, p2.getVertices().size());
        assertEquals(3, p2.getPathWeight());
        assertEquals(a, p2.getVertices().get(0));
        assertEquals(b, p2.getVertices().get(1));
    }

    @Test
    public void testPathEdgeConstructString() {
        Edge<String> e = new Edge<>("A", "B", 3);
        Path<String> p1 = new Path<>("A");
        Path<String> p2 = new Path<>(p1, e);

        assertEquals(2, p2.getVertices().size());
        assertEquals(3, p2.getPathWeight());
        assertEquals("A", p2.getVertices().get(0));
        assertEquals("B", p2.getVertices().get(1));
    }

    @Test
    public void testPathEdgeConstructWithError() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Vertex c = new Vertex("C");
        Edge<Vertex> e = new Edge<>(b, c, 3);
        Path<Vertex> p1 = new Path<>(a);

        assertThrows(RuntimeException.class, () -> new Path<>(p1, e));
    }

    @Test
    public void testPathEdgeConstructWithErrorString() {
        Edge<String> e = new Edge<>("B", "C", 3);
        Path<String> p1 = new Path<>("A");

        assertThrows(RuntimeException.class, () -> new Path<>(p1, e));
    }

    @Test
    public void testVertexInsertion() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Edge<Vertex> e = new Edge<>(a, b, 3);
        Path<Vertex> p1 = new Path<>(a);
        Path<Vertex> p2 = new Path<>(p1, e);

        Vertex c = new Vertex("C");
        assertThrows(UnsupportedOperationException.class, () -> p2.getVertices().add(c));
    }

    @Test
    public void testVertexInsertionString() {
        Edge<String> e = new Edge<>("A", "B", 3);
        Path<String> p1 = new Path<>("A");
        Path<String> p2 = new Path<>(p1, e);
        assertThrows(UnsupportedOperationException.class, () -> p2.getVertices().add("C"));
    }

    @Test
    public void testCompareTo1() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Edge<Vertex> e1 = new Edge<>(a, b, 3);
        Edge<Vertex> e2 = new Edge<>(a, b, 5);

        Path<Vertex> p1 = new Path<>(a);
        Path<Vertex> p2 = new Path<>(p1, e1);

        Path<Vertex> p3 = new Path<>(a);
        Path<Vertex> p4 = new Path<>(p3, e2);

        assertEquals(-1, p2.compareTo(p4));
        assertEquals(1, p4.compareTo(p2));
    }

    @Test
    public void testCompareTo2() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Vertex c = new Vertex("C");
        Edge<Vertex> e1 = new Edge<>(a, b, 3);
        Edge<Vertex> e2 = new Edge<>(b, c, 2);
        Edge<Vertex> e3 = new Edge<>(a, c, 5);

        Path<Vertex> p1 = new Path<>(a);
        Path<Vertex> p2 = new Path<>(p1, e1);
        Path<Vertex> p3 = new Path<>(p2, e2);

        Path<Vertex> p4 = new Path<>(a);
        Path<Vertex> p5 = new Path<>(p4, e3);

        assertEquals(1, p3.compareTo(p5));
        assertEquals(-1, p5.compareTo(p3));
    }

    @Test
    public void testCompareTo3() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Vertex c = new Vertex("C");
        Edge<Vertex> e1 = new Edge<>(a, b, 3);
        Edge<Vertex> e2 = new Edge<>(a, c, 3);

        Path<Vertex> p1 = new Path<>(a);
        Path<Vertex> p2 = new Path<>(p1, e1);

        Path<Vertex> p3 = new Path<>(a);
        Path<Vertex> p4 = new Path<>(p3, e2);

        assertEquals(-1, p2.compareTo(p4));
        assertEquals(1, p4.compareTo(p2));
    }

    @Test
    public void testCompareTo4() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Edge<Vertex> e1 = new Edge<>(a, b, 3);
        Edge<Vertex> e2 = new Edge<>(a, b, 3);

        Path<Vertex> p1 = new Path<>(a);
        Path<Vertex> p2 = new Path<>(p1, e1);

        Path<Vertex> p3 = new Path<>(a);
        Path<Vertex> p4 = new Path<>(p3, e2);

        assertEquals(0, p2.compareTo(p4));
        assertEquals(0, p4.compareTo(p2));
    }
}
