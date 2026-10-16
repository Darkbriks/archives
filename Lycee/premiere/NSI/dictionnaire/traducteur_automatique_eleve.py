dico_ang= {'ordinateur':'computer','outil':'tool','ami':'friend',
          'fichier':'file','bureau':'desktop','disque':'disk',
          'clavier':'computer keyboard','dur':'hard',
          'mémoire':'memory','long':'long','homme':'man','ami':'friend',}

dico_fr={'book':'livre','tomato':'tomate','teacher':'professeur','box':'boîte'}

dico_sp= {'bonjour':'hola','fille':'chica'}

def fonction1(texte,dico):
    '''
    ????
    :param:texte(str)
    :param : dico(dict)
    :return:traduction(str)
    '''
    texte=texte.lower()
    texte=texte.replace("'"," ")
    texte=texte.replace(":"," ")
    #le texte est mis dans une liste, avec comme séparateur l'espace
    liste=texte.split()
    traduction=''
    for elt in liste:
        if elt in dico:
            traduction=traduction+dico[elt]+' '
        else:
            traduction=traduction+'??'+' '
    return traduction

     
def fonction2(mot,dico):
    '''
    ??????
    :param:texte(str)
    :param : dico(dict)
    effet de bord : dico est modifié
    '''
    reponse=input('avez vous la traduction de : '+mot+' .Répondre non ou donner la traduction de '+mot)
    if reponse!='non':
        dico[mot] = reponse

def fonction3(dico):
    for elt in dico:
        mot=elt+'s'
        dico[mot]=dico[elt]+'s'
    return dico

def fonction4(dico):
    new=dico
    #ATTENTION, mutabilité des dictionnaires
    for elt in dico:
        mot=elt+'s'
        new[mot]=dico[elt]+'s'
    return dico


def ajouter_pluriel(dico):
    """
    modifier dico afin d'ajouter le pluriel des différents noms.
    :param : dico(dict)
    effet de bord : dico est modifié
    """
    

def translate_plus(texte,dico):
    '''
    convertir du français vers ....., traducteur automatique
    on peut ajouter des mots inconnus si besoin
    :param:texte(str)
    :param : dico(dict)
    :return:traduction(str)
    '''


