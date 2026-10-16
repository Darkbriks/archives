# TP3 Patron Antoine

## Q3 Jointure interne : non équi-jointure
### 3.1
#### 3.1.1 - Equi jointure - Lister pour chaque nom de réalisateur, son année de naissance, les noms et l’année de naissance des acteurs qui sont nés la même année, classé par nom de réalisateur et année de naissance d’acteur croissante
```sql
mysql> SELECT realisateur.nom_real, realisateur.anNais_real, acteur.nom_act, acteur.anNais_act FROM realisateur, acteur WHERE realisateur.anNais_real = acteur.anNais_act ORDER BY acteur.anNais_act ASC;
+--------------------+-------------+---------------------+------------+
| nom_real           | anNais_real | nom_act             | anNais_act |
+--------------------+-------------+---------------------+------------+
| Clint Eastwood     |        1930 | Clint Eastwood      |       1930 |
| Antonello Grimaldi |        1955 | Isabelle Adjani     |       1955 |
| Andreas Dresen     |        1963 | Olivier Gourmet     |       1963 |
| Ben Stiller        |        1965 | Ben Stiller         |       1965 |
| Ben Stiller        |        1965 | Robert Downey Jr.   |       1965 |
| Ben Stiller        |        1965 | Alessandro Gassman  |       1965 |
| Joann Sfar         |        1971 | Guillaume Depardieu |       1971 |
| Ursula Meier       |        1971 | Guillaume Depardieu |       1971 |
+--------------------+-------------+---------------------+------------+
8 rows in set (0,00 sec)
```

#### 3.1.2 - Non équi jointure - Lister pour chaque nom de réalisateur, son année de naissance, les noms et l’année de naissance des acteurs qui sont plus jeunes que lui, classé par nom de réalisateur et année de naissance d’acteur croissante
```sql
mysql> SELECT realisateur.nom_real, realisateur.anNais_real, acteur.nom_act, acteur.anNais_act FROM realisateur, acteur WHERE realisateur.anNais_real >= acteur.anNais_act ORDER BY acteur.anNais_act ASC, realisateur.nom_real ASC;
+--------------------+-------------+------------------------+------------+
| nom_real           | anNais_real | nom_act                | anNais_act |
+--------------------+-------------+------------------------+------------+
| Andreas Dresen     |        1963 | Annie Cordy            |       1928 |
| Anna Novion        |        1979 | Annie Cordy            |       1928 |
| Antonello Grimaldi |        1955 | Annie Cordy            |       1928 |
| Ben Stiller        |        1965 | Annie Cordy            |       1928 |
| Clint Eastwood     |        1930 | Annie Cordy            |       1928 |
| Edward Zwick       |        1952 | Annie Cordy            |       1928 |
| Hong Sang-soo      |        1960 | Annie Cordy            |       1928 |
| Joann Sfar         |        1971 | Annie Cordy            |       1928 |
| Pascal Thomas      |        1945 | Annie Cordy            |       1928 |
| René Féret         |        1945 | Annie Cordy            |       1928 |
| Sylvie Verheyde    |        1967 | Annie Cordy            |       1928 |
| Ursula Meier       |        1971 | Annie Cordy            |       1928 |
| Andreas Dresen     |        1963 | Horst Westphal         |       1929 |
| Anna Novion        |        1979 | Horst Westphal         |       1929 |
| Antonello Grimaldi |        1955 | Horst Westphal         |       1929 |
| Ben Stiller        |        1965 | Horst Westphal         |       1929 |
| Clint Eastwood     |        1930 | Horst Westphal         |       1929 |
| Edward Zwick       |        1952 | Horst Westphal         |       1929 |
| Hong Sang-soo      |        1960 | Horst Westphal         |       1929 |
| Joann Sfar         |        1971 | Horst Westphal         |       1929 |
| Pascal Thomas      |        1945 | Horst Westphal         |       1929 |
| René Féret         |        1945 | Horst Westphal         |       1929 |
| Sylvie Verheyde    |        1967 | Horst Westphal         |       1929 |
| Ursula Meier       |        1971 | Horst Westphal         |       1929 |
| Andreas Dresen     |        1963 | Clint Eastwood         |       1930 |
| Anna Novion        |        1979 | Clint Eastwood         |       1930 |
| Antonello Grimaldi |        1955 | Clint Eastwood         |       1930 |
| Ben Stiller        |        1965 | Clint Eastwood         |       1930 |
| Clint Eastwood     |        1930 | Clint Eastwood         |       1930 |
| Edward Zwick       |        1952 | Clint Eastwood         |       1930 |
| Hong Sang-soo      |        1960 | Clint Eastwood         |       1930 |
| Joann Sfar         |        1971 | Clint Eastwood         |       1930 |
| Pascal Thomas      |        1945 | Clint Eastwood         |       1930 |
| René Féret         |        1945 | Clint Eastwood         |       1930 |
| Sylvie Verheyde    |        1967 | Clint Eastwood         |       1930 |
| Ursula Meier       |        1971 | Clint Eastwood         |       1930 |
| Andreas Dresen     |        1963 | Ursula Werner          |       1943 |
| Anna Novion        |        1979 | Ursula Werner          |       1943 |
| Antonello Grimaldi |        1955 | Ursula Werner          |       1943 |
| Ben Stiller        |        1965 | Ursula Werner          |       1943 |
| Edward Zwick       |        1952 | Ursula Werner          |       1943 |
| Hong Sang-soo      |        1960 | Ursula Werner          |       1943 |
| Joann Sfar         |        1971 | Ursula Werner          |       1943 |
| Pascal Thomas      |        1945 | Ursula Werner          |       1943 |
| René Féret         |        1945 | Ursula Werner          |       1943 |
| Sylvie Verheyde    |        1967 | Ursula Werner          |       1943 |
| Ursula Meier       |        1971 | Ursula Werner          |       1943 |
| Andreas Dresen     |        1963 | André Dussolier        |       1946 |
| Anna Novion        |        1979 | André Dussolier        |       1946 |
| Antonello Grimaldi |        1955 | André Dussolier        |       1946 |
| Ben Stiller        |        1965 | André Dussolier        |       1946 |
| Edward Zwick       |        1952 | André Dussolier        |       1946 |
| Hong Sang-soo      |        1960 | André Dussolier        |       1946 |
| Joann Sfar         |        1971 | André Dussolier        |       1946 |
| Sylvie Verheyde    |        1967 | André Dussolier        |       1946 |
| Ursula Meier       |        1971 | André Dussolier        |       1946 |
| Andreas Dresen     |        1963 | Jean-Pierre Darroussin |       1953 |
| Andreas Dresen     |        1963 | John Malkovich         |       1953 |
| Andreas Dresen     |        1963 | Isabelle Huppert       |       1953 |
| Andreas Dresen     |        1963 | Nanni Moretti          |       1953 |
| Anna Novion        |        1979 | Jean-Pierre Darroussin |       1953 |
| Anna Novion        |        1979 | John Malkovich         |       1953 |
| Anna Novion        |        1979 | Isabelle Huppert       |       1953 |
| Anna Novion        |        1979 | Nanni Moretti          |       1953 |
| Antonello Grimaldi |        1955 | Jean-Pierre Darroussin |       1953 |
| Antonello Grimaldi |        1955 | John Malkovich         |       1953 |
| Antonello Grimaldi |        1955 | Isabelle Huppert       |       1953 |
| Antonello Grimaldi |        1955 | Nanni Moretti          |       1953 |
| Ben Stiller        |        1965 | Jean-Pierre Darroussin |       1953 |
| Ben Stiller        |        1965 | John Malkovich         |       1953 |
| Ben Stiller        |        1965 | Isabelle Huppert       |       1953 |
| Ben Stiller        |        1965 | Nanni Moretti          |       1953 |
| Hong Sang-soo      |        1960 | Jean-Pierre Darroussin |       1953 |
| Hong Sang-soo      |        1960 | John Malkovich         |       1953 |
| Hong Sang-soo      |        1960 | Isabelle Huppert       |       1953 |
| Hong Sang-soo      |        1960 | Nanni Moretti          |       1953 |
| Joann Sfar         |        1971 | Jean-Pierre Darroussin |       1953 |
| Joann Sfar         |        1971 | John Malkovich         |       1953 |
| Joann Sfar         |        1971 | Isabelle Huppert       |       1953 |
| Joann Sfar         |        1971 | Nanni Moretti          |       1953 |
| Sylvie Verheyde    |        1967 | Jean-Pierre Darroussin |       1953 |
| Sylvie Verheyde    |        1967 | John Malkovich         |       1953 |
| Sylvie Verheyde    |        1967 | Isabelle Huppert       |       1953 |
| Sylvie Verheyde    |        1967 | Nanni Moretti          |       1953 |
| Ursula Meier       |        1971 | Jean-Pierre Darroussin |       1953 |
| Ursula Meier       |        1971 | John Malkovich         |       1953 |
| Ursula Meier       |        1971 | Isabelle Huppert       |       1953 |
| Ursula Meier       |        1971 | Nanni Moretti          |       1953 |
| Andreas Dresen     |        1963 | Isabelle Adjani        |       1955 |
| Anna Novion        |        1979 | Isabelle Adjani        |       1955 |
| Antonello Grimaldi |        1955 | Isabelle Adjani        |       1955 |
| Ben Stiller        |        1965 | Isabelle Adjani        |       1955 |
| Hong Sang-soo      |        1960 | Isabelle Adjani        |       1955 |
| Joann Sfar         |        1971 | Isabelle Adjani        |       1955 |
| Sylvie Verheyde    |        1967 | Isabelle Adjani        |       1955 |
| Ursula Meier       |        1971 | Isabelle Adjani        |       1955 |
| Andreas Dresen     |        1963 | Catherine Frot         |       1956 |
| Anna Novion        |        1979 | Catherine Frot         |       1956 |
| Ben Stiller        |        1965 | Catherine Frot         |       1956 |
| Hong Sang-soo      |        1960 | Catherine Frot         |       1956 |
| Joann Sfar         |        1971 | Catherine Frot         |       1956 |
| Sylvie Verheyde    |        1967 | Catherine Frot         |       1956 |
| Ursula Meier       |        1971 | Catherine Frot         |       1956 |
| Andreas Dresen     |        1963 | Tom Cruise             |       1962 |
| Anna Novion        |        1979 | Tom Cruise             |       1962 |
| Ben Stiller        |        1965 | Tom Cruise             |       1962 |
| Joann Sfar         |        1971 | Tom Cruise             |       1962 |
| Sylvie Verheyde    |        1967 | Tom Cruise             |       1962 |
| Ursula Meier       |        1971 | Tom Cruise             |       1962 |
| Andreas Dresen     |        1963 | Olivier Gourmet        |       1963 |
| Anna Novion        |        1979 | Olivier Gourmet        |       1963 |
| Ben Stiller        |        1965 | Olivier Gourmet        |       1963 |
| Joann Sfar         |        1971 | Olivier Gourmet        |       1963 |
| Sylvie Verheyde    |        1967 | Olivier Gourmet        |       1963 |
| Ursula Meier       |        1971 | Olivier Gourmet        |       1963 |
| Anna Novion        |        1979 | Isabelle Ferrari       |       1964 |
| Ben Stiller        |        1965 | Isabelle Ferrari       |       1964 |
| Joann Sfar         |        1971 | Isabelle Ferrari       |       1964 |
| Sylvie Verheyde    |        1967 | Isabelle Ferrari       |       1964 |
| Ursula Meier       |        1971 | Isabelle Ferrari       |       1964 |
| Anna Novion        |        1979 | Ben Stiller            |       1965 |
| Anna Novion        |        1979 | Robert Downey Jr.      |       1965 |
| Anna Novion        |        1979 | Alessandro Gassman     |       1965 |
| Ben Stiller        |        1965 | Ben Stiller            |       1965 |
| Ben Stiller        |        1965 | Robert Downey Jr.      |       1965 |
| Ben Stiller        |        1965 | Alessandro Gassman     |       1965 |
| Joann Sfar         |        1971 | Ben Stiller            |       1965 |
| Joann Sfar         |        1971 | Robert Downey Jr.      |       1965 |
| Joann Sfar         |        1971 | Alessandro Gassman     |       1965 |
| Sylvie Verheyde    |        1967 | Ben Stiller            |       1965 |
| Sylvie Verheyde    |        1967 | Robert Downey Jr.      |       1965 |
| Sylvie Verheyde    |        1967 | Alessandro Gassman     |       1965 |
| Ursula Meier       |        1971 | Ben Stiller            |       1965 |
| Ursula Meier       |        1971 | Robert Downey Jr.      |       1965 |
| Ursula Meier       |        1971 | Alessandro Gassman     |       1965 |
| Anna Novion        |        1979 | Valeria Golino         |       1966 |
| Anna Novion        |        1979 | Sophie Marceau         |       1966 |
| Joann Sfar         |        1971 | Valeria Golino         |       1966 |
| Joann Sfar         |        1971 | Sophie Marceau         |       1966 |
| Sylvie Verheyde    |        1967 | Valeria Golino         |       1966 |
| Sylvie Verheyde    |        1967 | Sophie Marceau         |       1966 |
| Ursula Meier       |        1971 | Valeria Golino         |       1966 |
| Ursula Meier       |        1971 | Sophie Marceau         |       1966 |
| Anna Novion        |        1979 | Judith Henry           |       1968 |
| Joann Sfar         |        1971 | Judith Henry           |       1968 |
| Ursula Meier       |        1971 | Judith Henry           |       1968 |
| Anna Novion        |        1979 | Jack Black             |       1969 |
| Joann Sfar         |        1971 | Jack Black             |       1969 |
| Ursula Meier       |        1971 | Jack Black             |       1969 |
| Anna Novion        |        1979 | Guillaume Depardieu    |       1971 |
| Joann Sfar         |        1971 | Guillaume Depardieu    |       1971 |
| Ursula Meier       |        1971 | Guillaume Depardieu    |       1971 |
| Anna Novion        |        1979 | Benjamin Biolay        |       1973 |
| Anna Novion        |        1979 | Karole Rocher          |       1974 |
| Anna Novion        |        1979 | Angeline Jolie         |       1975 |
| Anna Novion        |        1979 | Nicolas Giraud         |       1978 |
+--------------------+-------------+------------------------+------------+
156 rows in set (0,00 sec)
```

## 4 - Jointure externe
### 4.1
#### 4.1.1 - Jointure interne - Lister les réalisateurs et les titres des films qu'ils ont réalisés, classé par titre de film croissant
```sql
mysql> SELECT realisateur.nom_real, film.titre_film FROM realisateur INNER JOIN film ON realisateur.num_real = film.num_real ORDER BY film.titre_film ASC;
+--------------------+-------------------------------------+
| nom_real           | titre_film                          |
+--------------------+-------------------------------------+
| Antonello Grimaldi | Caos Calmo                          |
| René Féret         | Comme une ?oile dans la nuit        |
| Ursula Meier       | Home                                |
| George Lucas       | Indiana Jones and the Crystal Skull |
| Clint Eastwood     | L'?hange                            |
| Claude Pinoteau    | La boom                             |
| Pascal Thomas      | Le crime est notre affaire          |
| Andreas Dresen     | Le septieme ciel                    |
| Anna Novion        | Les grandes personnes               |
| George Lucas       | Red Tails                           |
| George Lucas       | Star Wars: Episode IV - A New Hope  |
| Sylvie Verheyde    | Stella                              |
| Edward Zwick       | The Last Samurai                    |
| Ben Stiller        | Tonnere sous les tropiques          |
| Hong Sang-soo      | Woman on the beach                  |
+--------------------+-------------------------------------+
15 rows in set (0,00 sec)
```

#### 4.1.2 - Combien de réalisateurs ont réalisé au moins un film ?
```sql
mysql> SELECT COUNT(DISTINCT realisateur.nom_real) FROM realisateur INNER JOIN film ON realisateur.num_real = film.num_real;
+--------------------------------------+
| COUNT(DISTINCT realisateur.nom_real) |
+--------------------------------------+
|                                   13 |
+--------------------------------------+
1 row in set (0,01 sec)
```
#### 4.1.3 - Compter les réalisateurs dans la table `realisateur` ; D'où provient l'écart avec le résultat précédent ?
```sql
mysql> SELECT COUNT(DISTINCT realisateur.nom_real) FROM realisateur;
+--------------------------------------+
| COUNT(DISTINCT realisateur.nom_real) |
+--------------------------------------+
|                                   14 |
+--------------------------------------+
1 row in set (0,00 sec)
```
L'écart provient du fait qu'un réalisateur n'a pas réalisé de film. Il n'à donc pas pu être joint avec la table `film` et n'apparait donc pas dans le résultat de la requête précédente.

#### 4.1.4 - Jointure externe - Lister __tous__ les réalisateurs et éventuellement les titres des films qu'ils ont réalisés, classé par titre de film croissant
```sql
mysql> SELECT realisateur.nom_real, film.titre_film FROM realisateur LEFT JOIN film ON realisateur.num_real = film.num_real ORDER BY film.titre_film ASC;
+--------------------+-------------------------------------+
| nom_real           | titre_film                          |
+--------------------+-------------------------------------+
| Joann Sfar         | NULL                                |
| Antonello Grimaldi | Caos Calmo                          |
| René Féret         | Comme une ?oile dans la nuit        |
| Ursula Meier       | Home                                |
| George Lucas       | Indiana Jones and the Crystal Skull |
| Clint Eastwood     | L'?hange                            |
| Claude Pinoteau    | La boom                             |
| Pascal Thomas      | Le crime est notre affaire          |
| Andreas Dresen     | Le septieme ciel                    |
| Anna Novion        | Les grandes personnes               |
| George Lucas       | Red Tails                           |
| George Lucas       | Star Wars: Episode IV - A New Hope  |
| Sylvie Verheyde    | Stella                              |
| Edward Zwick       | The Last Samurai                    |
| Ben Stiller        | Tonnere sous les tropiques          |
| Hong Sang-soo      | Woman on the beach                  |
+--------------------+-------------------------------------+
16 rows in set (0,00 sec)
```

#### 4.1.5 - Même chose que le précedant mais avec l'indication `NA` pour les réalisateurs qui n'ont pas réalisé de film
```sql
mysql> SELECT realisateur.nom_real, IF(film.titre_film IS NULL, 'NA', film.titre_film) FROM realisateur LEFT JOIN film ON realisateur.num_real = film.num_real ORDER BY film.titre_film ASC;
+--------------------+----------------------------------------------------+
| nom_real           | IF(film.titre_film IS NULL, 'NA', film.titre_film) |
+--------------------+----------------------------------------------------+
| Joann Sfar         | NA                                                 |
| Antonello Grimaldi | Caos Calmo                                         |
| René Féret         | Comme une ?oile dans la nuit                       |
| Ursula Meier       | Home                                               |
| George Lucas       | Indiana Jones and the Crystal Skull                |
| Clint Eastwood     | L'?hange                                           |
| Claude Pinoteau    | La boom                                            |
| Pascal Thomas      | Le crime est notre affaire                         |
| Andreas Dresen     | Le septieme ciel                                   |
| Anna Novion        | Les grandes personnes                              |
| George Lucas       | Red Tails                                          |
| George Lucas       | Star Wars: Episode IV - A New Hope                 |
| Sylvie Verheyde    | Stella                                             |
| Edward Zwick       | The Last Samurai                                   |
| Ben Stiller        | Tonnere sous les tropiques                         |
| Hong Sang-soo      | Woman on the beach                                 |
+--------------------+----------------------------------------------------+
16 rows in set (0,00 sec)
```

## 5 - Jointures internes et jointures externes
### 5.1
#### 5.1.1 - Lister les noms des acteurs et écentuellement les titres des films dans lesquels ils ont joué, classé par nom d'acteur et par titre de film croissant
```sql
mysql> SELECT acteur.nom_act, film.titre_film FROM acteur LEFT JOIN jouer ON acteur.num_act = jouer.num_act LEFT JOIN film ON jouer.num_film = film.num_film ORDER BY acteur.nom_act ASC, film.titre_film ASC;
+------------------------+------------------------------+
| nom_act                | titre_film                   |
+------------------------+------------------------------+
| Alessandro Gassman     | Caos Calmo                   |
| André Dussolier        | Le crime est notre affaire   |
| Angeline Jolie         | L'?hange                     |
| Angeline Jolie         | Le septieme ciel             |
| Annie Cordy            | Le crime est notre affaire   |
| Ben Stiller            | Tonnere sous les tropiques   |
| Benjamin Biolay        | Stella                       |
| Catherine Frot         | Le crime est notre affaire   |
| Clint Eastwood         | NULL                         |
| Guillaume Depardieu    | Stella                       |
| Horst Westphal         | Le septieme ciel             |
| Isabelle Adjani        | NULL                         |
| Isabelle Ferrari       | NULL                         |
| Isabelle Huppert       | Home                         |
| Jack Black             | Tonnere sous les tropiques   |
| Jean-Pierre Darroussin | Home                         |
| Jean-Pierre Darroussin | Le crime est notre affaire   |
| Jean-Pierre Darroussin | Les grandes personnes        |
| John Malkovich         | L'?hange                     |
| Judith Henry           | Les grandes personnes        |
| Judith Henry           | Stella                       |
| Karole Rocher          | Stella                       |
| Leora Barbara          | Stella                       |
| Melissa Rodrigues      | Stella                       |
| Nanni Moretti          | Caos Calmo                   |
| Nicolas Giraud         | Comme une ?oile dans la nuit |
| Olivier Gourmet        | Home                         |
| Robert Downey Jr.      | Tonnere sous les tropiques   |
| Salomé Stéverin        | Comme une ?oile dans la nuit |
| Sophie Marceau         | La boom                      |
| Tom Cruise             | Comme une ?oile dans la nuit |
| Tom Cruise             | The Last Samurai             |
| Tom Cruise             | Woman on the beach           |
| Ursula Werner          | Le septieme ciel             |
| Valeria Golino         | Caos Calmo                   |
+------------------------+------------------------------+
35 rows in set (0,00 sec)
```

#### 5.1.2 - Même chose que le précedant mais avec l'indication `NA` pour les acteurs qui n'ont pas joué dans de film, trié par titre de film et par nom d'acteur croissant
```sql
mysql> SELECT acteur.nom_act, IF(film.titre_film IS NULL, 'NA', film.titre_film) FROM acteur LEFT JOIN jouer ON acteur.num_act = jouer.num_act LEFT JOIN film ON jouer.num_film = film.num_film ORDER BY film.titre_film ASC, acteur.nom_act ASC;
+------------------------+----------------------------------------------------+
| nom_act                | IF(film.titre_film IS NULL, 'NA', film.titre_film) |
+------------------------+----------------------------------------------------+
| Clint Eastwood         | NA                                                 |
| Isabelle Adjani        | NA                                                 |
| Isabelle Ferrari       | NA                                                 |
| Alessandro Gassman     | Caos Calmo                                         |
| Nanni Moretti          | Caos Calmo                                         |
| Valeria Golino         | Caos Calmo                                         |
| Nicolas Giraud         | Comme une ?oile dans la nuit                       |
| Salomé Stéverin        | Comme une ?oile dans la nuit                       |
| Tom Cruise             | Comme une ?oile dans la nuit                       |
| Isabelle Huppert       | Home                                               |
| Jean-Pierre Darroussin | Home                                               |
| Olivier Gourmet        | Home                                               |
| Angeline Jolie         | L'?hange                                           |
| John Malkovich         | L'?hange                                           |
| Sophie Marceau         | La boom                                            |
| André Dussolier        | Le crime est notre affaire                         |
| Annie Cordy            | Le crime est notre affaire                         |
| Catherine Frot         | Le crime est notre affaire                         |
| Jean-Pierre Darroussin | Le crime est notre affaire                         |
| Angeline Jolie         | Le septieme ciel                                   |
| Horst Westphal         | Le septieme ciel                                   |
| Ursula Werner          | Le septieme ciel                                   |
| Jean-Pierre Darroussin | Les grandes personnes                              |
| Judith Henry           | Les grandes personnes                              |
| Benjamin Biolay        | Stella                                             |
| Guillaume Depardieu    | Stella                                             |
| Judith Henry           | Stella                                             |
| Karole Rocher          | Stella                                             |
| Leora Barbara          | Stella                                             |
| Melissa Rodrigues      | Stella                                             |
| Tom Cruise             | The Last Samurai                                   |
| Ben Stiller            | Tonnere sous les tropiques                         |
| Jack Black             | Tonnere sous les tropiques                         |
| Robert Downey Jr.      | Tonnere sous les tropiques                         |
| Tom Cruise             | Woman on the beach                                 |
+------------------------+----------------------------------------------------+
35 rows in set (0,00 sec)
```

#### 5.1.3 - Lister tous les noms d'acteurs et éventuellement les numéros des salles dans lesquelles on a pu les voir, classé par salle croissante et par nom d'acteur croissant
```sql
mysql> SELECT acteur.nom_act, IF(salle.num_salle IS NULL, 'NA', salle.num_salle) as salle FROM acteur LEFT JOIN jouer ON acteur.num_act = jouer.num_act LEFT JOIN film ON jouer.num_film = film.num_film LEFT JOIN projeter ON film.num_film = projeter.num_film LEFT JOIN salle ON projeter.num_salle = salle.num_salle ORDER BY salle.num_salle ASC, acteur.nom_act ASC;
+------------------------+-------+
| nom_act                | salle |
+------------------------+-------+
| Clint Eastwood         | NA    |
| Isabelle Adjani        | NA    |
| Isabelle Ferrari       | NA    |
| Nicolas Giraud         | NA    |
| Salomé Stéverin        | NA    |
| Sophie Marceau         | NA    |
| Tom Cruise             | NA    |
| Alessandro Gassman     | 1     |
| Angeline Jolie         | 1     |
| Angeline Jolie         | 1     |
| Horst Westphal         | 1     |
| Jean-Pierre Darroussin | 1     |
| John Malkovich         | 1     |
| Judith Henry           | 1     |
| Nanni Moretti          | 1     |
| Tom Cruise             | 1     |
| Tom Cruise             | 1     |
| Ursula Werner          | 1     |
| Valeria Golino         | 1     |
| Alessandro Gassman     | 2     |
| Angeline Jolie         | 2     |
| Angeline Jolie         | 2     |
| Horst Westphal         | 2     |
| Jean-Pierre Darroussin | 2     |
| John Malkovich         | 2     |
| Judith Henry           | 2     |
| Nanni Moretti          | 2     |
| Tom Cruise             | 2     |
| Ursula Werner          | 2     |
| Valeria Golino         | 2     |
| Alessandro Gassman     | 3     |
| Angeline Jolie         | 3     |
| Ben Stiller            | 3     |
| Benjamin Biolay        | 3     |
| Guillaume Depardieu    | 3     |
| Jack Black             | 3     |
| John Malkovich         | 3     |
| Judith Henry           | 3     |
| Karole Rocher          | 3     |
| Leora Barbara          | 3     |
| Melissa Rodrigues      | 3     |
| Nanni Moretti          | 3     |
| Robert Downey Jr.      | 3     |
| Tom Cruise             | 3     |
| Valeria Golino         | 3     |
| André Dussolier        | 4     |
| André Dussolier        | 4     |
| Angeline Jolie         | 4     |
| Annie Cordy            | 4     |
| Annie Cordy            | 4     |
| Benjamin Biolay        | 4     |
| Catherine Frot         | 4     |
| Catherine Frot         | 4     |
| Guillaume Depardieu    | 4     |
| Isabelle Huppert       | 4     |
| Jean-Pierre Darroussin | 4     |
| Jean-Pierre Darroussin | 4     |
| Jean-Pierre Darroussin | 4     |
| John Malkovich         | 4     |
| Judith Henry           | 4     |
| Karole Rocher          | 4     |
| Leora Barbara          | 4     |
| Melissa Rodrigues      | 4     |
| Olivier Gourmet        | 4     |
| Tom Cruise             | 4     |
| André Dussolier        | 5     |
| Angeline Jolie         | 5     |
| Annie Cordy            | 5     |
| Benjamin Biolay        | 5     |
| Catherine Frot         | 5     |
| Guillaume Depardieu    | 5     |
| Isabelle Huppert       | 5     |
| Jean-Pierre Darroussin | 5     |
| Jean-Pierre Darroussin | 5     |
| John Malkovich         | 5     |
| Judith Henry           | 5     |
| Karole Rocher          | 5     |
| Leora Barbara          | 5     |
| Melissa Rodrigues      | 5     |
| Olivier Gourmet        | 5     |
| Tom Cruise             | 5     |
+------------------------+-------+
81 rows in set (0,00 sec)
```

## 6 Sous-requêtes indépendantes et sous-requêtes corrélées
### 6.1 Sous-requêtes : Principes généraux
#### 6.1.1
##### 6.1.1.1 - Pour lister les acteurs qui sont plus jeunes que `Sophie Marceau` :
###### 6.1.1.1.a - D'abord, récupérer l'année de naissance de `Sophie Marceau`
```sql
mysql> SELECT acteur.anNais_act FROM acteur WHERE acteur.nom_act = 'Sophie Marceau';
+------------+
| anNais_act |
+------------+
|       1966 |
+------------+
1 row in set (0,00 sec)
```

###### 6.1.1.1.b - Puis, lister les acteurs dont l'année de naissance est supérieure à celle de `Sophie Marceau`
```sql
mysql> SELECT acteur.nom_act, acteur.anNais_act FROM acteur WHERE acteur.anNais_act > (SELECT acteur.anNais_act FROM acteur WHERE acteur.nom_act = 'Sophie Marceau');
+---------------------+------------+
| nom_act             | anNais_act |
+---------------------+------------+
| Judith Henry        |       1968 |
| Angeline Jolie      |       1975 |
| Jack Black          |       1969 |
| Salomé Stéverin     |       1985 |
| Nicolas Giraud      |       1978 |
| Leora Barbara       |       1996 |
| Karole Rocher       |       1974 |
| Melissa Rodrigues   |       1988 |
| Benjamin Biolay     |       1973 |
| Guillaume Depardieu |       1971 |
+---------------------+------------+
10 rows in set (0,00 sec)
```

###### 6.1.1.1.c - On peut aussi répondre à cette question en utilisant une non équi auto-jointure
```sql
mysql> SELECT acteur.nom_act, acteur.anNais_act FROM acteur, acteur AS acteur2 WHERE acteur.anNais_act > acteur2.anNais_act AND acteur2.nom_act = 'Sophie Marceau';
+---------------------+------------+
| nom_act             | anNais_act |
+---------------------+------------+
| Judith Henry        |       1968 |
| Angeline Jolie      |       1975 |
| Jack Black          |       1969 |
| Salomé Stéverin     |       1985 |
| Nicolas Giraud      |       1978 |
| Leora Barbara       |       1996 |
| Karole Rocher       |       1974 |
| Melissa Rodrigues   |       1988 |
| Benjamin Biolay     |       1973 |
| Guillaume Depardieu |       1971 |
+---------------------+------------+
10 rows in set (0,00 sec)
```

##### 6.1.1.2 - Lister lmes films dont le réalisateur est né en `1971`
###### 6.1.1.2.a - D'abord, récupérer le numéro des réalisateurs nés en `1971`
```sql
mysql> SELECT realisateur.num_real FROM realisateur WHERE realisateur.anNais_real = 1971;
+----------+
| num_real |
+----------+
|        4 |
|       12 |
+----------+
2 rows in set (0,00 sec)
```

###### 6.1.1.2.b - Puis, lister les films dont le numéro de réalisateur est le numéro d'un réalisateur né en `1971`
```sql
mysql> SELECT * FROM film WHERE film.num_real = (SELECT realisateur.num_real FROM realisateur WHERE realisateur.anNais_real = 1971);
ERROR 1242 (21000): Subquery returns more than 1 row
```

###### 6.1.1.2.c - Proposer la requête et l'opérateur adéquat pour répondre à la question précédente
```sql
mysql> SELECT * FROM film WHERE film.num_real IN (SELECT realisateur.num_real FROM realisateur WHERE realisateur.anNais_real = 1971);
+----------+------------+---------------+-------------+-------------------+----------+
| num_film | titre_film | anSortie_film | budget_film | genre_film        | num_real |
+----------+------------+---------------+-------------+-------------------+----------+
|        7 | Home       |          2008 |     3000000 | film documentaire |        4 |
+----------+------------+---------------+-------------+-------------------+----------+
1 row in set (0,00 sec)
```

###### 6.1.1.2.d - Essayer la même requête avec `2000` comme année de naissance
```sql
mysql> SELECT * FROM film WHERE film.num_real IN (SELECT realisateur.num_real FROM realisateur WHERE realisateur.anNais_real = 2000);
Empty set (0,00 sec)
```

### 6.2 Sous-requêtes indépendantes
#### 6.2.1
##### 6.2.1.1 - Lister les acteurs et les films dans lesquels ils ont joués, avec le nom d'acteur, le titre du film, le pourcentage de cachet perçu par rapport au total général des cachets, classé par nom d'acteur et numéro de film croissants
###### 6.2.1.1.a - D'abord, récupérer le total des cachets perçus
```sql
mysql> SELECT sum(cachet_jouer) FROM jouer;
+-------------------+
| sum(cachet_jouer) |
+-------------------+
|           1758995 |
+-------------------+
1 row in set (0,00 sec)
```

###### 6.2.1.1.b - Puis lister les noms d'acteurs, les titres de films, le rapport du chachet au total des cachets perçus
```sql
mysql> SELECT acteur.nom_act, film.titre_film, jouer.cachet_jouer, (jouer.cachet_jouer / (SELECT sum(cachet_jouer) FROM jouer)) * 100 as TotalCachetActeur FROM acteur, jouer, film WHERE acteur.num_act = jouer.num_act AND jouer.num_film = film.num_film ORDER BY acteur.nom_act ASC, film.num_film ASC;
+------------------------+------------------------------+--------------+-------------------+
| nom_act                | titre_film                   | cachet_jouer | TotalCachetActeur |
+------------------------+------------------------------+--------------+-------------------+
| Alessandro Gassman     | Caos Calmo                   |        12770 |            0.7260 |
| André Dussolier        | Le crime est notre affaire   |        41578 |            2.3637 |
| Angeline Jolie         | Le septieme ciel             |        10202 |            0.5800 |
| Angeline Jolie         | L'?hange                     |        54198 |            3.0812 |
| Annie Cordy            | Le crime est notre affaire   |        63537 |            3.6121 |
| Ben Stiller            | Tonnere sous les tropiques   |        85961 |            4.8869 |
| Benjamin Biolay        | Stella                       |        77410 |            4.4008 |
| Catherine Frot         | Le crime est notre affaire   |        47358 |            2.6923 |
| Guillaume Depardieu    | Stella                       |        95731 |            5.4424 |
| Horst Westphal         | Le septieme ciel             |        24677 |            1.4029 |
| Isabelle Huppert       | Home                         |        46566 |            2.6473 |
| Jack Black             | Tonnere sous les tropiques   |        73347 |            4.1698 |
| Jean-Pierre Darroussin | Le crime est notre affaire   |        54618 |            3.1051 |
| Jean-Pierre Darroussin | Home                         |         1613 |            0.0917 |
| Jean-Pierre Darroussin | Les grandes personnes        |        21846 |            1.2420 |
| John Malkovich         | L'?hange                     |        95734 |            5.4425 |
| Judith Henry           | Stella                       |        96460 |            5.4838 |
| Judith Henry           | Les grandes personnes        |        90175 |            5.1265 |
| Karole Rocher          | Stella                       |        79894 |            4.5420 |
| Leora Barbara          | Stella                       |        64132 |            3.6459 |
| Melissa Rodrigues      | Stella                       |        70226 |            3.9924 |
| Nanni Moretti          | Caos Calmo                   |        10308 |            0.5860 |
| Nicolas Giraud         | Comme une ?oile dans la nuit |        48137 |            2.7366 |
| Olivier Gourmet        | Home                         |        12263 |            0.6972 |
| Robert Downey Jr.      | Tonnere sous les tropiques   |        71812 |            4.0826 |
| Salomé Stéverin        | Comme une ?oile dans la nuit |         4565 |            0.2595 |
| Sophie Marceau         | La boom                      |        98680 |            5.6100 |
| Tom Cruise             | The Last Samurai             |        55887 |            3.1772 |
| Tom Cruise             | Woman on the beach           |        90487 |            5.1442 |
| Tom Cruise             | Comme une ?oile dans la nuit |        80740 |            4.5901 |
| Ursula Werner          | Le septieme ciel             |        47557 |            2.7036 |
| Valeria Golino         | Caos Calmo                   |        30526 |            1.7354 |
+------------------------+------------------------------+--------------+-------------------+
32 rows in set (0,00 sec)
```

### 6.3 Sous-requêtes corrélées
#### 6.3.1
##### 6.3.1.1 - Lister les acteurs et les films dans lesquels ils ont joués, avec le nom d'acteur, le titre du film, le pourcentage de cachet perçu par rapport au total général des cachets, classé par nom d'acteur et numéro de film croissants
###### 6.3.1.1.a - D'abord, récupérer le total des cachets perçus de l'acteur ? (? devra être remplacé par une valeur de la requête principale)
```sql
SELECT sum(cachet_jouer) FROM jouer WHERE num_act = ?;
```
###### 6.3.1.1.b - Puis lister les noms d'acteurs, les titres de films, le rapport du chachet au total des cachets perçus de l'acteur
```sql
mysql> SELECT acteur.nom_act, film.titre_film, jouer.cachet_jouer, (jouer.cachet_jouer / (SELECT sum(cachet_jouer) FROM jouer WHERE num_act = acteur.num_act)) * 100 as TotalCachetActeur FROM acteur, jouer, film WHERE acteur.num_act = jouer.num_act AND jouer.num_film = film.num_film ORDER BY acteur.nom_act ASC, film.num_film ASC;
+------------------------+------------------------------+--------------+-------------------+
| nom_act                | titre_film                   | cachet_jouer | TotalCachetActeur |
+------------------------+------------------------------+--------------+-------------------+
| Alessandro Gassman     | Caos Calmo                   |        12770 |          100.0000 |
| André Dussolier        | Le crime est notre affaire   |        41578 |          100.0000 |
| Angeline Jolie         | Le septieme ciel             |        10202 |           15.8416 |
| Angeline Jolie         | L'?hange                     |        54198 |           84.1584 |
| Annie Cordy            | Le crime est notre affaire   |        63537 |          100.0000 |
| Ben Stiller            | Tonnere sous les tropiques   |        85961 |          100.0000 |
| Benjamin Biolay        | Stella                       |        77410 |          100.0000 |
| Catherine Frot         | Le crime est notre affaire   |        47358 |          100.0000 |
| Guillaume Depardieu    | Stella                       |        95731 |          100.0000 |
| Horst Westphal         | Le septieme ciel             |        24677 |          100.0000 |
| Isabelle Huppert       | Home                         |        46566 |          100.0000 |
| Jack Black             | Tonnere sous les tropiques   |        73347 |          100.0000 |
| Jean-Pierre Darroussin | Le crime est notre affaire   |        54618 |           69.9540 |
| Jean-Pierre Darroussin | Home                         |         1613 |            2.0659 |
| Jean-Pierre Darroussin | Les grandes personnes        |        21846 |           27.9801 |
| John Malkovich         | L'?hange                     |        95734 |          100.0000 |
| Judith Henry           | Stella                       |        96460 |           51.6838 |
| Judith Henry           | Les grandes personnes        |        90175 |           48.3162 |
| Karole Rocher          | Stella                       |        79894 |          100.0000 |
| Leora Barbara          | Stella                       |        64132 |          100.0000 |
| Melissa Rodrigues      | Stella                       |        70226 |          100.0000 |
| Nanni Moretti          | Caos Calmo                   |        10308 |          100.0000 |
| Nicolas Giraud         | Comme une ?oile dans la nuit |        48137 |          100.0000 |
| Olivier Gourmet        | Home                         |        12263 |          100.0000 |
| Robert Downey Jr.      | Tonnere sous les tropiques   |        71812 |          100.0000 |
| Salomé Stéverin        | Comme une ?oile dans la nuit |         4565 |          100.0000 |
| Sophie Marceau         | La boom                      |        98680 |          100.0000 |
| Tom Cruise             | The Last Samurai             |        55887 |           24.6075 |
| Tom Cruise             | Woman on the beach           |        90487 |           39.8421 |
| Tom Cruise             | Comme une ?oile dans la nuit |        80740 |           35.5504 |
| Ursula Werner          | Le septieme ciel             |        47557 |          100.0000 |
| Valeria Golino         | Caos Calmo                   |        30526 |          100.0000 |
+------------------------+------------------------------+--------------+-------------------+
32 rows in set (0,00 sec)
```

## 7 - Intersection et requêtes non imbriquées
### 7.1
#### 7.1.1 - Avec l'opérateur `in`
##### 7.1.1.1 - Lister les réalisateurs s'il existe des films de ces réalisateurs qui on été projetés dans la salle `1`
###### 7.1.1.1.a - D'abord, récupérer les numéros des réalisateurs dont les films ont été projetés dans la salle `1`, classé par numéro de réalisateur croissant
```sql
mysql> SELECT DISTINCT realisateur.num_real FROM realisateur, film, projeter WHERE realisateur.num_real = film.num_real AND film.num_film = projeter.num_film AND projeter.num_salle = 1 ORDER BY realisateur.num_real ASC;
+----------+
| num_real |
+----------+
|        1 |
|        2 |
|        6 |
|        9 |
|       10 |
|       11 |
+----------+
6 rows in set (0,00 sec)
```

###### 7.1.1.1.b - Puis, lister les réalisateurs dont le numéro est dans la liste précédente, classé par numéro de réalisateur croissant
```sql
mysql> SELECT * FROM realisateur WHERE realisateur.num_real IN (SELECT DISTINCT realisateur.num_real FROM realisateur, film, projeter WHERE realisateur.num_real = film.num_real AND film.num_film = projeter.num_film AND projeter.num_salle = 1) ORDER BY realisateur.num_real ASC;
+----------+--------------------+-------------+
| num_real | nom_real           | anNais_real |
+----------+--------------------+-------------+
|        1 | Edward Zwick       |        1952 |
|        2 | Clint Eastwood     |        1930 |
|        6 | Andreas Dresen     |        1963 |
|        9 | Hong Sang-soo      |        1960 |
|       10 | Anna Novion        |        1979 |
|       11 | Antonello Grimaldi |        1955 |
+----------+--------------------+-------------+
6 rows in set (0,00 sec)
```

#### 7.1.2 - Avec l'opérateur `exists`
##### 7.1.2.1 - Lister les réalisateurs s'il existe des films de ces réalisateurs qui on été projetés dans la salle `1`
###### 7.1.2.1.a - D'abord, lister les projections de films du réalisateur ? dans la salle `1`
```sql
SELECT * FROM projeter WHERE projeter.num_film IN (SELECT film.num_film FROM film WHERE film.num_real = ?) AND projeter.num_salle = 1;
```

###### 7.1.2.1.b - Puis, lister les réalisateurs s'il existe des projections de films du réalisateur ? dans la salle `1`, classé par numéro de réalisateur croissant
```sql
mysql> SELECT * FROM realisateur WHERE EXISTS (SELECT * FROM projeter WHERE projeter.num_film IN (SELECT film.num_film FROM film WHERE film.num_real = realisateur.num_real) AND projeter.num_salle = 1) ORDER BY realisateur.num_real ASC;
+----------+--------------------+-------------+
| num_real | nom_real           | anNais_real |
+----------+--------------------+-------------+
|        1 | Edward Zwick       |        1952 |
|        2 | Clint Eastwood     |        1930 |
|        6 | Andreas Dresen     |        1963 |
|        9 | Hong Sang-soo      |        1960 |
|       10 | Anna Novion        |        1979 |
|       11 | Antonello Grimaldi |        1955 |
+----------+--------------------+-------------+
6 rows in set (0,00 sec)
```

## 8 - Différance et requêtes imbriquées
### 8.1
#### 8.1.1 - Avec l'opérateur `not in`
##### 8.1.1.1 - Lister les réalisateurs s'il n'existe pas de films de ces réalisateurs qui on été projetés dans la salle `1`
###### 8.1.1.1.a - D'abord, récupérer les numéros des réalisateurs dont les films ont été projetés dans la salle `1`, classé par numéro de réalisateur croissant
```sql
mysql> SELECT DISTINCT realisateur.num_real FROM realisateur, film, projeter WHERE realisateur.num_real = film.num_real AND film.num_film = projeter.num_film AND projeter.num_salle = 1 ORDER BY realisateur.num_real ASC;
+----------+
| num_real |
+----------+
|        1 |
|        2 |
|        6 |
|        9 |
|       10 |
|       11 |
+----------+
6 rows in set (0,00 sec)
```

###### 8.1.1.1.b - Puis, lister les réalisateurs dont le numéro ne se trouve pas dans la liste précédente, classé par numéro de réalisateur croissant
```sql
mysql> SELECT * FROM realisateur WHERE realisateur.num_real NOT IN (SELECT DISTINCT realisateur.num_real FROM realisateur, film, projeter WHERE realisateur.num_real = film.num_real AND film.num_film = projeter.num_film AND projeter.num_salle = 1) ORDER BY realisateur.num_real ASC;
+----------+-----------------+-------------+
| num_real | nom_real        | anNais_real |
+----------+-----------------+-------------+
|        3 | Ben Stiller     |        1965 |
|        4 | Ursula Meier    |        1971 |
|        5 | René Féret      |        1945 |
|        7 | Sylvie Verheyde |        1967 |
|        8 | Pascal Thomas   |        1945 |
|       12 | Joann Sfar      |        1971 |
|       13 | Claude Pinoteau |        1925 |
|       14 | George Lucas    |        NULL |
+----------+-----------------+-------------+
8 rows in set (0,00 sec)
```

#### 8.1.2 - Avec l'opérateur `not exists`
##### 8.1.2.1 - Lister les réalisateurs s'il n'existe pas de films de ces réalisateurs qui on été projetés dans la salle `1`
###### 8.1.2.1.a - D'abord, lister les projections de films du réalisateur `x` dans la salle `1`
```sql
SELECT * FROM projeter WHERE projeter.num_film IN (SELECT film.num_film FROM film WHERE film.num_real = x) AND projeter.num_salle = 1;
```

###### 8.1.2.1.b - Puis, lister les réalisateurs s'il n'existe pas de projections de films du réalisateur `x` dans la salle `1`, classé par numéro de réalisateur croissant
```sql
mysql> SELECT * FROM realisateur WHERE NOT EXISTS (SELECT * FROM projeter WHERE projeter.num_film IN (SELECT film.num_film FROM film WHERE film.num_real = realisateur.num_real) AND projeter.num_salle = 1) ORDER BY realisateur.num_real ASC;
+----------+-----------------+-------------+
| num_real | nom_real        | anNais_real |
+----------+-----------------+-------------+
|        3 | Ben Stiller     |        1965 |
|        4 | Ursula Meier    |        1971 |
|        5 | René Féret      |        1945 |
|        7 | Sylvie Verheyde |        1967 |
|        8 | Pascal Thomas   |        1945 |
|       12 | Joann Sfar      |        1971 |
|       13 | Claude Pinoteau |        1925 |
|       14 | George Lucas    |        NULL |
+----------+-----------------+-------------+
8 rows in set (0,00 sec)
```

## 9 - Division et requêtes imbriquées
### 9.1
#### 9.1.1 - Lister les films qui ont été projetés dans toutes les salles dans lesquelles au moins un film a été projeté
##### 9.1.1.a - Lister les films tel qu'il n'existe pas de salles (dans lequelles des projections ont eu lieu) dans lesquelles le film n'a pas été projeté
###### 9.1.1.a.1 - Lister les salles dans lesquelles au moins un film a été projeté
```sql
mysql> SELECT DISTINCT projeter.num_salle FROM projeter;
+-----------+
| num_salle |
+-----------+
|         1 |
|         2 |
|         3 |
|         4 |
|         5 |
+-----------+
5 rows in set (0,00 sec)
```

###### 9.1.1.a.2 - Lister les films qui ont été projetés dans toutes les salles de la liste précédente
```sql
SELECT DISTINCT f.* FROM film f WHERE NOT EXISTS (
    SELECT DISTINCT p1.num_salle FROM projeter p1 WHERE NOT EXISTS (
    SELECT DISTINCT p2.num_salle FROM projeter p2 WHERE p1.num_salle = p2.num_salle AND p2.num_film = f.num_film));
+----------+------------------+---------------+-------------+------------+----------+
| num_film | titre_film       | anSortie_film | budget_film | genre_film | num_real |
+----------+------------------+---------------+-------------+------------+----------+
|        1 | The Last Samurai |          2003 |     8000000 | ?op?       |        1 |
|        9 | L'?hange         |          2008 |     5000000 | Drame      |        2 |
+----------+------------------+---------------+-------------+------------+----------+
2 rows in set (0,00 sec)
```

##### 9.1.1.b - Lister les films tels que le nombre de salles différentes dans lesquelles ils ont été projetés correspond au nombre de salles dans lesquelles au moins un film a été projeté
```sql
mysql> SELECT DISTINCT f.* FROM film f WHERE (SELECT COUNT(DISTINCT p1.num_salle) FROM projeter p1 WHERE p1.num_film = f.num_film) = (SELECT COUNT(DISTINCT p2.num_salle) FROM projeter p2);
+----------+------------------+---------------+-------------+------------+----------+
| num_film | titre_film       | anSortie_film | budget_film | genre_film | num_real |
+----------+------------------+---------------+-------------+------------+----------+
|        1 | The Last Samurai |          2003 |     8000000 | ?op?       |        1 |
|        9 | L'?hange         |          2008 |     5000000 | Drame      |        2 |
+----------+------------------+---------------+-------------+------------+----------+
2 rows in set (0,00 sec)
```

## 10 - Union
### 10.1
#### 10.1.1 - Lister les nom des acteurs et des réalisateurs
```sql
mysql> SELECT acteur.nom_act FROM acteur UNION SELECT realisateur.nom_real FROM realisateur;
+------------------------+
| nom_act                |
+------------------------+
| Tom Cruise             |
| Jean-Pierre Darroussin |
| Judith Henry           |
| Angeline Jolie         |
| John Malkovich         |
| Ben Stiller            |
| Jack Black             |
| Robert Downey Jr.      |
| Isabelle Huppert       |
| Olivier Gourmet        |
| Salomé Stéverin        |
| Nicolas Giraud         |
| Ursula Werner          |
| Horst Westphal         |
| Nanni Moretti          |
| Valeria Golino         |
| Alessandro Gassman     |
| Isabelle Ferrari       |
| Leora Barbara          |
| Karole Rocher          |
| Melissa Rodrigues      |
| Benjamin Biolay        |
| Guillaume Depardieu    |
| Catherine Frot         |
| André Dussolier        |
| Annie Cordy            |
| Isabelle Adjani        |
| Clint Eastwood         |
| Sophie Marceau         |
| Edward Zwick           |
| Ursula Meier           |
| René Féret             |
| Andreas Dresen         |
| Sylvie Verheyde        |
| Pascal Thomas          |
| Hong Sang-soo          |
| Anna Novion            |
| Antonello Grimaldi     |
| Joann Sfar             |
| Claude Pinoteau        |
| George Lucas           |
+------------------------+
41 rows in set (0,00 sec)
```

#### 10.1.2 - Lister les nom des acteurs et des réalisateurs, en les distinguant
```sql
mysql> SELECT acteur.nom_act, 'acteur' as type FROM acteur UNION SELECT realisateur.nom_real, 'realisateur' as type FROM realisateur;
+------------------------+-------------+
| nom_act                | type        |
+------------------------+-------------+
| Tom Cruise             | acteur      |
| Jean-Pierre Darroussin | acteur      |
| Judith Henry           | acteur      |
| Angeline Jolie         | acteur      |
| John Malkovich         | acteur      |
| Ben Stiller            | acteur      |
| Jack Black             | acteur      |
| Robert Downey Jr.      | acteur      |
| Isabelle Huppert       | acteur      |
| Olivier Gourmet        | acteur      |
| Salomé Stéverin        | acteur      |
| Nicolas Giraud         | acteur      |
| Ursula Werner          | acteur      |
| Horst Westphal         | acteur      |
| Nanni Moretti          | acteur      |
| Valeria Golino         | acteur      |
| Alessandro Gassman     | acteur      |
| Isabelle Ferrari       | acteur      |
| Leora Barbara          | acteur      |
| Karole Rocher          | acteur      |
| Melissa Rodrigues      | acteur      |
| Benjamin Biolay        | acteur      |
| Guillaume Depardieu    | acteur      |
| Catherine Frot         | acteur      |
| André Dussolier        | acteur      |
| Annie Cordy            | acteur      |
| Isabelle Adjani        | acteur      |
| Clint Eastwood         | acteur      |
| Sophie Marceau         | acteur      |
| Edward Zwick           | realisateur |
| Clint Eastwood         | realisateur |
| Ben Stiller            | realisateur |
| Ursula Meier           | realisateur |
| René Féret             | realisateur |
| Andreas Dresen         | realisateur |
| Sylvie Verheyde        | realisateur |
| Pascal Thomas          | realisateur |
| Hong Sang-soo          | realisateur |
| Anna Novion            | realisateur |
| Antonello Grimaldi     | realisateur |
| Joann Sfar             | realisateur |
| Claude Pinoteau        | realisateur |
| George Lucas           | realisateur |
+------------------------+-------------+
43 rows in set (0,00 sec)
```

#### 10.1.3 - D'où vient cette différence de comptage ?
Cette différence de comptage vient du fait que 2 acteurs sont aussi réalisateurs, ce qui ajoute 2 lignes quand on cherche a séparer les acteurs des réalisateurs.

## 11 - Les vue stockées
### 11.1
#### 11.1.1 - Créer une vue
```sql
mysql> CREATE VIEW pilotesAvecVol AS SELECT DISTINCT numpil FROM pilote INNER JOIN vol USING ( numpil );
Query OK, 0 rows affected (0,01 sec)
```

#### 11.1.2 - Utiliser une vue
```sql
mysql> SELECT * FROM pilotesAvecVol ORDER BY numpil ;
+--------+
| numpil |
+--------+
|      2 |
+--------+
1 row in set (0,00 sec)
```

#### 11.1.3 - Lister les pilotes qui ont effectué au moins un vol
```sql
mysql> SELECT * FROM pilote WHERE numpil IN ( SELECT numpil FROM pilotesAvecVol ) ORDER BY numpil ;
+--------+--------+--------+------------+
| numpil | nompil | vilpil | salairepil |
+--------+--------+--------+------------+
|      2 | John   | Calais | 2000       |
+--------+--------+--------+------------+
1 row in set (0,01 sec)
```