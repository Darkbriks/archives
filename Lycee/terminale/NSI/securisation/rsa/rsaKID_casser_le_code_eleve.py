from rsaKID_eleve import*
from  time import *
(test1_pub,test1_priv)=((1553, 17203), (2437, 17203))
(test2_pub,test2_priv)=((15269, 626929), (20201, 626929))
test1_code=[13137, 8238, 11224, 2026, 15290, 12897, 2026, 15290, 5132, 5012, 13017, 16003, 473, 15290, 353, 5012, 13017, 12897, 15290, 11824]
test2_code=[533515, 288311, 488608, 456270, 227235, 517346, 486808, 441001, 425732, 44907, 488608, 257773, 595491, 288311, 502077, 517346, 488608, 410463, 441001, 349387, 488608, 441001, 532615, 488608, 547884, 441001, 532615, 502077, 488608, 456270, 486808, 288311, 425732, 288311, 608960, 488608, 395194, 227235, 488608, 456270, 441001, 486808, 517346, 288311, 488608, 503877, 488608, 365556, 488608, 547884, 441001, 532615, 502077, 488608, 273042, 288311, 488608, 257773, 334118, 441001, 349387, 502077, 349387, 486808, 75445]
def casser_brouillon(code,n):
    """
    permet de trouver la clef privée à partir de la clef publique
    :param e : int
    :param n : int
    """
    for d in range(1,n):
        msg=dechiffrer(code,(d,n))
        print(msg)

def casser(code,cle_pub):
    """
    permet de trouver la clef privée à partir de la clef publique
    >>> casser(test1_code,(1553, 17203))
    Vive le grand oral ?
    :param e : int
    :param n : int
    """
    n,e=cle_pub[1],cle_pub[0]
    for d in range(1,n):
        if ((e*d)-1)%n==0:
            msg=dechiffrer(code,(d,n))
            print(msg)
        
       
        


    
    