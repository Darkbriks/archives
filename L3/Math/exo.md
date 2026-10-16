# Exercice 2

Pour la fonction suivante, definie sur l'interval $[0,2]$, determiner la valeur de $x$ pour qu'elle soit une densité de probabilité.

$f(x) = kx^3$

1) $f$ est continue par morceaux sur $[0,2]$
2) $\forall \ x \in [0,2],\ f(0) = 0 \geq 0$ et $f(2) = k2^3 = 8k \geq 0$
3) $$\int_{-\infty}^{+\infty} f(x)dx = 1 \Rightarrow \int_{0}^{2} kx^3dx = 1 \Rightarrow k\int_{0}^{2} x^3dx = 1 \Rightarrow$$
$$k\left[\frac{x^4}{4}\right]_{0}^{2} = 1 \Rightarrow k\left[\frac{2^4}{4} - \frac{0^4}{4}\right] = 1 \Rightarrow k\left[\frac{16}{4}\right] = 1 \Rightarrow k4 = 1 \Rightarrow k = \frac{1}{4}$$

Donc, pour que $f$ soit une densité de probabilité, il faut que $k = \frac{1}{4}$

# Exercice 3

Soit $X$ la variable aléatoire dont la fonction de densité définit sur $\mathbb{R+}$ par $f(x) = 4e^{-4x}$

a) Calculer $F(5)$

$$F(5) = \int_{-\infty}^{5} f(t)dt = \int_{0}^{5} 4e^{-4t}dt = 4\int_{0}^{5} e^{-4t}dt = 4\left[\frac{e^{-4t}}{-4}\right]_{0}^{5} = -e^{-20} + 1$$

b) Calculer $P(1 \leq X \leq 3)$

$$P(1 \leq X \leq 3) = F(3) - F(1) = \int_{0}^{3} 4e^{-4t}dt - \int_{0}^{1} 4e^{-4t}dt = 4\int_{0}^{3} e^{-4t}dt - 4\int_{0}^{1} e^{-4t}dt = 4$$
$$\left[\frac{e^{-4t}}{-4}\right]_{0}^{3} - 4\left[\frac{e^{-4t}}{-4}\right]_{0}^{1} = -e^{-12} + e^{-4}$$

# Exercice 4

Soit $f$ définie par :
$$f(x) = \left\{
    \begin{array}{ll}
        k(2-x) \ si \ x \in [0,1] \\
        0 \ sinon
    \end{array}
\right.$$

a) Pour quelle valeur de $k$ cette fonction est-elle une densité de probabilité ?

1) $f$ est continue par morceaux sur $[0,1]$
2) $\forall \ x \in [0,1], \ f(0) = k(2-0) = 2k \geq 0$ et $f(1) = k(2-1) = k \geq 0$
3) $$\int_{-\infty}^{+\infty} f(x)dx = 1 \Rightarrow \int_{0}^{1} k(2-x)dx = 1 \Rightarrow k\int_{0}^{1} (2-x)dx = 1$$
$$ \Rightarrow k\left[2x - \frac{x^2}{2}\right]_{0}^{1} = 1 \Rightarrow k\left[2 - \frac{1}{2}\right] = 1 \Rightarrow k\left[\frac{3}{2}\right] = 1 \Rightarrow k = \frac{2}{3}$$

b) Calculer sa fonction de répartition $F$

$$F(x) = \int_{-\infty}^{x} f(t)dt$$
$$x < 0, \ F(x) = 0$$
$$0 \leq x < 1, F(x) = \int_{0}^{x} f(t)dt = \int_{0}^{x} \frac{2}{3}(2-t)dt = \frac{2}{3}\int_{0}^{x} (2-t)dt$$
$$= \frac{2}{3}\left[2t - \frac{t^2}{2}\right]_{0}^{x} = \frac{2}{3}\left[2x - \frac{x^2}{2}\right] = \frac{2}{3}(2x - \frac{x^2}{2})$$
$$1 \leq x, \ F(x) = 1 \Rightarrow F(1) = \frac{2}{3}(2 - \frac{1}{2}) = \frac{2}{3}(\frac{3}{2}) = 1$$

# TD 2 Exercice 4

Déterminer si les fonctions suivantes sont des densités de probabilité, et déterminer la fonction de répartition associée de la variable aléatoire associée a cette densité le cas échéant.

a$g(t) = \left\{
    \begin{array}{ll}
        0 \ si \ t< 0 \\
        4te^{-2t} \ si \ t \geq 0
    \end{array}
\right.$

$g$ est continue sur $]-\infty, 0[$, et par produit de fonctions continues la fontion $t \mapsto 4te^{-2t}$ est continue sur $[0, +\infty[$

$g$ est une fonction positive
$$\mapsto 0 \geq 0$$
$$\mapsto 4te^{-2t} \geq 0 \quad t \geq 0$$

$$\int_{-\infty}^{+\infty} g(t)dt = 1$$
$$\int_{-\infty}^{+\infty} g(t)dt = \int_{-\infty}^{0} g(t)dt + \int_{0}^{+\infty} g(t)dt = 0 + \int_{0}^{+\infty} g(t)dt = \int_{0}^{+\infty} g(t)dt = 1$$

$$\int_{0}^{+\infty} 4te^{-2t}dt = \left[4t(-\frac{1}{2}e^{-2t})\right]_{0}^{+\infty} - \int_{0}^{+\infty} 4(-\frac{1}{2}e^{-2t})dt = \left[-2te^{-2t}\right]_{0}^{+\infty} + 2 \int_{0}^{+\infty} e^{-2t}dt$$
$$= 0 + 2\left[-\frac{1}{2}e^{-2t}\right]_{0}^{+\infty} = -\left[e^{-2t}\right]_{0}^{+\infty} = -(0-1) = 1$$

Soit $X$ une variable aléatoire réelle de densité $g$ et $G$ sa fonction de répartition
$$G(x) = \int_{-\infty}^{x} g(t)dt$$
$$x < 0,\quad G(x) = 0$$
$$x \geq 0,\quad G(x) = \int_{0}^{x} 4te^{-2t}dt = \left[-2te^{-2t}\right]_{0}^{x} + 2\int_{0}^{x} e^{-2t}dt$$
$$= -2xe^{-2x} + 2\left[-\frac{1}{2}e^{-2t}\right]_{0}^{x} = -2xe^{-2x} + 2(-\frac{1}{2}e^{-2x}) = -2xe^{-2x} - e^{-2x} = e^{-2x}(2x+1)$$
$$G(x) = \left\{
    \begin{array}{ll}
        0\quad si\quad x < 0 \\
        1-(2x+1)e^{-2x}\quad si\quad x \geq 0
    \end{array}
\right.$$

# TD 2 Exercice 5
Soit $x$ une variable aléatoire réelle dont la fontion de répartition $F$ est définie par :
$$F(x) = \left\{
    \begin{array}{ll}
        0 \ si \ x < 0 \\
        1-e^{(-x^2)/2} \ si \ x \geq 0
    \end{array}
\right.$$
Montrer que $X$ est une variable à densité et déterminer une densité de $X$

La fonction nulle est continue sur $]-\infty, 0[$ et par produit de fonctions continues, la fonction $x \mapsto 1-e^{(-x^2)/2}$ est continue sur $[0, +\infty[$. Donc $F$ est continue sur $\mathbb{R*}$

De plus, $\lim_{x \to 0^-} F(x) = 0 = \lim_{x \to 0^+} F(x)$. Donc $F$ est continue sur $\mathbb{R}$

La fontion nulle est dérivable sur $]-\infty, 0[$ et par produit de fonctions dérivables, la fonction $x \mapsto 1-e^{(-x^2)/2}$ est dérivable sur $[0, +\infty[$. Donc $F$ est dérivable sur $\mathbb{R*}$

$X$ est donc une variable aléatoire à densité

$$f(x) = F'(x) = \left\{
    \begin{array}{ll}
        0\quad si\quad x < 0 \\
        -\frac{-x^2}{2}e^{(-x^2)/2}\quad si\quad x \geq 0
    \end{array}
\right.$$
$$= \left\{
    \begin{array}{ll}
        0\quad si\quad x < 0 \\
        xe^{(-x^2)/2}\quad si\quad x \geq 0
    \end{array}
\right.$$

# TD 2 Exercice 6

On considère la fonction $f$ définie par :
$$f(x) = \left\{
    \begin{array}{ll}
        \frac{4}{3}(1-x)^{1/3}\quad si\quad 0 \leq x \leq 1 \\
        0\quad sinon
    \end{array}
\right.$$

a) Montrer que $f$ est la densité d'une variable aléatoire $X$

b) Déterminer la fonction de répartition $F$ de la variable $X$

c) Calculer l'éspérance de la variable $X$

d) Calculer $P(0.488 \leq X \leq 1.2)$

# TD 2 Exercice 7

Soit $(X, Y)$ un couple de variables aléatoires gaussien de moyennes $m=\begin{pmatrix} 0 \\ 0 \end{pmatrix}$ et de matrice de covariance $\Sigma = \begin{pmatrix} 5 & -2 \\ -2 & 2 \end{pmatrix}$ 

1) Donner l'expression de la densité de probabilité du couple $(X, Y)$
2) Donner la matrice de covariance du couple $(U, V)$, $U$ et $V$ étant définis par $\begin {cases} U = X + 2Y \\ V = 2X + Y \end{cases}$
3) Montrer que les variables aléatoires $U$ et $V$ sont indépendantes
4) Donner l'expression de la densité de probabilité du couple $(U, V)$

# Compilation

```bash
pandoc exo.md -o exo.pdf
```