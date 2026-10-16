zoo_Beauval={'éléphant':('Asie',0,2),'écureuil':('Asie',12,15),'panda':('Asie',2,0),
             'hippopotame':('Afrique',0,7),'girafe':('Afrique',2,2)}
#A beauval, les éléphants viennent d'asie, il y a 0 mâles et 2 femelles, ....
zoo_LaFleche={'ours':('Europe',0,4),'tigre':('Asie',3,5),'hippopotame':('Afrique',3,0),
              'girafe':('Afrique',3,2),'aigle':('Amerique',4,3)}
"""1)A partir du dico, que tapez dans le shell, pour obtenir:
a)tous les renseignements sur les pandas au zoo Beauval:
    zoo_Beauval["panda"]

b)l'origine des pandas de Beauval
    zoo_Beauval["panda"][0]

c)nombre de tigres mâles à la Fleche
    zoo_LaFleche["tigre"][1]

2)que sait-on avec zoo_LaFleche.keys()
    on obtient la liste des clés contenue dans le dictionnaire zoo_La Fleche
    (dict_keys(['ours', 'tigre', 'hippopotame', 'girafe', 'aigle']))

3)Que sait -on avec [zoo_Beauval[clef][2]for clef in zoo_Beauval]
ou avec [zoo_Beauval[clef][2]for clef in zoo_Beauval if zoo_Beauval[clef][0]=='Asie']
    a) une liste contenant le nombre de femmelle du zoo par espece
    
    b) une liste contenant le nombre de femmelle du zoo par espece si elle est originaire d'asie

"""
def etudier(dico):
    """
    cette fonction affiche une liste contenant les cle de chaque espece si le zoo ne possede aucun mal de cette espece
    """
    liste=[]
    for clef in dico:
        if dico[clef][1]==0:
            liste.append(clef)
    return liste

def etudier1(dico):
    """
    total d'animaux pour un zoo
    """
    nbAnimaux=0
    for clef in dico:
        nbAnimaux = nbAnimaux + dico[clef][1] + dico[clef][2]
    return nbAnimaux


def total_continent(dico,continent):
    """
    :param: dico (dict)
    :param: continent(str)
    >>> total_continent(zoo_Beauval,'Afrique')
    11
    >>> total_continent(zoo_LaFleche,'Amerique')
    7
    """
    nbAnimaux=0
    for clef in dico.keys():
        if dico[clef][0] == continent:
            nbAnimaux = nbAnimaux + dico[clef][1] + dico[clef][2]
    return nbAnimaux

def avoir_bébé(dico):
    '''
    liste des animaux qui peuvent se reproduire
    '''
    liste=[]
    for clef in dico.keys():
        if dico[clef][1] != 0 and dico[clef][2] != 0:
            liste.append(clef)
    return liste
