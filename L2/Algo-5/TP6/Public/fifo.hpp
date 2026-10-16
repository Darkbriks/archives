
/* fonctions de gestion d'une fifo contenant des nombres entiers >= 0 */
void initialiserFifo(Fifo &file);
bool estVide(Fifo file);
void ajouter(Fifo &file, int v);
int retirer(Fifo &file);
