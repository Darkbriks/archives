from factorielles import *

# Commenter au fur et à mesure les fonctions détectées comme fausses
a_tester = (factorielle1,
            factorielle2,
            factorielle3,
            factorielle4,
            factorielle5,
            factorielle6,
            factorielle7,
            factorielle8,
            factorielle9,
            factorielle10,
            factorielle11
            )


for f in a_tester :
    for (n, factn) in ((0,1), (2,2), (5,120)):
        assert f(n) == factn, "Échec pour "+str(f)+" : avec n="+str(n)+", f(n)="+str(f(n))
        

for f in a_tester :
    for n in range(10, 100, 10):
        assert f(n) == n * f(n-1), "Échec pour "+str(f)+" : avec n="+str(n)+", f(n) != n*f(n-1)"
       