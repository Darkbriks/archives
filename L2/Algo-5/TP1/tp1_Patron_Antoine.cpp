#include <iostream>
#include <fstream>
using namespace std;

// représentation d'un matrice d'adjacence
struct MatriceAdjacence {
  int ordre;// nombre de sommets du graphe
  int *coef;// tableau contenant les (ordre x ordre) coefficients de la matrice
};

// Créer une matrice remplie de 0
void creerMatrice(MatriceAdjacence &m, int size)
{
  m.ordre = size;
  m.coef = new int[size * size];
  for(int i=0; i < size * size; i++)
    m.coef[i] = 0;
}

// Afficher une matrice
void afficher(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        for (int j = 0; j < mat.ordre; ++j)
        {
            cout << mat.coef[i * mat.ordre + j] << " ";
        }
        cout << "\n";
    }
}

// Verifie si un unique parametre a ete passer sur la ligne de commande
void checkCommandeLine(int argc)
{
    if (argc != 2)
    {
        cout << "Erreur : le nombre de parametres est incorect.\n";
        exit(1); // Termine le programme
    }
}

// Chargement de fichier
bool charger(string nomFichier, MatriceAdjacence &mat)
{
    ifstream fichier;
    fichier.open(nomFichier, ios::in);
    if (!fichier.is_open()) { cout << "Erreur : Le fichier n'a pas put etre ouvert.\n"; return false; }

    fichier >> mat.ordre;
    mat.coef = new int[mat.ordre * mat.ordre];
    for (int i = 0; i < mat.ordre * mat.ordre; ++i) { fichier >> mat.coef[i]; }

    fichier.close();
    return true;
}

// Verifier si la matrice represente un grphe complet
bool estComplet(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        for (int j = 0; j < mat.ordre; ++j)
        {
            if (i != j && mat.coef[i * mat.ordre + j] == 0) { return false; }
        }
    }
    return true;
}

// Verifier si la matrice est symetrique
bool estSymetrique(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        for (int j = i; j < mat.ordre; ++j)
        {
            if (mat.coef[i * mat.ordre + j] != mat.coef[j * mat.ordre + i]) { return false; }
        }
    }
    return true;
}

bool estIsole(MatriceAdjacence mat, int sommet)
{
    int nbVoisin = 0;
    for (int i = 0; i < mat.ordre; ++i) { if (sommet != i && mat.coef[sommet * mat.ordre + i] != 0) { nbVoisin++; } }
    for (int i = 0; i < mat.ordre; ++i) { if (sommet != i && mat.coef[i * mat.ordre + sommet] != 0) { nbVoisin++; } }
    return nbVoisin == 0;
}

void afficherDegresNonOriente(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        int nbVoisin = 0;
        for (int j = 0; j < mat.ordre; ++j) { if (i != j && mat.coef[i * mat.ordre + j] != 0) { nbVoisin++; } }
        cout << "Degre du sommet " << i << " : " << nbVoisin << "\n";
    }
}

void afficherDegresOriente(MatriceAdjacence mat)
{
    for (int i = 0; i < mat.ordre; ++i)
    {
        int nbVoisin = 0;
        for (int j = 0; j < mat.ordre; ++j) { if (mat.coef[i * mat.ordre + j] != 0) { nbVoisin++; } }
        for (int j = 0; j < mat.ordre; ++j) { if (mat.coef[j * mat.ordre + i] != 0) { nbVoisin++; } }
        cout << "Degre du sommet " << i << " : " << nbVoisin << "\n";
    }
}

int main(int argc, char *argv[])
{
    cout << "\n////////// Test exercice 1 //////////\n";
    MatriceAdjacence *mat1 = new MatriceAdjacence();
    creerMatrice(*mat1, 2);
    /*afficher(*mat1);

    MatriceAdjacence *mat2 = new MatriceAdjacence();
    creerMatrice(*mat2, 5);
    afficher(*mat2);*/

    cout << "\n////////// Test exercice 2 //////////\n";
    checkCommandeLine(argc);
    cout << "Nombre d'argument correct.\n";

    cout << "\n////////// Test exercice 3 //////////\n";
    string nomFichier = argv[1];
    if (!charger(nomFichier, *mat1)) { exit(1); }
    cout << "Fichier correctement ouvert.\n";

    cout << mat1->ordre << "\n";
    afficher(*mat1);

    cout << "\n////////// Test exercice 4 //////////\n";
    cout << (estComplet(*mat1) ? "Complete\n" : "Incomplete\n");

    cout << "\n////////// Test exercice 5 //////////\n";
    cout << (estSymetrique(*mat1) ? "Symetrique\n" : "Non symetrique\n");

    cout << "\n////////// Test exercice 6 //////////\n";
    for (int i = 0; i < mat1->ordre; ++i) { cout << "Sommet " << i << " : " << (estIsole(*mat1, i) ? "Isole\n" : "Non isole\n"); }

    cout << "\n////////// Test exercice 7 //////////\n";
    afficherDegresNonOriente(*mat1);

    cout << "\n////////// Test exercice 8 //////////\n";
    afficherDegresOriente(*mat1);

    return 1;
}

