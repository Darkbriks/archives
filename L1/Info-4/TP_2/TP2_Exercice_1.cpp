#include <iostream>

using namespace std;

const int TAILLE = 9;

struct Deplacement
{
    int ligne;
    int colonne;
    char type_deplacement;
    char sens_deplacement;
};

int bool_to_int(const bool _bool)
{
    if (_bool)
    {
        return 1;
    }
    return 0;
}

void init_grille(int grille[TAILLE][TAILLE])
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            grille[i][j] = -1;
        }
    }
}

void remplir_grille(int grille[TAILLE][TAILLE])
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (i < 3 or i > 5)
            {
                if (2 < j and j < 6)
                {
                    grille[i][j] = 1;
                }
            }
            else
            {
                grille[i][j] = 1;
            }
        }
    }
    grille[4][4] = 0;
}

void afficher_grille(int grille[TAILLE][TAILLE])
{
    cout << "  1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < TAILLE; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == -1)
            {
                cout << "." << " ";
            }
            else if (grille[i][j] == 1)
            {
                cout << grille[i][j] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int nb_pions(int grille[TAILLE][TAILLE])
{
    int nb = 0;
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == 1)
            {
                nb++;
            }
        }
    }
    return nb;
}

bool est_prise_horizontal_droite(int grille[TAILLE][TAILLE], const int x, const int y)
{
    if (x + 1 < 8 and grille[y][x] == 1 and grille[y][x + 1] == 1 and grille[y][x + 2] == 0)
    {
        return true;
    }
    return false;
}

bool est_prise_horizontal_gauche(int grille[TAILLE][TAILLE], const int x, const int y)
{
    if (x - 2 >= 0 and grille[y][x] == 1 and grille[y][x - 1] == 1 and grille[y][x - 2] == 0)
    {
        return true;
    }
    return false;
}

bool est_prise_vertical_haut(int grille[TAILLE][TAILLE], const int x, const int y)
{
    if (x - 2 >= 0 and grille[y][x] == 1 and grille[y - 1][x] == 1 and grille[y - 2][x] == 0)
    {
        return true;
    }
    return false;
}

bool est_prise_vertical_bas(int grille[TAILLE][TAILLE], const int x, const int y)
{
    if (y + 1 < 8 and grille[y][x] == 1 and grille[y + 1][x] == 1 and grille[y + 2][x] == 0)
    {
        return true;
    }
    return false;
}

bool est_prise(int grille[TAILLE][TAILLE], Deplacement deplacement)
{
    if (deplacement.type_deplacement == 'H')
    {
        if (deplacement.sens_deplacement == 'D')
        {
            return est_prise_horizontal_droite(grille, deplacement.colonne, deplacement.ligne);
        }
        return est_prise_horizontal_gauche(grille, deplacement.colonne, deplacement.ligne);
    }
    if (deplacement.sens_deplacement == 'H')
    {
        return est_prise_vertical_haut(grille, deplacement.colonne, deplacement.ligne);
    }
    return est_prise_vertical_bas(grille, deplacement.colonne, deplacement.ligne);
}

void prise_horizontal_droite(int grille[TAILLE][TAILLE], const int x, const int y)
{
    grille[y][x] = 0;
    grille[y][x + 1] = 0;
    grille[y][x + 2] = 1;
}

void prise_horizontal_gauche(int grille[TAILLE][TAILLE], const int x, const int y)
{
    grille[y][x] = 0;
    grille[y][x - 1] = 0;
    grille[y][x - 2] = 1;
}

void prise_vertical_haut(int grille[TAILLE][TAILLE], const int x, const int y)
{
    grille[y][x] = 0;
    grille[y - 1][x] = 0;
    grille[y - 2][x] = 1;
}

void prise_vertical_bas(int grille[TAILLE][TAILLE], const int x, const int y)
{
    grille[y][x] = 0;
    grille[y + 1][x] = 0;
    grille[y + 2][x] = 1;
}

int nb_coups(int grille[TAILLE][TAILLE], const int x, const int y)
{
    int nb = 0;
    nb += bool_to_int(est_prise_horizontal_droite(grille, x, y));
    nb += bool_to_int(est_prise_horizontal_gauche(grille, x, y));
    nb += bool_to_int(est_prise_vertical_bas(grille, x, y));
    nb += bool_to_int(est_prise_vertical_haut(grille, x, y));
    return nb;
}

int nb_coups_total(int grille[TAILLE][TAILLE])
{
    int nb = 0;
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == 1)
            {
                nb += nb_coups(grille, j, i);
            }
        }
    }
    return nb;
}

void jouer_coup(int grille[TAILLE][TAILLE], Deplacement deplacement)
{
    if (deplacement.type_deplacement == 'H')
    {
        if (deplacement.sens_deplacement == 'D')
        {
            return prise_horizontal_droite(grille, deplacement.colonne, deplacement.ligne);
        }
        return prise_horizontal_gauche(grille, deplacement.colonne, deplacement.ligne);
    }
    if (deplacement.sens_deplacement == 'H')
    {
        return prise_vertical_haut(grille, deplacement.colonne, deplacement.ligne);
    }
    return prise_vertical_bas(grille, deplacement.colonne, deplacement.ligne);
}

Deplacement saisir_deplacement(int grille[TAILLE][TAILLE])
{
    Deplacement d;

    while (true)
    {
        cout << "Entrez la ligne : " << endl;
        cin >> d.ligne;
        cout << "Entrez la colonne : " << endl;
        cin >> d.colonne;

        d.ligne--;
        d.colonne--;
        
        if (nb_coups(grille, d.colonne, d.ligne) < 1)
        {
            cout << "Erreur : ligne ou colonne invalide." << endl;
            continue;
        }
        cout << "Entrez le type de deplacement (H pour horizontal, V pour vertical) : " << endl;
        cin >> d.type_deplacement;
        cout << "Entrez le sens de deplacement (D pour droite, G pour gauche, H pour haut, B pour bas) : " << endl;
        cin >> d.sens_deplacement;

        d.type_deplacement = toupper(d.type_deplacement);
        d.sens_deplacement = toupper(d.sens_deplacement);

        if (d.type_deplacement == 'H')
        {
            if (d.sens_deplacement == 'D' and est_prise_horizontal_droite(grille, d.colonne, d.ligne) == true)
            {
                break;
            }
            if (d.sens_deplacement == 'G' and est_prise_horizontal_gauche(grille, d.colonne, d.ligne) == true)
            {
                break;
            }
        }
        else
        {
            if (d.sens_deplacement == 'H' and est_prise_vertical_haut(grille, d.colonne, d.ligne) == true)
            {
                break;
            }
            if (d.sens_deplacement == 'B' and est_prise_vertical_bas(grille, d.colonne, d.ligne) == true)
            {
                break;
            }
        }
        cout << "Ce coup n'est pas valide, veuillez recommencer." << endl;
    }
    return d;
}

int est_gagnante(int grille[TAILLE][TAILLE])
{
    if (nb_pions(grille) == 1)
    {
        return 1;
    }
    if (nb_coups_total(grille) == 0)
    {
        return -1;
    }
    return 0;
}

void jouer(int grille[TAILLE][TAILLE])
{
    init_grille(grille);
    remplir_grille(grille);
    
    while (true)
    {
        afficher_grille(grille);
        cout << "Il y a " << nb_pions(grille) << " pions sur la grille et il reste " << nb_coups_total(grille) << " coups possibles." << endl;
        Deplacement d = saisir_deplacement(grille);
        jouer_coup(grille, d);
        cout << endl;
        if (est_gagnante(grille) == 1)
        {
            cout << "Vous avez gagne !" << endl;
            break;
        }
        if (est_gagnante(grille) == -1)
        {
            cout << "Vous avez perdu !" << endl;
            break;
        }
    }
}

/*int main()
{
    int grille[TAILLE][TAILLE];
    jouer(grille);

    char temp;
    cin >> temp;
    
    return 0;
}*/