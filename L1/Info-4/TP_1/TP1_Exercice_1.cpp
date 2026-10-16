#include <iostream>
#include <random>

using namespace std;

int addition(const int a, const int b)
{
    return a + b;
}

void init_tab(const int min, const int max, const int len_tableau, int tableau[])
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(min, max);

    for (int i = 0; i < len_tableau; i+=1)
    {
        tableau[i] = dist(rng);
    }
}

int add_element_tab(const int min, const int max, const int len_tableau, int tableau[])
{
    init_tab(min, max, len_tableau, tableau);
    int somme = 0;
    for (int i = 0; i < len_tableau; i+=1)
    {
        somme = addition(somme, tableau[i]);
    }
    return somme;
}

float suite_recursive(int n)
{
    if (n == 0)
    {
        return 2.0;
    }
    if (n == 1)
    {
        return 3.0;
    }
    if (n % 2 == 0 and n >= 2)
    {
        return 3 * suite_recursive(n - 1) + suite_recursive(n - 2);
    }
    if (n % 2 != 0 and n >= 2)
    {
        return suite_recursive(n - 1) + suite_recursive(n - 2);
    }
    return 0.0;
}

/*int main()
{
    constexpr int a = 0, b = 10, x = 5, y = 16, len_tableau = 50;
    int tableau[len_tableau];
    const int somme_tab = add_element_tab(a, b, len_tableau, tableau);
    int n;
    string retour;
    
    cout << "La somme de " << x << " + " << y << " est egale a : " << addition(x, y) << endl;

    cout << "Le tableau d'entier aleatoire est : " << endl;
    for (int i = 0; i < len_tableau; i+=1)
    {
        cout << "\t" << tableau[i] << endl;
    }
    cout << "La somme des elements du tableau est : " << somme_tab << endl;

    cout << "Entrez une valeur de n :" << endl;
    cin >> n;
    cout << endl << "S(n) = " << suite_recursive(n);
    
    cin >> retour;
    
    return 0;
}*/
