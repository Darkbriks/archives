#include <iostream>
#include <random>

using namespace std;


int alea(const int min, const int max)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<> dist(min, max);
    return dist(rng);
}

#pragma region Tableau_dynamique

// Tableau dynamique d'entiers et taille du tableau
struct tableau
{
    int* tab = new int[0];
    int taille = 0;
};

// Initialise un tableau dynamique de taille donnee avec des valeurs aleatoires entre 0 et n
bool create_liste_tab(tableau *tableau, int taille)
{
    tableau->taille = taille; tableau->tab = new int[taille];
    for (int i = 0; i < taille; i++) {tableau->tab[i] = alea(0, taille);}
    return true;
}

// Affiche le tableau dynamique avec " -> " entre chaque element
void affiche_liste_tab(const tableau tableau)
{
    for (int i = 0; i < tableau.taille; i++)
    {
        cout << tableau.tab[i];
        if (i < tableau.taille - 1) {cout << " -> ";}
        else {cout << endl;}
    }
}

// Recherche un element dans le tableau dynamique et un booleen ainsi que l'indice de l'element si trouve (on retournera 1 pour le premier element)
bool recherche_valeur_tab(const tableau tableau, const int element, int* indice)
{
    for (int i = 0; i < tableau.taille; i++)
        if (tableau.tab[i] == element) {*indice = i + 1; return true;}
    return false;
}

// Supprime l'element en position i du tab dynamique et retourne un booleen ainsi que la valeur de l'element supprime
bool supprime_position_tab(tableau *tab, const int i, int* element)
{
    if (i < 0 || i >= tab->taille) {return false;}
    *element = tab->tab[i];
    tableau new_tab; new_tab.tab = new int[tab->taille - 1]; new_tab.taille = tab->taille - 1;
    for (int j = 0; j < i; j++) {new_tab.tab[j] = tab->tab[j];}
    for (int j = i; j < new_tab.taille; j++) {new_tab.tab[j] = tab->tab[j + 1];}
    delete[] tab->tab; tab->tab = new_tab.tab; tab->taille = new_tab.taille;
    return true;
}

// Insere un element en position i du tab dynamique et retourne un booleen
bool insere_position_tab(tableau *tab, const int i, const int element)
{
    if (i < 0 || i >= tab->taille) {return false;}
    tableau new_tab; new_tab.tab = new int[tab->taille + 1]; new_tab.taille = tab->taille + 1;
    for (int j = 0; j < i; j++) {new_tab.tab[j] = tab->tab[j];}
    new_tab.tab[i] = element;
    for (int j = i + 1; j < new_tab.taille; j++) {new_tab.tab[j] = tab->tab[j - 1];}
    delete[] tab->tab; tab->tab = new_tab.tab; tab->taille = new_tab.taille;
    return true;
}

// Recopie un premier tableau dans un second tableau
bool recopie_tab(const tableau tab1, tableau *tab2)
{
    delete[] tab2->tab;
    tab2->taille = tab1.taille; tab2->tab = new int[tab1.taille];
    for (int i = 0; i < tab1.taille; i++) {tab2->tab[i] = tab1.tab[i];}
    return true;
}

// Concatene deux tableaux dynamiques et retourne le tout dans un troisieme tableau dynamique
bool concatene_tab(const tableau tab1, const tableau tab2, tableau *tab3)
{
    delete[] tab3->tab;
    tab3->taille = tab1.taille + tab2.taille; tab3->tab = new int[tab3->taille];
    for (int i = 0; i < tab1.taille; i++) {tab3->tab[i] = tab1.tab[i];}
    for (int i = tab1.taille; i < tab3->taille; i++) {tab3->tab[i] = tab2.tab[i - tab1.taille];}
    return true;
}

// Supprime toutes les occurences d'un element dans le tableau dynamique et retourne le nombre d'elements supprimes
int supprime_element_tab(tableau *tab, int element)
{
    int nb_supprimes = 0; tableau new_tab; recopie_tab(*tab, &new_tab);
    for (int i = 0; i < tab->taille; i++)
        if (tab->tab[i] == element) {supprime_position_tab(&new_tab, i - nb_supprimes, &element); nb_supprimes++;}
    delete[] tab->tab; tab->tab = new_tab.tab; tab->taille = new_tab.taille;
    return nb_supprimes;
}

#pragma endregion Tableau_dynamique

#pragma region Liste_chainee

// Maillon contenant un entier et un pointeur vers le maillon suivant
struct maillon
{
    int val = 0;
    maillon* suivant = NULL;
};

// Initialise une liste chainee de taille donnee avec des valeurs aleatoires entre 0 et taille
bool create_liste_chaine(maillon **tete, const int taille)
{
    if (taille < 1) {return false;}
    *tete = new maillon; (*tete)->val = alea(0, taille); maillon* ptr = *tete;
    for (int i = 1; i < taille; i++)
    {
        ptr->suivant = new maillon; ptr = ptr->suivant; ptr->val = alea(0, taille);
    }
    return true;
}

// Affiche une liste chainee avec " -> " entre chaque element
void affiche_liste_chaine(maillon *tete)
{
    maillon* ptr = tete;
    while (ptr != NULL)
    {
        cout << ptr->val;
        if (ptr->suivant != NULL) {cout << " -> ";}
        ptr = ptr->suivant;
    }
    cout << endl;
}

// Recherche d'un element dans une liste chainee et retourne un booleen ainsi que la position de l'element (on considere 1 pour le premier element)
bool recherche_valeur_chaine(maillon *tete, const int element, int* position)
{
    maillon* ptr = tete; *position = 1;
    while (ptr != NULL)
    {
        if (ptr->val == element) {return true;}
        ptr = ptr->suivant; (*position)++;
    }
    return false;
}

// Supprime un element en position i dans une liste chainee et retourne un booleen ainsi que la valeur de l'element supprime
bool supprime_position_chaine(maillon **tete, const int i, int* element)
{
    if (i < 1) {return false;}
    maillon* ptr = *tete; int position = 1;
    while (ptr != NULL)
    {
        if (position == i - 1)
        {
            if (ptr->suivant == NULL) {return false;}
            *element = ptr->suivant->val;
            maillon* temp = ptr->suivant; ptr->suivant = ptr->suivant->suivant; delete temp;
            return true;
        }
        ptr = ptr->suivant; position++;
    }
    return false;
}

// Insertion d'un element en position i dans une liste chainee et retourne un booleen
bool insert_position_chaine(maillon **tete, const int i, const int element)
{
    if (i < 0) {return false;}
    
    maillon* temp = new maillon; temp->val = element;
    
    if (i == 0) {temp->suivant = *tete; *tete = temp; return true;}
    
    maillon* ptr = *tete; int position = 0;
    while (ptr != NULL)
    {
        if (position == i - 1) {temp->suivant = ptr->suivant; ptr->suivant = temp; return true;}
        ptr = ptr->suivant; position++;
    }
    return false;
}

// Supprime une liste chainee
bool delete_liste_chaine(maillon **tete)
{
    maillon* ptr = *tete;
    while (ptr != NULL)
    {
        maillon* temp = ptr; ptr = ptr->suivant; delete temp;
    }
    *tete = NULL;
    return true;
}

// Recopie une liste chainee dans une autre liste chainee
bool recopie_chaine(maillon *tete1, maillon **tete2)
{
    delete_liste_chaine(tete2);
    maillon* ptr = tete1; int position = 0;
    while (ptr != NULL)
    {
        insert_position_chaine(tete2, position, ptr->val);
        ptr = ptr->suivant; position++;
    }
    return true;
}

// Concatene deux listes chainees dans une troisieme liste chainee
bool concatene_chaine(maillon *tete1, maillon *tete2, maillon **tete3)
{
    delete_liste_chaine(tete3);
    maillon* ptr = tete1; int position = 0;
    while (ptr != NULL)
    {
        insert_position_chaine(tete3, position, ptr->val);
        ptr = ptr->suivant; position++;
    }
    ptr = tete2;
    while (ptr != NULL)
    {
        insert_position_chaine(tete3, position, ptr->val);
        ptr = ptr->suivant; position++;
    }
    return true;
}

// Supprime toutes les occurences d'un element dans une liste chainee et retourne le nombre d'elements supprimes
int supprime_element_chaine(maillon **tete, const int element)
{
    int nb_supprimes = 0;
    while ((*tete)->val == element) {maillon* temp = *tete; *tete = (*tete)->suivant; delete temp; nb_supprimes++;}
    maillon* ptr = *tete; int position = 0;
    while (ptr->suivant != NULL)
    {
        if (ptr->suivant->val == element) {maillon* temp = ptr->suivant; ptr->suivant = ptr->suivant->suivant; delete temp; nb_supprimes++;}
        else {ptr = ptr->suivant;}
    }
    return nb_supprimes;
}

#pragma endregion Liste_chainee

// Affiche le temps moyen d'execution d'une fonction tab et chaine sur n iterations
/*void affiche_temps_moyen(int n, bool (*f1)(), bool (*f2)(), string nom)
{
    cout << "Temps moyen d'execution de " << nom << " sur " << n << " iterations : " << endl;
    cout << "\t- Tableau dynamique : " << affiche_temps_moyen(n, f1) << " ms" << endl;
    cout << "\t- Liste chainee : " << affiche_temps_moyen(n, f2) << " ms" << endl << endl;
}*/

/*int main()
{
    // Saisie d'un nombre d'elements et du nombre d'iterations
    int nb_elements = 0, nb_iterations = 0;
    cout << "Nombre d'elements : "; cin >> nb_elements;
    cout << "Nombre d'iterations : "; cin >> nb_iterations;

    
    // Affichage du temps moyen d'execution des fonctions create_liste_tab, create_liste_chaine
    cout << "Temps moyen d'execution de create_liste_tab et create_liste_chaine avec " << nb_elements << " elements sur " << nb_iterations << " iterations : " << endl;

    clock_t temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {tableau tab; create_liste_tab(&tab, nb_elements);} clock_t temps2 = clock();
    cout << "\t- Tableau dynamique : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl;

    temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {maillon *tete = NULL; create_liste_chaine(&tete, nb_elements);} temps2 = clock();
    cout << "\t- Liste chainee : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl << endl;


    // Affichage du temps moyen d'execution des fonctions recherche_valeur_tab, recherche_valeur_chaine
    cout << "Temps moyen d'execution de recherche_valeur_tab et recherche_valeur_chaine avec " << nb_elements << " elements sur " << nb_iterations << " iterations : " << endl;

    tableau tab; create_liste_tab(&tab, nb_elements); int element = 0;
    temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {recherche_valeur_tab(tab, nb_elements, &element);} temps2 = clock();
    cout << "\t- Tableau dynamique : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl;

    maillon *tete = NULL; create_liste_chaine(&tete, nb_elements);
    temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {recherche_valeur_chaine(tete, nb_elements, &element);} temps2 = clock();
    cout << "\t- Liste chainee : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl << endl;


    // Affichage du temps moyen d'execution des fonctions supprime_element_tab, supprime_element_chaine
    cout << "Temps moyen d'execution de supprime_element_tab et supprime_element_chaine avec " << nb_elements << " elements sur " << nb_iterations << " iterations : " << endl;

    clock_t temp = 0;
    for (int i = 0; i < nb_iterations; i++)
    {
        tableau new_tab; recopie_tab(tab, &new_tab);
        temps1 = clock(); supprime_element_tab(&new_tab, element); temps2 = clock();
        temp += temps2 - temps1;
    }
    cout << "\t- Tableau dynamique : " << temp * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl;

    temp = 0;
    for (int i = 0; i < nb_iterations; i++)
    {
        maillon *new_tete = NULL; recopie_chaine(tete, &new_tete);
        temps1 = clock(); supprime_element_chaine(&new_tete, element); temps2 = clock();
        temp += temps2 - temps1;
    }
    cout << "\t- Liste chainee : " << temp * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl << endl;


    // Affichage du temps moyen d'execution des fonctions insere_position_tab, insert_position_chaine
    cout << "Temps moyen d'execution de insere_position_tab et insert_position_chaine avec " << nb_elements << " elements sur " << nb_iterations << " iterations : " << endl;

    temp = 0;
    for (int i = 0; i < nb_iterations; i++)
    {
        tableau new_tab; recopie_tab(tab, &new_tab);
        temps1 = clock(); insere_position_tab(&new_tab, nb_elements / 2, element); temps2 = clock();
        temp += temps2 - temps1;
    }
    cout << "\t- Tableau dynamique : " << temp * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl;

    temp = 0;
    for (int i = 0; i < nb_iterations; i++)
    {
        maillon *new_tete = NULL; recopie_chaine(tete, &new_tete);
        temps1 = clock(); insert_position_chaine(&new_tete, nb_elements / 2, element); temps2 = clock();
        temp += temps2 - temps1;
    }
    cout << "\t- Liste chainee : " << temp * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl << endl;


    // Affichage du temps moyen d'execution des fonctions recopie_tab, recopie_chaine
    cout << "Temps moyen d'execution de recopie_tab et recopie_chaine avec " << nb_elements << " elements sur " << nb_iterations << " iterations : " << endl;

    temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {tableau new_tab; recopie_tab(tab, &new_tab);} temps2 = clock();
    cout << "\t- Tableau dynamique : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl;

    temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {maillon *new_tete = NULL; recopie_chaine(tete, &new_tete);} temps2 = clock();
    cout << "\t- Liste chainee : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl << endl;


    // Affichage du temps moyen d'execution des fonctions concatene_tab, concatene_chaine
    cout << "Temps moyen d'execution de concatene_tab et concatene_chaine avec " << nb_elements << " elements sur " << nb_iterations << " iterations : " << endl;

    temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {tableau new_tab; concatene_tab(tab, tab, &new_tab);} temps2 = clock();
    cout << "\t- Tableau dynamique : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl;

    temps1 = clock(); for (int i = 0; i < nb_iterations; i++) {maillon *new_tete = NULL; concatene_chaine(tete, tete, &new_tete);} temps2 = clock();
    cout << "\t- Liste chainee : " << (temps2 - temps1) * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl << endl;


    // Affichage du temps moyen d'execution des fonctions supprime_element_tab, supprime_element_chaine
    cout << "Temps moyen d'execution de supprime_element_tab et supprime_element_chaine avec " << nb_elements << " elements sur " << nb_iterations << " iterations : " << endl;

    temp = 0;
    for (int i = 0; i < nb_iterations; i++)
    {
        tableau new_tab; recopie_tab(tab, &new_tab);
        temps1 = clock(); supprime_element_tab(&new_tab, element); temps2 = clock();
        temp += temps2 - temps1;
    }
    cout << "\t- Tableau dynamique : " << temp * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl;

    temp = 0;
    for (int i = 0; i < nb_iterations; i++)
    {
        maillon *new_tete = NULL; recopie_chaine(tete, &new_tete);
        temps1 = clock(); supprime_element_chaine(&new_tete, element); temps2 = clock();
        temp += temps2 - temps1;
    }
    cout << "\t- Liste chainee : " << temp * 1000 / (double)CLOCKS_PER_SEC << " ms" << endl << endl;
    
    // Attendre une entree pour fermer la console
    system("pause");
    return 0;
}*/