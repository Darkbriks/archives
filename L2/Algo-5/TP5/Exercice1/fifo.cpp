#include "types.hpp"


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
