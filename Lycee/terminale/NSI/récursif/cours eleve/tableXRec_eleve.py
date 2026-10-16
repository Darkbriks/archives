def une_table(n,k=10) :
    '''
    la table de n en récursif
    '''
    if k == -1:
        return
    une_table(n, k-1)
    print(k, " x " ,n," = ", k*n)
    return
    

def tables(n):
    '''
    les tables de 0 à n en récursif
    '''
    if n == -1:
        return
    une_table(n)
    tables(n-1)
   
    
