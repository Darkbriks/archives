#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    float abscisse, ordonnee;
};

Point saisir_point()
{
    Point point;
    cout << "Abscisse : ";
    cin >> point.abscisse;
    cout << "Ordonnee : ";
    cin >> point.ordonnee;
    return point;
}

void afficher_point(const Point p)
{
    cout << "(" << p.abscisse << ", " << p.ordonnee << ")" << endl;
}

float calculer_distance(const Point p1, const Point p2)
{
    return static_cast<float>(sqrt(pow(p2.abscisse - p1.abscisse, 2) + pow(p2.ordonnee - p1.ordonnee, 2)));
}

bool est_triangle(const Point p1, const Point p2, const Point p3)
{
    const float a = calculer_distance(p1, p2);
    const float b = calculer_distance(p2, p3);
    const float c = calculer_distance(p3, p1);
    return a + b > c and a + c > b and b + c > a;
}

/*int main()
{
    // Saisie de 3 points
    cout << "Saisie du point A" << endl;
    const Point point_a = saisir_point();
    cout << "Saisie du point B" << endl;
    const Point point_b = saisir_point();
    cout << "Saisie du point C" << endl;
    const Point point_c = saisir_point();

    // Affichage de A
    cout << "Point A : ";
    afficher_point(point_a);

    // Affichage de la distance entre A et B
    cout << "Distance entre A et B : " << calculer_distance(point_a, point_b) << endl;

    // Verification de la possibilite de former un triangle avec A, B et C
    if (est_triangle(point_a, point_b, point_c))
    {
        cout << "Les points A, B et C peuvent former un triangle" << endl;
    }
    else
    {
        cout << "Les points A, B et C ne peuvent pas former un triangle" << endl;
    }

    // Attente de la saisie d'une touche pour fermer la console
    system("pause");
    return 0;
}*/