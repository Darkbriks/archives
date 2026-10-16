from random import*
from datetime import*

nom = str(input("Quel est le nom de la personne passant le test"))
date = datetime.now()

table=randint(3,9)
note=0
for pas in range(7,10):
    print(pas,'x',table,' =  ???')
    reponse=input('réponse ???')
    reponse=int(reponse)
    if reponse==pas*table:
        print('bravo')
        note=note+1
    else:
        print('à revoir !! la bonne réponse est ', pas*table)

modif=open('tables_' + nom + '.txt','a')
modif.write(str(note) + str(date) + "\n")
modif.close()

moyenne = 0
nbNote = 0
"""
entree=open('tables_' + nom + '.txt','r')
texte=entree.readlines()
for ligne in texte :
    moyenne = moyenne + 
    nbNote = nbNote + 1
entree.close()
moyenne = moyenne / nbNote
"""