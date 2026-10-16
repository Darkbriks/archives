#include <iostream>

#include "../Public/types.hpp"
#include "../Public/pile.hpp"

bool existeBlanc(MatriceAdjacence mat, Couleur *coul) { for (int i = 0; i < mat.ordre; i++) { if (coul[i] == BLANC) return true; } return false; }

int sommetBlancMin(MatriceAdjacence mat, Couleur *coul, int *dist)
{
    int min = (int)INFINI; int sommet = -1;
    for (int i = 0; i < mat.ordre; i++)
    {
        if (coul[i] == BLANC && dist[i] < min)
        {
            min = dist[i]; sommet = i;
        }
    }
    return sommet;
}

bool isNeighbour(MatriceAdjacence mat, int sommet, int i)
{
    Maillon *ptr = mat.lignes[sommet];
    while (ptr != nullptr) { if (ptr->col == i) return true; ptr = ptr->suiv; }
    return false;
}

int getNeighbourWeight(MatriceAdjacence mat, int sommet, int i)
{
    Maillon *ptr = mat.lignes[sommet];
    while (ptr != nullptr) { if (ptr->col == i) return ptr->coef; ptr = ptr->suiv; }
    return (int)INFINI;
}

void algo_dijkstra(MatriceAdjacence mat, int sommetDepart, Couleur *coul, int *dist, int *parent)
{
    // Initialisation des tableaux
    for (int i = 0; i < mat.ordre; i++) { coul[i] = BLANC; dist[i] = (int)INFINI; parent[i] = INDEFINI; }
    dist[sommetDepart] = 0;

    // Boucle principale
    while (existeBlanc(mat, coul))
    {
        int sommet = sommetBlancMin(mat, coul, dist);

        for (int i = 0; i < mat.ordre; i++)
        {
            if (isNeighbour(mat, sommet, i) && coul[i] == BLANC)
            {
                if (dist[i] > dist[sommet] + getNeighbourWeight(mat, sommet, i))
                {
                    dist[i] = dist[sommet] + getNeighbourWeight(mat, sommet, i);
                    parent[i] = sommet;
                }
            }
        }
        coul[sommet] = NOIR;
    }
}

void afficherCheminVers_Dijkstra(int sf, int *parent) { if(parent[sf]!=INDEFINI) { afficherCheminVers_Dijkstra(parent[sf], parent); } std::cout << sf << " "; }