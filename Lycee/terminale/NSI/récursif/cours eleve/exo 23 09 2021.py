import time

def puissanceREC(x, n):
    assert n>=0 and type(n)==int, "La valeur n n'est pas valide"
    if n==0:
        return 1
    return x*puissanceREC(x, n-1)

def puissanceIT(x, n):
    assert n>=0 and type(n)==int, "La valeur n n'est pas valide"
    i=1
    for loop in range(n):
        i=i*x
    return i


def test(n):
    a=time.time()
    puissanceREC(5,n)
    b=time.time()
    print("La version recursive a mise {} seconde pour calculer 5 puissance {}".format(b-a, n))
    
    a=time.time()
    puissanceIT(5,n)
    b=time.time()
    print("La version iterative a mise {} seconde pour calculer 5 puissance {}".format(b-a, n))