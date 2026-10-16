package fr.uga.im2ag.m1info.tp1;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

public class VertexTest {
    @Test
    public void testVertexCreation() {
        Vertex v = new Vertex("A");
        assertEquals("A", v.toString());
    }

    @Test
    public void testVertexEquality() {
        Vertex v1 = new Vertex("A");
        Vertex v2 = new Vertex("A");
        Vertex v3 = new Vertex("B");

        assertEquals(v1, v2);
        assertNotEquals(v1, v3);
    }
}
