##############################################################################
#                                                                            #
# Rappel sur les listes, les listes en compréhension, les dictionnaires.    #
# Il est CAPITAL de faire régulièrement du python !!!!!                      #
#                                                                            #
##############################################################################

#partie 1, conversion
def base2_to_base10(n):
    """
    conversion de base2 vers la base 10 par une liste en compréhension
    Rappel dans le shell pour tester des conversions d'entiers:
    >>> bin(3)
    '0b11'
    >>> int('101',2)
    5
    >>> base2_to_base10('101')
    5
    >>> base2_to_base10('11111111')
    255
    >>> base2_to_base10('100000000')
    256
    
    """
    
    return sum([2**i*int(n[-1-i]) for i in range(len(n))])
    
#1) peut-on passer de la base 10 à la base2 par une liste en compréhension ?? Justifier !

#partie 2 un répertoire par une liste
repertoire = [{'nom':'dupond','tel':'0215744400'},{'nom':'tintin','tel':'02878714410'},
              {'nom':'migot','tel':'0798184906'},{'nom':'nigau','tel':'061425406'},]
#2) Que permet d'obtenir cette variable :
var1=repertoire[1]['tel']
#3) Que permet d'obtenir cette variable :
var2=repertoire[1]

#4) Que fait cette compréhension :
liste=[repertoire[elt]['nom'] for elt in range(len(repertoire))]
print('1',liste)
#la même chose avec une fonction
def liste_nom(liste):
    """
    permet d obtenir la liste des noms du repertoire
    liste:list
    >>> liste_nom(repertoire)
    ['dupond', 'tintin', 'migot', 'nigau']
    """
    nom=[]
    for elt in liste:
        nom.append(elt['nom'])
    return nom

#5) Obtenir la liste des numéros du repertoire en compréhension :

#6) Compléter :Obtenir la liste ..........................en compréhension si ............................. :
liste2=[repertoire[elt]['nom'] for elt in range(len(repertoire)) if len(repertoire[elt]['tel'])!=10]

#7) Faire la même chose avec une fonction


#8) Obtenir la liste des noms du repertoire en compréhension si le numéro de téléphone est un 06 :

#partie 3 un répertoire par un dictionnaire de dictionnaire
#C'est plus pratique, simple !
repertoire2={'dupond':{'prenom':'alber','tel':'0215744400','sexe':'h'},'herman':{'prenom':'gigi','tel':'060471438','sexe':'f'},
            'ceriez':{'prenom':'nath','tel':'01078484417','sexe':'f'},'manche':{'prenom':'jean','tel':'0600110011','sexe':'h'},
            'plé':{'prenom':'micheline','tel':'017845438','sexe':'f'},'egal':{'prenom':'sam','tel':'024785129','sexe':'h'},
            'aubin':{'prenom':'marie','tel':'0612351438','sexe':'f'}}
#9) Que permet d'obtenir cette variable :
repertoire2['aubin']
#10) Que permet d'obtenir cette variable :
repertoire2['egal']['tel']
#11) Que permet d'obtenir cette liste en compréhension :
liste3=[repertoire2[elt]['tel'] for elt in repertoire2 if repertoire2[elt]['sexe']=='f']

#Obtenir la liste des tuple (nom,téléphone) du repertoire2 en compréhension si le numéro de téléphone n'est pas à 10 chiffres :


#Donnez une liste en compréhension pour obtenir le numéro des femmes qui commencent par 02


#Donnez une liste en compréhension pour obtenir le nom des personnes ayant un 06 ou des femmes



if __name__ == '__main__':
    import doctest
    doctest.testmod(optionflags=doctest.NORMALIZE_WHITESPACE | doctest.ELLIPSIS, verbose=True)