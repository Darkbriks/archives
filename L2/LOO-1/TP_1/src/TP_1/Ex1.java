package TP_1;

public class Ex1
{
    public static void scope_1()
    {
        for (int i=0; i<5; i++)
        {
            System.out.print(i + ", ") ;
        }
        System.out.print("\n") ;
    }

    public static void scope_2(int min, int max)
    {
        for (int i=min; i<max; i++)
        {
            System.out.print(i + ", ") ;
        }
        System.out.print(max + "\n") ;
    }
}