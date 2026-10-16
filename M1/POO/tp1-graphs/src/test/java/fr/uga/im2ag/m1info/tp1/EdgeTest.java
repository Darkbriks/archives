package fr.uga.im2ag.m1info.tp1;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class EdgeTest {

    @Test
    public void testEdgeCreation() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Edge e = new Edge(a, b, 5);

        assertEquals(a, e.getSource());
        assertEquals(b, e.getTarget());
        assertEquals(5, e.getWeight());
    }

    @Test
    public void testEdgeToString() {
        Vertex a = new Vertex("A");
        Vertex b = new Vertex("B");
        Edge e = new Edge(a, b, 2);

        assertEquals("A -> B [ label=2 ]", e.toString());
    }
}
