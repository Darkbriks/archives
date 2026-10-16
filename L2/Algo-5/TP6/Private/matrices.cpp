#include <iostream>
#include <fstream>
#include "../Public/types.hpp"

using namespace std;

void creerMatrice(MatriceAdjacence &m, int taille)
{
    m.ordre = taille;
    m.lignes = new Maillon*[taille];
    m.positions = new coordonnees[taille];
    for(int i=0; i<taille; i++) m.lignes[i]=nullptr;
}

void effacerMatrice(MatriceAdjacence &mat){
    for(int l=0; l<mat.ordre; l++)
    {
        while(mat.lignes[l]!=nullptr)
        {
            Maillon *cour = mat.lignes[l];
            mat.lignes[l] = cour->suiv;
            delete cour;
        }
    }
    delete mat.positions;
    delete mat.lignes;
    mat.ordre = 0;
}

bool charger(char *nom, MatriceAdjacence &mat)
{
    ifstream in;

    in.open(nom, std::ifstream::in);
    if(!in.is_open()) { printf("Erreur d'ouverture de %s\n", nom); return false; }

    int taille;
    in >> taille;
    creerMatrice(mat, taille);

    for(int l=0; l<mat.ordre; l++)
    {
        coordonnees coord;
        in >> coord.x; in >> coord.y;
        mat.positions[l] = coord;

        Maillon *fin=nullptr;
        while(true)
        {
            int v;
            in >> v;
            if(v==-1) break;
            Maillon *nouveau = new Maillon;
            nouveau->col = v;
            in >> nouveau->coef;
            nouveau->suiv = nullptr;
            if(fin!=nullptr) { fin->suiv = nouveau; fin = nouveau; }
            else { mat.lignes[l] = nouveau; fin = nouveau; }
        }
    }

    in.close();
    return true;
}

void afficher(MatriceAdjacence mat)
{
    for(int l=0; l<mat.ordre; l++)
    {
        cout << mat.positions[l].x << " " << mat.positions[l].y << " : ";

        int c=0;
        Maillon *mcur=mat.lignes[l];
        while(c<mat.ordre)
        {
            if(mcur==nullptr) { cout << "0 "; c++; }
            else if(mcur->col != c) { cout << "0 "; c++; }
            else { cout << mcur->coef << " "; mcur = mcur->suiv; c++; }
        }
        cout << endl;
    }
}
