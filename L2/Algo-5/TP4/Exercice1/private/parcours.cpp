#include <iostream>

#include "../public/types.hpp"
#include "../public/fifo.hpp"
#include "../public/matrices.hpp"

// -----------------------------------------------
//      FONCTIONS DE PARCOURS DU GRAPHE EN LARGEUR
// -----------------------------------------------

void parcoursEnLargeur(MatriceAdjacence mat, int sommetDepart,
                       Couleur *coul, int *dist, int *parent){
    // initialisation des tableaux
    for(int i=0; i<mat.ordre; i++){
        coul[i] = BLANC;
        dist[i] = INFINI;
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
    std::cout << sf << " ";

}
