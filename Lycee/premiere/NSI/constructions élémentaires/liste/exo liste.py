def ex_1() :
    long = int(input('quelle est la longueur de la liste'))
    liste=[]
    for i in range(long):
        a=int(input('entrer un nombre'))
        liste=liste+[a]
        
    repetition=''

    while repetition != 'pas présent' :
        b=int(input('entrer un nombre a comparer'))
        repetition='pas présent'
        if b in liste :
            print('deja dit')
            repetition = liste
    print(repetition)

    
def ex_2() :
    liste=[10,5,7,12,10,8,7,3,0,4,8,6,12,0]
        
    b=int(input('entrer un nombre'))
    compteur = 0
    for i in range(10):
        if b==liste[i] :
            compteur = compteur + 1
    print('il y a',compteur,'fois ce caractére dans la liste')
    
def ex_3() :
    long = int(input('quelle est la longueur de la liste'))
    
    liste=[]
    for i in range(long):
        a=input('entrer un nombre')
        a=int(a)
        liste=liste+[a]
        
    minimum = liste[0]
    maximum = liste[0]
    somme = 0
    for loop in range(len(liste)) :
        if minimum > liste[loop] :
            minimum = liste[loop]
        
        if maximum < liste[loop] :
            maximum = liste[loop]
        somme = somme + liste[loop]
    print('le chiffre minimum est',minimum)
    print('le chiffre maximum est',maximum)
    print('la somme de la liste est',somme)
    
    
