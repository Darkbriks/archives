def fibo_iteratif(n):
    u = 1
    v = 1
    i = 2
    while i < n+1:
        u,v = v,u+v
        i = i+1
    return u

def fib_rec(n) :
    pass