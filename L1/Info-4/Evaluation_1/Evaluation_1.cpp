#include <iostream>
using namespace std;

bool verifProduit(int tableau[][])
{
    int produit_precedant;

    for (int i = 0; i < le
    {
        int produit;
        for (int j = 0; j < tableau[i].lenght(); j++)
        {
            produit *= tableau[i][j];
        }

        if (produit != produit_precedant and i != 0)
        {
            return false;
        }

        produit_precedant = produit;
    }
	
    return true;
}
