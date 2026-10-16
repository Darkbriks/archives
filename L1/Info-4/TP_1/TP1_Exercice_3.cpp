#include <iostream>
using namespace std;

const int nb_vendeurs = 5, nb_modeles = 4;
int prix[nb_modeles] = {1000, 2000, 3000, 4000};

void saisir_tableau_ventes(int tableau_ventes[nb_vendeurs][nb_modeles])
{
    for (int i = 0; i < nb_vendeurs; i+=1)
    {
        cout << "Entrez les ventes du vendeur " << i + 1 << " dans l'ordre des modeles, separees par des espaces: ";
        for (int j = 0; j < nb_modeles; j+=1)
        {
            cin >> tableau_ventes[i][j];
        }
    }
}

int calculer_nb_modele_vendu(const int tableau_ventes[nb_vendeurs][nb_modeles], const int modele)
{
    int nb_modele_vendu = 0;
    for (int i = 0; i < nb_vendeurs; i+=1)
    {
        nb_modele_vendu += tableau_ventes[i][modele];
    }
    return nb_modele_vendu;
}

void afficher_nb_modeles_vendus(const int tableau_ventes[nb_vendeurs][nb_modeles])
{
    for (int i = 0; i < nb_modeles; i+=1)
    {
        cout << "Modele no " << i + 1 << " : " << calculer_nb_modele_vendu(tableau_ventes, i) << endl;
    }
}

int calculer_nb_modele_vendu_par_vendeur(const int tableau_ventes[nb_vendeurs][nb_modeles], const int vendeur)
{
    int nb_modele_vendu = 0;
    for (int i = 0; i < nb_modeles; i+=1)
    {
        nb_modele_vendu += tableau_ventes[vendeur][i];
    }
    return nb_modele_vendu;
}

int calculer_chiffre_affaire_par_vendeur(const int tableau_ventes[nb_vendeurs][nb_modeles], const int vendeur)
{
    int chiffre_affaire = 0;
    for (int i = 0; i < nb_modeles; i+=1)
    {
        chiffre_affaire += tableau_ventes[vendeur][i] * prix[i];
    }
    return chiffre_affaire;
}

void afficher_chiffre_affaire_vendeurs(const int tableau_ventes[nb_vendeurs][nb_modeles])
{
    for (int i = 0; i < nb_vendeurs; i+=1)
    {
        cout << "Le vendeur " << i + 1 << " a vendu " << calculer_nb_modele_vendu_par_vendeur(tableau_ventes, i) << " voitures pour un chiffre d'affaire de : " << calculer_chiffre_affaire_par_vendeur(tableau_ventes, i) << " euros" << endl;
    }
}

int main()
{
    int tableau_ventes[nb_vendeurs][nb_modeles];
    char retour;

    //saisir les ventes
    saisir_tableau_ventes(tableau_ventes);

    //afficher le nombre de modeles vendus
    afficher_nb_modeles_vendus(tableau_ventes);

    //afficher le chiffre d'affaire par vendeur
    afficher_chiffre_affaire_vendeurs(tableau_ventes);

    //attendre un input pour fermer le programme
    cout << "Appuyez sur une touche pour fermer le programme...";
    cin >> retour;
    
    return 0;
}
