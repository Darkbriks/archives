#include <iostream>
#include <cmath>

using namespace std;

struct equation2
{
    float a = 0, b = 0, c = 0;
};

struct solution_reelle
{
    float x1 = 0, x2 = 0;
};

struct complexe
{
    float re = 0, im = 0;
};

struct solution_complexe
{
    complexe c1 = complexe(), c2 = complexe();
};

equation2 saisir_equation2()
{
    equation2 equation;
    cout << "Coefficient de a : ";
    cin >> equation.a;
    while (equation.a == 0.0f)
    {
        cout << "Coefficient de a : ";
        cin >> equation.a;
    }
    cout << "Coefficient de b : ";
    cin >> equation.b;
    cout << "Coefficient de c : ";
    cin >> equation.c;
    return equation;
}

void afficher_equation2(const equation2 eq)
{
    cout << eq.a << "x^2 + " << eq.b << "x + " << eq.c << " = 0" << endl;
}

float discriminant(const equation2 eq)
{
    return static_cast<float>(pow(eq.b, 2) - 4 * eq.a * eq.c);
}

bool a_solution_reelle(const equation2 eq, const float delta)
{
    return delta >= 0;
}

solution_reelle solutions_reelles(const equation2 eq, const float delta)
{
    solution_reelle solution;
    
    if(a_solution_reelle(eq, delta))
    {
        solution.x1 = static_cast<float>((-eq.b + sqrt(delta)) / (2 * eq.a));
        solution.x2 = static_cast<float>((-eq.b - sqrt(delta)) / (2 * eq.a));
    }
    return solution;
}

solution_complexe solutions_complexe(const equation2 eq, const float delta)
{
    solution_complexe solution;
    
    if(not a_solution_reelle(eq, delta))
    {
        solution.c1.re = -eq.b / (2 * eq.a);
        solution.c1.im = static_cast<float>(sqrt(-delta) / (2 * eq.a));
        solution.c2.re = -eq.b / (2 * eq.a);
        solution.c2.im = static_cast<float>(-sqrt(-delta) / (2 * eq.a));
    }
    return solution;
}

void afficher_solution(const equation2 eq, const float delta)
{
    if(a_solution_reelle(eq, delta))
    {
        if (solutions_reelles(eq, delta).x1 == solutions_reelles(eq, delta).x2)
        {
            cout << "Racine double : " << solutions_reelles(eq, delta).x1 << endl;
        }
        else
        {
            cout << "Racine 1 : " << solutions_reelles(eq, delta).x1 << endl;
            cout << "Racine 2 : " << solutions_reelles(eq, delta).x2 << endl;
        }
    }
    else
    {
        const solution_complexe solution = solutions_complexe(eq, delta);
        cout << "Racine 1 : " << solution.c1.re << " + " << solution.c1.im << "i" << endl;
        cout << "Racine 2 : " << solution.c2.re << " + " << solution.c2.im << "i" << endl;
    }
}

/*int main()
{
    char continuer = 'y';
    
    while (continuer == 'y')
    {
        // Saisie de l'equation
        const equation2 equation = saisir_equation2();

        // Affichage de l'equation
        afficher_equation2(equation);

        // Affichage du discriminant
        float delta = discriminant(equation);
        cout << "Discriminant : " << delta << endl;

        // Affichage des solutions
        afficher_solution(equation, delta);

        // Demander a l'utilisateur si il veut continuer
        cout << "Voulez-vous continuer ? (y/n) : ";
        cin >> continuer;
        cout << endl << endl;
    }
    return 0;
}*/