def fibonacci(n):
    assert type(n) == int
    assert n >= 0
    if n==0:
        return 0
    if n==1:
        return 1
    return fibonacci(n-2)+fibonacci(n-1)