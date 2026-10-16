#include "../Public/types.hpp"

void initialiserPile(Pile &p){
  p.sp = nullptr;
}

bool estVide(Pile p){
  return p.sp==nullptr;
}

void empiler(Pile &p, int v){
  MaillonPile *tmp = new MaillonPile;
  tmp->valeur = v;
  tmp->dessous = p.sp;
  p.sp = tmp;
}

int depiler(Pile &p){
  // hypothèse : pile non vide
  MaillonPile *tmp = p.sp;
  p.sp = p.sp->dessous;
  int v = tmp->valeur;
  delete tmp;
  return v;
}

