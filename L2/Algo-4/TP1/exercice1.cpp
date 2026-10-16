/*#include <iostream>
#include <random>
using namespace std;

struct Case { int x=0, y=0; Case *next=nullptr; };

Case* initListeCaseVideIter(int x, int y)
{
    Case *t=new Case;
    Case *ptr=t;

    for (int i=1;i<x*y;i++)
    {
        Case *temp = new Case;
        temp->x=i%x;
        temp->y=i/x;
        ptr->next=temp;
        ptr=ptr->next;
    }
    return t;
}

Case* initListeCaseVideRec(int x, int y, int i=0)
{
    if (i==x*y) { return nullptr; }
    
    Case *c=new Case;
    c->x=i%x;
    c->y=i/x;
    c->next=initListeCaseVideRec(x, y, i+1);
    return c;
}

int lenghtListeRec(Case *c) { if (c == nullptr) { return 0; } return 1 + lenghtListeRec(c->next); }

int random(const int a, const int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

void rechercheAlea(int*x, int*y, Case *c)
{
    int alea = random(0, lenghtListeRec(c));
    Case *ptr=c;
    for (int i=0; i<alea;i++) { ptr=ptr->next; }
    *x=ptr->x; *y=ptr->y;
}

bool estPrise(int x, int y, int dameX, int dameY)
{
    if (x == dameX or y == dameY or abs(x-dameX) == abs(y-dameY)) { return true; }
    return false;
}

void maj(Case **c, int x, int y, int nbc=8)
{
    if (*c == nullptr) { return; }
    
    if (estPrise((*c)->x, (*c)->y, x, y))
    {
        Case *temp = (*c)->next;
        delete *c;
        *c = temp;
        maj(c, x, y, nbc);
    }

    else { maj(&(*c)->next, x, y, nbc); }
}

void ajouteDame(Case **c, int x, int y)
{
    if (*c == nullptr)
    {
        *c = new Case;
        (*c)->x = x;
        (*c)->y = y;
        (*c)->next = nullptr;
    }
    else { ajouteDame(&(*c)->next, x, y); }
}

void printChainedList(Case *c) { if (c == nullptr) { return; } cout << "(" << c->x << ", " << c->y << ") -> "; printChainedList(c->next); }

int main()
{
    int n = 8, max = 1000, i = 0, maxPlacee = 0;
    
    while (i <= max and maxPlacee < n)
    {
        Case *t1 = initListeCaseVideIter(n, n);
        Case *dame = nullptr;
        while (lenghtListeRec(t1) > 0)
        {
            int x, y;
            rechercheAlea(&x, &y, t1);
            ajouteDame(&dame, x, y);
            maj(&t1, x, y);
        }
        cout << "Il a ete possible de placer " << lenghtListeRec(dame) << " dames sur l'echiquier de taille " << n << "x" << n << "." << endl;
        printChainedList(dame);
        if (lenghtListeRec(dame) > maxPlacee) { maxPlacee = lenghtListeRec(dame); }
        i++;
    }
    
    
    system("pause");
    return 0;
}*/
