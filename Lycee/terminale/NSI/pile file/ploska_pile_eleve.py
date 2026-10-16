from pile1_list import *

def NotationPostFixee(expression):
    pile=Pile()
    n=int()
    for i in expression:
        if i.isdigit()==True:
            pile.empiler(i)
        if i == '+':
            pile.empiler(int(pile.depiler())+int(pile.depiler()))
        if i == '*':
            pile.empiler(int(pile.depiler())*int(pile.depiler()))
        if i == '-':
             pile.empiler(int(pile.depiler())-int(pile.depiler()))
        if i == '/':
             pile.empiler(int(pile.depiler())/int(pile.depiler()))
    return pile.sommet()