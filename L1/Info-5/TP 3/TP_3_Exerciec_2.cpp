#include <iostream>
#include <array>
#include <string>
#include <cassert>

using namespace std;

const int NB = 128;
struct PileNombres
{
    int nombres[NB];
    int sommet;
};

/* initialise une pile */
void viderPile(PileNombres *p);

/* empiler un nombre dans la pile */
bool empiler(PileNombres * p, int num);

/*  dépiler un nombre */
bool depiler(PileNombres * p, int *num);

/* retourne vrai si la pile est vide */
bool estPileVide(PileNombres p);

/* retourne vrai si la pile est pleine */
bool estPilePleine(PileNombres p);



const int NBTERM = 256;
struct FileTermes
{
    string termes[NBTERM];
    int finDeFile;
};

void viderFile(FileTermes *f);
bool enqueue(FileTermes *f, string num);

string dequeue(FileTermes *f);

bool estFileVide(FileTermes f);

bool estFilePleine(FileTermes f);

/* une NPI comporte une liste de nombres et d'opérateurs séparés par des espaces */
void construireFile(string ch, FileTermes *f);

/* afficher liste des termes */
void afficherFile(FileTermes  f);

/* demande la saisie d'une chaine (une ligne terminée par entrée) */
void saisirChaine(string *ch);

/* afficher la chaine en mettant en évidence les espaces */
void afficherChaine(string ch);

/* extrait une sous-chaine d'une chaine à partir d'une position (indice) */
string sousChaine(string ch, int pos, bool aGauche);

int compterEspaceGauche(string ch);

int compterEspaceDroite(string ch);
/* supprime les espaces à gauche d'une chaine*/
string ltrim1(string ch);

/* supprime les espaces à gauche d'une chaine*/
string rtrim1(string ch);

string trim(string ch);


/* retourner le prochain terme d'une chaine (délimité par espace) */
string prochainTerme(string ch, int deb);

/* retourner le reste des termes d'une chaine */
string termesRestants(string ch, int deb);



/* renvoie vrai si une chaine possède des termes,
    c'est à dire si sa longueur est supérieure à 0
    (les espaces avant et après étant supprimés)*/
bool aUnTerme(string ch);



/* Les opérateurs valides */
const string MULT = "*";
const string MOD = "%";
const string DIV = "/";
const string ADD = "+";
const string SOUS = "-";

const int NBOPER = 5;
const string Operateurs[] = {MULT,DIV,ADD,SOUS, MOD};

/* retourne vrai si une chaine est un opérateur */
bool estUnOperateur(string ch);

/* indique si oui ou non un caractère est un chiffre */
bool estUnChiffre(char c);


/* convertir un caractère en nombre (en utilisant la table ascii)*/
int asciiEnNombre(char c);


/* détermine si les caractères d'une chaine correspond à un nombre entier */
bool estUnEntier(string ch);

/* convertir une chaine en nombre */
int chaineEnEntier(string ch);

/* une NPI comporte une liste de nombres et d'opérateurs séparés par des espaces */
bool estNPI(FileTermes f);

/* calculer la valeur à partir de la pile et d'un opérateur */
void calculer(PileNombres * p, string op);

/* analyse une chaine correspondant à une expression en notation polonaise inversée (notation post-fixée)*/
int evaluer(FileTermes f);




/*int main(void)
{
     return 0;
}*/


/* extrait une sous-chaine d'une chaine à partir d'une position (indice)
ou jusqu'à une certaine position */
/* pre-condition : pos >= 0 && pos <= ch.length() */
string sousChaine(string ch, int pos, bool aGauche)
{
  if ((int)(ch.length()) <= pos) return "";
    if (!aGauche) 
      return sousChaine(ch, pos+1, aGauche)+ch[(int)(ch.length())-pos-1];
    return ch[pos]+sousChaine(ch, pos+1, aGauche);
    /* itérativement
     int debut = pos;
    int fin = ch.length();
    
    if (!aGauche) {
       debut = 0;
	  fin = ch.length() - pos;
    }
    for(int i=debut; i<fin; i++)
    {
        r = r + ch[i];
    }
    return r+ch[i];*/
}