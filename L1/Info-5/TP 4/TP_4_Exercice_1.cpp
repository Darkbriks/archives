#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

#pragma region Modelisation des points et segments
struct point {float x=0, y=0;};
struct segment {point debut, fin;};

void affiche_point(const point p) {cout << p.x << "," << p.y;}

void affiche_segment(const segment s) {affiche_point(s.debut); cout << ","; affiche_point(s.fin); cout << endl;}

float calcule_longueur(const segment s)
{return static_cast<float>(sqrt(pow(s.fin.x - s.debut.x, 2) + pow(s.fin.y - s.debut.y, 2)));}

float calcule_angle(const segment s, const float epsilon)
{
    if (abs(s.debut.x - s.fin.x) <= epsilon)
    {
        if (s.fin.x > s.debut.x) {return static_cast<float>(M_PI_2);}
        return static_cast<float>(-M_PI_2);
    }
    else
    {
        if (s.fin.x > s.debut.x)
        {return atan((s.fin.y - s.debut.y) / (s.fin.x - s.debut.x));}
        return static_cast<float>(atan((s.fin.y - s.debut.y) / (s.fin.x - s.debut.x)) + M_PI);
    }
}

point avance_point(const point p, const float d, const float alpha)
{point b; b.x = p.x + d * cos(alpha); b.y = p.y + d * sin(alpha); return b;}
#pragma endregion

#pragma region Modelisation des ensembles de segments
struct maillon {segment s; maillon *next;};

void ajoute_segment_liste(maillon **tete, const segment s)
{maillon *m = new maillon; m->s = s; m->next = *tete; *tete = m;}

void affiche_liste(maillon *tete)
{
    if (tete->next != nullptr)
    {
        affiche_liste(tete->next);
        affiche_segment(tete->s);
    }
    else {affiche_segment(tete->s);}
}
#pragma endregion

#pragma region Calcul de la fractale
void init_triangle_koch(maillon **tete, const float l)
{
    point p1, p2, p3; segment s1, s2, s3; p1.x = 0; p1.y = 0;
    p2 = avance_point(p1, l, static_cast<float>(M_PI/3));
    p3 = avance_point(p1, l, static_cast<float>(2*M_PI/3));
    s1.debut = p1; s1.fin = p2;
    s2.debut = p2; s2.fin = p3;
    s3.debut = p3; s3.fin = p1;
    ajoute_segment_liste(tete, s1);
    ajoute_segment_liste(tete, s2);
    ajoute_segment_liste(tete, s3);
}

void developpe_segment_koch(maillon **tete, maillon **m)
{
    // Calcule des points
    point p1, p2, p3, p4; segment s1, s2, s3;
    float distance = calcule_longueur((*tete)->s)/3;
    float alpha = calcule_angle((*tete)->s, FLT_EPSILON);
    float alpha1 = alpha - M_PI/3; float alpha2 = alpha1 + 2*M_PI/3;
    p1 = avance_point((*tete)->s.debut, distance, alpha);
    p2 = avance_point(p1, distance, alpha1);
    p3 = avance_point(p2, distance, alpha2);

    // Ajout des maillons
    maillon *m1 = new maillon, *m2 = new maillon, *m3 = new maillon;
    m1->next = m2; m1->s.debut = (*tete)->s.debut; m1->s.fin = p1;
    m2->next = m3; m2->s.debut = p1; m2->s.fin = p2;
    m3->next = (*tete)->next; m3->s.debut = p2; m3->s.fin = p3;
    (*tete)->s.debut = p3;
    (*tete)->next = m1;
    m = &m3->next;
}

void calcule_koch(maillon **tete, const int n)
{
    if (n == 0) {return;}
    maillon *m = *tete;
    while (m != nullptr) {developpe_segment_koch(&m, &m);}
    calcule_koch(tete, n-1);
}
#pragma endregion

int main()
{
    maillon *tete = nullptr;
    init_triangle_koch(&tete, 2.0);
    //calcule_koch(&tete, 5);
    affiche_liste(tete);

    system("pause");
    
    return 0;
}