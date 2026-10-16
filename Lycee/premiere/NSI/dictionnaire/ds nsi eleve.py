nsi1 = {"Daniel":[11,2,3],"Jean":[2,3] ,"Rezak":[15,16],"Anne":[13,18,20],"Sonia":[2,18] }

eleves = [{"nom":"Colette","spe1":"Math","spe2":"NSI","spe3":"SVT"},
          {"nom":"Franck","spe1":"Math","spe2":"CINE","spe3":"PC"},
          {"nom":"Nicole","spe1":"PC","spe2":"NSI","spe3":"SVT"},
          {"nom":"Gilles","spe1":"Math","spe2":"PC","spe3":"SVT"},]

premiere = {
"Alain":{"Math":[12,3,14],"P.C.":[17,5,6],"SVT":[1,7]},
"Benoit":{"Math":[11,13,17],"NSI":[8],"SES":[9,12]},
"Celine":{"Math":[17,15],"SES":[12,14,9],"Anglais":[9,3,12]},
"David":{"Math":[13,15,8],"NSI":[7,15,10],"Anglais":[19,13,15]},
"Alex":{"Math":[13,15],"P.C.":[10],"NSI":[16,20]}
}

def nsi(table):
    """
    voir qui a la spé nsi dans table(classe d'élèves)
    return : list, liste des noms
    """
    eleveDeNSI = []
    for eleve in table :
        if "NSI" in table[eleve]  :
            eleveDeNSI.append(eleve)
    return eleveDeNSI

def moyenne(groupe,nom,matiere):
    """
    >>> moyenne(premiere,'Alain','Anglais')
    4.0
    >>> moyenne(premiere,'David','P.C.')
    10.67
    """
    
    return (round(sum(groupe[nom][matiere])/len(groupe[nom][matiere]),2))
    
    


def moyenne_generale(table,nom):
    """
    >>> moyenne_generale(premiere,'Alex')
    14.0
    """
    note = 0
    for spe in table[nom] :
        note = note + moyenne(table, nom, spe)
    return round(note/3, 2)
    #return (round((note = note + moyenne(table, nom, spe) for spe in table[nom])/3, 2)) 
    
    

def moyenne_classe(table):
    """
    >>> moyenne_classe(premiere)
    11.65
    """
    note = 0
    for eleve in table :
        note = note + moyenne_generale(table, eleve)
    return round(note/len(table), 2)
        

