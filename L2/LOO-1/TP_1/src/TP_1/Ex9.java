package TP_1;
import java.util.Scanner;

public class Ex9
{
    public static void tableMultiplication()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Table de ? > ");
        int t = scanner.nextInt();

        System.out.print("-");
        for (int i=0; i<=t; i++) { System.out.print("\t"+i); }

        for (int i=0; i<=t; i++)
        {
            System.out.print("\n");
            System.out.print(i);
            for (int j=0; j<=t; j++) { System.out.print("\t"+i*j); }
        }
    }
}
