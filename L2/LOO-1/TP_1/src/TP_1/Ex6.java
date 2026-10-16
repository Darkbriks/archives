package TP_1;

public class Ex6
{
    // Ce code devrait produire l'affichage suivant :
    //i= 1 j= 11
    //i= 2 j= 4
    //i= 3 j= 6
    //i= 4 j= 8

    public static void main_()
    {
        for(int i=1, j=i+10 ; i < 5 ; i++, j=i*2) { System.out.println("i= " + i + " j= " + j); }
    }

    // Le resultat est :
    //i= 1 j= 11
    //i= 2 j= 4
    //i= 3 j= 6
    //i= 4 j= 8
}
