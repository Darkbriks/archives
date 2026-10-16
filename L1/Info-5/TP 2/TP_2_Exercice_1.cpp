#include <iostream>
#include <fstream>

using namespace std;

struct Case {int lig = 0, col = 0;};
struct element {Case coord = {0,0}; element *prec = nullptr, *suiv = nullptr;};
struct labyrinthe {int taille = 0; bool *grille = nullptr;};

labyrinthe load_lab(string const t)
{
    ifstream fic(t);
    labyrinthe l;
    if (fic) {
        fic >> l.taille;
        l.grille = new bool[l.taille*l.taille];
        int i=0;
        while (!fic.eof() && i<l.taille) {//tant qu'on acquière des lignes...
            for (int j=0;j<l.taille;j++) {fic >> l.grille[i*l.taille+j];}
            i++;
        }
    }
    else {cout << "ERREUR : impossible d'ouvrir le fichier" << endl;}
    fic.close();
    return l;
}

void affiche_lab(const labyrinthe lab)
{
    for (int i=0;i<lab.taille;i++) {
        for (int j=0;j<lab.taille;j++) {cout << lab.grille[i*lab.taille+j] << " ";}
        cout << endl;}
}

void init_tab_inverse(labyrinthe lab_init, labyrinthe *lab_res)
{
    lab_res->taille = lab_init.taille;
    lab_res->grille = new bool[lab_init.taille * lab_init.taille];
    for (int i = 0; i < lab_init.taille * lab_init.taille; i++)
    {lab_res->grille[i] = (lab_init.grille[i] - 1) * (lab_init.grille[i] - 1);}
}

bool create_first(element **tete, Case start_coord, labyrinthe *lab)
{
    if (lab->grille[start_coord.lig * lab->taille + start_coord.col] == false)
    {
        *tete = new element;
        (*tete)->coord = start_coord;
        (*tete)->prec = nullptr; (*tete)->suiv = nullptr;
        return true;
    }
    return false;
}

bool recherche_4_voisin(Case *last_coord, labyrinthe *lab_res)
{
    for (int i = 0; i < 4; i++)
    {
        if (last_coord->lig + (i == 0) - (i == 2) >= 0 && last_coord->lig + (i == 0) - (i == 2) < lab_res->taille && last_coord->col + (i == 1) - (i == 3) >= 0 && last_coord->col + (i == 1) - (i == 3) < lab_res->taille)
        {
            if (lab_res->grille[(last_coord->lig + (i == 0) - (i == 2)) * lab_res->taille + (last_coord->col + (i == 1) - (i == 3))] == false)
            {
                last_coord->lig += (i == 0) - (i == 2); last_coord->col += (i == 1) - (i == 3);
                lab_res->grille[(last_coord->lig + (i == 0) - (i == 2)) * lab_res->taille + (last_coord->col + (i == 1) - (i == 3))] = true;
                return true;
            }
        }
    }
    return false;
}

bool construit_est(element *dern_list, labyrinthe *lab_res)
{
    if (dern_list->coord.col == lab_res->taille - 1) {return true;}

    Case last_coord = dern_list->coord;
    if (recherche_4_voisin(&last_coord, lab_res))
    {
        dern_list->suiv = new element; dern_list->suiv->prec = dern_list; dern_list->suiv->suiv = nullptr;
        dern_list->suiv->coord = last_coord;
        return construit_est(dern_list->suiv, lab_res);
    }

    else if (dern_list->prec != nullptr)
    {
        dern_list->prec->suiv = nullptr;
        element *temp = dern_list; dern_list = dern_list->prec;
        delete temp;
        return construit_est(dern_list, lab_res);
    }

    else {return false;}
}

int create_chemin_est(element **elt, Case start_coord, labyrinthe lab_init, labyrinthe lab_res)
{
    init_tab_inverse(lab_init, &lab_res);
    if (!create_first(elt, start_coord, &lab_res)) {return -1;}
    lab_res.grille[start_coord.lig * lab_res.taille + start_coord.col] = true;
    return construit_est(*elt, &lab_res);
}

void print_liste(element *tete)
{
    element *elt = tete;
    cout << "Le chemin de "<< "(" << elt->coord.lig << ", " << elt->coord.col << ")" << " vers l'EST est :" << endl;
    while (elt->suiv != nullptr)
    {
        cout << "(" << elt->coord.lig << ", " << elt->coord.col << ")";
        if (elt->suiv->suiv != nullptr) {cout << " -> ";}
        elt = elt->suiv;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    if (argc==0) return EXIT_FAILURE;
    labyrinthe lab = load_lab((string const)argv[1]); labyrinthe lab_res;
    element *tete = nullptr; Case start_coord; int res;

    cout << "Coordonee de depart, separee par un espace : "; cin >> start_coord.lig; cin >> start_coord.col;
    res = create_chemin_est(&tete, start_coord, lab, lab_res);

    while (res == -1)
    {
        cout << "Cette case est un mur, veuillez en donner une nouvelle.";
        cout << "Coordonee de depart, separee par un espace : ";
        cin >> start_coord.lig; cin >> start_coord.col;
        res = create_chemin_est(&tete, start_coord, lab, lab_res);
    }
    if (res == 1) {affiche_lab(lab); print_liste(tete);}
    else {cout << "Il n'existe pas de chemin en partant de cette case.";}
    
    
    system("pause");
    
    return 0;
}