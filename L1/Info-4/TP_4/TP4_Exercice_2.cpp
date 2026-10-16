#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const int X = 9, Y = 9;

int alea(const int min, const int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(min, max);
    return dist(rng);
}

int deplacer(const int pos, const int sens, const int max_pos)
{
    int dep = pos + alea(1, 3) * sens;
    if (0 > dep) return 0;
    if (dep >= max_pos) return max_pos;
    return dep;
}

int sens_deplacer(const int sens, const int pos, const int max_pos)
{
    if (0 <= sens + pos and sens + pos < max_pos) return sens;
    return -sens;
}

void nouvelle_position(int *x, int *y, int *sens_x, int *sens_y, const char num, char T[X][Y])
{
    // Supression du charactere dans le tableau
    T[*x][*y] = ' ';

    // Mise a jour des positions
    *x = deplacer(*x, *sens_x, X - 1);
    *y = deplacer(*y, *sens_y, Y - 1);

    // Mise a jour des sens de deplacement
    *sens_x = sens_deplacer(*sens_x, *x, X - 1);
    *sens_y = sens_deplacer(*sens_y, *y, Y - 1);

    // Mise a jour de la grille
    T[*x][*y] = num;
}

void init_grille(char T[X][Y])
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            T[i][j] = ' ';
        }
    }

    T[alea(0, X - 1)][alea(0, Y - 1)] = 'A';
    T[alea(0, X - 1)][alea(0, Y - 1)] = 'B';
}

bool existe_a_b(char T[X][Y])
{
    bool a = false, b = false;
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (T[i][j] == 'A') a = true;
            if (T[i][j] == 'B') b = true;
            if (a and b) return true;
        }
    }
    return false;
}

int trouver_ligne(char T[X][Y], const char num)
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++) if (T[i][j] == num) return i;
    }
    return -1;
}

int trouver_colone(char T[X][Y], const int num)
{
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++) if (T[i][j] == num) return j;
    }
    return -1;
}

float calculer_distance(const int pos_a_x, const int pos_a_y, const int pos_b_x, const int pos_b_y)
{
    return static_cast<float>(sqrt(pow(pos_b_x - pos_a_x, 2) + pow(pos_b_y - pos_a_y, 2)));

}

bool est_en_collision(const int pos_a_x, const int pos_a_y, const int pos_b_x, const int pos_b_y, const int rayon_a, const int rayon_b)
{
    float distance = calculer_distance(pos_a_x, pos_a_y, pos_b_x, pos_b_y);

    if (distance < static_cast<float>(rayon_a + rayon_b)) return false;
    return true;
}

void afficher_espace(const char T[X][Y])
{
    cout << " ";
    for (int i = 0; i < X; i++) cout << " " << i + 1;
    cout << endl;

    for (int j = 0; j < Y; j++)
    {
        cout << j + 1 << " ";

        for (int i = 0; i < X; i++)
        {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
}

void afficher_info_cercle(const int pos_x, const int pos_y, const int sens_x, const int sens_y, const char num)
{
    cout << "Le cercle " << num << " de coordonee (" << pos_x + 1 << ", " << pos_y + 1 << ") a pour sens de deplacement (" << sens_x << ", " << sens_y << ")" << endl;
}

/*int main()
{
    // Initialisation grille
    char grille[X][Y];
    init_grille(grille);

    // Recuperation position initiale A et B
    int a_x = trouver_ligne(grille, 'A'), a_y = trouver_colone(grille, 'A');
    int b_x = trouver_ligne(grille, 'B'), b_y = trouver_colone(grille, 'B');

    // Initialisation du rayon de A et B
    int rayon_a = 2, rayon_b = 1;
    
    // Initialisation sens deplacement
    int sens_ligne_a = alea(0, 1) * 2 - 1, sens_colone_a = alea(0, 1) * 2 - 1;
    int sens_ligne_b = alea(0, 1) * 2 - 1, sens_colone_b = alea(0, 1) * 2 - 1;

    // Tant que A et B existent et n'entrent pas en colision
    while (existe_a_b(grille) and est_en_collision(a_x, a_y, b_x, b_y, rayon_a, rayon_b))
    {
        // Affichage position et sens
        afficher_info_cercle(a_x, a_y, sens_ligne_a, sens_colone_a, 'A');
        afficher_info_cercle(b_x, b_y, sens_ligne_b, sens_colone_b, 'B');
        
        // Affichage de la grille
        afficher_espace(grille);

        system("pause");
        
        // Mise a jour de A
        nouvelle_position(&a_x, &a_y, &sens_ligne_a, &sens_colone_a, 'A', grille);

        // Mise a jour de B
        nouvelle_position(&b_x, &b_y, &sens_ligne_b, &sens_colone_b, 'B', grille);
    }

    cout << endl << endl << "Collision : Arret du programme" << endl << endl;

    // Affichage position et sens
    afficher_info_cercle(a_x, a_y, sens_ligne_a, sens_colone_a, 'A');
    afficher_info_cercle(b_x, b_y, sens_ligne_b, sens_colone_b, 'B');

    // Affichage de la grille
    afficher_espace(grille);
    
    system("pause");
    
    return 0;
}*/