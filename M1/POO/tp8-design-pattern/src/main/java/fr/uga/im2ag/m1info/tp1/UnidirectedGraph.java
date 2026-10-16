package fr.uga.im2ag.m1info.tp1;

public class UnidirectedGraph<T> extends GraphImplementation<T> {
    public UnidirectedGraph() { super(); }

    @Override
    public void addEdge(T source, T target, int weight){
        super.addEdge(source, target, weight);
        super.addEdge(target, source, weight);
    }
}
