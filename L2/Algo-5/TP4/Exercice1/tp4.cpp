#include <iostream>
using namespace std;

#include "public/types.hpp"
#include "public/fifo.hpp"
#include "public/matrices.hpp"
#include "public/parcours.hpp"

/**
 * Exercice 1 - Modifications - Question 2
 *    -> Quel(s) fichier(s) doi(ven)t être recompilé(s) ?
 * Le fichier matrices.cpp doit être recompilé.
 */


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

    if(argc!=3){
        cout << "Syntaxe : " << argv[0] << " <file>  <indice_sommet_depart>" << endl;
        return -1;
    }

    MatriceAdjacence mat={0, nullptr};

    if(!charger(argv[1], mat)) return -1;

    int sommetDepart = atoi(argv[2]);
    if(sommetDepart <0 || sommetDepart >= mat.ordre){
        cout << "indice de sommet " << sommetDepart << " incorrect ! ";
        cout << "valeurs autorisées dans [0," << mat.ordre-1 << "]" << endl;
        effacerMatrice(mat);
        return -1;
    }


    afficher(mat);

    // créer les tableaux à remplir par le parcours en largeur
    Couleur *couleurs = new Couleur[mat.ordre];
    int *distances = new int[mat.ordre];
    int *parents = new int[mat.ordre];

    // effectuer le parcours en largeur
    parcoursEnLargeur(mat, sommetDepart, couleurs, distances, parents);

    // affichage des couleurs
    cout << "couleurs  : ";
    for(int i=0; i<mat.ordre; i++)
        switch(couleurs[i]){
            case BLANC: cout << "B "; break;
            case NOIR: cout << "N "; break;
            case GRIS: cout << "G "; break;
        }
    cout << endl;

    // affichage des distances
    cout << "distances : ";
    for(int i=0; i<mat.ordre; i++)
        if(distances[i]!=INFINI)
            cout << distances[i] << " ";
        else
            cout << "X ";
    cout << endl;

    // affichage des parents
    cout << "parents   : ";
    for(int i=0; i<mat.ordre; i++)
        if(parents[i]!=INDEFINI)
            cout << parents[i] << " ";
        else
            cout << "X ";
    cout << endl;

    // affichage des chemins
    for(int i=0; i<mat.ordre; i++){
        if(i!=sommetDepart){
            if(couleurs[i]==NOIR){// un chemin a été trouvé
                cout << "chemin vers " << i << " = ";
                afficherCheminVers(i, parents);
                cout << endl;
            }else{
                cout << "pas de chemin de " << sommetDepart << " vers " << i << endl;
            }
        }
    }

    // supprimer les tableaux
    delete couleurs;
    delete distances;
    delete parents;

    return 1;
}