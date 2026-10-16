 #include <iostream>
#include <random>

using namespace std;

struct eleve
{
    string nom, prenom;
    int annee_naissance;
    char sexe;
    float moyenne[5];
};

struct classe
{
    eleve eleves[25] = {};
    int nb_eleves = 0;
};

eleve saisir_eleve()
{
    // Saisir les informations d'un eleve
    eleve eleve;
    cout << "Nom : ";
    cin >> eleve.nom;
    cout << "Prenom : ";
    cin >> eleve.prenom;
    cout << "Annee de naissance : ";
    cin >> eleve.annee_naissance;
    cout << "Sexe (M/F) : ";
    cin >> eleve.sexe;
    // Remplir le tableau des moyennes avec des valeurs aleatoires
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(0, 20);
    for (int i = 0; i < 5; i++)
    {
        eleve.moyenne[i] = static_cast<float>(dist(rng));
    }
    return eleve;
}

int calculer_age(const eleve eleve)
{
    // Calculer l'age d'un eleve
    return 2023 - eleve.annee_naissance;
}

void afficher_eleve(const eleve eleve)
{
    // Afficher les informations d'un eleve
    cout << "Nom : " << eleve.nom << endl;
    cout << "Prenom : " << eleve.prenom << endl;
    cout << "Annee de naissance : " << eleve.annee_naissance << endl;
    cout << "Age : " << calculer_age(eleve) << endl;
    cout << "Sexe : " << eleve.sexe << endl;
    cout << "Moyennes : ";
    for (int i = 0; i < 5; i++)
    {
        cout << eleve.moyenne[i] << " ";
    }
}

classe saisir_classe(const int n)
{
    // Saisir les informations d'une classe
    classe classe;
    classe.nb_eleves = n;
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Eleve " << i+1 << endl;
            classe.eleves[i] = saisir_eleve();
            cout << endl;
        }
    }
    return classe;
}

void afficher_classe(const classe c)
{
    // Afficher les informations d'une classe
    for (int i = 0; i < c.nb_eleves; i++)
    {
        cout << "Eleve " << i+1 << endl;
        afficher_eleve(c.eleves[i]);
        cout << endl;
    }
}

bool existe_eleve(const classe c,const string nom, const string prenom)
{
    // Verifier si un eleve existe dans une classe
    for (int i = 0; i < c.nb_eleves; i++)
    {
        if (c.eleves[i].nom == nom and c.eleves[i].prenom == prenom)
        {
            return true;
        }
    }
    return false;
}

int indice_eleve(const classe c,const string nom, const string prenom)
{
    // Retourner l'indice d'un eleve dans une classe (-1 si l'eleve n'existe pas)
    for (int i = 0; i < c.nb_eleves; i++)
    {
        if (c.eleves[i].nom == nom and c.eleves[i].prenom == prenom)
        {
            return i + 1;
        }
    }
    return -1;
}

classe ajouter_eleve(classe c)
{
    // Ajouter un eleve a la classe si elle n'est pas pleine et que l'eleve n'est pas deja dans la classe
    if (c.nb_eleves != 25)
    {
        eleve e = saisir_eleve();

        if (existe_eleve(c, e.nom, e.prenom))
        {
            cout << "Cet eleve existe deja dans cette classe." << endl;
            return c;
        }
        c.eleves[c.nb_eleves] = e;
        c.nb_eleves += 1;
    }
    else
    {
        cout << "Cette classe a deja ateint sont effectif maximum. Reessayer avec une autre classe" << endl;
    }
    return c;
}



classe supprimer_eleve(classe c)
{
    // Supprimer un eleve de la classe si elle n'est pas vide et que l'eleve est dans la classe
    if (c.nb_eleves != 0)
    {
        string nom, prenom;
        cout << "Nom de l'eleve a supprimer : ";
        cin >> nom;
        cout << "Prenom de l'eleve a supprimer : ";
        cin >> prenom;

        if (existe_eleve(c, nom, prenom))
        {
            int indice = indice_eleve(c, nom, prenom);
            for (int i = indice; i < c.nb_eleves; i++)
            {
                c.eleves[i-1] = c.eleves[i];
            }
            c.nb_eleves -= 1;
        }
        else
        {
            cout << "Cet eleve n'existe pas dans cette classe." << endl;
        }
    }
    else
    {
        cout << "Cette classe est vide. Reessayer avec une autre classe" << endl;
    }
    return c;
}

int compter_nb(const classe c, const char s)
{
    // Compter le nombre d'eleves de sexe s dans la classe c
    int nb = 0;
    for (int i = 0; i < c.nb_eleves; i++)
    {
        if (c.eleves[i].sexe == s)
        {
            nb += 1;
        }
    }
    return nb;
}

float calculer_moyenn_eleve(const eleve e)
{
    // Calculer la moyenne d'un eleve
    float moyenne = 0;
    for (int i = 0; i < 5; i++)
    {
        moyenne += e.moyenne[i];
    }
    return moyenne / 5;
}

float calculer_moyenne_UE(const classe c, const int ue)
{
    // Calculer la moyenne de l'UE ue dans la classe c
    float moyenne = 0;
    for (int i = 0; i < c.nb_eleves; i++)
    {
        moyenne += c.eleves[i].moyenne[ue-1];
    }
    return moyenne / static_cast<float>(c.nb_eleves);
}

float calculer_moyenne_classe(const classe c)
{
    // Calculer la moyenne de la classe c
    float moyenne = 0;
    for (int i = 1; i < 6; i++)
    {
        moyenne += calculer_moyenne_UE(c, i);
    }
    return moyenne / 5;
}

int main()
{
    // Saisie du nombre d'eleve
    int nb_eleves;
    cout << "Combien d'eleves compte cette classe : ";
    cin >> nb_eleves;

    // Saisie des eleves
    cout << endl << "Saisir les eleves de la classe : " << endl;
    classe classe = saisir_classe(nb_eleves);

    // Afficher la classe
    cout << endl << "Affichage de la classe : " << endl;
    afficher_classe(classe);

    // Ajouter un eleve
    cout << endl << "Ajout d'un eleve : " << endl;
    classe = ajouter_eleve(classe);

    // Supprimer eleve
    cout << endl << "Supression d'un eleve : " << endl;
    classe = supprimer_eleve(classe);

    // Afficher la classe
    cout << endl << "Affichage de la classe pour verification : " << endl;
    afficher_classe(classe);

    // Calculer et afficher le nombre de filles et de garcons dans la classe
    cout << endl << "Calcule du nombre de personnes de chaque genre dans la classe : " << endl;
    cout << "Il y a " << compter_nb(classe, 'F') << " filles et " << compter_nb(classe, 'M') << " garcons dans cette classe." << endl;

    // Calcul de la moyenne de la classe
    cout << endl << "Calcule de la moyenne de la classe : " << endl;
    cout << "La moyenne de la classe est " << calculer_moyenne_classe(classe) << endl;
    
    // Attente de la saisie d'une touche pour fermer la console
    system("pause");
    return 0;
}