package TP_1;
import java.util.Scanner;

public class Ex8
{
    private static final String FRANCAIS = "BONJOUR !" ;
    private static final String ANGLAIS = "HELLO !" ;
    public static void v1()
    {
        int lu ;
        String message ;
        Scanner scanner = new Scanner(System.in);
        System.out.print("(1) Français / (AUTRE) Anglais > ");
        lu = scanner.nextInt() ;
        message = (lu == 1) ? FRANCAIS : ANGLAIS ;
        System.out.println(message);
    }

    public static void v2()
    {
        int lu ;
        String message ;
        Scanner scanner = new Scanner(System.in);
        System.out.print("(1) Français / (AUTRE) Anglais > ");
        lu = scanner.nextInt() ;
        if (lu == 1) { message=FRANCAIS; }
        else { message=ANGLAIS; }
        System.out.println(message);
    }

    public static void quest3(String[] args)
    {
        String m;
        m = (args.length != 3) ? "Bad" : "Good";
        System.out.println(m);
    }
}
