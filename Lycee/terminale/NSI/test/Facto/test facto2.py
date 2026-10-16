from factorielles import *

liste = [3628800, 2432902008176640000, 265252859812191058636308480000000, 815915283247897734345611269596115894272000000000, 30414093201713378043612608166064768844377641568960512000000000000,
8320987112741390144276341183223364380754172606361245952449277696409600000000000000, 11978571669969891796072783721689098736458938142546425857555362864628009582789845319680000000000000000,
71569457046263802294811533723186532165584657342365752577109445058227039255480148842668944867280814080000000000000000000, 1485715964481761497309522733620825737885569961284688766942216863704985393094065876545992131370884059645617234469978112000000000000000000000,
93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000]

def test1():
    l1 = []
    for loop in range(10):
        l1.append(factorielle1((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test2():
    l1 = []
    for loop in range(10):
        l1.append(factorielle2((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test3():
    l1 = []
    for loop in range(10):
        l1.append(factorielle3((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test4():
    l1 = []
    for loop in range(10):
        l1.append(factorielle4((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test5():
    l1 = []
    for loop in range(10):
        l1.append(factorielle5((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test6():
    l1 = []
    for loop in range(10):
        l1.append(factorielle6((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test7():
    l1 = []
    for loop in range(10):
        l1.append(factorielle7((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test8():
    l1 = []
    for loop in range(10):
        l1.append(factorielle8((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test9():
    l1 = []
    for loop in range(10):
        l1.append(factorielle9((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test10():
    l1 = []
    for loop in range(10):
        l1.append(factorielle10((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True

def test11():
    l1 = []
    for loop in range(10):
        l1.append(factorielle11((loop+1)*10))
        if l1[loop] != liste[loop]:
            return False
    return True
"""
print(test1())
print(test2())
print(test3())
print(test4())
print(test5())
print(test6())
print(test7())
print(test8())
print(test9())
print(test10())
print(test11())
"""

def test():
    liste = (facto((n+1)*10) for n in range(10))
    if (factorielle2((loop+1)*10) for loop in range(10)) == liste:
        return True
    return False

def facto(n):
    if n>0:
        return n*facto(n-1)
    return 1
