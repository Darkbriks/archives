zoo_Beauval={'éléphant':('Asie',0,2),'écureuil':('Asie',12,15),'panda':('Asie',2,0),
             'hippopotame':('Afrique',0,7),'girafe':('Afrique',2,2)}
#A beauval, les éléphants viennent d'asie, il y a 0 mâles et 2 femelles, ....
zoo_LaFleche={'ours':('Europe',0,4),'tigre':('Asie',3,5),'hippopotame':('Afrique',3,0),'girafe':('Afrique',3,2),'aigle':('Amerique',4,3)}
"""
tous les renseignements sur les pandas au zoo Beauval:
>>> zoo_Beauval['panda']
('Asie', 2, 0)
l'origine des pandas de Beauval
>>> zoo_Beauval['panda'][0]
'Asie'
nombre de tigres mâles à la Fleche
>>> zoo_LaFleche['tigre'][1]
3
que sait-on avec zoo_LaFleche.keys()
>>> zoo_LaFleche.keys()
dict_keys(['ours', 'tigre', 'hippopotame', 'girafe', 'aigle'])
Que sait -on avec [zoo_Beauval[clef][2]for clef in zoo_Beauval.keys()]
ou [zoo_Beauval[clef][2]for clef in zoo_Beauval.keys() if zoo_Beauval[clef][0]=='Asie']
[2, 15, 0, 7, 2]


"""
def etudier(dico):
    """
    trouver les animaux pour lesquels il n'y a pas de mâle
    """
    liste=[]
    for clef in dico.keys():
        if dico[clef][1]==0:
            liste.append(clef)
    return liste

def etudier1(dico):
    """
    total d'animaux
    """
    nombre=0
    for clef in dico.keys():
        nombre=nombre+dico[clef][1]+dico[clef][2]
    return nombre

def total_continent(dico,continent):
    """
    :param: dico (dict)
    :param: continent(str)
    >>> total_continent(zoo_Beauval,'Afrique')
    11
    >>> total_continent(zoo_LaFleche,'Amerique')
    7
    """
    nombre=0
    for clef in dico.keys():
        if dico[clef][0]==continent:
            nombre=nombre+dico[clef][1]+dico[clef][2]
    return nombre

def avoir_bébé(dico):
    '''
    liste des animaux qui peuvent se reproduire
    '''
    liste=[]
    for clef in dico.keys():
        if dico[clef][1]!=False and dico[clef][2]!=False:
            liste.append(clef)
    return liste