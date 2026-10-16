def fib_mem(n):
    #permet de créer un tableau contenant n+1 zéro
    #mem est le tableau qui enregistrera les valeurs de Fibonacci
    mem = [0]*(n+1)  
    return fib_mem_c(n,mem)

def fib_mem_c(n,m):
    #doit compléter le tableau
    #doit renvoyer la valeur utile
    pass