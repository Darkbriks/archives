bool existeBlanc(MatriceAdjacence mat, Couleur *coul);
int sommetBlancMin(MatriceAdjacence mat, Couleur *coul, int *dist);
bool isNeighbour(MatriceAdjacence mat, int sommet, int i);
int getNeighbourWeight(MatriceAdjacence mat, int sommet, int i);
void algo_dijkstra(MatriceAdjacence mat, int sommetDepart, Couleur *coul, int *dist, int *parent);
void afficherCheminVers_Dijkstra(int sf, int *parent);