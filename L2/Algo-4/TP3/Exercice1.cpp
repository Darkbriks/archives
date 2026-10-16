#include <iostream>
#include <string>
using namespace std;

struct noeud
{
    string nom="";
    int nbf=0;
    noeud *fils={nullptr};
};

noeud *createArbre()
{
    noeud *n = new noeud;
    cout << "Nom : "; cin >> n->nom;
    cout << "Nombre de fils de " << n->nom << " : "; cin >> n->nbf;
    n->fils = new noeud[n->nbf];

    for (int i = 0; i < n->nbf; i++) { n->fils[i] = *createArbre(); }

    return n;
}

void afficherProfondeur(noeud *r, int profondeur = 0)
{
    if (r != nullptr)
    {
        for (int i = 0; i < profondeur; i++) { cout << "\t"; }
        cout << r->nom << " a " << r->nbf << " enfants" << endl;
        for (int i = 0; i < r->nbf; i++) { afficherProfondeur(&r->fils[i], profondeur + 1); }
    }
}

noeud* rechercherParent(noeud *r, string nom)
{
    if (r != nullptr)
    {
        for (int i = 0; i < r->nbf; i++)
        {
            if (r->fils[i].nom == nom)
            {
                return r;
            }
        }
        for (int i = 0; i < r->nbf; i++)
        {
            noeud *ptr = nullptr;
            ptr = rechercherParent(&r->fils[i], nom);
            if (ptr != nullptr) { return ptr; }
        }
    }
    
    return nullptr;
}

noeud* rechercherGrandParent(noeud *r, string nom)
{
    if (r != nullptr) { return rechercherParent(r, rechercherParent(r, nom)->nom); }
    return nullptr;
}

void afficherCousins(noeud *r, string nom)
{
    noeud *gp = rechercherGrandParent(r, nom);
    noeud *p = rechercherParent(r, nom);
    if (gp != nullptr and p != nullptr)
    {
        for (int i = 0; i < gp->nbf; i++)
        {
            if (gp->fils[i].nom != p->nom)
            {
                for (int j = 0; j < gp->fils[i].nbf; j++)
                {
                    cout << gp->fils[i].fils[j].nom << endl;
                }
            }
                
        }
    }
}

void afficherFreres(noeud *r, string nom)
{
    noeud *p = rechercherParent(r, nom);
    if (p != nullptr)
    {
        for (int i = 0; i < p->nbf; i++)
        {
            if (p->fils[i].nom != nom)
            {
                cout << p->fils[i].nom << endl;
            }
        }
    }
}

void rajouterEnfant(noeud *r, string nom)
{
    if (r != nullptr)
    {
        if (r->nom == nom)
        {
            noeud *new_fils = createArbre();
            noeud *temp = new noeud[r->nbf];
            for (int i = 0; i < r->nbf; i++) { temp[i] = r->fils[i]; }
            r->fils = new noeud[r->nbf + 1];
            for (int i = 0; i < r->nbf; i++) { r->fils[i] = temp[i]; }
            r->fils[r->nbf] = *new_fils;
            r->nbf++;
            return;
        }
        for (int i = 0; i < r->nbf; i++) {  rajouterEnfant(&r->fils[i], nom); }
    }
}

// Recusivly create an arbre from a string array
noeud *createArbre(string L[], int n)
{
    noeud *r = new noeud;
    r->nom = L[0];
    r->nbf = stoi(L[1]);
    r->fils = new noeud[r->nbf];
    int j = 2;
    for (int i = 0; i < r->nbf; i++)
    {
        r->fils[i] = *createArbre(&L[j], n - j);
        j += 2 + r->fils[i].nbf * 2;
    }
    return r;
}

int main()
{
    // fred 3 yannis 2 toto 1 titi 1 tutu 0 tata 0 sami 0 noe 1 jaber 0
    string L1[] = { "fred", "3", "yannis", "2", "toto", "1", "titi", "1", "tutu", "0", "tata", "0", "sami", "0", "noe", "1", "jaber", "0" };
    
    string L2[] = {"PhilippeIV", "7",
"LouisX", "2", "JeanneII", "8", "Jeanne", "0", "Marie", "4", "ConstanceDAragon", "0", "JeanneDAragon", "0",
"MarieDAragon", "0", "PierreDAragon", "0", "BlancheDeNavarre", "0", "CharlesII", "8", "CharlesIII", "0", "Philippe",
"0", "Marie", "0", "Pierre", "0", "Isabelle", "0", "Blanche", "0", "Jeanne", "0", "Bonne", "0", "AgnesDeNavarre", "1",
"GastonDeFoix", "0", "PhilippeDeNavarre", "2", "LancelotBatard", "0", "RobineBatarde", "0", "Jeanne", "1", "CharlesDeRohan", "0", "LouisDeNavarre", "3", "CharlesDeBeaumont", "0", "TristanDeBeaumont", "0", "JeanneDeBeaumont",
"0", "JeanIer", "0",
"MargueriteDeFrance", "0",
"BlancheDeFrance", "0",
"Isabelle", "4", "EdouardIII", "12", "EdouardDeWoodstock", "0", "Isabelle", "0", "Jeanne", "0", "William", "0",
"LionelDAnvers", "0", "JeanDeGand", "0", "EdmondDeLanley", "0", "BlancheDeLaTourDeLondres", "0", "MarieDAngleterre", "0", "Marguerite", "0", "ThomasDeWindsor", "0", "GuillaumeDeWindsor", "0", "ThomasDeWoodstock", "1",
"JeanDEltham", "0", "AlienorDeWoodstock", "2", "RenaudIII", "0", "Edouard", "0", "JeanneDeLaTour", "0",
"PhilippeV", "5", "JeanneIII", "1", "PhilippeMonsieur", "0", "MargueriteI", "1", "LouisIIDeFlandres", "0", "Isabelle",
"0", "Blanche", "0", "Philippe", "0",
"CharlesIV", "3", "Jeanne", "0", "Marie", "0", "Blanche", "0",
"RobertDeFrance", "0" };
    
    cout << "Creation de l'arbre :" << endl;
    noeud *a1 = createArbre(L1, 9);
    afficherProfondeur(a1);

    // Cousins
    cout << "Affichage des cousins de jaber (toto et tata) :" << endl;
    afficherCousins(a1, "jaber");
    cout << "Affichage des cousins de sami (aucun) :" << endl;
    afficherCousins(a1, "sami");
    cout << "Affichage des cousins de tyty (n'existe pas) :" << endl;
    afficherCousins(a1, "tyty");

    // Freres
    cout << "Affichage des freres de toto (tata) :" << endl;
    afficherFreres(a1, "toto");
    cout << "Affichage des freres de jaber (aucun) :" << endl;
    afficherFreres(a1, "jaber");
    cout << "Affichage des freres de tyty (n'existe pas) :" << endl;
    afficherFreres(a1, "tyty");

    // Parent
    cout << "Affichage du parent de tutu (titi) :" << endl;
    cout << rechercherParent(a1, "tutu")->nom << endl;
    cout << "Affichage du parent de fred (aucun) :" << endl;
    cout << rechercherParent(a1, "fred")->nom << endl;
    cout << "Affichage du parent de tyty (n'existe pas) :" << endl;
    cout << rechercherParent(a1, "tyty")->nom << endl;

    // Grand parent
    cout << "Affichage du grand parent de tutu (toto) :" << endl;
    cout << rechercherGrandParent(a1, "tutu")->nom << endl;
    cout << "Affichage du grand parent de yannis (aucun) :" << endl;
    cout << rechercherGrandParent(a1, "yannis")->nom << endl;
    cout << "Affichage du grand parent de tyty (n'existe pas) :" << endl;
    cout << rechercherGrandParent(a1, "tyty")->nom << endl;

    // Rajouter enfant
    cout << "Rajout d'enfant a tyty (n'existe pas) :" << endl;
    rajouterEnfant(a1, "tyty");
    afficherProfondeur(a1);
    cout << "Rajout d'enfant a tutu :" << endl;
    rajouterEnfant(a1, "tutu");
    afficherProfondeur(a1);
    system("pause");


    cout << "Creation de l'arbre de Philippe le Bel :" << endl;
    noeud *a2 = createArbre(L2, 66);
    afficherProfondeur(a2);
    system("pause");
}