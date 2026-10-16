# 1.
Il s'agit d'un probléme de classification, car il s'agit de trouver la qualité (élysée, asphodèle, tartare) d'une âme.

# 2.
Dans ce cas, un arbre prédit un vecteur qui associe chaque qualité a une probabilité. Dans la cas ci dessus, une prédiction d'un arbre pourrait être (0, 0.45, 0.55), signifiant que la probabilitée pour l'élysée est de 0%, celle pour asphodèle est 45% et celle pour le tartare est  55%.

# 3.
Dans le cas d'un probléme de regression, un arbre va renvoyer la moyenne ou la mediane des valeurs contenus dans la feuille.

# 4.
Le fait de disposer de ces critéres pourrait être benefique, car cela augmente les chances de trouver une relation correctes entre les xi et yi. Cepandant, disposer de ces donnée peut égalment poser un probléme de suraprentissage, et ainsi, avoir une erreur nulle ou quasi nulle sur la base d'entrainement, mais être trés mauvais lors de la généralisation. Pour contrebalencer ce probléme, on peut procéder a un élégage de l'arbre, c'est a dire partir des feuilles, et remonter en, supprimer les neoud qui apportent peut de gain d'entropie. On peut également limiter la profondeur de l'arbre, ou encore ajouter un contrainte sur le nombre minumium d'echantillon dans un neud pour le diviser.

# 5.
Dans un probléme de classificaation, on peut utiliser l'entropie pour mesurer la dispertion des valeurs. Cette mesure sera minimale dans le cas d'une feuille pure, c'est a dire qui ne contient qu'une seule qualité, et maximale dans la cas d'un neud qui contient autant d'exemple de chaque qualité

# 6.
Dans le cas d'un probléme de regression, on utilise généralement la variance pour mesurer la dispértion des valeurs d'un noeud. Comme pour l'entropie, elle est minimale dans la cas d'une feuiulle pure. Cepandant, la variance peut théoriquement tendre vers l'infini, et n'a pas de valeur maximum. Cepandant, plus les donnée de l'ensemble sont étérogéne, et plus elle augmentera

# 7.
Les questions potentiellement interessante pour la racine sont:
- poids < 1.5
- poids < 2.5
- premium ?
- Fan de JJG ?

# 8.
- Calcul grâce a l'entropie

# 9.
- /

# 10.
- Suivre le chemin

# 11.
Dans un probléme de classification, on peut mesurer l'erreur de prédiction en calculant le taux d'erreur de l'arbre (proportion d'exemples mal classé). Plus un arbre est grand, et plus l'erreur aura tendance a diminuer, mais dépand également grandement de la base d'apprentissage. Par exemple, si elle est trop petite, ou si certaines classe sont mal représanté, l'arbre pourrait avoir pluus de difficulté lors de la généralisation

# 12.
Il peut être mauvais d'avoir une faible erreur, car cela peut signifier que l'arbre a fait du suraprentissage. Pour savoir si on est dans un tel cas, on peut coparer l'erreur sur la base d'aprenstissage et sur une bas de vérification, qui contiennent des donné differantes, et si l'erreur sur la base d'apprentissage diminue, alors que celle sur la base de vérification stage ou augmente, cela veut probablement dire que l'on se trouve dans un tel cas.

# 13.
Non, car l'algo ne vas explorer qu'une partie de l'espace disponible en maximisant certains critéres, mais il pourrait exister un arbre plus performant en dehors de l'espace explorer, qui ne maximise pas les critéres de l'algo, mais posséde une meilleure erreru de généralisation

# 16.
Les differances entre les deux en termes de qualité de jeu sont trés faible, voir identique, si alpha et beta sont correctement choisi. Cepandant, minmax est beaucoup plus leng car il pratique une recherche exhaustive.

# 17.
O(b^d)

# 18.
Il peut être améliorer en modifiant l'odre dans lequel les noeud sont visité.


> réponses de Thomas sur discord
# 21. L'algorithme Dijkstra retourne-t-il toujours un chemin optimal ?

Oui, l'algorithme de Dijkstra retourne toujours un chemin optimal à condition que toutes les arêtes aient des poids non négatifs. Si les poids des arêtes peuvent être négatifs, Dijkstra ne garantit plus l'optimalité.

# 22. L'algorithme A* retourne-t-il toujours un chemin optimal ?

Oui, l'algorithme A* retourne toujours un chemin optimal si l'heuristique utilisée est admissible (elle ne surestime jamais le coût réel pour atteindre le but). Dans ce cas, l'heuristique donnée est admissible, donc A* trouvera le chemin optimal.

# 23. L'algorithme A* visite-t-il toujours moins de nœuds que Dijkstra ?

Non, l'algorithme A* ne visite pas toujours moins de nœuds que Dijkstra. Cela dépend de la qualité de l'heuristique utilisée. Si l'heuristique est très précise, A* peut visiter moins de nœuds que Dijkstra. Cependant, si l'heuristique est moins informative, A* peut finir par visiter autant ou même plus de nœuds que Dijkstra.