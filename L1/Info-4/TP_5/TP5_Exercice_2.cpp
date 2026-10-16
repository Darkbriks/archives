#include  <iostream>
#include <vector>
using namespace std;

struct ingredient
{
    string nom_ing = "";
    int cal = 0;
};

struct ingredients
{
    ingredient tab[50] = {};
    int nb_ing = 0;
};

struct detail_menu
{
    int num_ing = 0, quantite = 0;
};

struct menus
{
    detail_menu tab[5][10] = {};
    int taille_detail_menu[5] = {0, 0, 0, 0, 0};
};

const string jours[5] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi"};

void saisir_ingredient(ingredient *p)
{
    cout << endl << "\t Nom de l'ingredient : "; cin >> (*p).nom_ing;
    cout << "\t Calorie pour 100g : "; cin >> (*p).cal;
}

void saisir_ingredients(ingredients *t)
{
    cout << "Nombre d'ingredients a saisir : "; int nb; cin >> nb;
    while (nb + (*t).nb_ing >= 50) {cout << "Erreur saisir_ingredients : Le nombre d'ingrdients a saisir est incorect." << endl << "Nombre d'ingredients a saisir : "; cin >> nb;}
    for (int i = (*t).nb_ing; i < (*t).nb_ing + nb; i++)
    {
        cout << "Ingrdients " << i+1;
        saisir_ingredient(&((*t).tab[i]));
    }
    (*t).nb_ing += nb;
}

void afficher_ingredients(ingredients t)
{
    cout << endl << endl << "Affichage des ingredients" << endl;
    for (int i = 0; i < t.nb_ing; i++) {cout << "\t" << i+1 << " : " << t.tab[i].nom_ing;}
}

int choisir_ingredient(ingredients t)
{
    afficher_ingredients(t);
    cout << endl << "Numero d'ingredient : "; int num; cin >> num;
    // si le numero n'est pas valide
    while ((num < 1 and num != -1) or num > t.nb_ing) {cout << "Erreur choisir_ingredient : Le numero d'ingredient est incorect." << endl << "Numero d'ingredient : "; cin >> num;}
    return num - 1;
}

int choisir_quantite()
{
    cout << "Quantite : "; int q; cin >> q;
    return q;
}

void init_menu(menus m)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            m.tab[i][j].num_ing = -1;
            m.tab[i][j].quantite = 0;
        }
    }
}

void saisir_menus(ingredients ti, menus *m)
{
    cout << endl << endl << "Saisie des menus" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << endl << endl << "Menu du " << jours[i] << endl << "--------------------";
        for (int j = 0; j < 10; j++)
        {
            m->tab[i][j].num_ing = choisir_ingredient(ti);
            if (m->tab[i][j].num_ing == -2) {break;}
            m->taille_detail_menu[i]++;
            m->tab[i][j].quantite = choisir_quantite();
        }
    }
}

int calculer_calories(ingredients ti, menus m, int jour)
{
    int cal = 0;
    for (int i = 0; i < 10; i++)
    {
        if (m.tab[jour][i].num_ing == -1) {break;}
        cal += ti.tab[m.tab[jour][i].num_ing].cal * m.tab[jour][i].quantite;
    }
    return cal;
}

void afficher_menus(ingredients ti, menus m)
{
    cout << endl << endl << "Affichage des menus" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << endl << "Menu du " << jours[i] << endl << "--------------------" << endl;
        for (int j = 0; j < m.taille_detail_menu[i]; j++)
        {
            cout << "\t" << ti.tab[m.tab[i][j].num_ing].nom_ing << " : " << m.tab[i][j].quantite << "g" << endl;
        }
    }
}

void afficher_bilan_semaine(ingredients ti, menus m)
{
    cout << endl << endl << "Affichage des calories" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << endl << "Menu du " << jours[i] << endl << "--------------------" << endl;
        cout << "\t" << calculer_calories(ti, m, i) << " calories" << endl;
    }
    cout << endl << endl << "Total des calories : " << calculer_calories(ti, m, 0) + calculer_calories(ti, m, 1) + calculer_calories(ti, m, 2) + calculer_calories(ti, m, 3) + calculer_calories(ti, m, 4) << endl;
}

int main()
{
    //Declarer un menu pour la semaine et un tableau d'ingredients
    menus m;
    ingredients ti;
    init_menu(m);

    //demander a l'utilisateur de saisir les ingredients
    saisir_ingredients(&ti);

    //saisir les menus
    saisir_menus(ti, &m);

    //afficher les menus
    afficher_menus(ti, m);

    //afficher le bilan de la semaine
    afficher_bilan_semaine(ti, m);

    system("PAUSE");
    
    return 0;
}