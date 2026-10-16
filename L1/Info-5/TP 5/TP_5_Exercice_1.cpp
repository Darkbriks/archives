// ds sur tp 2 et tp 3

#include <iostream>
#include <random>

using namespace std;

// Fonction qui renvoie une valeur aléatoire entre min et max
int alea(const int min, int const max)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<> dist(min, max);
    return dist(rng);
}

// Fonction qui initialise 3 tableaux de n entiers, un tableau aléatoire, un tableau croissant et un tableau décroissant
void init_3_tab(int *tab1[], int *tab2[], int *tab3[], const int n)
{
    *tab1 = new int[3]; *tab2 = new int[3]; *tab3 = new int[3];
    for (int i = 0; i < n; i++)
    {
        (*tab1)[i] = alea(0, n-1);
        (*tab2)[i] = i;
        (*tab3)[i] = n-1 -i;
    }
}

// Fonction qui affiche un tableau d'entier de taille n
void affiche_tab(int tab[], const int n)
{
    for (int i = 0; i < n; i++) {cout << tab[i] << ' ';} cout << endl;
}

// Fonction qui recopie un tableau d'entier de taille n
void recopier_tab(int tab1[], int tab2[], const int n)
{for (int i = 0; i < n; i++) {tab2[i] = tab1[i];}}

// Fonction qui tri un tableau d'entier grace au tri insertion
void tri_insertion(int tab[], const int n, int *cpt)
{
    int indice_elt, position, elt;
    for (indice_elt = 1; indice_elt < n; indice_elt++)
    {
        elt = tab[indice_elt];
        position = indice_elt;
        *cpt = *cpt + 1;
        while (position > 0 and tab[position-1] > elt)
        {
            tab[position] = tab[position-1];
            position=position-1;
            *cpt = *cpt + 1;
        }
        tab[position] = elt;
    }
}

// Fonction qui fusionne deux tableaux d'entier trié
void fusion(int tab[], const int debut, const int millieu, const int fin, int *cpt)
{
    // Tableau temporaire
    int *tab_t = new int[fin-debut+1];
    int i_debut = debut, i_fin = millieu+1, i = 0;
    
    // On parcourt les deux tableaux
    while (i_debut <= millieu or i_fin <= fin)
    {
        if (tab[i_debut] < tab[i_fin]) {tab_t[i] = tab[i_debut]; i_debut++;}
        else {tab_t[i] = tab[i_fin]; i_fin++;}
        i++; *cpt = *cpt + 1;
    }

    // On recopie la fin du tableau qui n'a pas été parcouru entièrement
    if (i_debut == millieu) {for (int j = i_fin; j <= fin; j++) {tab_t[i] = tab[i]; i++; *cpt = *cpt + 1;}}
    else {for (int j = i_debut; j <= millieu; j++) {tab_t[i] = tab[i]; i++; *cpt = *cpt + 1;}}

    // On recopie le tableau temporaire dans le tableau d'origine
    for (int j = 0; j <= fin-debut; j++) {tab[debut+j] = tab_t[j];}
}

// Fonction qui tri un tableau d'entier grace au tri fusion
void tri_fusion(int tab[], const int debut, const int fin, int *cpt)
{
    if (debut < fin)
    {
        int millieu = (debut+fin)/2;
        tri_fusion(tab, debut, millieu, cpt); tri_fusion(tab, millieu+1, fin, cpt);
        fusion(tab, debut, millieu, fin, cpt);
        cout << *cpt;
    }
}

// Fonction qui tri un tableau d'entier grace au tri rapide
void tri_rapide(int tab[], const int n, long int *cpt) {}

// En-tete pour le tri insertion
void lance_tri_insertion(int tab[], const int n, int *cpt)
{tri_insertion(tab, n, cpt);}

// En-tete pour le tri fusion
void lance_tri_fusion(int tab[], const int n, int *cpt)
{}

// En-tete pour le tri rapide
void lance_tri_rapide(int tab[], const int n, int *cpt)
{}

int main()
{
    int *cpt = 0;

    // Test du tri insertion
    int tab_tri_insertion[10] = {9, 5, 8, 1, 0, 6, 7, 2, 3, 4};
    tri_insertion(tab_tri_insertion, 10, cpt);
    affiche_tab(tab_tri_insertion, 10);
    
    // Test de la fusion
    /*int tab_fusion[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    fusion(tab_fusion, 0, 4, 9, cpt);
    affiche_tab(tab_fusion, 10);

    cout << endl;
    
    // Test du tri fusion
    int tab_tri_fusion[10] = {9, 5, 8, 1, 0, 6, 7, 2, 3, 4};
    tri_fusion(tab_tri_fusion, 0, 9, cpt);
    affiche_tab(tab_tri_fusion, 10);*/

    system("pause");
    
    return 0;
}