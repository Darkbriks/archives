modeleA="Son nom est {}, son âge est {}"
modeleB="La valeur est {} !!"

def fctA():
    print ("Début fonction fctA")
    i=4
    while i<10:
        print(modeleA.format("Titi",i))# on asigne a la premiere paire de crochet la valeur "Titi", et la valeur i a la seconde
        i = i + 3
    print ("Fin fonction fctA")

def fctB():
    print ("Début fonction fctB")
    i=0
    while i<5:
        print(modeleB.format(i))# On assigne la valeur i a la paire de crochet
        if i==3:
            print('appel de la fonction A')
            fctA()
            print("Retour à la fonction fctB")
        i = i + 1
    print ("Fin fonction fctB")

fctB()