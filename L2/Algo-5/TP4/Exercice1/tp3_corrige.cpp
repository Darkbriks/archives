#include <iostream>
#include <fstream>
using namespace std;

#include "public/types.hpp"

/**
 * Licence Informatique 2eme année - ULCO
 * correction du TP3 du module d'algorithmique
 * consacré aux graphes. Année 2023-2024
 * Auteur : C. Renaud
 */

/* pré-définition des fonctions utilisées dans ce module
 * Le code des fonctions est donnée après la fonction main
 */

/* fonction de gestion d'une matrice d'adjacence */
void creerMatrice(MatriceAdjacence &m, int taille);
void effacerMatrice(MatriceAdjacence &mat);
void afficher(MatriceAdjacence mat);
bool charger(char *nom, MatriceAdjacence &mat);

/* fonctions de gestion d'une fifo contenant des nombres entiers >= 0 */
void initialiserFifo(Fifo &file);
bool estVide(Fifo file);
void ajouter(Fifo &file, int v);
int retirer(Fifo &file);

/* fonction de parcours en largeur du graphe */
void parcoursEnLargeur(MatriceAdjacence mat, int sommetDepart,
		       Couleur *coul, int *dist, int *parent);
void afficherCheminVers(int sf, int *parent);


/** PROGRAMME PRINCIPAL **/

int main(int argc, char *argv[]){
  
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



// -----------------------------------------------
//      FONCTIONS DE GESTION D'UNE MATRICE D'ADJACENCE
// -----------------------------------------------


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

bool charger(char *nom, MatriceAdjacence &mat){
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

  for(int l=0; l<mat.ordre; l++){ // lire et créer une ligne complète
    Maillon *fin=nullptr;
    for(int c=0; c<mat.ordre; c++){ // lire et créer chaque colonne de la ligne courante
      in >> v;
      if(v!=0){// créer un maillon et l'insérer en fin de liste
	Maillon *nouveau = new Maillon;
	nouveau->col = c;
	nouveau->coef = v;
	nouveau->suiv = nullptr;
	if(fin!=nullptr){// il y a déjà des éléments dans la liste
	  fin->suiv = nouveau;// insertion en fin
	  fin = nouveau;// maj du pointeur vers le dernier élément de la liste
	}else{// c'est le premier coefficient de la liste
	  mat.lignes[l] = nouveau;// ajout au début de la liste
	  fin = nouveau;// maj du pointeur vers le dernier élément de la liste
	}
      }// if - rien à faire si v vaut 0
    }// for c
  }// for l

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

// -----------------------------------------------
//      FONCTIONS DE GESTION D'UNE FILE FIFO
// -----------------------------------------------

/**
 * Initialise une file f à "vide"
 **/
void initialiserFifo(Fifo &f){
  f.in = f.out = nullptr;
}

/**
 * Verifie si une file f est vide ou pas
 **/
bool estVide(Fifo f){
  return f.out == nullptr;// les deux pointeurs sont forcément nuls
}

/**
 * Ajouter une valeur entière v dans la file f
 **/
void ajouter(Fifo &f, int v){
  // création du nouveau maillon
  MaillonEntier *nouv = new MaillonEntier;
  nouv->valeur = v;
  // insertion en tête
  nouv->suiv = f.in;
  nouv->prec = nullptr;
  // maj du pointeur d'entrée
  if(f.in!=nullptr)
    f.in->prec = nouv;
  f.in = nouv;
  // maj du pointeur de sortie
  if(f.out == nullptr)
    f.out = nouv;
}

/**
 * Récupération d'une valeur dans la FIFO
 * Cette version suppose la file non vide ...
 * La présence d'au moins un élément dans la file
 * doit donc être traitée avant l'appel à retirer()
 **/
int retirer(Fifo &f){
  // récupérattion de la valeur
  MaillonEntier *cur = f.out;
  int v = cur->valeur;
  // maj des pointeurs d'entrée et de sortie
  f.out = cur->prec;
  if(f.out!=nullptr)// file non vide
    f.out->suiv = nullptr;
  else // file vide après le retrait
    f.in = nullptr;

  return v;
}

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
  cout << sf << " ";

}
