#include <iostream>
#include <fstream>
#include "types.hpp"

using namespace std;

void creerMatrice(MatriceAdjacence &m, int taille){
  // initialisation du nombre de lignes/colonnes de la matrice
  m.ordre = taille;
  // allocation mémoire du tableau de lignes
  m.lignes = new Maillon*[taille];
  // initialisation de chaque ligne à "vide"
  for(int i=0; i<taille; i++) m.lignes[i]=nullptr;
}

void effacerMatrice(MatriceAdjacence &mat){
  for(int l=0; l<mat.ordre; l++){// effacer chaque ligne
    while(mat.lignes[l]!=nullptr){// tq la ligne n'est pas vide
      // effacer le premier élément qui s'y trouve
      Maillon *cour = mat.lignes[l];// 1er élément de la liste
      mat.lignes[l] = cour->suiv;// élément suivant éventuel
      delete cour; // effacer le 1er élement courant
    }
  }
  // effacer le tableau de lignes
  delete mat.lignes;
  // raz de la taille
  mat.ordre = 0;
      
}

/*
 * 5
 * 0 1 0 0 0
 * 0 0 1 0 0
 * 1 1 0 1 0
 * 0 0 0 0 1
 * 0 0 0 0 0
 */
bool charger_old(char *nom, MatriceAdjacence &mat)
{
    ifstream in;

    in.open(nom, std::ifstream::in);
    if(!in.is_open()){
    printf("Erreur d'ouverture de %s\n", nom);
    return false;
    }

    int taille;
    in >> taille;

    // créer la matrice
    creerMatrice(mat, taille);

    int v; // coefficient lu

    for(int l=0; l<mat.ordre; l++) // lire et créer une ligne complète
    {
        Maillon *fin=nullptr;
        for(int c=0; c<mat.ordre; c++) // lire et créer chaque colonne de la ligne courante
        {
            in >> v;
            if(v!=0) // créer un maillon et l'insérer en fin de liste
            {
                Maillon *nouveau = new Maillon;
                nouveau->col = c;
                nouveau->coef = v;
                nouveau->suiv = nullptr;
                if(fin!=nullptr) // il y a déjà des éléments dans la liste
                {
                    fin->suiv = nouveau;// insertion en fin
                    fin = nouveau;// maj du pointeur vers le dernier élément de la liste
                }
                else// c'est le premier coefficient de la liste
                {
                    mat.lignes[l] = nouveau;// ajout au début de la liste
                    fin = nouveau;// maj du pointeur vers le dernier élément de la liste
                }
            }// if - rien à faire si v vaut 0
        }// for c
    }// for l

    in.close();
  return true;
}

/*
 * 5
 * 1 1 -1
 * 2 1 -1
 * 0 1 1 1 3 1 -1
 * 4 1 -1
 * -1
 */
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



void afficher(MatriceAdjacence mat){
  // affichage de chacune des lignes
  for(int l=0; l<mat.ordre; l++){// affichage de la ligne l
    int c=0;
    Maillon *mcur=mat.lignes[l];
    while(c<mat.ordre){
      if(mcur==nullptr){// le coefficients de la ligne >=c sont nuls
	cout << "0 ";
	c++;
      }else if(mcur->col != c){
	// on est sur un coefficient nul, qui se trouve avant c
	cout << "0 ";
	c++;
      }else{// afficher le coefficient
	cout << mcur->coef << " ";
	mcur = mcur->suiv;
	c++;
      }   
    }// while
    cout << endl;// fin de la ligne l
  }// for
}
