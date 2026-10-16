package TP_1;

public class Ex3
{
    public static void main_()
    {
        byte b = 42 ;
        char c = 'a' ;
        short s = 1024 ;
        int i = 50000 ;
        float f = 5.67f ;
        double d = .1234 ;
        double resultat = (f * b) + ((double) i / c) - (d * s);
        System.out.print((f * b) + " + " + (i / c) + " - " + (d * s));
        System.out.println(" = " + resultat);
        byte b2 = 10;
        byte b3 = (byte) (b2 * b);
        System.out.println("b = " + b);
        System.out.println("b2 = " + b2);
        System.out.println("b3 = " + b3);
    }
}
