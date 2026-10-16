#include <iostream>
using namespace std;

const int MAX = 3;

struct pile {int p[MAX] = {};};
struct tableau {pile t[3] = {pile(), pile(), pile()};};

void afficher_disque(const int rayon)
{
    if (rayon != 0)
    {
        int nb_etoiles = rayon*2 - 1;
        for (int i = 0; i < (MAX*2+1 - nb_etoiles)/2; i++) {cout << ' ';}
        for (int i = 0; i < nb_etoiles; i++) {cout << '*';}
        for (int i = 0; i < (MAX*2+1 - nb_etoiles)/2; i++) {cout << ' ';}
    }
    else {for (int i = 0; i < 2*MAX+1; i++) {cout << ' ';}}
}

void afficher_ligne(const int nb_ligne, const tableau hanoi)
{
    for (int i = 0; i < 3; i++)
    {
        afficher_disque(hanoi.t[i].p[nb_ligne]);
        for (int j = 0; j < MAX; j++) {cout << ' ';}
    }
    cout << endl;
}

void afficher_hanoi(const tableau hanoi)
{
    char nom[3] = {'D', 'I', 'A'};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < MAX; j++) {cout << ' ';}
        cout << nom[i];
        for (int j = 0; j < MAX*2; j++) {cout << ' ';}
    }
    cout << endl;
    for (int i = 0; i < MAX; i++) {afficher_ligne(i, hanoi);}
}

void init_tab(tableau *hanoi)
{
    for (int i = 0; i < 3; i++) {for (int j = 0; j < MAX; j++) {hanoi->t[i].p[j] = 0;}}
    for (int i = 1; i <= MAX; i++) {hanoi->t[0].p[i-1] = i;}
}

/*
Les tours de Hanoï est un jeu qui consiste à faire passer des disques de diamètres différents, superposés du plus grand
diamètre au plus petit diamètre vers le haut sur un socle de départ D, vers un socle d’arrivée A, en utilisant un socle
intermédiaire I, avec comme règle :
• un disque doit toujours être placé sur des disques de diamètre plus grand;
• tous les socles peuvent être utilisés.
Comment faire ?
Déplacer N disques de D vers A en utilisant I, revient à :
• déplacer N-1 disques de D vers I en utilisant A;
• puis déplacer le disque restant sur D (celui qui a le plus grand diamètre) de D vers A;
• et enfin de terminer en déplaçant maintenant les N-1 disques qui sont sur I vers A en utilisant D (le socle libre).
 */

void deplacer(int nb_disques, tableau *hanoi, int depart, int arrivee, int intermediaire)
{
    if (nb_disques == 1)
    {
        // Depiler le disque de la tour de départ
        for (int i = 0; i < MAX; i++)
        {
            if (hanoi->t[depart].p[i] != 0)
            {
                int disque = hanoi->t[depart].p[i]; hanoi->t[depart].p[i] = 0;
                // Empiler le disque sur la tour d'arrivée
                for (int j = MAX-1; j >= 0; j--)
                {if (hanoi->t[arrivee].p[j] == 0) {hanoi->t[arrivee].p[j] = disque; break;}}
                break;
            }
        }
        afficher_hanoi(*hanoi);
        system("pause");
    }
    else
    {
        deplacer(nb_disques-1, hanoi, depart, intermediaire, arrivee);
        deplacer(1, hanoi, depart, arrivee, intermediaire);
        deplacer(nb_disques-1, hanoi, intermediaire, arrivee, depart);
    }
}

int main()
{
    tableau hanoi2;
    init_tab(&hanoi2);
    afficher_hanoi(hanoi2);
    system("pause");
    deplacer(MAX, &hanoi2, 0, 2, 1);

    return 0;
}