def fct_it(x, n):
    '''
    renvoie x puissance n
    '''
    assert n>=0
    produit=1
    for pas in range(n):
        produit=produit*x
    return produit
    
def fct_rec(x, n):
    '''
    renvoie x puissance n
    '''
    assert n>=0
    if n==0:
        return 1
     
    if n%2 ==0:
        return fct_rec(x*x,n//2)
     
    return fct_rec(x*x,n//2)*x

def fct_rec_naive(x, n):
    '''
    renvoie x puissance n
    '''
    assert n>=0
    if n==0:
        return 1
    else:
        return fct_rec_naive(x, n-1)*x