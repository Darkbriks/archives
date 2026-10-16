#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "Public/types.hpp"
#include "Public/fifo.hpp"
#include "Public/matrices.hpp"
#include "Public/dijkstra.hpp"

/**
 * Licence Informatique 2eme année - ULCO
 * correction du TP4 du module d'algorithmique
 * consacré aux graphes. Année 2023-2024
 * Auteur : C. Renaud
 */



/**
 * Fonction prinicpale permettant de tester le parcours en profondeur
 * d'un graphe, en utilisant un parcours récursif puis un parcours avec
 * une pile. L'application attend le nom d'un fichier contenant la description
 * d'un matrice d'adjacence pour pouvoir s'exécuter.
 */

int main(int argc, char *argv[]){
  
    if(argc!=3){
        cout << "Syntaxe : " << argv[0] << " <file> <sommet>" << endl;
        return -1;
    }

    // matrice d'adjacence du graphe à parcourir
    MatriceAdjacence mat={0, nullptr};


    if(!charger(argv[1], mat)) { cerr << "Erreur lors du chargement du fichier " << argv[1] << endl; return -1; }

    // Verification de la validité du sommet
    int sommet = atoi(argv[2]);
    if(sommet < 0 || sommet >= mat.ordre) { cerr << "Erreur : le sommet " << sommet << " n'existe pas dans le graphe" << endl; return -1; }

    // affichage de la matrice pour contrôle
    afficher(mat);


    Couleur *couleurs = new Couleur[mat.ordre];
    int *distances = new int[mat.ordre];
    int *parents = new int[mat.ordre];

    // effectuer le parcours en profondeur récursif
    cout << "ALGORITHME DE DIJKSTRA (PLUS COURTS CHEMINS)" << endl;
    cout << "-------------------------------" << endl;
    algo_dijkstra(mat, sommet, couleurs, distances, parents);

    // affichage du contenu des tableaux
  
    cout << "couleurs  : ";
    for(int i=0; i<mat.ordre; i++)
    switch(couleurs[i]) { case BLANC: cout << "B "; break; case NOIR: cout << "N "; break; case GRIS: cout << "G "; break; }
    cout << endl;

    cout << "distances : ";
    for (int i = 0; i < mat.ordre; i++) { cout << distances[i] << " "; }

  
    cout << endl << "parents   : ";
    for(int i=0; i<mat.ordre; i++) { cout << parents[i] << " "; }

    // affichage des chemins
    cout << endl << "Chemin vers les sommets : " << endl;
    for(int i=0; i<mat.ordre; i++) { if (i != sommet)
    {
        cout << "Chemin vers " << i << " (lg = " << distances[i] << ") : ";
        afficherCheminVers_Dijkstra(i, parents); cout << endl; }
    }


    delete couleurs;
    delete distances;
    delete parents;
    return 1;
}


