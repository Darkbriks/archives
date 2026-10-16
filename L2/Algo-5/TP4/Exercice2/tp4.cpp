#include <iostream>
using namespace std;

#include "public/types.hpp"
#include "public/fifo.hpp"
#include "public/pile.hpp"
#include "public/matrices.hpp"
#include "public/parcours.hpp"

/**
 * Licence Informatique 2eme année - ULCO
 * correction du TP3 du module d'algorithmique
 * consacré aux graphes. Année 2023-2024
 * Auteur : C. Renaud
 */

/** PROGRAMME PRINCIPAL **/

int main(int argc, char *argv[])
{
    cout << "PATRON Antoine - TP4 - Exercice 1\n";
    if(argc!=2) { cout << "Syntaxe : " << argv[0] << " <file>" << endl; return -1; }

    MatriceAdjacence mat={0, nullptr};
    if(!charger(argv[1], mat)) return -1;
    afficher(mat);

    // parcours en profondeur
    Couleur *couleurs = new Couleur[mat.ordre];
    int *parents = new int[mat.ordre];
    for (int i = 0; i < mat.ordre; i++) { couleurs[i] = BLANC; parents[i] = INDEFINI; }

    parcourEnProfondeurPile(mat, 0, couleurs, parents);

    cout << "couleurs    : "; for (int i = 0; i < mat.ordre; i++) { cout << couleurs[i] << " "; }
    cout << "\nparents     : "; for (int i = 0; i < mat.ordre; i++) { cout << parents[i] << " "; }

    cout << "\nParcours en largeur depuis le sommet 0 : " << endl;
    for (int i = 0; i < mat.ordre; i++)
    {
        cout << "Sommet " << i << " : ";
        afficherCheminVers(i, parents);
        cout << endl;
    }

    effacerMatrice(mat);
    delete[] couleurs;
    delete[] parents;

    return 1;
}