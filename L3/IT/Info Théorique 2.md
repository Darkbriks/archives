## **1. Définitions de base**

### **Mot et Langage**

- **Mot** : Un mot est une séquence finie de symboles d'un alphabet (par exemple, {a, b}).
- **Langage** : Un langage est un ensemble de mots sur un alphabet donné. On peut définir un langage de manière explicite, ou le décrire à l'aide de règles, comme des expressions régulières ou des automates.

### **Expression régulière simple**

- Une **expression régulière** est une notation permettant de décrire des langages. Par exemple :
    - `a*` : zéro ou plusieurs occurrences de `a`
    - `(ab|cd)*` : une alternance entre "ab" et "cd", répétée n'importe quel nombre de fois
    - `[a-z]+` : une ou plusieurs lettres minuscules

---

## **2. Automates finis**

### **Automate fini déterministe (DFA)**

- **Définition** : Un automate fini déterministe est une machine qui reconnaît un langage en suivant une séquence de transitions à partir d'un état initial, avec des règles déterminées pour chaque symbole de l'alphabet.
    - Formulation : M=(Q,Σ,δ,q0,F)M = (Q, \Sigma, \delta, q_0, F)
        - QQ : ensemble des états
        - Σ\Sigma : alphabet
        - δ\delta : fonction de transition
        - q0q_0 : état initial
        - FF : ensemble des états finaux

### **Construire un automate fini déterministe**

1. Identifier les états possibles du système.
2. Définir les transitions entre les états pour chaque symbole de l'alphabet.
3. Spécifier un état initial et des états finaux.

### **Langage reconnu par un automate fini déterministe**

- Le **langage reconnu** par un automate fini déterministe est l'ensemble des mots qui, lorsqu'ils sont lus par l'automate, le mènent à un état final.

### **Écrire l'expression régulière d’un langage reconnu par un DFA**

- Utiliser les opérations algébriques (union, concaténation, étoile) pour exprimer le langage accepté par un automate sous forme d'une expression régulière.

---

## **3. Automates non-déterministes (NFA)**

### **Automate fini non-déterministe (NFA)**

- **Définition** : Un automate fini non-déterministe permet plusieurs transitions pour un même symbole ou même aucune transition. Il n'y a pas de trajectoire unique vers un état final.
    - Formulation : N=(Q,Σ,δ,q0,F)N = (Q, \Sigma, \delta, q_0, F), mais ici, δ\delta peut donner plusieurs résultats.

### **Déterminisation d’un automate fini non-déterministe**

1. Créer un ensemble d'états pour représenter les différentes configurations possibles de l’automate non-déterministe.
2. Appliquer une procédure de construction de l'automate déterministe équivalent (algorithme de déterminisation).

### **Langage rationnel**

- Un **langage rationnel** est un langage qui peut être décrit par une expression régulière ou reconnu par un automate fini. Les langages rationnels sont fermés par les opérations de réunion, concaténation et étoile.

### **Théorème de Kleene**

- Le **théorème de Kleene** établit que le langage d'un automate fini est exactement le même que celui décrit par une expression régulière, c'est-à-dire qu'il existe une correspondance entre les automates finis et les expressions régulières.

---

## **4. Automates pondérés et machines de Turing**

### **Automate pondéré**

- Un **automate pondéré** est un automate dont les transitions sont associées à des poids, souvent utilisés pour modéliser des problèmes de décision avec des coûts ou des probabilités.

### **Machine de Turing**

- **Définition** : Une machine de Turing est un modèle de calcul plus puissant qu'un automate fini, capable de résoudre des problèmes qui ne peuvent pas être résolus par des automates finis. Elle est constituée d'une bande infinie, d'une tête de lecture/écriture, et d'une fonction de transition.
- **Langage reconnu** : Le langage reconnu par une machine de Turing est l'ensemble des mots sur lesquels la machine finit dans un état d'acceptation.
- **Fonction calculée** : La fonction calculée par une machine de Turing est la transformation qu'elle effectue sur les mots d'entrée, en fonction des règles de transition.

### **Thèse de Church-Turing**

- La **thèse de Church-Turing** affirme que tout problème calculable par un humain à l’aide d’une méthode algorithmique peut être résolu par une machine de Turing.

### **Problème de l’arrêt**

- Le **problème de l'arrêt** est le problème de déterminer si un programme donné s'arrêtera ou non sur une entrée spécifique. Il est **non calculable** (indécidable).

---

## **5. Complexité algorithmique**

### **Complexité temporelle et spatiale**

- **Complexité temporelle** : Mesure du nombre d'étapes qu'un algorithme effectue en fonction de la taille de l'entrée.
- **Complexité spatiale** : Mesure de l'espace mémoire utilisé par un algorithme en fonction de la taille de l'entrée.

### **Notation "grand O"**

- La notation **O** décrit la **complexité asymptotique** d’un algorithme, en indiquant son comportement pour de grandes tailles d'entrée. Par exemple, O(n)O(n) signifie que le temps d'exécution de l'algorithme est proportionnel à la taille de l'entrée.

### **Classes de complexité**

- **P** : Classe des problèmes résolus en temps polynomial.
- **NP** : Classe des problèmes dont une solution peut être vérifiée en temps polynomial.
- **NP-complet** : Problèmes qui sont les plus difficiles de NP, au sens où tout problème de NP peut être réduit en temps polynomial à un problème NP-complet.

### **Problèmes SAT et 3-SAT**

- **SAT** (problème de satisfiabilité) consiste à déterminer si une formule booléenne est satisfiable.
- **3-SAT** est une version du problème SAT où chaque clause contient exactement 3 littéraux.

### **Réduction en problème SAT**

- Une **réduction en SAT** consiste à transformer un problème de décision donné en une instance de SAT de manière à ce que la solution du problème initial corresponde à celle de l'instance SAT.

---

## **6. Théorème de Cook-Levin**

### **Théorème de Cook-Levin**

- Le **théorème de Cook-Levin** affirme que le problème SAT est NP-complet. Cela signifie que SAT est l'un des problèmes les plus fondamentaux dans la classe NP, et que la résolution de SAT permettrait de résoudre tous les problèmes de NP en temps polynomial.

---

### **7. Conjonction (ET) : ∧\land**

L'opérateur de conjonction (ET) donne le résultat **vrai** seulement si les deux opérandes sont vrais.

|AA|BB|A∧BA \land B|
|---|---|---|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

---

### **8. Disjonction (OU) : ∨\lor**

L'opérateur de disjonction (OU) donne le résultat **vrai** si au moins l'un des opérandes est vrai.

|AA|BB|A∨BA \lor B|
|---|---|---|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

---

### **9. Négation (NON) : ¬\neg**

L'opérateur de négation (NON) inverse la valeur de vérité de l'opérande. Si AA est vrai, ¬A\neg A sera faux, et vice versa.

|AA|¬A\neg A|
|---|---|
|0|1|
|1|0|

---

### **10. Implication (SI...ALORS) : ⇒\Rightarrow**

L'opérateur d'implication est vrai sauf lorsque AA est vrai et BB est faux.
A⇒B≡¬A∨B

|AA|BB|A⇒BA \Rightarrow B|
|---|---|---|
|0|0|1|
|0|1|1|
|1|0|0|
|1|1|1|

---

### **11. Équivalence (SI et seulement SI) : ⇔\Leftrightarrow**

L'opérateur d'équivalence est vrai lorsque AA et BB ont la même valeur de vérité.
A⇔B≡(A∧B)∨(¬A∧¬B)

|AA|BB|A⇔BA \Leftrightarrow B|
|---|---|---|
|0|0|1|
|0|1|0|
|1|0|0|
|1|1|1|
