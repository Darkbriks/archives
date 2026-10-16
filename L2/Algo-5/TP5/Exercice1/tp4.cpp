#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "types.hpp"
#include "fifo.hpp"
#include "matrices.hpp"
#include "parcours.hpp"

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
  
  if(argc!=2){
    cout << "Syntaxe : " << argv[0] << " <file>" << endl;
    return -1;
  }

  // matrice d'adjacence du graphe à parcourir
  MatriceAdjacence mat={0, nullptr};


  if(!charger(argv[1], mat)){
    cerr << "Erreur lors du chargement du fichier " << argv[1] << endl;
    return -1;
  }

  // affichage de la matrice pour contrôle
  afficher(mat);

 
  // créer les tableaux à remplir par le parcours en profondeur
  // l'initialisation des tableaux est effectué dans les fonctions
  // de parcours en profondeur
  Couleur *couleurs = new Couleur[mat.ordre];
  int *parents = new int[mat.ordre];

  // effectuer le parcours en profondeur récursif
  cout << "PARCOURS EN PROFONDEUR RECURSIF" << endl;
  cout << "-------------------------------" << endl;
  parcoursEnProfondeurRecursif(mat, couleurs,parents);

  // affichage du contenu des tableaux
  
  cout << "couleurs  : ";
  for(int i=0; i<mat.ordre; i++)
    switch(couleurs[i]){
    case BLANC: cout << "B "; break;
    case NOIR: cout << "N "; break;
    case GRIS: cout << "G "; break;
    }
  cout << endl;

  
  cout << "parents   : ";
  for(int i=0; i<mat.ordre; i++)
    if(parents[i]!=INDEFINI)
      cout << parents[i] << " ";
    else
      cout << "X ";
  cout << endl; 

  // affichage des chemins
  for(int i=0; i<mat.ordre; i++){
    afficherCheminVers(i, parents);
    cout << endl;
  }

  
  // effectuer le parcours en profondeur avec une pile
  cout << "PARCOURS EN PROFONDEUR AVEC UNE PILE" << endl;
  cout << "------------------------------------" << endl;
  parcoursEnProfondeurPile(mat, couleurs,parents);

  // affichage du contenu des tableaux
  
  cout << "couleurs  : ";
  for(int i=0; i<mat.ordre; i++)
    switch(couleurs[i]){
    case BLANC: cout << "B "; break;
    case NOIR: cout << "N "; break;
    case GRIS: cout << "G "; break;
    }
  cout << endl;

  
  cout << "parents   : ";
  for(int i=0; i<mat.ordre; i++)
    if(parents[i]!=INDEFINI)
      cout << parents[i] << " ";
    else
      cout << "X ";
  cout << endl; 

  // affichage des chemins
  for(int i=0; i<mat.ordre; i++){
    afficherCheminVers(i, parents);
    cout << endl;
  }

  // suppression des tableaux
  delete couleurs;
  delete parents;
  
  
  return 1;
}


