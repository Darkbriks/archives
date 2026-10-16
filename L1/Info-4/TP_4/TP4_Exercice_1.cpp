#include <iostream>
#include <string>

using namespace std;

void saisir_point(float *x, float *y)
{
    cout << "Abscisse : ";
    cin >> *x;

    cout << "Ordonnee : ";
    cin >> *y;
}

void saisir_delta(float *d_x, float *d_y)
{
    cout << "Delta x : ";
    cin >> *d_x;

    cout << "Delta y : ";
    cin >> *d_y;
}

void saisir_point_msg(float *x, float *y, string msg_x, string msg_y)
{
    cout << msg_x;
    cin >> *x;

    cout << msg_y;
    cin >> *y;
}

void translater(float *x, float *y, float *delta_x, float *delta_y)
{
    *x += *delta_x;
    *y += *delta_y;
}

void afficher_point(float x, float y)
{
    cout << "(" << x << ", " << y << ")" << endl;
}

/*int main()
{
    float x = 0, y = 0, d_x = 0, d_y = 0;
    
    // Saisie d'un point
    saisir_point_msg(&x, &y, "Abscisse : ", "Ordonnee : ");

    // Saisie d'une translation
    saisir_point_msg(&d_x, &d_y, "Delta x : ", "Delta y : ");

    // Affiche le point
    afficher_point(x, y);

    // Translation
    translater(&x, &y, &d_x, &d_y);

    // Affiche le point
    afficher_point(x, y);

    system("pause");
    
    return 0;
}*/
