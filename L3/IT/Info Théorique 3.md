# Exercice 1
## A. Quelle est la complexité temporelle de l'algorithme de Needleman-Wunsch ?
La complexité temporelle de l'algorithme de Needleman-Wunsch est polynomiale, $O(n*m)$.

## B. Dans quels cas l'alignement local de séquences est utilisé ?
L'alignement local de séquences est utilisé pour aligner une séquence avec une partie d'une autre séquence.

# Exercice 2
## A. En déroulant l'algorithme de Needleman-Wunsch de manière détaillée, aligner les séquences $S_{1} = AGGCT$ et $S_{2} = AGCTAT$.

|     | -   | A   | G   | G   | C   | T   |
| --- | --- | --- | --- | --- | --- | --- |
| -   | 0   | -1  | -2  | -3  | -4  | -5  |
| A   | -1  | 2   | 1   | 0   | -1  | -2  |
| G   | -2  | 1   | 4   | 3   | 2   | 1   |
| C   | -3  | 0   | 3   | 2   | 5   | 4   |
| T   | -4  | -1  | 2   | 1   | 4   | 7   |
| A   | -5  | -2  | 1   | 0   | 3   | 6   |
| T   | -6  | -3  | 0   | -1  | 2   | 5   |
Un alignement optimal possible pour ces séquences est :
$$
\begin{matrix}
A & G & G & C & - & - & T \\
A & - & G & C & T & A & T
\end{matrix}
$$

## B. Existe-t-il des alignements co-optimaux pour ces deux séquences ? Justifier
Pour ces deux séquences, il existe des alignements co-optimaux, car il est par exemple possible de les aligner de manière optimale de la façon suivante :
$$
\begin{matrix}
A & G & G & C & T & - & - \\
A & - & G & C & T & A & T
\end{matrix}
$$

## C. Donner le score de l'alignement multiple suivant en utilisant le principe de la somme des paires.
$$
\begin{matrix}
A & - & T & C & C & A \\
A & G & T & T & - & G \\
- & C & T & G & C & A \\
- & - & - & - & - & - \\
2 & -1 & 2 & -2 & -1 & -2 \\
-1 & -1 & 2 & -2 & 2 & 2 \\
-1 & -2 & 2 & -2 & -1 & -2 \\
= & = & = & = & = & = \\
0 & -4 & 6 & -6 & 0 & -2
\end{matrix}
$$

Le score de l'alignement multiple est $0-4+6-6+0-2=-6$

# Exercice 3
## A. $\{a^{n}b^{m} \mid 0 \leq n \leq m+1\}$
Alphabet terminal : $\Sigma = \{a, b\}$
Axiome : $S$
Règles de production :
1. $S \to aT \mid T$
2. $T \to aTU \mid \epsilon$
3. $U \to bU \mid \epsilon$

## B. $\{a^{n}b^{n}c^{m}d^{m} \mid n, m \geq 0\}$
Alphabet terminal : $\Sigma = \{a, b, c, d\}$
Axiome : $S$
Règles de production :
1. $S \to TU$
2. $T \to aTb \mid \epsilon$
3. $U \to cUd \mid \epsilon$

## C. $\{a^{n}b^{m}c^{p}d^{q} \mid n+q = m + p\}$
Alphabet terminal : $\Sigma = \{a, b, c, d\}$
Axiome : $S$
Règles de production :
1. $S \to A^{1}D \mid A^{2}D \mid \epsilon$
2. $A^{1} \to aA^{1}c \mid A^{2} \mid \epsilon$
3. $A^{2} \to aA^{2}b \mid \epsilon$
4. $D \to cDd \mid \epsilon$
*Faux, mais meilleure approximation trouvée*

# Exercice 4
## A. Quel est le langage reconnu par cette grammaire ?
$\{a^{n}(bb)^{m}a^{m}c^{l} \mid l \geq 1\ \ ; n, m \geq 0\}$

## B. Donner un arbre de dérivation pour le mot $w=aabbacc$
```mermaid
stateDiagram-v2
	s : S
	a1 : a
	s1 : S
	a2 : a
	s2 : S
	b : bb
	t : T
	a3 : a
	u1 : U
	c1 : c
	u2 : U
	c2 : c
    s --> a1
    s --> s1
    s1 --> a2
    s1 --> s2
    s2 --> b
    s2 --> t
    t --> a3
    t --> u1
    u1 --> c1
    u1 --> u2
    u2 --> c2
```

## C. Cette grammaire est elle ambigüe ? Justifier
Cette grammaire est ambigüe, car si on prend par exemple le mot $w=acc$, il est possible de le construire d'au moins 2 manières différentes :
```mermaid
stateDiagram-v2
	s : S
	a : a
	s1 : S
	c1 : c
	u : U
	c2 : c
    s --> a
    s --> s1
    s1 --> c1
    s1 --> u
    u --> c2
```
```mermaid
stateDiagram-v2
	s : S
	t : T
	a : a
	u1 : U
	c1 : c
	u2 : U
	c2 : c
    s --> t
    t --> a
    t --> u1
    u1 --> c1
    u1 --> u2
    u2 --> c2
```

# Exercice 5
## A.
```mermaid
stateDiagram-v2
    [*] --> S
    S --> S1: c
    S1 --> S: c
    S --> A: b
    S --> F : a
    A --> A: c
    A --> A1: b
    A1 --> B: c
    B --> B: a
    B --> F: a
    F --> [*]
```

## B.
```mermaid
stateDiagram-v2
    [*] --> S
    S --> S1: a
    S1 --> A: a
    S --> S: b
    S --> B : epsilon
    A --> A: a
    A --> F: epsilon
    B --> B: b
    B --> S: a
    F --> [*]
```
