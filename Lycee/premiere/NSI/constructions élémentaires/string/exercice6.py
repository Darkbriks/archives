def enleverCar(mot,car):
    '''
    enlever la lettre car de mot si lettre est présente dans le mot
    :param mot:str
    :param lettre:str
    :effet de bord : afficher nouveau
    '''
    #création d'une variable de type str vide
    nouveau=''
    #boucle, prendre les lettres une à une de mot
    for lettre in mot :
        #tester si lettre est différent de car
        if lettre!=car :
            #ajouter lettre à nouveau
            nouveau=nouveau+lettre
    print(nouveau)



