#include <iostream>
#include <string>

using namespace std;

int arrondi_superieur(const float x)
/*
 * resoudre erreur de conversion
 * arrondi_superieur(2.000001f) = 3
 * arrondi_superieur(2.0000001f) = 2
 */
{
    if (x - static_cast<float>(static_cast<int>(x)) == 0.0)
    {
        return static_cast<int>(x);
    }
    return static_cast<int>(x) + 1;
}

int temp_de_reaction(const bool fatigue, const bool alcool)
{
    int temp = 1;
    if (fatigue)
        {temp += 1;}
    if (alcool)
        {temp = (temp + 1) * 2;}

    return temp;
}

int kmh_2_ms(const float speed_kmh)
{
    return arrondi_superieur((speed_kmh * 1000) / 3600);
}

int distance_reaction(const float speed_kmh, const bool fatigue, const bool alcool)
{
    return temp_de_reaction(fatigue, alcool) * kmh_2_ms(speed_kmh);
}

int distance_freinage(const float speed_kmh)
{
    return arrondi_superieur(pow(static_cast<float>(speed_kmh/10),2.0f));
}

int distance_totale_sec(const float speed_kmh, const bool fatigue, const bool alcool)
{
    return distance_reaction(speed_kmh, fatigue, alcool) + distance_freinage(speed_kmh);
}

int distance_totale_hum(const float speed_kmh, const bool fatigue, const bool alcool)
{
    return distance_reaction(speed_kmh, fatigue, alcool) + 2 * distance_freinage(speed_kmh);
}

int distance_etage(const float distance)
{
    return arrondi_superieur(distance/2.5f);
}

void print_entete()
{
    cout << "Estimation simplifiee de la distance d'arret d'un vehicule" << endl << endl << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << "| Vitesse (km/h) | Reaction | Freinage | Normale  | Fatigue  |  Alcool  | Fatigue + Alcool | Route Humide | Equivalence en nombre d'etages |" << endl << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void print_case(const int column, const int value, const string unit)
{
    const int value_len = static_cast<int>((to_string(value)).length()), column_size[9] = {16, 10, 10, 10, 10, 10, 18, 14, 32};
    const int n = static_cast<int>(column_size[column] - value_len - unit.length())/2, nb_elt = static_cast<int>(column_size[column] - value_len - unit.length());

    if (column == 0)
        {cout << "|";}
    
    for (int i = 0; i <= nb_elt + 1; i+=1)
    {
        if (i == n)
            {cout << to_string(value);}
        else if (i == n+1)
            {cout << unit;}
        else
            {cout << " ";}
    }
    cout << "|";
}

void print_ligne(const float vitesse)
{
    print_case(0, static_cast<int>(vitesse), " km/h");
    print_case(1,  distance_reaction(vitesse, false, false), " m");
    print_case(2, distance_freinage(vitesse), " m");
    print_case(3, distance_totale_sec(vitesse, false, false), " m");
    print_case(4, distance_totale_sec(vitesse, true, false), " m");
    print_case(5, distance_totale_sec(vitesse, false, true), " m");
    print_case(6, distance_totale_sec(vitesse, true, true), " m");
    print_case(7, distance_totale_hum(vitesse, true, true), " m");
    print_case(8, distance_etage(static_cast<float>(distance_totale_hum(vitesse, true, true))), " etages");
    cout << endl << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
}

/*int main()
{
    string retour;

    print_entete();
    for (int i = 20; i <= 130; i +=10)
    {
        print_ligne(static_cast<float>(i));
    }

    cin >> retour;

    return 0;
}*/