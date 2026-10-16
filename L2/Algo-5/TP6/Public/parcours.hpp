
/* fonction de parcours en largeur du graphe */
void parcoursEnLargeur(MatriceAdjacence mat, int sommetDepart,
		       Couleur *coul, int *dist, int *parent);
void afficherCheminVers(int sf, int *parent);

/* fonction de parcours en profondeur du graphe */

void parcoursEnProfondeurRecursif(MatriceAdjacence m,  Couleur *coul, int *parent);
void parcoursEnProfondeurPile(MatriceAdjacence m,  Couleur *coul, int *parent);
