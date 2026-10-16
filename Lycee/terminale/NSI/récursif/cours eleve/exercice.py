def somme1(n):
    somme=0
    for loop in range(n):
        somme=somme+loop+1
    return somme

def somme2(n):
    if n==0:
        return 0
    return n+somme2(n-1)

def escalier1(n):
    assert n>=0
    for loop in range(n):
        print("* "*(loop + 1))
        
def escalier2(n):
    if n<1:
        return
    escalier2(n-1)
    print(" "+"* "*n)
    
def multiplication1(n):
    if n == 0:
        return
    else :
        for loop in range(11):
            print(loop, " x " ,n," = ", loop*n)
        multiplication1(n-1)
        
#def multiplication2(n, p=0):
 #   if n == 0:      