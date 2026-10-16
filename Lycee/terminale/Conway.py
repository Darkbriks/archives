def int_to_list(n):
    return [int(i) for i in str(n)]

def list_to_int(l):
    return "".join([str(i) for i in l])

def etude(l):
    resultat = list()
    while l:
        precedant, i = l.pop(0), 1
        while l and precedant == l[0]:
            i, precedant = i+1, l.pop(0)
        resultat = resultat + [i, precedant]
    return resultat

def conway(longeur):
    suite_conway = [1]
    for i in range(longeur):
        suite_conway.append(list_to_int(etude(int_to_list(suite_conway[-1]))))
    print("".join([str(i) + "\n" for i in suite_conway]))
    
def syracuse(antecedant, longeur):
    liste = [antecedant]
    for i in range(longeur):
        if liste[-1] % 2 == 0:
            liste.append(int(liste[-1]/2))
        else:
            liste.append(int(liste[-1]*3 +1))
    return liste

def fibonnaci_naive(i):
    if i == 1 or i == 2:
        return 1
    return fibonnaci_naive(i-1) + fibonnaci_naive(i-2)

dic={1}
def fibonnaci(i):
    