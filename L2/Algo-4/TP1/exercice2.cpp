/*#include <iostream>
using namespace std;

struct Case { int nb=0; Case *next=nullptr; };

void printChainedList(Case *c) { if (c != nullptr) { cout << "(" << c->nb << ") -> "; printChainedList(c->next); } else { cout << endl; } }

int getNb(Case *c, int i)
{
    if (c == nullptr) { return -1; }
    if (i==0) { return c->nb; }
    return getNb(c->next, i-1);
}

Case* initListeCaseVideRec(int n, int i=1)
{
    if (i==n) { return nullptr; }
    
    Case *c=new Case;
    c->nb=i;
    c->next=initListeCaseVideRec(n, i+1);
    return c;
}

int lenghtListeRec(Case *c) { if (c == nullptr) { return 0; } return 1 + lenghtListeRec(c->next); }

bool isMultiple(int a, int b) {return a%b == 0 and a != b;}

void removeAllMultipleOff(Case *c, int m)
{
    // TODO : fix
    Case *prec=c;
    Case *ptr=c->next;
    for (int i=0;i<lenghtListeRec(c)-2;i++)
    {
        if (isMultiple(ptr->nb, m))
        {
            prec->next=ptr->next;
            delete ptr;
        }
        else { prec = prec->next; }
        ptr=prec->next;
    }
    if (isMultiple(ptr->nb, m))
    {
        delete ptr;
        prec->next=nullptr;
    }
    
}

void cribleErathostene(Case *c, int indice) { removeAllMultipleOff(c, getNb(c, indice)); }

int main()
{
    Case *c=initListeCaseVideRec(100);
    for (int i = 1; i < lenghtListeRec(c); i++)
    {
        cribleErathostene(c, i);
    }
    printChainedList(c);
    system("pause");
    return 0;
}*/