#include <iostream>
#include <numeric>
#include <random>
#include <algorithm>

using namespace std;

/**
 * \brief Structure d'un noeud d'un arbre binaire de recherche
 * \param valeur Valeur du noeud (int) (0 par defaut)
 * \param gauche Fils gauche du noeud (noeudABR*) (nullptr par defaut)
 * \param droit Fils droit du noeud (noeudABR*) (nullptr par defaut)
 * \param parent Parent du noeud (noeudABR*) (nullptr par defaut)
 */
struct noeudABR { int valeur = 0; noeudABR *gauche = nullptr; noeudABR *droit = nullptr; noeudABR *parent = nullptr; };

/**
 * \brief Fonction pour creer un arbre binaire de recherche
 * \param n Noeud a creer (noeudABR*)
 * \param p Parent du noeud a creer (noeudABR*)
 * \return Noeud cree (noeudABR*)
 */
noeudABR* createUser(noeudABR* n = nullptr, noeudABR* p = nullptr)
{
    if (n == nullptr) { n = new noeudABR; }
    cout << "Valeur du noeud : "; cin >> n->valeur;
    n->parent = p;

    // Fils gauche
    cout << "Noeud gauche de " << n->valeur << " ? (o/n) "; char c; cin >> c;
    n->gauche = nullptr; if (c == 'o') { n->gauche = createUser(n->gauche, n); }

    // Fils droit
    cout << "Noeud droit de " << n->valeur << " ? (o/n) "; cin >> c;
    n->droit = nullptr; if (c == 'o') { n->droit = createUser(n->droit, n); }

    return n;
}

/**
 * \brief Fonction pour afficher un arbre binaire de recherche
 * \param n Racine de l'arbre binaire de recherche (noeudABR*)
 */
void printABR(noeudABR* n)
{
    if (n != nullptr)
    {
        printABR(n->gauche);
        cout << n->valeur << " ";
        printABR(n->droit);
    }
}

/**
 * \brief Fonction pour trouver un noeud de valeur v dans un arbre binaire de recherche
 * \param v Valeur du noeud a trouver (int)
 * \param n Racine de l'arbre binaire de recherche (noeudABR*)
 * \return Noeud de valeur v (noeudABR*)
 */
noeudABR* noeudValue(int v, noeudABR* n)
{
    if (n == nullptr) { return nullptr; }
    if (n->valeur == v) { return n; }
    if (n->valeur > v) { return noeudValue(v, n->gauche); }
    return noeudValue(v, n->droit);
}

/**
 * \brief Fonction pour trouver le noeud de valeur min d'un arbre binaire de recherche
 * \param n Racine de l'arbre binaire de recherche (noeudABR*)
 * \return Noeud de valeur min (noeudABR*)
 */
noeudABR* noeudMin(noeudABR* n)
{
    if (n == nullptr) { return nullptr; }
    if (n->gauche == nullptr) { return n; }
    return noeudMin(n->gauche);
}

/**
 * \brief Fonction pour trouver le noeud de valeur max d'un arbre binaire de recherche
 * \param n Racine de l'arbre binaire de recherche (noeudABR*)
 * \return Noeud de valeur max (noeudABR*)
 */
noeudABR* noeudMax(noeudABR* n)
{
    if (n == nullptr) { return nullptr; }
    if (n->droit == nullptr) { return n; }
    return noeudMax(n->droit);
}

/**
 * \brief Fonction pour trouver le noeud predecesseur d'un noeud
 * \param n Noeud dont on veut trouver le predecesseur (noeudABR*)
 * \return Noeud predecesseur (noeudABR*)
 */
noeudABR* noeudPredecesseur(noeudABR* n)
{
    if (n == nullptr) { return nullptr; }
    if (n->gauche != nullptr) { return noeudMax(n->gauche); }
    noeudABR* p = n->parent;
    while (p != nullptr && n == p->gauche)
    {
        n = p;
        p = p->parent;
    }
    return p;
}

/**
 * \brief Fonction pour trouver le noeud successeur d'un noeud
 * \param n Noeud dont on veut trouver le successeur (noeudABR*)
 * \return Noeud successeur (noeudABR*)
 */
noeudABR* noeudSuccesseur(noeudABR* n)
{
    if (n == nullptr) { return nullptr; }
    if (n->droit != nullptr) { return noeudMin(n->droit); }
    noeudABR* p = n->parent;
    while (p != nullptr && n == p->droit)
    {
        n = p;
        p = p->parent;
    }
    return p;
}

/**
 * \brief Fonction pour inserer un noeud dans un arbre binaire de recherche
 * \param v Valeur du noeud a inserer (int)
 * \param n Racine de l'arbre binaire de recherche (noeudABR*)
 * \return Racine de l'arbre binaire de recherche (noeudABR*)
 */
noeudABR* noeudInsertionIterative(int v, noeudABR* n)
{
    noeudABR* p = nullptr;
    noeudABR* x = n;
    while (x != nullptr)
    {
        p = x;
        if (v < x->valeur) { x = x->gauche; }
        else { x = x->droit; }
    }
    noeudABR* z = new noeudABR;
    z->valeur = v;
    z->parent = p;
    if (p == nullptr) { n = z; }
    else if (v < p->valeur) { p->gauche = z; }
    else { p->droit = z; }
    return n;
}

/**
 * \brief Fonction pour inserer un noeud dans un arbre binaire de recherche
 * \param v Valeur du noeud a inserer (int)
 * \param n Racine de l'arbre binaire de recherche (noeudABR*)
 * \return Racine de l'arbre binaire de recherche (noeudABR*)
 */
noeudABR* noeudInsertionRecursive(int v, noeudABR* n)
{
    if (n == nullptr)
    {
        noeudABR* z = new noeudABR;
        z->valeur = v;
        return z;
    }
    if (v < n->valeur) { n->gauche = noeudInsertionRecursive(v, n->gauche); }
    else { n->droit = noeudInsertionRecursive(v, n->droit); }
    return n;
}

/**
 * \brief Fonction pour supprimer un noeud d'un arbre binaire de recherche
 * \param r Racine de l'arbre binaire de recherche (noeudABR**)
 * \param n Noeud a supprimer (noeudABR*)
 * \return true si le noeud a ete supprime, false sinon (bool)
 */
bool supprimer(noeudABR** r, noeudABR* n)
{
    noeudABR *p, *noeud;
    if (n == nullptr) { return false; }
    if (n->gauche == nullptr || n->droit == nullptr) { noeud = n; }
    else { noeud = noeudSuccesseur(n); n->valeur = noeud->valeur; }
    if (noeud->gauche == nullptr) { p = noeud->droit; }
    else { p = noeud->gauche; }
    if (p != nullptr) { p->parent = noeud->parent; }
    if (noeud->parent == nullptr) { *r = p; }
    else if (noeud == noeud->parent->droit) { noeud->parent->droit = p; }
    else { noeud->parent->gauche = p; }
    delete noeud;
    return true;
}

/**
 * \brief Fonction pour creer un arbre binaire de recherche a partir d'un tableau
 * \param arr Tableau d'entiers (int*)
 * \param size Taille du tableau (int)
 * \return Racine de l'arbre binaire de recherche (noeudABR*)
 */
noeudABR* createABRFromArr(int* arr, int size)
{
    noeudABR* n = nullptr;
    for (int i = 0; i < size; i++) { n = noeudInsertionIterative(arr[i], n); }
    return n;
}

int* createArrFromABR(noeudABR* n, int* size = nullptr)
{
    int* arr = new int[1];
    *size = 0;
    noeudABR* p = noeudMin(n);
    while (p != nullptr)
    {
        arr[*size] = p->valeur;
        (*size)++;
        int* tmp = new int[*size + 1];
        for (int i = 0; i < *size; i++) { tmp[i] = arr[i]; }
        delete[] arr;
        arr = tmp;
        p = noeudSuccesseur(p);
    }
    return arr;
}

/**
 * \brief Fonction pour trier un tableau avec un arbre binaire de recherche
 * \param arr Tableau d'entiers (int*)
 * \param size Taille du tableau (int)
 * \param returnSortList Definit si la fonction doit retourner le tableau trié (bool)
 * \param sortList Pointeur vers le tableau trié, peut etre nullptr si returnSortList est false (int**)
 * \return Racine de l'arbre binaire de recherche (noeudABR*)
 */
noeudABR* triAvecABR(int* arr, int size, bool returnSortList = false, int** sortList = nullptr)
{
    noeudABR* r = createABRFromArr(arr, size);
    if (returnSortList) { *sortList = createArrFromABR(r, &size); }
    return r;
}

/**
 * \brief Fonction pour creer un arbre binaire de recherche equilibre a partir d'un tableau
 * \param arr Tableau d'entiers (pas necessairement trié) (int*)
 * \param size Taille du tableau (int)
 * \param arrayIsSortList Si le tableau est deja trié, il est possible de ne pas le re-trier en passant ce parametre a true (bool)
 * \return Racine de l'arbre binaire de recherche equilibre (noeudABR*)
 */
noeudABR* createABREquilibre(int* arr, int size, bool arrayIsSortList = false)
{
    if (!arrayIsSortList) { triAvecABR(arr, size, true, &arr); }
    noeudABR* r = nullptr;
    if (size > 0)
    {
        int mid = size / 2;
        r = new noeudABR;
        r->valeur = arr[mid];
        r->gauche = createABREquilibre(arr, mid, true);
        r->droit = createABREquilibre(arr + mid + 1, size - mid - 1, true);
    }
    return r;
}

/**
 * \brief Fonction pour generer un nombre aleatoire entre a et b
 * \param a Min (int)
 * \param b Max (int)
 * \return Nombre aleatoire (int)
 */
int random(const int a, const int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

/**
 * \brief Fonction pour calculer la hauteur d'un arbre binaire de recherche
 * \param n Racine de l'arbre binaire de recherche (noeudABR*)
 * \return Hauteur de l'arbre binaire de recherche (int)
 */
int hauteur(noeudABR* n)
{
    if (n == nullptr) { return 0; }
    return 1 + max(hauteur(n->gauche), hauteur(n->droit));
}

/**
 * \brief Fonction pour afficher les statistiques d'une serie de temps (min, max, moyenne, ecart type, median, quartiles inferieur et superieur, liste des temps)
 * \param serie Liste des temps (double*)
 * \param size Taille de la liste des temps (int)
 */
void printStatSerie(double* serie, int size)
{
    double sum = 0; for (int i = 0; i < size; i++) { sum += serie[i]; }
    double avg = sum / size;
    cout << "\t\tTemps minimum : " << *min_element(serie, serie + size) << endl;
    cout << "\t\tTemps maximum : " << *max_element(serie, serie + size) << endl;
    cout << "\t\tTemps moyen : " << avg << endl;
    cout << "\t\tEcart type : " << sqrt(accumulate(serie, serie + size, 0.0, [avg](double a, double b) { return a + (b - avg) * (b - avg); }) / size) << endl;
    cout << "\t\tTemps median : " << serie[size / 2] << endl;
    cout << "\t\tTemps quartile inferieur : " << serie[size / 4] << endl;
    cout << "\t\tTemps quartile superieur : " << serie[3 * size / 4] << endl;
    cout << "\t\tTemps total : " << sum << endl;
    cout << "\t\tListe des temps : "; for (int i = 0; i < size; i++) { cout << serie[i] << " "; } cout << endl << endl;
}

/**
 * \brief Fonction pour comparer la vitesse de tri d'un tableau avec un ABR et la methode classique de c++ (sort)
 * \param size Taille du tableau (int)
 * \param nbIter Nombre d'iterations (int)
 */
void compareSortSpeed(int size = 100000, int nbIter = 10)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++) { arr[i] = random(0, size); }
    int* arr2 = new int[size];
    for (int i = 0; i < size; i++) { arr2[i] = arr[i]; }
    cout << "Tri d'un tableau de " << size << " elements aleatoires" << endl;

    // Tri avec ABR
    double* times = new double[nbIter];
    for (int i = 0; i < nbIter; i++)
    {
        // Comme la liste n'est pas triée "sur place", on peut utiliser le meme tableau pour chaque iteration
        clock_t start = clock();
        triAvecABR(arr, size);
        clock_t end = clock();
        double time = double(end - start) / CLOCKS_PER_SEC;
        times[i] = time;
    }
    cout << "\tStatistiques de tri avec un ABR sur " << nbIter << " iterations de " << size << " elements aleatoires :" << endl;
    printStatSerie(times, nbIter);

    // Tri avec sort
    times = new double[nbIter];
    for (int i = 0; i < nbIter; i++)
    {
        // Comme le tableau est deja trié, on ne peut pas utiliser le meme tableau pour chaque iteration
        int* arr3 = new int[size]; for (int j = 0; j < size; j++) { arr3[j] = arr2[j]; }
        clock_t start = clock();
        sort(arr3, arr3 + size);
        clock_t end = clock();
        double time = double(end - start) / CLOCKS_PER_SEC;
        times[i] = time;
    }
    cout << "\tStatistiques de tri avec sort sur " << nbIter << " iterations de " << size << " elements aleatoires :" << endl;
    printStatSerie(times, nbIter);

    // Tri avec qsort
    times = new double[nbIter];
    for (int i = 0; i < nbIter; i++)
    {
        // Comme le tableau est deja trié, on ne peut pas utiliser le meme tableau pour chaque iteration
        int* arr3 = new int[size]; for (int j = 0; j < size; j++) { arr3[j] = arr2[j]; }
        clock_t start = clock();
        qsort(arr3, size, sizeof(int), [](const void* a, const void* b) { return (*(int*)a - *(int*)b); });
        clock_t end = clock();
        double time = double(end - start) / CLOCKS_PER_SEC;
        times[i] = time;
    }
    cout << "\tStatistiques de tri avec qsort sur " << nbIter << " iterations de " << size << " elements aleatoires :" << endl;
    printStatSerie(times, nbIter);
}

int main()
{
    // Chaine de creation de l'arbre utilisée pour les tests = 4o2o1nno3nno6o5nno7nn
    cout << "Creation par utilisateur d'un ABR" << endl;
    noeudABR* racine = createUser(); cout << endl;
    
    cout << "\tParcours infixe de l'ABR : "; printABR(racine); cout << endl << endl;

    cout << "\tRecherche de noeuds" << endl;
    cout << "\t\tNoeud de valeur 5 : " << noeudValue(5, racine)->valeur << endl;
    cout << "\t\tNoeud de valeur min : " << noeudMin(racine)->valeur << endl;
    cout << "\t\tNoeud de valeur max : " << noeudMax(racine)->valeur << endl;
    cout << "\t\tNoeud predecesseur de 5 : " << noeudPredecesseur(noeudValue(5, racine))->valeur << endl;
    cout << "\t\tNoeud successeur de 5 : " << noeudSuccesseur(noeudValue(5, racine))->valeur << endl;
    cout << endl;

    // Creation d'une liste de 500 elements aleatoires
    cout << "Creation d'un ABR a partir d'un tableau" << endl;
    int* arr = new int[500];
    for (int i = 0; i < 500; i++) { arr[i] = random(0, 1000); }
    noeudABR* racine2 = createABRFromArr(arr, 500);

    cout << "\tParcours infixe de l'ABR : "; printABR(racine2); cout << endl << endl;

    cout << "\tRecherche de noeuds" << endl;
    cout << "\t\tY a-t-il un noeud de valeur 5 ? " << (noeudValue(5, racine2) != nullptr ? "oui" : "non") << endl;
    cout << "\t\tY a-t-il un noeud de valeur 500 ? " << (noeudValue(500, racine2) != nullptr ? "oui" : "non") << endl;
    cout << "\t\tNoeud de valeur min : " << noeudMin(racine2)->valeur << endl;
    cout << "\t\tNoeud de valeur max : " << noeudMax(racine2)->valeur << endl;
    cout << "\t\tNoeud predecesseur de " << racine2->valeur << " : " << noeudPredecesseur(racine2)->valeur << endl;
    cout << "\t\tNoeud successeur de " << racine2->valeur << " : " << noeudSuccesseur(racine2)->valeur << endl;
    cout << endl;

    cout << "Insertion et suppression de noeuds" << endl;

    cout << "\tInsertion de 5 (iterative)" << endl; noeudInsertionIterative(5, racine2);
    cout << "\t\tParcours infixe de l'ABR : "; printABR(racine2); cout << endl << endl;
    cout << "\tInsertion de 5 (recursive)" << endl; noeudInsertionRecursive(5, racine2);
    cout << "\t\tParcours infixe de l'ABR : "; printABR(racine2); cout << endl << endl;

    cout << "\tSuppression de 5" << endl; supprimer(&racine2, noeudValue(5, racine2));
    cout << "\t\tParcours infixe de l'ABR : "; printABR(racine2); cout << endl << endl;
    cout << "\tSuppression d'un noeud non existant (-1)" << endl; supprimer(&racine2, noeudValue(-1, racine2));
    cout << "\t\tParcours infixe de l'ABR : "; printABR(racine2); cout << endl << endl;
    cout << "\tSuppression de la racine (" << racine2->valeur << ")" << endl; supprimer(&racine2, racine2);
    cout << "\t\tParcours infixe de l'ABR : "; printABR(racine2); cout << endl << endl;

    cout << "Creation d'une liste a partir d'un ABR" << endl;
    int size = 0;
    int* arr2 = createArrFromABR(racine2, &size);
    for (int i = 0; i < size; i++) { cout << arr2[i] << " "; }

    cout << endl << endl << "Tri d'un tableau avec un ABR" << endl;
    int arr3[] = { 4, 2, 1, 3, 6, 5, 7 };
    int* arr4 = nullptr;
    noeudABR* racine3 = triAvecABR(arr3, 7, true, &arr4);
    for (int i = 0; i < 7; i++) { cout << arr4[i] << " "; } cout << endl;
    printABR(racine3); cout << endl;

    cout << endl << endl << "Creation d'un ABR equilibre a partir du tableau de 500 elements" << endl;
    noeudABR* racine4 = createABREquilibre(arr, 500, false);
    printABR(racine4); cout << endl;
    cout << "Si l'arbre est equilibre, la hauteur de l'arbre est de " << 1 + log2(500) << endl;
    cout << "La hauteur de l'arbre est de " << hauteur(racine4) << endl;

    //cout << endl << endl << "Comparaison de la vitesse de tri d'un tableau avec un ABR, sort et qsort" << endl;
    //compareSortSpeed(10000000, 1);
    
    return 0;
}

/*
Test de la rapidité des tris :
Matériel utilisé : AMD Ryzen 9 5900X 12-Core Processor, 3.70 GHz ; 32 Go de RAM DDR4 3200 MHz ; Windows 11 Famille 64 bits

Tri d'un tableau de 10000 elements aleatoires
        Statistiques de tri avec un ABR sur 50 iterations de 10000 elements aleatoires :
                Temps minimum : 0.002
                Temps maximum : 0.003
                Temps moyen : 0.0021
                Ecart type : 0.0003
                Temps median : 0.002
                Temps quartile inferieur : 0.002
                Temps quartile superieur : 0.002
                Temps total : 0.105
                Liste des temps : 0.002 0.003 0.002 0.002 0.002 0.002 0.002 0.002 0.003 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.003 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.003 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.003

        Statistiques de tri avec sort sur 50 iterations de 10000 elements aleatoires :
                Temps minimum : 0.002
                Temps maximum : 0.003
                Temps moyen : 0.00254
                Ecart type : 0.000498397
                Temps median : 0.003
                Temps quartile inferieur : 0.003
                Temps quartile superieur : 0.003
                Temps total : 0.127
                Liste des temps : 0.003 0.003 0.002 0.003 0.002 0.003 0.003 0.002 0.003 0.002 0.003 0.002 0.003 0.003 0.002 0.003 0.002 0.003 0.002 0.002 0.003 0.002 0.003 0.002 0.003 0.003 0.002 0.003 0.002 0.003 0.002 0.002 0.003 0.002 0.003 0.002 0.003 0.003 0.002 0.003 0.002 0.003 0.003 0.002 0.003 0.002 0.003 0.002 0.002 0.003

        Statistiques de tri avec qsort sur 50 iterations de 10000 elements aleatoires :
                Temps minimum : 0.001
                Temps maximum : 0.002
                Temps moyen : 0.00182
                Ecart type : 0.000384187
                Temps median : 0.001
                Temps quartile inferieur : 0.002
                Temps quartile superieur : 0.002
                Temps total : 0.091
                Liste des temps : 0.001 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.001 0.001 0.002 0.002 0.002 0.002 0.002 0.002 0.001 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.001 0.002 0.002 0.002 0.002 0.002 0.002 0.001 0.001 0.002 0.002 0.002 0.002 0.002 0.002 0.001 0.002 0.002 0.002 0.002 0.002 0.002 0.002 0.001 0.002


Tri d'un tableau de 100000 elements aleatoires
        Statistiques de tri avec un ABR sur 50 iterations de 100000 elements aleatoires :
                Temps minimum : 0.028
                Temps maximum : 0.036
                Temps moyen : 0.0299
                Ecart type : 0.0013
                Temps median : 0.03
                Temps quartile inferieur : 0.029
                Temps quartile superieur : 0.03
                Temps total : 1.495
                Liste des temps : 0.036 0.032 0.032 0.032 0.032 0.031 0.029 0.029 0.029 0.029 0.029 0.028 0.029 0.029 0.03 0.03 0.03 0.03 0.03 0.029 0.031 0.03 0.03 0.03 0.03 0.03 0.03 0.03 0.031 0.03 0.03 0.029 0.028 0.029 0.029 0.03 0.028 0.03 0.028 0.03 0.03 0.03 0.03 0.03 0.029 0.03 0.03 0.03 0.029 0.029

        Statistiques de tri avec sort sur 50 iterations de 100000 elements aleatoires :
                Temps minimum : 0.032
                Temps maximum : 0.034
                Temps moyen : 0.03268
                Ecart type : 0.000507543
                Temps median : 0.033
                Temps quartile inferieur : 0.033
                Temps quartile superieur : 0.032
                Temps total : 1.634
                Liste des temps : 0.033 0.033 0.032 0.033 0.032 0.032 0.032 0.033 0.033 0.033 0.032 0.032 0.033 0.033 0.033 0.033 0.033 0.034 0.033 0.032 0.032 0.033 0.033 0.033 0.033 0.033 0.032 0.033 0.033 0.032 0.032 0.033 0.033 0.033 0.032 0.032 0.032 0.032 0.032 0.032 0.033 0.033 0.033 0.033 0.033 0.033 0.033 0.033 0.033 0.033

        Statistiques de tri avec qsort sur 50 iterations de 100000 elements aleatoires :
                Temps minimum : 0.021
                Temps maximum : 0.023
                Temps moyen : 0.02234
                Ecart type : 0.000551725
                Temps median : 0.022
                Temps quartile inferieur : 0.022
                Temps quartile superieur : 0.021
                Temps total : 1.117
                Liste des temps : 0.021 0.022 0.022 0.022 0.022 0.023 0.022 0.023 0.022 0.023 0.022 0.023 0.022 0.023 0.022 0.023 0.023 0.022 0.023 0.023 0.023 0.023 0.022 0.022 0.023 0.022 0.022 0.023 0.022 0.023 0.022 0.022 0.023 0.022 0.022 0.023 0.022 0.021 0.022 0.022 0.022 0.022 0.022 0.022 0.023 0.022 0.023 0.022 0.023 0.022


Tri d'un tableau de 1000000 elements aleatoires
        Statistiques de tri avec un ABR sur 25 iterations de 1000000 elements aleatoires :
                Temps minimum : 0.651
                Temps maximum : 0.706
                Temps moyen : 0.6716
                Ecart type : 0.0142969
                Temps median : 0.674
                Temps quartile inferieur : 0.664
                Temps quartile superieur : 0.655
                Temps total : 16.79
                Liste des temps : 0.676 0.66 0.668 0.671 0.701 0.656 0.664 0.659 0.653 0.651 0.682 0.667 0.674 0.702 0.679 0.675 0.676 0.675 0.655 0.659 0.677 0.669 0.706 0.666 0.669

        Statistiques de tri avec sort sur 25 iterations de 1000000 elements aleatoires :
                Temps minimum : 0.394
                Temps maximum : 0.398
                Temps moyen : 0.39536
                Ecart type : 0.000741889
                Temps median : 0.394
                Temps quartile inferieur : 0.395
                Temps quartile superieur : 0.396
                Temps total : 9.884
                Liste des temps : 0.396 0.396 0.395 0.395 0.395 0.395 0.395 0.395 0.395 0.395 0.395 0.395 0.394 0.395 0.396 0.396 0.396 0.395 0.396 0.398 0.395 0.396 0.395 0.395 0.395

        Statistiques de tri avec qsort sur 25 iterations de 1000000 elements aleatoires :
                Temps minimum : 0.254
                Temps maximum : 0.266
                Temps moyen : 0.26252
                Ecart type : 0.00467436
                Temps median : 0.265
                Temps quartile inferieur : 0.265
                Temps quartile superieur : 0.266
                Temps total : 6.563
                Liste des temps : 0.256 0.254 0.254 0.254 0.254 0.265 0.265 0.254 0.266 0.265 0.266 0.265 0.265 0.265 0.266 0.265 0.265 0.265 0.266 0.266 0.265 0.265 0.265 0.265 0.262


Tri d'un tableau de 10000000 elements aleatoires
        Statistiques de tri avec un ABR sur 1 iterations de 10000000 elements aleatoires :
                Temps minimum : 12.319
                Temps maximum : 12.319
                Temps moyen : 12.319
                Ecart type : 0
                Temps median : 12.319
                Temps quartile inferieur : 12.319
                Temps quartile superieur : 12.319
                Temps total : 12.319
                Liste des temps : 12.319

        Statistiques de tri avec sort sur 1 iterations de 10000000 elements aleatoires :
                Temps minimum : 4.65
                Temps maximum : 4.65
                Temps moyen : 4.65
                Ecart type : 0
                Temps median : 4.65
                Temps quartile inferieur : 4.65
                Temps quartile superieur : 4.65
                Temps total : 4.65
                Liste des temps : 4.65

        Statistiques de tri avec qsort sur 1 iterations de 10000000 elements aleatoires :
                Temps minimum : 2.931
                Temps maximum : 2.931
                Temps moyen : 2.931
                Ecart type : 0
                Temps median : 2.931
                Temps quartile inferieur : 2.931
                Temps quartile superieur : 2.931
                Temps total : 2.931
                Liste des temps : 2.931

Grâce a ces test, on peut voir que le tri par ABR est plus rapide que le tri basique de c++ (sort) sur un nombre d'elements relativement faible (jusqu'a 10 000 elements), mais que le tri basique de c++ est plus rapide que le tri par ABR sur un nombre d'elements plus important (a partir de 100 000 elements).
Le quicksort est quand a lui plus rapide que les deux autres methodes, et ce, quelque soit le nombre d'elements.
Cepandant, le coût memoire et la stabilité de ces methodes sont a prendre en compte lors d'anaylse plus approfondies pour determiner si une methode est meilleure qu'une autre.
*/