package TP_1;

public class Ex4
{
    public static void tableVerite()
    {
        System.out.println("x\t\t\ty\t\t\tx and y\t\tx or y\t\tx xor y");
        int a, b;
        for (int i=0; i<4; i++)
        {
            a = i%2;
            b = i/2;
            System.out.print(intToBool(a)+"\t\t"+intToBool(b));
            System.out.print("\t\t"+(intToBool(a) && intToBool(b)));
            System.out.print("\t\t"+(intToBool(a) || intToBool(b)));
            System.out.print("\t\t"+(intToBool(a) ^ intToBool(b))+"\n");
        }
    }

    private static boolean intToBool(int x) { return x==1; }
}
