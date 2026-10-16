/*#include <iostream>
using namespace std;

struct noeudMult
{
    int v=0;
    int nbf=0;
    noeudMult *fils[100]={nullptr};
};

struct File { noeudMult *n = nullptr; int ligne=0; File *next=nullptr; };

void enfiler(noeudMult *n, int ligne, File **f)
{
    if (*f == nullptr)
    {
        *f = new File;
        (*f)->n = n;
        (*f)->ligne=ligne;
        (*f)->next = nullptr;
    }
    else { enfiler(n, ligne, &(*f)->next); }
}

noeudMult* defiler(File **f, int *l)
{
    noeudMult *temp = (*f)->n;
    *l = (*f)->ligne;
    *f = (*f)->next;
    return temp;
}

noeudMult *createArbreNAire()
{
    noeudMult *n = new noeudMult;
    cout << "Valeur du noeud : "; cin >> n->v;
    cout << "Nombre de fils du noeud " << n->v << " : "; cin >> n->nbf;

    for (int i = 0; i < n->nbf; i++) { n->fils[i] = createArbreNAire(); }

    return n;
}

void afficherProfondeur(noeudMult *r)
{
    if (r != nullptr)
    {
        cout << r->v << " ";
        for (int i = 0; i < r->nbf; i++) { afficherProfondeur(r->fils[i]); }
    }
}

void afficherLargeur(noeudMult *r)
{
    File *f = nullptr;
    enfiler(r, 0, &f);

    int niveau = 0;
    while (f != nullptr)
    {
        int ligne;
        noeudMult *current = defiler(&f, &ligne);
        if (ligne != niveau)
        {
            cout << endl;
            niveau++;
        }
        cout << current->v << " ";
        for (int i = 0; i < current->nbf; i++)
        {
            enfiler(current->fils[i], ligne+1, &f);
        }
    }
}

int rechercheHauteur(noeudMult *r)
{
    if (r != nullptr)
    {
        if (r->nbf == 0) { return 0; }
        int m = 0;
        for (int i = 0; i < r->nbf; i++)
        {
            int h = rechercheHauteur(r->fils[i]);
            if (h > m) { m = h; }
        }
        return 1 + m;
    }
    return 0;
}

void afficherNiveau(noeudMult *r, int p)
{
    if (r != nullptr)
    {
        if (p == 0) { cout << r->v << " "; return; }
        for (int i = 0; i < r->nbf; i++) { afficherNiveau(r->fils[i], p-1); }
    }
}

void afficherLargeur2(noeudMult *r)
{
    for (int i = 0; i <= rechercheHauteur(r); i++)
    {
        afficherNiveau(r, i);
        cout << endl;
    }
}

int main()
{
    cout << "Creation de l'arbre n-aires :" << endl;
    noeudMult *a1 = createArbreNAire();
    cout << "Affichage en profondeur de l'arbre : ";
    afficherProfondeur(a1); cout << endl;
    cout << "Affichage en largeur de l'arbre : " << endl;
    afficherLargeur(a1); cout << endl;
    cout << "Affichage de la hauteur de l'arbre : " << rechercheHauteur(a1) << endl;

    cout << "Affichage des noeuds de profondeur 0 : ";
    afficherNiveau(a1, 0); cout << endl;
    cout << "Affichage des noeuds de profondeur 1 : ";
    afficherNiveau(a1, 1); cout << endl;
    cout << "Affichage des noeuds de profondeur 2 : ";
    afficherNiveau(a1, 2); cout << endl;
    cout << "Affichage des noeuds de profondeur 3 : ";
    afficherNiveau(a1, 3); cout << endl;
    cout << "Affichage des noeuds de profondeur 4 : ";
    afficherNiveau(a1, 4); cout << endl;

    cout << "Affichage en largeur 2 : " << endl;
    afficherLargeur2(a1);

    system("pause");
    return 0;
}
*/