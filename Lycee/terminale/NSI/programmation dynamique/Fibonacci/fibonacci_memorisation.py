def fib_mem(n):
    mem = [0]*(n+1)  #permet de créer un tableau contenant n+1 zéro
    return fib_mem_c(n,mem)


def fib_mem_c(n,m):
    if n==0 or n==1:
        m[n]=n
        return n
    elif m[n]>0:
        return m[n]
    else:
        m[n]=fib_mem_c(n-1,m) + fib_mem_c(n-2,m)
        return m[n]