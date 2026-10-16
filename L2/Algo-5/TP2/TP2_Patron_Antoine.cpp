#include <iostream>
#include <fstream>
using namespace std;

struct Maillon {
  int col; // numéro de la colonne à laquelle correspond le coefficient
  int coef;// coefficient de la matrice
  Maillon *suiv;// élément suivant non nul sur la ligne
} ;

struct MatriceAdjacence {
  int ordre; // nombre de sommets du graphe
  Maillon* *lignes;// tableau à allouer de taille "ordre", représentant les lignes de la matrice
};

// hypothèses :
// - mat contient une matrice
// - l et c sont des coordonnées valides
int getCoeff(MatriceAdjacence mat, int l, int c)
{
    if (l >= mat.ordre || c >= mat.ordre || l < 0 || c < 0)
    {
        cerr << "Indice incorect\n";
        return -1;
    }

    Maillon* ptr = mat.lignes[l];

    while (ptr != nullptr)
    {
        if (ptr->col == c)
        { return ptr->coef; }
        ptr = ptr->suiv;
    }

    return 0; // on a pas trouvé la colonne c
}

bool estSymetrique(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        for (int j = 0; j < mat.ordre; ++j)
        {
            if (getCoeff(mat, i, j) != getCoeff(mat, j, i)) { return false; }
        }
    }
    return true;
}

bool estComplet(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        for (int j = 0; j < mat.ordre; ++j)
        {
            if (i != j && getCoeff(mat, i, j) == 0) { return false; }
        }
    }
    return true;// aucun 0 trouvé
}

void creerMatrice(MatriceAdjacence &m, int size)
{
    m.ordre = size;
    m.lignes = new Maillon*[size];
    for(int i=0; i < size; i++) { m.lignes[i] = nullptr; }
}

void effacerMatrice(MatriceAdjacence &mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        Maillon *tmp = mat.lignes[i];
        while (tmp != nullptr)
        {
            Maillon *tmp2 = tmp;
            tmp = tmp->suiv;
            delete tmp2;
        }
    }
    delete[] mat.lignes;
}

bool charger(char *nom, MatriceAdjacence &mat)
{
    ifstream fichier(nom);
    if(!fichier.is_open()) return false;

    int ordre;
    fichier >> ordre;
    creerMatrice(mat, ordre);

    for (int i = 0; i < ordre * ordre; ++i)
    {
        int val;
        fichier >> val;

        if (val != 0)
        {
            Maillon *m = new Maillon;
            m->col = i % ordre;
            m->coef = val;
            m->suiv = nullptr;

            if (mat.lignes[i / ordre] == nullptr) { mat.lignes[i / ordre] = m; }
            else
            {
                Maillon *tmp = mat.lignes[i / ordre];
                while (tmp->suiv != nullptr) { tmp = tmp->suiv; }
                tmp->suiv = m;
            }
        }
    }
    fichier.close();
    return true;
}

void afficher(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        Maillon *tmp = mat.lignes[i];
        for (int j = 0; j < mat.ordre; ++j)
        {
            if (tmp != nullptr && tmp->col == j)
            {
                cout << tmp->coef << " ";
                tmp = tmp->suiv;
            }
            else { cout << "0 "; }
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[]){
  
  if(argc!=2){
    printf("Erreur - il manque le nom du fichier à lire\n");
    return -1;
  }

  MatriceAdjacence mat;

  creerMatrice(mat, 3); 
  afficher(mat); 

  effacerMatrice(mat); 
  
  if(!charger(argv[1], mat)) return -1;

  
  afficher(mat);


  if(estSymetrique(mat))
    cout << "symétrique" << endl;
  else
    cout << "non symétrique" << endl;

  if(estComplet(mat))
    cout << "complet" << endl;
  else
    cout << "incomplet" << endl;

  effacerMatrice(mat);
  
  return 1;
}