#include <iostream>
#include <random>

using namespace std;

struct place {int numero = 0; bool etat = false;};
struct wagon {int nb_places = 0; place *places = nullptr; int numero = 0; wagon *suivant = nullptr;};
struct train {int nb_wagons = 0; wagon *locomotive = nullptr;};

int aleatoire(const int min, const int max)
{random_device dev; mt19937 rng(dev()); uniform_int_distribution<> dist(min, max); return dist(rng);}

place creer_place(const int n, bool *tab_existe, bool etat)
{
    place place;
    int numero = aleatoire(0, 2*n);
    while (tab_existe[numero]) {numero = aleatoire(0, n*2);}
    tab_existe[numero] = true;
    place.numero = numero+1;
    place.etat = etat;
    return place;
}

wagon *cree_wagon(int n, int nb_place_occupee)
{
    wagon *ptr = new wagon; ptr->nb_places = n; ptr->suivant = nullptr;
    bool est_pris[n*2]; for (int i= 0 ; i < n*2; i++) {est_pris[i]=false;}
    ptr->places = new place[n];// *2 ?
    while (n > 0) {
        if (n > nb_place_occupee and nb_place_occupee > 0) {ptr->places[ptr -> nb_places - n] = creer_place(ptr -> nb_places, est_pris, aleatoire(0, 1)); // 0 = libre, 1 = occupe
            if (ptr->places[ptr -> nb_places - n].etat) {nb_place_occupee--;}}

        else
            {if (n <= nb_place_occupee) {ptr->places[ptr -> nb_places - n] = creer_place(ptr -> nb_places, est_pris, true); nb_place_occupee--;}
            else {ptr->places[ptr -> nb_places - n] = creer_place(ptr -> nb_places, est_pris, false);}}
        n--;
    }
    return ptr;
}

bool rechercher_place_wagon(const wagon w, const int num, int *etat)
{
  int i=0;
  while (i<w.nb_places) {if (w.places[i].numero == num) {*etat = w.places[i].etat; return true;} i++;}
  return false;
}

int rechercher_place_occupee_wagon(const wagon w)
{
  int nb = 0;
  for (int i=0; i<w.nb_places;i++) {nb = nb + w.places[i].etat;}
  return nb;
}

bool rechercher_place_train(const train train, const int num_wagon, const int num_place, int *etat)
{
  wagon *ptr = train.locomotive;
  while (ptr != nullptr and ptr->numero != num_wagon) ptr = ptr->suivant;
  if (ptr==nullptr) return false ;
  return rechercher_place_wagon(*ptr, num_place, etat);
}

void inserer_position(train *train, wagon *w)
{
  if (train->locomotive == NULL or train->locomotive->numero > w->numero) {w->suivant = train->locomotive; train->locomotive = w;}
  
  else
  {
      wagon *precedant = train->locomotive;
      while (precedant->suivant != NULL and precedant->suivant->numero <= w->numero) {precedant = precedant->suivant;}
      w->suivant = precedant->suivant;
      precedant->suivant = w;
  }
}

void creer_train(train *train, int n)
{
    int num, nb_places, nb_place_occupee;
    train->locomotive = nullptr; train->nb_wagons = n;
    while (n>=1)
    {
        cout << "Numéro du wagon, nombre de places et nombre de places occupée : ";
        cin >> num >> nb_places >> nb_place_occupee;
        wagon *w = cree_wagon(nb_places, nb_place_occupee); w->numero = num;
        inserer_position(train, w);
        n--;
    }
}

void afficher(const train train)
{
    wagon *ptr = train.locomotive;
    while (ptr!=nullptr)
    {
        cout << "(" << ptr->numero << ", " << ptr->nb_places << ", " << rechercher_place_occupee_wagon(*ptr) << ")";
        ptr = ptr->suivant;
        if (ptr!=NULL) cout << " -> ";
        else cout << endl;
    }
}

/*int main()
{
    train t; 
    int nb_wagons;

    cout << "Nombre de wagons : "; cin >> nb_wagons;
    creer_train(&t, nb_wagons); afficher(t);

    while (true)
    {
        int num_wagon, num_place, etat;
        cout << "Numéro du wagon, numéro de la place : "; cin >> num_wagon >> num_place;
        if (rechercher_place_train(t, num_wagon, num_place, &etat)) {cout << "Place " << num_place << " du wagon " << num_wagon << " : " << etat << endl;}
        else {cout << "Place " << num_place << " du wagon " << num_wagon << " : " << "inexistante" << endl;}

        cout << "Voulez-vous continuer ? (0 = non, 1 = oui) : "; cin >> etat;
        if (etat == 0) {break;}
    }
    
    return 0;
}*/