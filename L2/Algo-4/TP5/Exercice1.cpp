#include <iostream>

using namespace std;

/**
 * \brief Structure d'un noeud d'un arbre rouge et noir
 * \param valeur Valeur du noeud (int) (0 par defaut)
 * \param gauche Fils gauche du noeud (noeudABR*) (nullptr par defaut)
 * \param droit Fils droit du noeud (noeudABR*) (nullptr par defaut)
 * \param parent Parent du noeud (noeudABR*) (nullptr par defaut)
 * \param couleur Couleur du noeud (char) (n par defaut)
 */
struct noeudARN { int valeur = 0; noeudARN *gauche = nullptr; noeudARN *droit = nullptr; noeudARN *parent = nullptr; char couleur = 'n'; };

/**
 * \brief Definition de la constante NIL
 */
noeudARN* NIL = new noeudARN;

/**
 * \brief Fonction pour creer un arbre binaire de recherche
 * \bug Always return NIL
 * \param n Noeud a creer (noeudABR*)
 * \param p Parent du noeud a creer (noeudABR*)
 * \return Noeud cree (noeudABR*)
 */
noeudARN* createUser(noeudARN* n = nullptr, noeudARN* p = NIL)
{
    if (n == nullptr) { n = new noeudARN; }
    cout << "Valeur du noeud : "; cin >> n->valeur;
    cout << "Couleur du noeud (n, r) : "; cin >> n->couleur;
    n->parent = p;

    // Fils gauche
    cout << "Noeud gauche de " << n->valeur << " ? (o/n) : "; char c; cin >> c;
    if (c == 'o') { n->gauche = new noeudARN; n->gauche = createUser(n->gauche, n); }
    else { n->gauche = NIL; }

    // Fils droit
    cout << "Noeud droit de " << n->valeur << " ? (o/n) : "; cin >> c;
    if (c == 'o') { n->droit = new noeudARN; n->droit = createUser(n->droit, n); }
    else { n->droit = NIL; }

    return n;
}

/**
 * \brief Fonction pour afficher un arbre binaire de recherche
 * @param r Racine de l'arbre (noeudABR*)
 * @param profondeur Profondeur de l'arbre (int) (0 par defaut)
 * @return None
 */
void afficherProfondeur(noeudARN *r, int profondeur = 0)
{
    if (r != NIL)
    {
        for (int i = 0; i < profondeur; i++) { cout << "\t"; }
        cout << r->valeur << " " << r->couleur << endl;
        afficherProfondeur(r->gauche, profondeur+1);
        afficherProfondeur(r->droit, profondeur+1);
    }
    else
    {
        for (int i = 0; i < profondeur; i++) { cout << "\t"; }
        cout << "NIL " << endl;
    }
}

/**
 * \brief Permet de transformer x en un fils droit de son fils initial
 * @param r Racine de l'arbre (noeudABR*)
 * @param x noeud dont on effectue la rotation de l'arbre (noeudABR*)
 * @return Racine de l'arbre modifié (noeudABR*)
 */
noeudARN* rotationDroite(noeudARN* &racine, noeudARN* x) {
    noeudARN* y = x->gauche;
    x->gauche = y->droit;

    if (y->droit != nullptr) {
        y->droit->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        racine = y;
    } else if (x == x->parent->gauche) {
        x->parent->gauche = y;
    } else {
        x->parent->droit = y;
    }

    y->droit = x;
    x->parent = y;

    return racine;
}


/**
 * \brief Permet de transformer x en un fils gauche de son fils initial
 * @param r Racine de l'arbre (noeudABR*)
 * @param x noeud dont on effectue la rotation de l'arbre (noeudABR*)
 * @return Racine de l'arbre modifié (noeudABR*)
 */
noeudARN* rotationGauche(noeudARN* &racine, noeudARN* y) {
    noeudARN* x = y->droit;
    y->droit = x->gauche;

    if (x->gauche != nullptr) {
        x->gauche->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == nullptr) {
        racine = x;
    } else if (y == y->parent->gauche) {
        y->parent->gauche = x;
    } else {
        y->parent->droit = x;
    }

    x->gauche = y;
    y->parent = x;

    return racine;
}

/**
 * \brief Fonction pour inserer un noeud dans un arbre binaire de recherche
 * \param n Noeud a inserer (noeudARN*)
 * \param r Racine de l'arbre (noeudARN*)
 * \return Racine modifié (noeudARN*)
 */
noeudARN* noeudInsertionRecursive(noeudARN* n, noeudARN* r)
{
    if (r == NIL)
    {
        n->gauche = NIL;
        n->droit = NIL;
        return n;
    }
    n->parent = r;
    if (n->valeur < r->valeur) { r->gauche = noeudInsertionRecursive(n, r->gauche); }
    else { r->droit = noeudInsertionRecursive(n, r->droit); }
    return r;
}

/**
 * \brief Permet d'inserer un noeud
 * \param r Racine de l'arbre (noeudARN**)
 * \param n Noeud a inserer (noeudARN*)
 * \return None
 */
void insertion(noeudARN **r, noeudARN *n)
{
    *r = noeudInsertionRecursive(n, *r);
    noeudARN *o;
    while (*r != n && n->parent->couleur == 'r' && n->parent->parent != nullptr)
    {
        if (n->parent == n->parent->parent->gauche)
        {
            o = n->parent->parent->droit;
            if (o->couleur == 'r') // Cas 1
            {
                n->parent->couleur = 'n';
                o->couleur = 'n';
                n->parent->parent->couleur = 'r';
                n = n->parent->parent;
            }
            else
            {
                if (n == n->parent->droit) // Cas 2 : rotation gauche(r, n->parent)
                {
                    n = n->parent;
                    *r = rotationGauche(*r, n);
                }
                // Cas 3 : rotation droite(r, n->parent->parent)
                n->parent->couleur = 'n';
                n->parent->parent->couleur = 'r';
                *r = rotationDroite(*r, n->parent->parent);
            }
        }
        else
        {
            o = n->parent->parent->gauche;
            if (o->couleur == 'r') // Cas 1
            {
                n->parent->couleur = 'n';
                o->couleur = 'n';
                n->parent->parent->couleur = 'r';
                n = n->parent->parent;
            }
            else
            {
                if (n == n->parent->gauche) // Cas 2 : rotation droite(r, n->parent)
                {
                    n = n->parent;
                    *r = rotationDroite(*r, n);
                }
                // Cas 3 : rotation gauche(r, n->parent->parent)
                n->parent->couleur = 'n';
                n->parent->parent->couleur = 'r';
                *r = rotationGauche(*r, n->parent->parent);
            }
        }
    }
    (*r)->couleur = 'n';
}

/**
 * \brief Fonction pour creer un arbre rouge et noir a k noeuds. La valeur des noeuds est definie par l'utilisateur
 * \param nb_noeud Nombre de noeuds de l'arbre (int)
 * \param r Racine de l'arbre (noeudARN*) (NIL par defaut)
 * @return
 */
void createARN(int nb_noeud, noeudARN **r = &NIL)
{
    if (*r == NIL) {
        *r = new noeudARN; cout << "Valeur de la racine : "; cin >> (*r)->valeur; (*r)->couleur = 'n';
        (*r)->gauche = NIL; (*r)->droit = NIL; (*r)->parent = NIL; }
    if (nb_noeud > 1) {
        noeudARN *n = new noeudARN;
        cout << "Valeur du noeud : "; cin >> n->valeur; n->couleur = 'r';
        n->gauche = NIL; n->droit = NIL; n->parent = NIL;
        insertion(r, n);
        createARN(nb_noeud - 1, r);
    }
}

/**
 * \brief Fonction qui ajoute NIL a un arbre rouge et noir
 * \param r Racine de l'arbre (noeudARN**)
 * @return None
 */
void ajoutNIL(noeudARN **r)
{
    if (*r != NIL || *r != nullptr)
    {
        ajoutNIL(&(*r)->gauche);
        ajoutNIL(&(*r)->droit);
    }
    else { *r = NIL; }
}

/**
 * \brief Fonction pour trouver le noeud de valeur min d'un arbre binaire de recherche
 * \param n Racine de l'arbre binaire de recherche (noeudARN*)
 * \return Noeud de valeur min (noeudARN*)
 */
noeudARN* noeudMin(noeudARN* n)
{
    if (n == NIL) { return NIL; }
    if (n->gauche == NIL) { return n; }
    return noeudMin(n->gauche);
}

/**
 * \brief Fonction pour trouver le noeud successeur d'un noeud
 * \param n Noeud dont on veut trouver le successeur (noeudARN*)
 * \return Noeud successeur (noeudARN*)
 */
noeudARN* noeudSuccesseur(noeudARN* n)
{
    if (n == NIL) { return NIL; }
    if (n->droit != NIL) { return noeudMin(n->droit); }
    noeudARN* p = n->parent;
    while (p != NIL && n == p->droit)
    {
        n = p;
        p = p->parent;
    }
    return p;
}

/**
 * \brief Fonction pour supprimer un noeud d'un arbre binaire de recherche
 * \param r Racine de l'arbre binaire de recherche (noeudARN**)
 * \param n Noeud a supprimer (noeudARN*)
 * \return Le noeud qui a ete supprime (noeudARN*)
 */
noeudARN* supprimer(noeudARN** r, noeudARN* n)
{
    noeudARN* noeudSupprimer = n;
    noeudARN *p, *noeud;
    if (n == NIL) { return NIL; }
    if (n->gauche == NIL || n->droit == NIL) { noeud = n; }
    else { noeud = noeudSuccesseur(n); n->valeur = noeud->valeur; }
    if (noeud->gauche == NIL) { p = noeud->droit; }
    else { p = noeud->gauche; }
    if (p != NIL) { p->parent = noeud->parent; }
    if (noeud->parent == NIL) { *r = p; }
    else if (noeud == noeud->parent->droit) { noeud->parent->droit = p; }
    else { noeud->parent->gauche = p; }
    return noeudSupprimer;
}

/**
 * \brief Fonction qui supprime un noeud d'un arbre rouge et noir
 * \param r Racine de l'arbre (noeudARN**)
 * \param n Noeud a supprimer (noeudARN*)
 * @return Noeud supprime (noeudARN*)
 */
noeudARN* suppression(noeudARN **r, noeudARN *n)
{
    noeudARN *n_suppr = supprimer(r, n);
    noeudARN *brother;
    if (n_suppr->couleur = 'n')
    {
        while (n_suppr != *r && n_suppr->couleur == 'n') {
            if (n_suppr == n_suppr->parent->gauche) {
                brother = n_suppr->parent->droit;
                if (brother->couleur == 'r') // Cas 1
                {
                    brother->couleur = 'n';
                    n_suppr->parent->couleur = 'r';
                    rotationGauche(*r, n_suppr->parent);
                    brother = n_suppr->parent->droit;
                }
                if (brother->gauche->couleur == 'n' && brother->droit->couleur == 'n') // Cas 2
                {
                    brother->couleur = 'r';
                    n_suppr = n_suppr->parent;
                } else {
                    if (brother->droit->couleur == 'n') // Cas 3
                    {
                        brother->gauche->couleur = 'n';
                        brother->couleur = 'r';
                        rotationDroite(*r, brother);
                        brother = n_suppr->parent->droit;
                    }
                    // Cas 4
                    brother->couleur = n_suppr->parent->couleur;
                    n_suppr->parent->couleur = 'n';
                    brother->droit->couleur = 'n';
                    rotationGauche(*r, n_suppr->parent);
                    n_suppr = *r;
                }
            } else {
                brother = n_suppr->parent->gauche;
                if (brother->couleur == 'r') // Cas 1
                {
                    brother->couleur = 'n';
                    n_suppr->parent->couleur = 'r';
                    rotationDroite(*r, n_suppr->parent);
                    brother = n_suppr->parent->gauche;
                }
                if (brother->gauche->couleur == 'n' && brother->droit->couleur == 'n') // Cas 2
                {
                    brother->couleur = 'r';
                    n_suppr = n_suppr->parent;
                }
            }
        }
        n_suppr->couleur = 'n';
    }
    return n_suppr;
}

int main()
{
    // Initialisation de NIL
    NIL->valeur = -1;

    // Test
    cout << "Creation par utilisateur d'un ABR" << endl;
    noeudARN* racine = createUser(); cout << endl;
    cout << "Impression de l'arbre" << endl; afficherProfondeur(racine); cout << endl;

    cout << "Rotation gauche du fils droit de la racine" << endl;
    cout << "Impression de l'arbre" << endl; afficherProfondeur(rotationGauche(racine, racine->droit)); cout << endl;

    cout << "Rotation droite du fils gauche de la racine" << endl;
    cout << "Impression de l'arbre" << endl; afficherProfondeur(rotationDroite(racine, racine->gauche)); cout << endl;

    cout << "Insertion du noeud 16" << endl;
    noeudARN* n = new noeudARN();
    n->valeur = 16; n->couleur = 'r';
    insertion(&racine, n);
    cout << "Impression de l'arbre" << endl; afficherProfondeur(racine); cout << endl;

    cout << "Suppression du noeud 16" << endl;
    suppression(&racine, n);
    cout << "Impression de l'arbre" << endl; afficherProfondeur(racine); cout << endl;

    cout << "Creation d'un ABR a 7 noeuds" << endl;
    noeudARN* racine2 = NIL;
    createARN(7, &racine2);
    cout << "Impression de l'arbre" << endl; afficherProfondeur(racine2); cout << endl;

    cout << endl;
    return 0;
}