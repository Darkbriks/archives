/*#include <iostream>
using namespace std;

struct noeud { int v=0; noeud *fg=nullptr, *fd=nullptr; };

noeud* createArbrePrefixe(int p)
{
    noeud *n = new noeud;
    cout << "Valeur du noeud : "; cin >> n->v;
    if (p==0) { n->fg = nullptr; n->fd = nullptr; }
    else { n->fg = createArbrePrefixe(p-1); n->fd = createArbrePrefixe(p-1); }
    return n;
}

noeud* createArbreInfixe(int p)
{
    noeud *n = new noeud;
    
    if (p==0)
    {
        n->fg = nullptr;
        cout << "Valeur du noeud : "; cin >> n->v;
        n->fd = nullptr;
    }
    else
    {
        n->fg = createArbrePrefixe(p-1);
        cout << "Valeur du noeud : "; cin >> n->v;
        n->fd = createArbrePrefixe(p-1);
    }
    return n;
}

noeud* createArbrePostfixe(int p)
{
    noeud *n = new noeud;
    if (p==0) { n->fg = nullptr; n->fd = nullptr; }
    else { n->fg = createArbrePrefixe(p-1); n->fd = createArbrePrefixe(p-1); }
    cout << "Valeur du noeud : "; cin >> n->v;
    return n;
}

void printPrefixe(noeud * r)
{
    if (r != nullptr)
    {
        cout << r->v << " ";
        printPrefixe (r->fg);
        printPrefixe (r->fd);
    }
}

void printInfixe(noeud * r)
{
    if (r != nullptr)
    {
        printPrefixe (r->fg);
        cout << r->v << " ";
        printPrefixe (r->fd);
    }
}

void printPostfixe(noeud *r)
{
    if (r != nullptr)
    {
        printPrefixe (r->fg);
        printPrefixe (r->fd);
        cout << r->v << " ";
    }
}

void printArbre(noeud *r, int parcour=0)
{
    switch (parcour)
    {
        case 1: printInfixe(r); break;
        case 2: printPostfixe(r); break;
        default: printPrefixe(r); break;
    }
}

void afficheValeurPrefixe(noeud * r, int max)
{
    if (r != nullptr)
    {
        if (r->v < max) { cout << r->v << " "; }
        afficheValeurPrefixe (r->fg, max);
        afficheValeurPrefixe (r->fd, max);
    }
}

void afficheValeurInfixe(noeud * r, int max)
{
    if (r != nullptr)
    {
        afficheValeurInfixe (r->fg, max);
        if (r->v < max) { cout << r->v << " "; }
        afficheValeurInfixe (r->fd, max);
    }
}

void afficheValeurPostfixe(noeud *r, int max)
{
    if (r != nullptr)
    {
        afficheValeurPostfixe (r->fg, max);
        afficheValeurPostfixe (r->fd, max);
        if (r->v < max) { cout << r->v << " "; }
    }
}

bool rechercheValeurPrefixe(noeud *r, int val)
{
    if (r != nullptr)
    {
        if (r->v == val) { return true; }
        return rechercheValeurPrefixe (r->fg, val) or rechercheValeurPrefixe (r->fd, val);
    }
    return false;
}

int compterFeuille(noeud *r)
{
    if (r != nullptr)
    {
        if (r->fg == nullptr and r->fd == nullptr) { return 1; }
        return compterFeuille (r->fg) + compterFeuille (r->fd);
    }
    return 0;
}

int compterNoeud(noeud *r)
{
    if (r != nullptr)
    {
        return 1 + compterNoeud (r->fg) + compterNoeud (r->fd);
    }
    return 0;
}

int compterNoeudInterne(noeud *r)
{
    if (r != nullptr)
    {
        if (r->fg == nullptr and r->fd == nullptr) { return 0; }
        return 1 + compterNoeudInterne (r->fg) + compterNoeudInterne (r->fd);
    }
    return 0;
}

int profondeur(noeud *r)
{
    if (r != nullptr)
    {
        if (r->fg == nullptr and r->fd == nullptr) { return 0; }
        return 1 + max(profondeur (r->fg), profondeur (r->fd));
    }
    return 0;
}

int combienProf(noeud *r, int p)
{
    if (r != nullptr)
    {
        if (p == 0) { return 1; }
        return combienProf (r->fg, p-1) + combienProf (r->fd, p-1);
    }
    return 0;
}

void noeudProf(noeud *r, int p)
{
    if (r != nullptr)
    {
        if (p == 0) { cout << r->v << " "; return; }
        noeudProf (r->fg, p-1);
        noeudProf (r->fd, p-1);
    }
}

bool estPlein(noeud *r) { return compterNoeud(r) == (int)pow(2, profondeur(r)+1)-1; }

int main()
{
    cout << "---------- PREFIXE ----------";
    cout << "Creation de l'arbre [prefixe] :" << endl;
    noeud *a1 = createArbrePrefixe(2);

    cout << "Affichage de l'arbre [prefixe] : ";
    printArbre(a1); cout << endl;

    cout << "Affiche les valeures inferieures a 4 [prefixe] : ";
    afficheValeurPrefixe(a1, 4); cout << endl;

    cout << "Presence de la valeure 1 : " << rechercheValeurPrefixe(a1, 1) << endl;
    cout << "Presence de la valeure -1 : " << rechercheValeurPrefixe(a1, -1) << endl;
    cout << "Nombre de feuille de l'arbre : " << compterFeuille(a1) << endl;
    cout << "Nombre de noeud de l'arbre : " << compterNoeud(a1) << endl;
    cout << "Nombre de noeud interne de l'arbre : " << compterNoeudInterne(a1) << endl;
    cout << "Profondeur de l'arbre : " << profondeur(a1) << endl;
    cout << "Nombre de noeud a la profondeure 0 : " << combienProf(a1, 0) << endl;
    cout << "Nombre de noeud a la profondeure 1 : " << combienProf(a1, 1) << endl;
    cout << "Nombre de noeud a la profondeure 2 : " << combienProf(a1, 2) << endl;
    cout << "Nombre de noeud a la profondeure 10 : " << combienProf(a1, 10) << endl;

    cout << "Affiche les noeuds de profondeur 0 : ";
    noeudProf(a1, 0); cout << endl;
    cout << "Affiche les noeuds de profondeur 1 : ";
    noeudProf(a1, 1); cout << endl;
    cout << "Affiche les noeuds de profondeur 2 : ";
    noeudProf(a1, 2); cout << endl;
    cout << "Affiche les noeuds de profondeur 10 : ";
    noeudProf(a1, 10); cout << endl;

    cout << "Affiche si l'arbre est plein : " << estPlein(a1) << endl;
    system("pause");
    
    cout << "---------- INFIXE ----------";
    cout << "Creation de l'arbre [infixe] :" << endl;
    noeud *a2 = createArbreInfixe(2);

    cout << "Affichage de l'arbre [infixe] : ";
    printArbre(a2, 1); cout << endl;

    cout << "Affiche les valeures inferieures a 4 [infixe] : ";
    afficheValeurInfixe(a2, 4); cout << endl;

    cout << "Presence de la valeure 1 : " << rechercheValeurPrefixe(a2, 1) << endl;
    cout << "Presence de la valeure -1 : " << rechercheValeurPrefixe(a2, -1) << endl;
    cout << "Nombre de feuille de l'arbre : " << compterFeuille(a2) << endl;
    cout << "Nombre de noeud de l'arbre : " << compterNoeud(a2) << endl;
    cout << "Nombre de noeud interne de l'arbre : " << compterNoeudInterne(a2) << endl;
    cout << "Profondeur de l'arbre : " << profondeur(a2) << endl;
    cout << "Nombre de noeud a la profondeure 0 : " << combienProf(a2, 0) << endl;
    cout << "Nombre de noeud a la profondeure 1 : " << combienProf(a2, 1) << endl;
    cout << "Nombre de noeud a la profondeure 2 : " << combienProf(a2, 2) << endl;
    cout << "Nombre de noeud a la profondeure 10 : " << combienProf(a2, 10) << endl;

    cout << "Affiche les noeuds de profondeur 0 : ";
    noeudProf(a2, 0); cout << endl;
    cout << "Affiche les noeuds de profondeur 1 : ";
    noeudProf(a2, 1); cout << endl;
    cout << "Affiche les noeuds de profondeur 2 : ";
    noeudProf(a2, 2); cout << endl;
    cout << "Affiche les noeuds de profondeur 10 : ";
    noeudProf(a2, 10); cout << endl;

    cout << "Affiche si l'arbre est plein : " << estPlein(a1) << endl;
    system("pause");
    
    cout << "---------- POSTFIXE ----------";
    cout << "Creation de l'arbre [postfixe] :" << endl;
    noeud *a3 = createArbrePostfixe(2);

    cout << "Affichage de l'arbre [postfixe] : ";
    printArbre(a3, 2); cout << endl;

    cout << "Affiche les valeures inferieures a 4 [postfixe] : ";
    afficheValeurPostfixe(a3, 4); cout << endl;

    cout << "Presence de la valeure 1 : " << rechercheValeurPrefixe(a3, 1) << endl;
    cout << "Presence de la valeure -1 : " << rechercheValeurPrefixe(a3, -1) << endl;
    cout << "Nombre de feuille de l'arbre : " << compterFeuille(a3) << endl;
    cout << "Nombre de noeud de l'arbre : " << compterNoeud(a3) << endl;
    cout << "Nombre de noeud interne de l'arbre : " << compterNoeudInterne(a3) << endl;
    cout << "Profondeur de l'arbre : " << profondeur(a3) << endl;
    cout << "Nombre de noeud a la profondeure 0 : " << combienProf(a3, 0) << endl;
    cout << "Nombre de noeud a la profondeure 1 : " << combienProf(a3, 1) << endl;
    cout << "Nombre de noeud a la profondeure 2 : " << combienProf(a3, 2) << endl;
    cout << "Nombre de noeud a la profondeure 10 : " << combienProf(a3, 10) << endl;

    cout << "Affiche les noeuds de profondeur 0 : ";
    noeudProf(a3, 0); cout << endl;
    cout << "Affiche les noeuds de profondeur 1 : ";
    noeudProf(a3, 1); cout << endl;
    cout << "Affiche les noeuds de profondeur 2 : ";
    noeudProf(a3, 2); cout << endl;
    cout << "Affiche les noeuds de profondeur 10 : ";
    noeudProf(a3, 10); cout << endl;

    cout << "Affiche si l'arbre est plein : " << estPlein(a3) << endl;
    system("pause");
    
    return 0;
}*/