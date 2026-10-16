#include "../public/types.hpp"
#include <iostream>

using namespace std;

void initialiserPile(Pile &p)
{
    p.sommet = nullptr;
}

bool estVide(Pile p)
{
    return p.sommet == nullptr;
}

void empiler(Pile &p, int v)
{
    MaillonPile *nouveau = new MaillonPile;
    nouveau->valeur = v;
    nouveau->suiv = p.sommet;
    p.sommet = nouveau;
}

int depiler(Pile &p)
{
    if (estVide(p))
    {
        cerr << "Erreur : tentative de dépiler une pile vide" << endl;
        return -1;
    }
    MaillonPile *aSupprimer = p.sommet;
    int v = aSupprimer->valeur;
    p.sommet = aSupprimer->suiv;
    delete aSupprimer;
    return v;
}