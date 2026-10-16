#include <random>
#include <iostream>

using namespace std;

int aleatoire(const int n1, const int n2)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(n1, n2);

    return dist(rng);
}

int saisir_nb_lettres()
{
    cout << "Nombre de lettres (entre 1 et 10) : ";
    int nb;
    cin >> nb;
    if (nb <= 10 and nb >= 1)
    {
        return nb;
    }
    cout << "Erreur ! ";
    return saisir_nb_lettres();
}

char saisir_char_max(const char char_min)
{
    cout << "Caractere maximum : ";
    char char_max;
    cin >> char_max;
    if (char_max >= char_min)
    {
        return char_max;
    }
    cout << "Erreur ! ";
    return saisir_char_max(char_min);
}

string init_chaine(const int nb_lettres, const char char_min, const char char_max)
{
    if (nb_lettres == 0)
    {
        return "";
    }
    return static_cast<char>(aleatoire(char_min, char_max)) + init_chaine(nb_lettres - 1, char_min, char_max);
}

string verif_chaine(const int nb_lettres, string chaine_ref, string chaine)
{
    if (nb_lettres == 1)
    {
        if (chaine == chaine_ref)
        {
            return chaine_ref;
        }
        return "*";
    }
    if (chaine[0] == chaine_ref[0])
    {
        return chaine_ref[0] + verif_chaine(nb_lettres - 1, chaine_ref.substr(1, nb_lettres - 1), chaine.substr(1, nb_lettres - 1));
    }
    return "*" + verif_chaine(nb_lettres - 1, chaine_ref.substr(1, nb_lettres - 1), chaine.substr(1, nb_lettres - 1));
}

void afficher(const int nb_lettres, string chaine)
{
    if (nb_lettres == 1)
    {
        cout << chaine + " :";
    }
    else
    {
        cout << chaine[0] << " ";
        afficher(nb_lettres - 1, chaine.substr(1, nb_lettres - 1));
    }
}

string saisir(const int nb_lettres)
{
    string tmp;
    if (nb_lettres == 1)
    {
        cin >> tmp;
        return tmp;
    }
    cin >> tmp;
    return tmp + saisir(nb_lettres - 1);
}

bool est_gagne(const int nb_lettres, string chaine_ref, string chaine)
{
    if (nb_lettres == 1)
    {
        if (chaine_ref == chaine)
        {
            return true;
        }
        return false;
    }
    if (chaine[0] == chaine_ref[0])
    {
        return est_gagne(nb_lettres - 1, chaine_ref.substr(1, nb_lettres - 1), chaine.substr(1, nb_lettres - 1));
    }
    return false;
}

void jouer()
{
    // Initialisation
    const int nb_lettres = saisir_nb_lettres();
    char char_min = ' ';
    cout << "Quel est le plus petit caractere autorise : ";
    cin >> char_min;
    const char char_max = saisir_char_max(char_min);
    int nb_essai_max;
    cout << "Combien d'essai maximum voulez vous faire (si vous souhaiter un nombre illimité d'essai, mettez 0) : ";
    cin >> nb_essai_max;
    string chaine_ref = init_chaine(nb_lettres, char_min, char_max);
    string chaine = "";
    int i = 1;

    // Jeu
    cout << endl << "Debut de la partie !" << endl;

    // Tant que la chaine n'est pas la bonne et que le nombre d'essai n'est pas atteint. si le nombre d'essai est 0, alors on ne compte pas le nombre d'essai
    while (!est_gagne(nb_lettres, chaine_ref, chaine) and (i <= nb_essai_max or nb_essai_max == 0))
    {
        cout << "Essai no " << i << " : ";
        chaine = saisir(nb_lettres);
        afficher(nb_lettres, verif_chaine(nb_lettres, chaine_ref, chaine));
        cout << endl;
        i+=1;
    }
    if (chaine == chaine_ref)
    {
        cout << "Bravo, vous avez trouvez la solution !" << endl <<  endl << "Souhaitez vous rejouer ?" << "(y/n) : ";
    }
    else
    {
        cout << "Vous n'avez pas trouvez la solution. Le mot a trouver est :" << chaine_ref << endl <<  endl << "Souhaitez vous rejouer ?" << "(y/n) : ";
    }

    // Rejouer ?
    char rejouer = ' ';
    cin >> rejouer;
    if (rejouer == 'y')
    {
        cout << endl << endl<< endl; 
        jouer();
    }
}

int main()
{
    jouer();

    return 0;
}