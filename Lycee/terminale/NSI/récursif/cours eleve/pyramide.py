def pyramide1(n, p=0):
    if n==1:
        print(" "*p,"*")
    else:
        pyramide1(n-1, p+1)
        print(" "*p,"* "*n)
        
def pyramide2(n):
    for loop in range(n):
        print(" "*(n-loop-1),"* "*(loop+1))