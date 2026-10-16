#include <iostream>
#include <random>

using namespace std;

struct puissance4
{
    int grille[6][7] = {}, max[2] = {};
    char type_joueur[2] = {};
    char joueur1 = 'X', joueur2 = 'O';
};

int aleatoire(const int min, const int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(min, max);
    return dist(rng);
}

puissance4 init_jeu()
{
    puissance4 p4;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            p4.grille[i][j] = -1;
        }
    }
    p4.max[0] = 0;
    p4.max[1] = 0;

    cout << "Saisir le type du joueur 1 (H pour Humain, O pour Ordinateur) : ";
    cin >> p4.type_joueur[0];
    p4.type_joueur[0] = toupper(p4.type_joueur[0]);
    cout << "Saisir le type du joueur 2 (H pour Humain, O pour Ordinateur) : ";
    cin >> p4.type_joueur[1];
    p4.type_joueur[1] = toupper(p4.type_joueur[1]);

    cout << "Voulez-vous changer les symboles par defaut (X et O) des joueurs ? (O/N) : ";
    char reponse;
    cin >> reponse;
    reponse = toupper(reponse);
    if (reponse == 'O')
    {
        cout << "Saisir le symbole du joueur 1 : ";
        cin >> p4.joueur1;
        cout << "Saisir le symbole du joueur 2 : ";
        cin >> p4.joueur2;
    }
    
    return p4;
}

void affiche_grille(const puissance4 p4)
{
    cout << "  1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << " ";
        
        for (int j = 0; j < 7; j++)
        {
            if (p4.grille[i][j] == -1) {cout << "  ";}
            else if (p4.grille[i][j] == 0) {cout << p4.joueur1 << " ";}
            else if (p4.grille[i][j] == 1) {cout << p4.joueur2 << " ";}
            else {cout << "Erreur affiche_grille() : p4.grille[" << i << "][" << j << "] doit etre -1, 0 ou 1";}
        }
        cout << endl;
    }
}

bool colone_pleine(const puissance4 p4, const int colone)
{
    if (colone < 0 or colone > 6) {cout << "Erreur colone_pleine() : colone doit etre entre 0 et 6" << endl; return true;}
    if (p4.grille[0][colone] != -1) {return true;}
    return false;
}

int saisir_colone(char type_joueur)
{
    // type_joueur = 'H' ou 'O' pour Humain ou Ordinateur
    // Si type_joueur = 'H' on demande à l'utilisateur de saisir une colone
    // Si type_joueur = 'O' on génère une colone aléatoire

    if (type_joueur == 'H')
    {
        int colone;
        cout << "Saisir une colone : ";
        cin >> colone;
        return colone;
    }
    else if (type_joueur == 'O') {return aleatoire(0, 6);}
    else {cout << "Erreur saisir_colone() : type_joueur doit etre 'H' ou 'O'" << endl; return -1;}
}

int choix_colone(const puissance4 p4, char type_joueur)
{
    // type_joueur = 'H' ou 'O' pour Humain ou Ordinateur

    int colone = saisir_colone(type_joueur);
    while (colone_pleine(p4, colone))
    {
        cout << "La colone " << colone << " est pleine, veuillez en saisir une autre" << endl;
        colone = saisir_colone(type_joueur);
    }
    return colone;
}

int ligne_nouveau_jeton(const puissance4 p4, const int colone)
{
    if (colone < 0 or colone > 6) {cout << "Erreur ligne_nouveau_jeton() : colone doit etre entre 0 et 6" << endl; return -1;}
    for (int i = 5; i >= 0; i--)
    {
        if (p4.grille[i][colone] == -1) {return i;}
    }
    return -1;
}

int pions_horisontaux(const puissance4 p4, const int ligne, const int colone, const int joueur)
{
    int pions = 0;
    for (int i = colone; i < 7; i++)
    {
        if (p4.grille[ligne][i] == joueur) {pions++;}
        else {break;}
    }
    for (int i = colone - 1; i >= 0; i--)
    {
        if (p4.grille[ligne][i] == joueur) {pions++;}
        else {break;}
    }
    return pions;
}

int pions_verticaux(const puissance4 p4, const int ligne, const int colone, const int joueur)
{
    int pions = 0;
    for (int i = ligne; i < 6; i++)
    {
        if (p4.grille[i][colone] == joueur) {pions++;}
        else {break;}
    }
    for (int i = ligne - 1; i >= 0; i--)
    {
        if (p4.grille[i][colone] == joueur) {pions++;}
        else {break;}
    }
    return pions;
}

int pions_diagonale_gauche_droite(const puissance4 p4, const int ligne, const int colone, const int joueur)
{
    int pions = 0;
    for (int i = ligne, j = colone; i < 6 and j < 7; i++, j++)
    {
        if (p4.grille[i][j] == joueur) {pions++;}
        else {break;}
    }
    for (int i = ligne - 1, j = colone - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (p4.grille[i][j] == joueur) {pions++;}
        else {break;}
    }
    return pions;
}

int pions_diagonale_droite_gauche(const puissance4 p4, const int ligne, const int colone, const int joueur)
{
    int pions = 0;
    for (int i = ligne, j = colone; i < 6 and j >= 0; i++, j--)
    {
        if (p4.grille[i][j] == joueur) {pions++;}
        else {break;}
    }
    for (int i = ligne - 1, j = colone + 1; i >= 0 and j < 7; i--, j++)
    {
        if (p4.grille[i][j] == joueur) {pions++;}
        else {break;}
    }
    return pions;
}

int mise_a_jour_jeu(puissance4 *p4, const int colone, const int ligne, const int joueur)
{
    if (colone < 0 or colone > 6) {cout << "Erreur mise_a_jour_jeu() : colone doit etre entre 0 et 6" << endl; return -1;}
    if (ligne < 0 or ligne > 5) {cout << "Erreur mise_a_jour_jeu() : ligne doit etre entre 0 et 5" << endl; return -1;}
    if (joueur < 0 or joueur > 1) {cout << "Erreur mise_a_jour_jeu() : joueur doit etre 0 ou 1" << endl; return -1;}

    (*p4).grille[ligne][colone] = joueur;
    (*p4).max[joueur] = max((*p4).max[joueur], pions_horisontaux((*p4), ligne, colone, joueur));
    (*p4).max[joueur] = max((*p4).max[joueur], pions_verticaux((*p4), ligne, colone, joueur));
    (*p4).max[joueur] = max((*p4).max[joueur], pions_diagonale_gauche_droite((*p4), ligne, colone, joueur));
    (*p4).max[joueur] = max((*p4).max[joueur], pions_diagonale_droite_gauche((*p4), ligne, colone, joueur));

    return 0;
}

int jouer(puissance4 *p4, char type_joueur, int joueur)
{
    int colone = choix_colone(*p4, type_joueur);
    int ligne = ligne_nouveau_jeton(*p4, colone);
    int erreur = mise_a_jour_jeu(p4, colone, ligne, joueur);
    if (erreur == -1) {cout << "Erreur jouer() : mise_a_jour_jeu() a echoue" << endl; return -1;}
    affiche_grille(*p4);
    return 0;
}

bool victoire(const puissance4 p4, const int joueur)
{
    if (p4.max[joueur] >= 4) {return true;}
    return false;
}

int main()
{
    puissance4 p4 = init_jeu();
    int n = 0;

    while (n < 42)
    {
        cout << endl << endl << "Tour du joueur " << n % 2 << endl;
        int erreur = jouer(&p4, p4.type_joueur[n % 2], n % 2);
        while (erreur == -1)
        {
            cout << "Erreur main() : jouer() a echoue" << endl;
            erreur = jouer(&p4, p4.type_joueur[n % 2], n % 2);
        }
        if (victoire(p4, n % 2)) {cout << "Le joueur " << n % 2 + 1 << " a gagne en " << n/2 << " coups !" << endl; break;}
        n += 1;
    }
    system("Pause");
    return 0;
}