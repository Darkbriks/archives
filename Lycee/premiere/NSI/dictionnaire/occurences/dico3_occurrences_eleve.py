texte1="Python est un langage de programmation qui peut s'utiliser dans de nombreux contextes et s'adapter à tout type d'utilisation grâce à des bibliothèques spécialisées. Il est cependant particulièrement utilisé comme langage de script pour automatiser des tâches simples mais fastidieuses, comme un script qui récupérerait la météo sur Internet ou qui s'intégrerait dans un logiciel de conception assistée par ordinateur afin d'automatiser certains enchaînements d'actions répétitives (voir la section Adoption). On l'utilise également comme langage de développement de prototype lorsqu'on a besoin d'une application fonctionnelle avant de l'optimiser avec un langage de plus bas niveau. Il est particulièrement répandu dans le monde scientifique, et possède de nombreuses bibliothèques optimisées destinées au calcul numérique."
texte2="Python is an interpreted, high-level and general-purpose programming language. Python's design philosophy emphasizes code readability with its notable use of significant whitespace. Its language constructs and object-oriented approach aim to help programmers write clear, logical code for small and large-scale projects. Python is dynamically-typed and garbage-collected. It supports multiple programming paradigms, including structured (particularly, procedural), object-oriented and functional programming. Python is often described as a batteries included language due to its comprehensive standard library."

texte1_a_vaut_k="zidryx ocd ex vkxqkqo no zbyqbkwwkdsyx aes zoed c'edsvscob nkxc no xywlboeh myxdohdoc od c'knkzdob à dyed dizo n'edsvsckdsyx qbâmo à noc lslvsydrèaeoc czémskvscéoc. sv ocd mozoxnkxd zkbdsmevsèbowoxd edsvscé mywwo vkxqkqo no cmbszd zyeb kedywkdscob noc dâmroc cswzvoc wksc pkcdsnsoecoc, mywwo ex cmbszd aes bémezébobksd vk wédéy ceb sxdobxod ye aes c'sxdéqbobksd nkxc ex vyqsmsov no myxmozdsyx kccscdéo zkb ybnsxkdoeb kpsx n'kedywkdscob mobdksxc oxmrkîxowoxdc n'kmdsyxc bézédsdsfoc (fysb vk comdsyx knyzdsyx). yx v'edsvsco éqkvowoxd mywwo vkxqkqo no néfovyzzowoxd no zbydydizo vybcae'yx k locysx n'exo kzzvsmkdsyx pyxmdsyxxovvo kfkxd no v'yzdswscob kfom ex vkxqkqo no zvec lkc xsfoke. sv ocd zkbdsmevsèbowoxd bézkxne nkxc vo wyxno cmsoxdspsaeo, od zyccèno no xywlboecoc lslvsydrèaeoc yzdswscéoc nocdsxéoc ke mkvmev xewébsaeo."
frequanceLangueFrancaise = {'e':12.10,'a':7.11,'i':6.59,'s':6.51,'n':6.39, 'r': 6.07, 't': 5.92, 'o': 5.02, 'l': 4.96 , 'u': 4.49 ,'d': 3.67 ,'c': 3.18, 'm': 2.62, 'p': 2.49, 'é': 1.94, 'g': 1.23, 'b': 1.14, 'v': 1.11, 'h': 1.11, 'f': 1.11, 'q': 0.65, 'y': 0.46, 'x': 0.38, 'j': 0.34, 'è': 0.31, 'à': 0.31, 'k': 0.29, 'w': 0.17, 'z': 0.15, 'ê': 0.08, 'ç': 0.06, 'ô': 0.04, 'â': 0.03, 'î': 0.03, 'û': 0.02, 'ù': 0.02, 'ï': 0.01, 'ü': 0.01, 'ë': 0.01}

def est_lettre(c):
    """
    à compléter, docstring et doctest à proposer
    
    cette fonction va mettre la lettre en minuscule puis si elle est dans l'alphabet "classique", on la retourne.
    si elle fait parti des lettres acentue, on retourne la lettre sans accent
    si elle ne correspont a aucune lettre francaise, on retourne false
    
    >>> est_lettre('a')
    'a'
    
    >>> est_lettre('â')
    'a'
    
    >>> est_lettre('!')
    False
    """
    c=c.lower()#lower() permet de passer les majuscules en minuscule
    if 97<=ord(c)<=122:#97 correspond a l'ord de a, 122 a l'ord de z. tester 97<=ord(c)<=122 revient a dire si une lettre est comprise entre a et z inclus
        return c
    elif c in "àâä":
        return "a"
    elif c in "éèêë":
        return "e"
    elif c in "îï":
        return "i"
    elif c in "ôö":
        return "o"
    elif c in "ùûü":
        return "u"
    else:
        return False
    

    
def occurrences_lettres(t):
    """calcule le nombre d'occurrences de chaque lettre dans un texte
    :param:(str) texte à étudier
    :return:(dict) de la forme {lettre:effectif}
    >>> d=occurrences_lettres("Ananas !")
    >>> len(d)
    3
    >>> d["a"]==3 and d["n"]==2 and d["s"]==1
    True
    """
    #à coder
    d={}
    for x in t :
        x = x.lower()
        if est_lettre(x) != False :
            if x in d :
                d[x] = d[x]+1
            else :
                d[x] = 1
    return d
    
def frequences_lettres(texte):
    """
    calcule la fréquence d'apparition de chaque lettre dans un texte
    :param:(str) texte à étudier
    :return:(dict) de la forme {lettre:fréquence}
    """
    #à coder
    d=occurrences_lettres(texte)
    nbLettre = sum(d.values())
    for lettre in d.keys():
        d[lettre] = round((d[lettre]/nbLettre)*100, 2)
    return d

def Casseur_de_code(texte_code):
    maxi = -1
    l = ''
    new_texte = ''
    f = frequences_lettres(texte_code)
    for lettre in f.keys():
        if f[lettre] > maxi :
            maxi = f[lettre]
            l = lettre
    
    ecart = ord(lettre) - ord('e')
    for caractere in texte_code :
        new_texte = new_texte + chr(ord(caractere)-ecart)
        
    return new_texte
        

import doctest
doctest.testmod()