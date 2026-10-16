import random
code_genetique = {
'UUU' : "F", 'UUC' : 'F',
'UUA' : 'L', 'UUG' : 'L', 'CUU' : 'L', 'CUC' : 'L', 'CUA' : 'L', 'CUG' : 'L',
'AUU' : 'I', 'AUC' : 'I', 'AUA' : 'I',
'AUG' : 'M',
'GUU' : 'V', 'GUC' : 'V', 'GUA' : 'V', 'GUG' : 'V',
'UCU' : 'S', 'UCC' : 'S', 'UCA' : 'S', 'UCG' : 'S', 'AGU' : 'S', 'AGC' : 'S',
'CCU' : 'P', 'CCC' : 'P', 'CCA' : 'P', 'CCG' : 'P',
'ACU' : 'T', 'ACC' : 'T', 'ACA' : 'T', 'ACG' : 'T',
'GCU' : 'A', 'GCC' : 'A', 'GCA' : 'A', 'GCG' : 'A',
'UAU' : 'Y', 'UAC' : 'Y',
'UAA' : '*', 'UAG' : '*', 'UGA' : '*',
'CAU' : 'H', 'CAC' : 'H',
'CAA' : 'Q', 'CAG' : 'Q',
'AAU' : 'N', 'AAC' : 'N',
'AAA' : 'K', 'AAG' : 'K',
'GAU' : 'D', 'GAC' : 'D',
'GAA' : 'E', 'GAG' : 'E',
'UGU' : 'C', 'UGC' : 'C',
'UGG' : 'W',
'CGU' : 'R', 'CGC' : 'R', 'CGA' : 'R', 'CGG' : 'R', 'AGA' : 'R', 'AGG' : 'R',
'GGU' : 'G', 'GGC' : 'G', 'GGA' : 'G', 'GGG' : 'G'}


def estADN(chaine) :
    """
    teste si une chane de caractere est bien une sequance ADN
    :param chaine: str
    :param return: bool
    >>> estADN('ATGCGATC')
    True
    >>> estADN('ACKT')
    False
    >>> estADN('ACTK')
    False
    >>> estADN("")
    True
    """    
    for carct in chaine :
        if carct != 'A' and carct != 'T' and carct != 'G' and carct != 'C' :
            return False
    return True

def genereADN(long) :
    '''
    genere un molecule d'ADN aleatoire de longueur X
    :param long: int
    :param return: str
    '''
    ADN = ''
    nucleotides = 'ATGC'
            
    for loop in range(long) :
        ADN = ADN + nucleotides[random.randint(0,3)]
    return ADN

def baseComplementaire(nucleotides, transcription) :
    """
    fonction qui renvoie la base complémentaire de la base passée en paramètre selon la sequance 'ADN' ou 'ARN'
    :param nucleotides: str, ne peut être uniquement les lettres A, T, C ou G
    :param trancription: str ne peut etre que ADN ou ARN
    
    >>> baseComplementaire('G', 'ADN')
    'C'
    >>> baseComplementaire('A', 'ARN')
    'U'

    """
    transcription = transcription.upper()
    ADN = {'A' : 'T', 'T' : 'A', 'G' : 'C', 'C' : 'G'}
    ARN = {'A' : 'U', 'T' : 'A', 'G' : 'C', 'C' : 'G'}
    newNucleotides = ''
    
    if estADN(nucleotides) == False or (transcription != 'ADN' and transcription != 'ARN') :
        return (False, "la nucleotide ou la methode de transcription n'existe pas")
    
    for nucl in nucleotides :
        if transcription == 'ADN' :
            newNucleotides = newNucleotides + ADN[nucl]
    
        if transcription == 'ARN' :
            newNucleotides = newNucleotides +ARN[nucl]
        
    return newNucleotides

def transcription(nucleotides, debut, fin) :
    """
    cette fonction renvoie l'ARN construit à partir de la sous-séquence d'ADN comprise entre les deux positions passées en paramètre
    :param nucleotides: str
    :param debut: int
    :param fin: int
    :param return: str
    >>> transcription('TTCTTCTTCGTACTTTGTGCTGGCCTCCACACGATAATCC', 4, 23)
    'AAGAAGCAUGAAACACGACC'

    """
    newNucleotides = [nucleotides[a] for a in range(len(nucleotides)) if a >= debut-1 and a <= fin-1]
    newNucleotides = baseComplementaire(newNucleotides, 'ARN')
    return newNucleotides

def traduit(nucleotides) :
    """
    cette fonction construit la séquence protéique obtenue par la traduction de la séquence ARN passée en paramètre
    :param nucleotides: str
    :param traduction: str
    
    >>> traduit('AUGCGAAGCCGAAAGAACACCGGCUAA')
    'MRSRKNTG*'
    """
    groupe = []
    traduction = ''
    if (len(nucleotides) % 3) != 0 :
        return (False, 'Le nombre de nucleotides est incorect')
    for loop in range(0, len(nucleotides), 3) :
        groupe.append(nucleotides[loop] + nucleotides[loop + 1] + nucleotides[loop + 2])
    for ensemble in groupe :
        traduction = traduction + code_genetique[ensemble]
    return traduction

def replique(sequance) :
    """
    cette fonction construit la séquence ADN complémentaire et inversée de celle passée en paramètre
    :param sequance: str
    :param return: str
    
    >>> replique('ACTG')
    'CAGT'
    """
    Replique = {'A' : 'C', 'T' : 'G', 'G' : 'T', 'C' : 'A'}
    newSequance = ''
    for nucl in sequance :
        newSequance = newSequance + Replique[nucl]
    return newSequance
    
import doctest
doctest.testmod(verbose = True)