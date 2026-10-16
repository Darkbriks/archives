#include <iostream>

using  namespace std;

struct projecteur
{
    int puissance = 0;
    string couleur = "";
};

struct liste_projecteurs
{
    projecteur tab[50] = {};
    int nb_proj = 0;
};

struct sequence
{
    int num_proj = 0, attente = 0;
    float duree = 0.0, pourcentage = 0.0;
};

struct plan_de_feu
{
    sequence tab[100] = {};
    int nb_seq = 0;
};

int choix_menu()
{
    cout << endl << "Menu :" << endl << "--------------------";
    cout << endl << "\t Action 1 : Saisir/Completer les projecteurs" << endl << "\t Action 2 : Afficher les projecteurs";
    cout << endl << "\t Action 3 : Saisir/Completer les sequence d'allumage des projecteurs" << endl << "\t Action 4 : Afficher le plan de feu";
    cout << endl << "\t Action 5 : Effacer les projecteurs et le sequences" << endl << "\t Action 6 : Quitter";
    cout << endl << "--------------------" << endl << "Saisir votre choix : ";
    int action; cin >> action;
    action -= 1;
    if (action == 5) {action = -1;}
    return action;
}

void saisir_projecteur(projecteur *p)
{
    cout << endl << "\t Couleur du projecteur : "; cin >> (*p).couleur;
    cout << "\t Puissance du projecteur : "; cin >> (*p).puissance;
}

liste_projecteurs saisir_projecteurs(liste_projecteurs lp)
{
    cout << "Nombre de projecteur a saisir : "; int nb; cin >> nb;
    if (nb + lp.nb_proj >= 50) {cout << "Erreur saisir_projecteurs : Le nombre de projecteur a saisir est incorect."; return lp;}
    for (int i = lp.nb_proj; i < lp.nb_proj + nb; i++)
    {
        cout << "Projecteur " << i+1;
        saisir_projecteur(&(lp.tab[i]));
    }
    lp.nb_proj += nb;
    return lp;
}

void afficher_projecteurs(liste_projecteurs lp)
{
    cout << endl << "Affichage des projecteurs";
    for (int i = 0; i < lp.nb_proj; i++)
    {
        cout << endl << "\t Projecteur " << i+1 << " : " << lp.tab[i].puissance << " Wh, " << lp.tab[i].couleur;
    }
    cout << endl << "Total : " << lp.nb_proj << "Projecteurs";
}

void saisir_sequence(sequence *s, liste_projecteurs ls)
{
    cout << endl << "\t Numero du projecteur : "; cin >> (*s).num_proj;
    while ((*s).num_proj > ls.nb_proj + 1)
    {
        cout << "Erreur saisir_sequence : Le projecteur saisie n'existe pas. Veuillez saisir un numero de projecteur valide.";
        cout << endl << "\t Numero du projecteur : "; cin >> (*s).num_proj;
    }
    (*s).num_proj -= 1;
    cout << "\t Duree d'allumage : "; cin >> (*s).duree;
    cout << "\t Pourcentage de la puissance : "; cin >> (*s).pourcentage;
    cout << "\t Duree d'attente : "; cin >> (*s).attente;
}

plan_de_feu saisir_sequences(plan_de_feu pf, liste_projecteurs lp)
{
    cout << "Nombre de sequence a saisir : "; int nb; cin >> nb;
    if (nb + pf.nb_seq >= 100) {cout << "Erreur saisir_sequences : Le nombre de sequences a saisir est incorect."; return pf;}
    for (int i = pf.nb_seq; i < pf.nb_seq + nb; i++)
    {
        cout << "Sequence " << i+1;
        saisir_sequence(&(pf.tab[i]), lp);
    }
    pf.nb_seq += nb;
    return pf;
}

float calcul_conso_totale(plan_de_feu pf, liste_projecteurs lp)
{
    float somme = 0;
    for (int i = 0; i < pf.nb_seq; i++)
    {
        somme += pf.tab[i].duree / 3600 * static_cast<float>(lp.tab[pf.tab[i].num_proj].puissance) * pf.tab[i].pourcentage;
    }
    return somme;
}

void afficher_plan(plan_de_feu pf, liste_projecteurs lp)
{
    cout << endl << "Affichage des sequence";
    for (int i = 0; i < pf.nb_seq; i++)
    {
        cout << endl << "\t Sequence " << i+1 << " : " << "Projecteur " << pf.tab[i].num_proj << ", " << lp.tab[pf.tab[i].num_proj].puissance << "Wh x " << pf.tab[i].pourcentage;
        cout << ", " << pf.tab[i].duree << "sec, " << pf.tab[i].attente << "sec d'attente";
    }
    cout << endl << "Total : " << calcul_conso_totale(pf, lp) << "Wh";
}

/*int main()
{
    liste_projecteurs lp;
    plan_de_feu pf;

    int action = choix_menu();
    while (action != -1)
    {
        if (action == 0) {lp = saisir_projecteurs(lp);}
        else if (action == 1) {afficher_projecteurs(lp);}
        else if (action == 2) {pf = saisir_sequences(pf, lp);}
        else if (action == 3) {afficher_plan(pf, lp);}
        else if (action == 4) {lp.nb_proj = 0; pf.nb_seq = 0;}
        else {cout << "Erreur main : Action non reconnue, veuiller saisir une nouvelle action" << endl;}
        action = choix_menu();
    }

    system("Pause");
    
    return 0;
}*/
