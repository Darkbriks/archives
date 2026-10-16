#include <iostream>

#include "../public/types.hpp"
#include "../public/fifo.hpp"
#include "../public/pile.hpp"
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


// -----------------------------------------------
//      FONCTIONS DE PARCOURS DU GRAPHE EN PROFONDEUR
// -----------------------------------------------

void parcourEnProfondeurRec(MatriceAdjacence mat, int sommetDepart, Couleur *coul, int *parent)
{
    // Sommet decouvert en gris
    coul[sommetDepart] = GRIS;

    // Parcours des sommets voisins
    Maillon *cur = mat.lignes[sommetDepart];
    while (cur)
    {
        int v = cur->col;
        if (coul[v] == BLANC)
        {
            parent[v] = sommetDepart;
            parcourEnProfondeurRec(mat, v, coul, parent);
        }
        cur = cur->suiv;
    }

    // Sommet traité en noir
    coul[sommetDepart] = NOIR;
}

void parcourEnProfondeurPile(MatriceAdjacence mat, int sommetDepart, Couleur *coul, int *parent)
{
    // Initialisation de la pile
    Pile p;
    initialiserPile(p);
    empiler(p, sommetDepart);

    // Parcours en profondeur
    while (!estVide(p))
    {
        int s = depiler(p);
        if (coul[s] == BLANC)
        {
            coul[s] = GRIS;
            Maillon *cur = mat.lignes[s];
            while (cur)
            {
                int v = cur->col;
                if (coul[v] == BLANC)
                {
                    parent[v] = s;
                    empiler(p, v);
                }
                cur = cur->suiv;
            }
        }
        coul[s] = NOIR;
    }
}