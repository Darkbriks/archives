#include <iostream>
using namespace std;

#include "../Public/types.hpp"
#include "../Public/fifo.hpp"
#include "../Public/pile.hpp"

/**
 * Licence Informatique 2eme année - ULCO
 * correction du TP4 du module d'algorithmique
 * consacré aux graphes. Année 2023-2024
 * Auteur : C. Renaud
 * Module contentnant les fonctions de parcours en largeur
 * et en profondeur d'un graphe
 */


// parcours du graphe en largeur 
void parcoursEnLargeur(MatriceAdjacence mat, int sommetDepart,
		       Couleur *coul, int *dist, int *parent){
  // initialisation des tableaux
  for(int i=0; i<mat.ordre; i++){
    coul[i] = BLANC;
    dist[i] = INFINI_INT;
    parent[i] = INDEFINI;
  }

  // initialiser le sommet de départ
  coul[sommetDepart] = GRIS;
  dist[sommetDepart] = 0;

  // enfiler le sommet de départ
  Fifo mafile;
  initialiserFifo(mafile);
  ajouter(mafile, sommetDepart);

  // boucle de parcours
  while(!estVide(mafile)){
    int s = retirer(mafile);
    Maillon *cur = mat.lignes[s];
    while(cur){// pour les sommets adjacents au sommet s
      int v = cur->col;
      if(coul[v] == BLANC){
	coul[v] = GRIS;
	dist[v] = dist[s]+1;
	parent[v] = s;
	ajouter(mafile, v);
      }
      cur = cur->suiv;
    }
    coul[s] = NOIR;
  }
  
}

void afficherCheminVers(int sf, int *parent){// version récursive
  if(parent[sf]!=INDEFINI){// on est sur un sommet intermédiaire
    afficherCheminVers(parent[sf], parent);
  }
  // afficher le sommet courant
  cout << sf << " ";

}

/**
 * Fonctions permettant le parcours en profondeur récursif
 */

void explorerDepuis(MatriceAdjacence mat, int s,
		    Couleur *coul, int *parent){

  // le sommet s vient d'être découvert
  coul[s] = GRIS;

  // visiter les sommets d'adjacents
  Maillon *cur = mat.lignes[s];
  while(cur!=nullptr){// il reste des sommets adjacents à traiter
    int col = cur->col;
    if(coul[col]==BLANC){
      parent[col] = s;
      explorerDepuis(mat, col, coul, parent);
    }
    cur = cur->suiv;
  }//while

  // fin du traitement du sommet s
  coul[s] = NOIR;
}




void parcoursEnProfondeurRecursif(MatriceAdjacence m,  Couleur *coul, int *parent){
  // initialisation de tous les sommets
  for(int i=0; i<m.ordre; i++){
    coul[i] = BLANC;
    parent[i] = INDEFINI;
  }

  // lancer l'exploration à partir de chaque sommet
  for(int i=0; i<m.ordre; i++)
    if(coul[i]==BLANC)
      explorerDepuis(m, i, coul, parent);
  
}



/**
 * Fonctions permettant le parcours en profondeur avec une pile
 */

void parcoursEnProfondeurPile(MatriceAdjacence m,  Couleur *coul, int *parent){
  // initialisation de tous les sommets
  for(int i=0; i<m.ordre; i++){
    coul[i] = BLANC;
    parent[i] = INDEFINI;
  }

  // créer la pile des somemts en attente
  Pile mapile;
  initialiserPile(mapile);

  
  // lancer l'exploration à partir de chaque sommet
  for(int i=0; i<m.ordre; i++)
    if(coul[i]==BLANC){
      coul[i]=GRIS;
      empiler(mapile, i);
      while(!estVide(mapile)){
	int s = depiler(mapile);
	Maillon *cur = m.lignes[s];
	// on recherche le premier voisin blanc
	// s'il existe, on rempile s et ce voisin
	// car on a pas terminé le traitement de s
	// sinon le traitement de s est terminé
	while(cur){
	  int col = cur->col;
	  if(coul[col]==BLANC){
	    coul[col]=GRIS;
	    parent[col]=s;
	    empiler(mapile, s);// pour poursuivre son traitement ultérieurement
	    empiler(mapile,col);
	    break;// poursuivre le traitement sur le nouveau sommet en sp
	  }
	  cur=cur->suiv;
	}
	coul[s] = NOIR;
      }//while
    }	  
  
}



