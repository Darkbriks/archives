def ex_1() :
    chaine = str(input('quel est votre chaine de caractére '))
    for loop in range(len(chaine)) :
        print(chaine[loop])
        
def ex_1_bis() :
    chaine = str(input('quel est votre chaine de caractére '))
    for loop in range(len(chaine)) :
        print(chaine[loop],'*')
        
def ex_2() :
    compteur = 0
    chaine = str(input('quel est votre chaine de caractére '))
    for loop in range(len(chaine)) :
        if chaine[loop] == " " :
            compteur = compteur + 1
    print('il y a',compteur,'espace dans cette chaine de caractére')
    
def ex_3():
    chaine_bis = ''
    chaine = str(input('quel est votre chaine de caractére '))
    maj = chaine[0]
    maj = maj.upper()
    
    for loop in range(len(chaine)) :
        if chaine[loop] != " " :
            chaine_bis = chaine_bis + chaine[loop]
            
    print(maj+chaine_bis[1:])
    
def ex_4(chaine,indice) :
    print(chaine[:indice-1] + chaine[indice:])
    
def ex_5(chaine,occurance) :
    compteur = 0
    for loop in range(len(chaine)) :
        if chaine[loop] == occurance :
            compteur = compteur + 1
    print('il y a',compteur,'occurance de',occurance,' dans cette chaine de caractére')
    
def ex_6(chaine,caractere) :
    chaine_bis = ''
    for loop in range(len(chaine)) :
        if chaine[loop] != caractere :
            chaine_bis = chaine_bis + chaine[loop]
    print(chaine_bis)
  