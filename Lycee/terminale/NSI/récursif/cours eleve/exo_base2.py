def f1(n):
    if n==0:
        print(0)
    if n==1:
        print(1)
    if n==2:
        print(2)
    if n>=3:
        f1(n-3)
        print(n)
        
def f2(n):
    if n==0:
        print(0)
    if n==1:
        print(1)
    if n==2:
        print(2)
    else:
        f2(n-3)
        print(n)
        
        
def f3(n):
    if n==0:
        print(0)
    if n==1:
        print(1)
    if n==2:
        print(2)
    if n>=3:
        print(n)
        f3(n-3)
        
def f4(n):
    if n==0:
        return(0)
    if n==1:
        return(1)
    if n==2:
        return(2)
    if n>=3:
        return n + f4(n-3)
    
    """
    f4(1) retourne 1
    f4(4) retourne 4 + f4(1)
    f4(7) retourne 7 + f4(4)
    affichage = 12
    """
    """
    f4(0) retourne 0
    f4(3) retourne 3 + f4(0)
    f4(6) retourne 6 + f4(3)
    f4(9) retourne 9 + f4(6)
    f4(12) retourne 12 + f4(9)
    
    affichage = 30
    """
    
def f5(n):
    if n==0:
        return(0)
    if n==1:
        return(1)
    if n==2:
        return(2)
    if n>=3:
        return (n,f5(n-3))
    
    """
    f5(0) retourne 0
    f5(3) retourne (3, f5(0))
    f5(6) retourne (6, f5(3))
    f5(9) retourne (9, f5(6))
    f5(12) retourne (12, f5(9))
    f5(15) retourne (15, f5(12))

    affichage = (15, (12, (9, (6, (3, 0)))))
    """