void parcoursEnLargeur(MatriceAdjacence mat, int sommetDepart, Couleur *coul, int *dist, int *parent);
void afficherCheminVers(int sf, int *parent);

void parcourEnProfondeurRec(MatriceAdjacence mat, int sommetDepart, Couleur *coul, int *parent);
void parcourEnProfondeurPile(MatriceAdjacence mat, int sommetDepart, Couleur *coul, int *parent);