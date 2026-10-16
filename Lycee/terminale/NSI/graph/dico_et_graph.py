graph2={'a':[],'b':['a'],'c':['a'],'d':['e'],'e':['a']}
twitter={'amel':['bob','eric','ela'],'bob':['eric'],'eric':['bob','amel'],'dina':['bob'],'ela':['dina','amel','eric']}

def suivre(x,y,dico):
    '''
    permet de savoir si x suit y sur le réseau dico
    >>> suivre('amel','eric',twitter)
    True
    >>> suivre('amel','dina',twitter)
    False
    '''
def maxi(dico):
    '''
    nombre maximum de personnes suivies par un menbre du réseau dico
    >>> maxi(graph2)
    1
    >>> maxi(twitter)
    3
    '''
    

def suit_max(dico):
    '''
    personne qui suit le plus de personnes sur le réseau dico
    >>> suit_max(graph2)
    ['b', 'c', 'd', 'e']
    >>> suit_max(twitter)
    ['amel', 'ela']
    '''
    
    
            

import doctest
doctest.testmod()