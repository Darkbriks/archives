from random import*

def revoir_table(n):
    '''
    afficher la table de multiplication par n
    :param:n(int)
    :effet de bord: afficher la table
    '''
    
    for pas in range(11):
        print(pas,'x',n,' = ', pas*n)
        
        
def reciter():
    '''
    afficher une table à reciter au hasard entre 3 et 9
    :effet de bord: afficher la table et une note
    '''
    
    table=randint(3,9)
    note=0
    for pas in range(1,10):
        print(pas,'x',table,' =  ???')
        reponse=input('réponse ???')
        reponse=int(reponse)
        if reponse==pas*table:
            note=note+1
            print('bon')
        else:
            print('à revoir !! la bonne réponse est ', pas*table)

    print('ta note est ',note)
    
    
def evaluer():
    '''
    afficher 5 produits à calculer
    :param:aucun
    :effet de bord: afficher les questions
    :return:nombre de bonnes réponses
    '''
    note=0
    for pas in range(5):
        table=randint(3,9)
        pas=randint(1,9)
        print(pas,'x',table,' =  ???')
        reponse=input('réponse ???')
        reponse=int(reponse)
        if reponse==pas*table:
            note=note+1
    return note
    
    


