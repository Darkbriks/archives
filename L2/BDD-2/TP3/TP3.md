# TP3 Patron Antoine

## Q2
### 2.1
#### 2.1.1 - Lister les noms des réalisateurs et les titres de leurs films classé par nom de réalisateurs puis par titre de film
```sql
mysql> SELECT nom_real, titre_film FROM realisateur JOIN film using (num_real) ORDER BY nom_real, titre_film;
+--------------------+-------------------------------------+
| nom_real           | titre_film                          |
+--------------------+-------------------------------------+
| Andreas Dresen     | Le septieme ciel                    |
| Anna Novion        | Les grandes personnes               |
| Antonello Grimaldi | Caos Calmo                          |
| Ben Stiller        | Tonnere sous les tropiques          |
| Claude Pinoteau    | La boom                             |
| Clint Eastwood     | L'?hange                            |
| Edward Zwick       | The Last Samurai                    |
| George Lucas       | Indiana Jones and the Crystal Skull |
| George Lucas       | Red Tails                           |
| George Lucas       | Star Wars: Episode IV - A New Hope  |
| Hong Sang-soo      | Woman on the beach                  |
| Pascal Thomas      | Le crime est notre affaire          |
| René Féret         | Comme une ?oile dans la nuit        |
| Sylvie Verheyde    | Stella                              |
| Ursula Meier       | Home                                |
+--------------------+-------------------------------------+
15 rows in set (0,00 sec)
```

#### 2.1.2 - Lister les titres des films et les noms et rôles des acteurs qui ont joué dans ces films, classé par titre et nom
```sql
mysql> SELECT titre_film, nom_act, role_jouer FROM film JOIN jouer using (num_film) JOIN acteur using (num_act) ORDER BY titre_film, nom_act;
+------------------------------+------------------------+------------+
| titre_film                   | nom_act                | role_jouer |
+------------------------------+------------------------+------------+
| Caos Calmo                   | Alessandro Gassman     | second     |
| Caos Calmo                   | Nanni Moretti          | apparition |
| Caos Calmo                   | Valeria Golino         | premier    |
| Comme une ?oile dans la nuit | Nicolas Giraud         | apparition |
| Comme une ?oile dans la nuit | Salomé Stéverin        | second     |
| Comme une ?oile dans la nuit | Tom Cruise             | premier    |
| Home                         | Isabelle Huppert       | apparition |
| Home                         | Jean-Pierre Darroussin | second     |
| Home                         | Olivier Gourmet        | premier    |
| L'?hange                     | Angeline Jolie         | premier    |
| L'?hange                     | John Malkovich         | second     |
| La boom                      | Sophie Marceau         | premier    |
| Le crime est notre affaire   | André Dussolier        | apparition |
| Le crime est notre affaire   | Annie Cordy            | premier    |
| Le crime est notre affaire   | Catherine Frot         | second     |
| Le crime est notre affaire   | Jean-Pierre Darroussin | second     |
| Le septieme ciel             | Angeline Jolie         | premier    |
| Le septieme ciel             | Horst Westphal         | second     |
| Le septieme ciel             | Ursula Werner          | premier    |
| Les grandes personnes        | Jean-Pierre Darroussin | second     |
| Les grandes personnes        | Judith Henry           | apparition |
| Stella                       | Benjamin Biolay        | apparition |
| Stella                       | Guillaume Depardieu    | premier    |
| Stella                       | Judith Henry           | apparition |
| Stella                       | Karole Rocher          | premier    |
| Stella                       | Leora Barbara          | apparition |
| Stella                       | Melissa Rodrigues      | second     |
| The Last Samurai             | Tom Cruise             | premier    |
| Tonnere sous les tropiques   | Ben Stiller            | apparition |
| Tonnere sous les tropiques   | Jack Black             | premier    |
| Tonnere sous les tropiques   | Robert Downey Jr.      | second     |
| Woman on the beach           | Tom Cruise             | premier    |
+------------------------------+------------------------+------------+
32 rows in set (0,00 sec)
```

#### 2.1.3 - Lister les différents noms de réalisateurs et les noms des acteurs qu'ils ont dirigés dans les films qu'ils ont réalisés, classé par nom de réalisateur et nom d'acteur
```sql
mysql> SELECT nom_real, nom_act FROM realisateur JOIN film using (num_real) JOIN jouer using (num_film) JOIN acteur using (num_act) ORDER BY nom_real, nom_act;
+--------------------+------------------------+
| nom_real           | nom_act                |
+--------------------+------------------------+
| Andreas Dresen     | Angeline Jolie         |
| Andreas Dresen     | Horst Westphal         |
| Andreas Dresen     | Ursula Werner          |
| Anna Novion        | Jean-Pierre Darroussin |
| Anna Novion        | Judith Henry           |
| Antonello Grimaldi | Alessandro Gassman     |
| Antonello Grimaldi | Nanni Moretti          |
| Antonello Grimaldi | Valeria Golino         |
| Ben Stiller        | Ben Stiller            |
| Ben Stiller        | Jack Black             |
| Ben Stiller        | Robert Downey Jr.      |
| Claude Pinoteau    | Sophie Marceau         |
| Clint Eastwood     | Angeline Jolie         |
| Clint Eastwood     | John Malkovich         |
| Edward Zwick       | Tom Cruise             |
| Hong Sang-soo      | Tom Cruise             |
| Pascal Thomas      | André Dussolier        |
| Pascal Thomas      | Annie Cordy            |
| Pascal Thomas      | Catherine Frot         |
| Pascal Thomas      | Jean-Pierre Darroussin |
| René Féret         | Nicolas Giraud         |
| René Féret         | Salomé Stéverin        |
| René Féret         | Tom Cruise             |
| Sylvie Verheyde    | Benjamin Biolay        |
| Sylvie Verheyde    | Guillaume Depardieu    |
| Sylvie Verheyde    | Judith Henry           |
| Sylvie Verheyde    | Karole Rocher          |
| Sylvie Verheyde    | Leora Barbara          |
| Sylvie Verheyde    | Melissa Rodrigues      |
| Ursula Meier       | Isabelle Huppert       |
| Ursula Meier       | Jean-Pierre Darroussin |
| Ursula Meier       | Olivier Gourmet        |
+--------------------+------------------------+
32 rows in set (0,00 sec)
```

#### 2.1.4 - Lister les numéro, titre et budget des films dans lesquels ont joué des acteurs nés après 1950, classé par titre de film
```sql
mysql> SELECT num_film, titre_film, budget_film FROM film JOIN jouer using (num_film) JOIN acteur using (num_act) WHERE anNais_act > 1950 ORDER BY titre_film;
+----------+------------------------------+-------------+
| num_film | titre_film                   | budget_film |
+----------+------------------------------+-------------+
|       10 | Caos Calmo                   |     1000000 |
|       10 | Caos Calmo                   |     1000000 |
|       10 | Caos Calmo                   |     1000000 |
|        6 | Comme une ?oile dans la nuit |     6000000 |
|        6 | Comme une ?oile dans la nuit |     6000000 |
|        6 | Comme une ?oile dans la nuit |     6000000 |
|        7 | Home                         |     3000000 |
|        7 | Home                         |     3000000 |
|        7 | Home                         |     3000000 |
|        9 | L'?hange                     |     5000000 |
|        9 | L'?hange                     |     5000000 |
|       12 | La boom                      |     4000000 |
|        3 | Le crime est notre affaire   |     1000000 |
|        3 | Le crime est notre affaire   |     1000000 |
|        5 | Le septieme ciel             |     2000000 |
|       11 | Les grandes personnes        |     1000000 |
|       11 | Les grandes personnes        |     1000000 |
|        4 | Stella                       |     4000000 |
|        4 | Stella                       |     4000000 |
|        4 | Stella                       |     4000000 |
|        4 | Stella                       |     4000000 |
|        4 | Stella                       |     4000000 |
|        4 | Stella                       |     4000000 |
|        1 | The Last Samurai             |     8000000 |
|        8 | Tonnere sous les tropiques   |     6000000 |
|        8 | Tonnere sous les tropiques   |     6000000 |
|        8 | Tonnere sous les tropiques   |     6000000 |
|        2 | Woman on the beach           |     9000000 |
+----------+------------------------------+-------------+
28 rows in set (0,00 sec)
```

##### 2.1.4.1 - Quelle est la raison qui fait apparaitre plusieurs fois le même film ?
Il peut y avoir plusieurs réccurences d'un même film car plusieurs acteurs qui on remplis les conditions ont joué dans le même film.

##### 2.1.4.2 - Proposer la requête permettant de n'afficher qu'une seule fois chaque film
```sql
mysql> SELECT DISTINCT num_film, titre_film, budget_film FROM film JOIN jouer using (num_film) JOIN acteur using (num_act) WHERE anNais_act > 1950 ORDER BY titre_film;
+----------+------------------------------+-------------+
| num_film | titre_film                   | budget_film |
+----------+------------------------------+-------------+
|       10 | Caos Calmo                   |     1000000 |
|        6 | Comme une ?oile dans la nuit |     6000000 |
|        7 | Home                         |     3000000 |
|        9 | L'?hange                     |     5000000 |
|       12 | La boom                      |     4000000 |
|        3 | Le crime est notre affaire   |     1000000 |
|        5 | Le septieme ciel             |     2000000 |
|       11 | Les grandes personnes        |     1000000 |
|        4 | Stella                       |     4000000 |
|        1 | The Last Samurai             |     8000000 |
|        8 | Tonnere sous les tropiques   |     6000000 |
|        2 | Woman on the beach           |     9000000 |
+----------+------------------------------+-------------+
12 rows in set (0,00 sec)
```

#### 2.1.5 - Lister les noms des acteurs qui sont aussi réalisateurs, classé par nom
```sql
mysql> SELECT nom_act FROM acteur JOIN realisateur on (nom_act = nom_real) ORDER BY nom_act;
+----------------+
| nom_act        |
+----------------+
| Ben Stiller    |
| Clint Eastwood |
+----------------+
2 rows in set (0,00 sec)
```

### 2.2 - Utilisation complèmentaire de fonctions
#### 2.2.1 - Afficher la date du jour et la date décalée de 5 jours
```sql
mysql> SELECT NOW() AS 'Date du jour', DATE_ADD(NOW(), INTERVAL 5 DAY) AS 'Date décalée de 5 jours';
+---------------------+---------------------------+
| Date du jour        | Date décalée de 5 jours   |
+---------------------+---------------------------+
| 2023-11-15 09:45:50 | 2023-11-20 09:45:50       |
+---------------------+---------------------------+
1 row in set (0,00 sec)
```

#### 2.2.2 - Afficher la date du jour et la date décalée de 5 mois
```sql
mysql> SELECT NOW() AS 'Date du jour', DATE_ADD(NOW(), INTERVAL 5 MONTH) AS 'Date décalée de 5 mois';
+---------------------+--------------------------+
| Date du jour        | Date décalée de 5 mois   |
+---------------------+--------------------------+
| 2023-11-15 09:46:51 | 2024-04-15 09:46:51      |
+---------------------+--------------------------+
1 row in set (0,00 sec)
```

#### 2.2.3 - Afficher la date du jour et la date décalée de 5 ans
```sql
mysql> SELECT NOW() AS 'Date du jour', DATE_ADD(NOW(), INTERVAL 5 YEAR) AS 'Date décalée de 5 ans';
+---------------------+-------------------------+
| Date du jour        | Date décalée de 5 ans   |
+---------------------+-------------------------+
| 2023-11-15 09:47:18 | 2028-11-15 09:47:18     |
+---------------------+-------------------------+
1 row in set (0,00 sec)
```

#### 2.2.4 - Lister les dates de projection des films décalées de 5 mois
```sql
mysql> SELECT date_projection, DATE_ADD(date_projection, INTERVAL 5 MONTH) AS 'Date décalée de 5 mois' FROM projection ORDER BY date_projection;
+-----------------+--------------------------+
| date_projection | Date décalée de 5 mois   |
+-----------------+--------------------------+
| 2017-09-11      | 2018-02-11               |
| 2017-09-11      | 2018-02-11               |
| 2017-09-12      | 2018-02-12               |
| 2017-09-12      | 2018-02-12               |
| 2017-09-12      | 2018-02-12               |
| 2017-09-12      | 2018-02-12               |
| 2017-09-12      | 2018-02-12               |
| 2017-09-12      | 2018-02-12               |
| 2017-09-13      | 2018-02-13               |
| 2017-09-13      | 2018-02-13               |
| 2017-09-14      | 2018-02-14               |
| 2017-09-14      | 2018-02-14               |
| 2017-09-14      | 2018-02-14               |
| 2017-09-17      | 2018-02-17               |
| 2017-09-17      | 2018-02-17               |
| 2017-09-20      | 2018-02-20               |
| 2017-09-27      | 2018-02-27               |
| 2017-10-01      | 2018-03-01               |
+-----------------+--------------------------+
18 rows in set (0,00 sec)
```

#### 2.2.5 - Lister les écarts entre les dates de projection et aujourd'hui
```sql
mysql> SELECT date_projection, NOW(), DATEDIFF(NOW(), date_projection) AS 'Ecart' FROM projection ORDER BY date_projection;
+-----------------+---------------------+-------+
| date_projection | NOW()               | Ecart |
+-----------------+---------------------+-------+
| 2017-09-11      | 2023-11-15 09:56:43 |  2256 |
| 2017-09-11      | 2023-11-15 09:56:43 |  2256 |
| 2017-09-12      | 2023-11-15 09:56:43 |  2255 |
| 2017-09-12      | 2023-11-15 09:56:43 |  2255 |
| 2017-09-12      | 2023-11-15 09:56:43 |  2255 |
| 2017-09-12      | 2023-11-15 09:56:43 |  2255 |
| 2017-09-12      | 2023-11-15 09:56:43 |  2255 |
| 2017-09-12      | 2023-11-15 09:56:43 |  2255 |
| 2017-09-13      | 2023-11-15 09:56:43 |  2254 |
| 2017-09-13      | 2023-11-15 09:56:43 |  2254 |
| 2017-09-14      | 2023-11-15 09:56:43 |  2253 |
| 2017-09-14      | 2023-11-15 09:56:43 |  2253 |
| 2017-09-14      | 2023-11-15 09:56:43 |  2253 |
| 2017-09-17      | 2023-11-15 09:56:43 |  2250 |
| 2017-09-17      | 2023-11-15 09:56:43 |  2250 |
| 2017-09-20      | 2023-11-15 09:56:43 |  2247 |
| 2017-09-27      | 2023-11-15 09:56:43 |  2240 |
| 2017-10-01      | 2023-11-15 09:56:43 |  2236 |
+-----------------+---------------------+-------+
18 rows in set (0,00 sec)
```

#### 2.2.6 - Rechercher le plus grand écart entre une date de projection et aujourd'hui
```sql
mysql> SELECT max(DATEDIFF(NOW(), date_projection)) AS 'Ecart max' FROM projection;
+-----------+
| Ecart max |
+-----------+
|      2256 |
+-----------+
1 row in set (0,00 sec)
```

#### 2.2.7 - Lister le jour de la semaine, le jour du mois, le mois et l'année de la date du jour (tout en chiffre)
```sql
mysql> SELECT WEEKDAY(NOW()) AS 'Jour de la semaine', WEEKDAY(NOW()) AS 'Jour du mois', MONTH(NOW()) AS 'Mois', YEAR(NOW()) AS 'Année';
+--------------------+--------------+------+--------+
| Jour de la semaine | Jour du mois | Mois | Année  |
+--------------------+--------------+------+--------+
|                  2 |            2 |   11 |   2023 |
+--------------------+--------------+------+--------+
1 row in set (0,00 sec)
```

#### 2.2.8 - Lister les acteurs qu'on a pu voir un jeudi dans une salle qui a plus de 300 places, classé par nom d'acteur
```sql
mysql> SELECT DISTINCT num_act, nom_act, anNais_act, WEEKDAY(date_projection) AS 'Jour de la semaine' FROM acteur JOIN jouer using (num_act) JOIN film using (num_film) JOIN projeter using (num_film) JOIN salle using (num_salle) WHERE WEEKDAY(date_projection) = 3 AND nbPlaces_salle > 300 ORDER BY nom_act;
+---------+---------------------+------------+--------------------+
| num_act | nom_act             | anNais_act | Jour de la semaine |
+---------+---------------------+------------+--------------------+
|      22 | Benjamin Biolay     |       1973 |                  3 |
|      23 | Guillaume Depardieu |       1971 |                  3 |
|       3 | Judith Henry        |       1968 |                  3 |
|      20 | Karole Rocher       |       1974 |                  3 |
|      19 | Leora Barbara       |       1996 |                  3 |
|      21 | Melissa Rodrigues   |       1988 |                  3 |
+---------+---------------------+------------+--------------------+
6 rows in set (0,00 sec)
```

#### 2.2.9 - Lister les titres des films, le nom de leur réalisateur et leur année de naissance, classé par année de naissance puis nom de réalisateur puis titre de film. Si un realisateur n'a pas de date de naissance, on affichera `NA`
```sql
mysql> SELECT titre_film, nom_real, IFNULL(anNais_real, 'NA') AS 'Année de naissance' FROM film JOIN realisateur using (num_real) ORDER BY anNais_real, nom_real, titre_film;
+-------------------------------------+--------------------+---------------------+
| titre_film                          | nom_real           | Année de naissance  |
+-------------------------------------+--------------------+---------------------+
| Indiana Jones and the Crystal Skull | George Lucas       | NA                  |
| Red Tails                           | George Lucas       | NA                  |
| Star Wars: Episode IV - A New Hope  | George Lucas       | NA                  |
| La boom                             | Claude Pinoteau    | 1925                |
| L'?hange                            | Clint Eastwood     | 1930                |
| Le crime est notre affaire          | Pascal Thomas      | 1945                |
| Comme une ?oile dans la nuit        | René Féret         | 1945                |
| The Last Samurai                    | Edward Zwick       | 1952                |
| Caos Calmo                          | Antonello Grimaldi | 1955                |
| Woman on the beach                  | Hong Sang-soo      | 1960                |
| Le septieme ciel                    | Andreas Dresen     | 1963                |
| Tonnere sous les tropiques          | Ben Stiller        | 1965                |
| Stella                              | Sylvie Verheyde    | 1967                |
| Home                                | Ursula Meier       | 1971                |
| Les grandes personnes               | Anna Novion        | 1979                |
+-------------------------------------+--------------------+---------------------+
15 rows in set (0,00 sec)
```

#### 2.2.10 - Lister les noms d'acteurs qui *sonnent* comme `bnstlr` ou `isbldjn` classé par nom d'acteur
```sql
mysql> SELECT nom_act FROM acteur WHERE nom_act SOUNDS LIKE 'bnstlr' OR nom_act SOUNDS LIKE 'isbldjn' ORDER BY nom_act;
+-----------------+
| nom_act         |
+-----------------+
| Ben Stiller     |
| Isabelle Adjani |
+-----------------+
2 rows in set (0,01 sec)
```

#### 2.2.11 - Lister le planning de projection du mois de septembre 2017, classé par numéro du jour de la semaine, salle, date et heure
```sql
mysql> SELECT DAYNAME(date_projection) AS 'Jour', num_salle AS 'Salle', date_projection AS 'le', heure_projection AS 'a', titre_film AS 'Titre' FROM projeter JOIN film using (num_film) WHERE MONTH(date_projection) = 9 AND YEAR(date_projection) = 2017 ORDER BY WEEKDAY(date_projection), num_salle, date_projection, heure_projection;
+-----------+-------+------------+----------+----------------------------+
| Jour      | Salle | le         | a        | Titre                      |
+-----------+-------+------------+----------+----------------------------+
| Monday    |     1 | 2017-09-11 | 18:00:00 | Caos Calmo                 |
| Monday    |     2 | 2017-09-11 | 18:00:00 | Caos Calmo                 |
| Monday    |     3 | 2017-09-11 | 20:20:00 | Caos Calmo                 |
| Tuesday   |     1 | 2017-09-12 | 14:00:00 | L'?hange                   |
| Tuesday   |     1 | 2017-09-12 | 17:45:00 | Woman on the beach         |
| Tuesday   |     2 | 2017-09-12 | 17:00:00 | L'?hange                   |
| Tuesday   |     3 | 2017-09-12 | 20:00:00 | L'?hange                   |
| Tuesday   |     4 | 2017-09-12 | 12:05:00 | Le crime est notre affaire |
| Tuesday   |     4 | 2017-09-12 | 16:20:00 | Le crime est notre affaire |
| Wednesday |     1 | 2017-09-13 | 18:30:00 | Les grandes personnes      |
| Wednesday |     1 | 2017-09-20 | 18:15:00 | Le septieme ciel           |
| Wednesday |     2 | 2017-09-13 | 20:20:00 | Les grandes personnes      |
| Wednesday |     2 | 2017-09-20 | 18:15:00 | Le septieme ciel           |
| Wednesday |     3 | 2017-09-20 | 18:15:00 | Tonnere sous les tropiques |
| Wednesday |     4 | 2017-09-27 | 20:10:00 | Home                       |
| Wednesday |     5 | 2017-09-27 | 20:10:00 | Home                       |
| Thursday  |     3 | 2017-09-14 | 18:00:00 | Stella                     |
| Thursday  |     4 | 2017-09-14 | 18:00:00 | Stella                     |
| Thursday  |     5 | 2017-09-14 | 20:10:00 | Stella                     |
| Thursday  |     5 | 2017-09-14 | 22:00:00 | Le crime est notre affaire |
| Sunday    |     4 | 2017-09-17 | 17:30:00 | L'?hange                   |
| Sunday    |     5 | 2017-09-17 | 20:15:00 | L'?hange                   |
+-----------+-------+------------+----------+----------------------------+
22 rows in set (0,00 sec)
```

## Q3 - Rejouer le script
```bash
$ mysql -h localhost -u root -p </home/antoine/Documents/L2/BDD_2/TP3/TP3.sql> /home/antoine/Documents/L2/BDD_2/TP3/TP3_result.txt
```
Lien vers le résultat: [TP3_result.txt](TP3_result.txt)

## Q4 - Effectuer une sauvegarde et une restauration
### 4.1 - Sauvegarde en mode commande
```bash
$ mysqldump -h localhost -u root -p tp_cinema > /home/antoine/Documents/L2/BDD_2/TP3/TP3_dump.sql
```
Lien vers le dump: [TP3_dump.sql](TP3_dump.sql)

### 4.2 - Restauration en mode commande 
```bash
$ mysql -h localhost -u root -p tp_cinema_dump < /home/antoine/Documents/L2/BDD_2/TP3/TP3_dump.sql
```
#### 4.2.1 - Vérification de la restauration
```bash
$ mysql -h localhost -u root -p
```
```sql
mysql> use tp_cinema_dump;
mysql> show tables;
+--------------------------+
| Tables_in_tp_cinema_dump |
+--------------------------+
| acteur                   |
| film                     |
| jouer                    |
| mots                     |
| projection               |
| projeter                 |
| realisateur              |
| salle                    |
| termes                   |
+--------------------------+
9 rows in set (0,00 sec)

mysql> select * from acteur;
+---------+------------------------+------------+
| num_act | nom_act                | anNais_act |
+---------+------------------------+------------+
|       1 | Tom Cruise             |       1962 |
|       2 | Jean-Pierre Darroussin |       1953 |
|       3 | Judith Henry           |       1968 |
|       4 | Angeline Jolie         |       1975 |
|       5 | John Malkovich         |       1953 |
|       6 | Ben Stiller            |       1965 |
|       7 | Jack Black             |       1969 |
|       8 | Robert Downey Jr.      |       1965 |
|       9 | Isabelle Huppert       |       1953 |
|      10 | Olivier Gourmet        |       1963 |
|      11 | Salomé Stéverin        |       1985 |
|      12 | Nicolas Giraud         |       1978 |
|      13 | Ursula Werner          |       1943 |
|      14 | Horst Westphal         |       1929 |
|      15 | Nanni Moretti          |       1953 |
|      16 | Valeria Golino         |       1966 |
|      17 | Alessandro Gassman     |       1965 |
|      18 | Isabelle Ferrari       |       1964 |
|      19 | Leora Barbara          |       1996 |
|      20 | Karole Rocher          |       1974 |
|      21 | Melissa Rodrigues      |       1988 |
|      22 | Benjamin Biolay        |       1973 |
|      23 | Guillaume Depardieu    |       1971 |
|      24 | Catherine Frot         |       1956 |
|      25 | André Dussolier        |       1946 |
|      26 | Annie Cordy            |       1928 |
|      27 | Isabelle Adjani        |       1955 |
|      28 | Clint Eastwood         |       1930 |
|      29 | Sophie Marceau         |       1966 |
+---------+------------------------+------------+
29 rows in set (0,00 sec)

mysql> select * from film;
+----------+-------------------------------------+---------------+-------------+-----------------------------------+----------+
| num_film | titre_film                          | anSortie_film | budget_film | genre_film                        | num_real |
+----------+-------------------------------------+---------------+-------------+-----------------------------------+----------+
|        1 | The Last Samurai                    |          2003 |     8000000 | ?op?                              |        1 |
|        2 | Woman on the beach                  |          2007 |     9000000 | Com?ie dramatique                 |        9 |
|        3 | Le crime est notre affaire          |          2008 |     1000000 | Com?ie polici?e                   |        8 |
|        4 | Stella                              |          2008 |     4000000 | com?ie dramatique                 |        7 |
|        5 | Le septieme ciel                    |          2008 |     2000000 | Com?ie                            |        6 |
|        6 | Comme une ?oile dans la nuit        |          2008 |     6000000 | Drame, Com?ie dramatique, Romance |        5 |
|        7 | Home                                |          2008 |     3000000 | film documentaire                 |        4 |
|        8 | Tonnere sous les tropiques          |          2008 |     6000000 | Com?ie, Aventure, action          |        3 |
|        9 | L'?hange                            |          2008 |     5000000 | Drame                             |        2 |
|       10 | Caos Calmo                          |          2008 |     1000000 | Drame, Romance                    |       11 |
|       11 | Les grandes personnes               |          2007 |     1000000 | Com?ie dramatique                 |       10 |
|       12 | La boom                             |          1980 |     4000000 | Comedie, Drame, Romance           |       13 |
|       13 | Red Tails                           |          2012 |        NULL | NULL                              |       14 |
|       14 | Star Wars: Episode IV - A New Hope  |          1977 |        NULL | NULL                              |       14 |
|       15 | Indiana Jones and the Crystal Skull |          2008 |        NULL | NULL                              |       14 |
+----------+-------------------------------------+---------------+-------------+-----------------------------------+----------+
15 rows in set (0,00 sec)

mysql> select * from jouer;
+---------+----------+------------+--------------+
| num_act | num_film | role_jouer | cachet_jouer |
+---------+----------+------------+--------------+
|       1 |        1 | premier    |        55887 |
|       1 |        2 | premier    |        90487 |
|       1 |        6 | premier    |        80740 |
|       2 |        3 | second     |        54618 |
|       2 |        7 | second     |         1613 |
|       2 |       11 | second     |        21846 |
|       3 |        4 | apparition |        96460 |
|       3 |       11 | apparition |        90175 |
|       4 |        5 | premier    |        10202 |
|       4 |        9 | premier    |        54198 |
|       5 |        9 | second     |        95734 |
|       6 |        8 | apparition |        85961 |
|       7 |        8 | premier    |        73347 |
|       8 |        8 | second     |        71812 |
|       9 |        7 | apparition |        46566 |
|      10 |        7 | premier    |        12263 |
|      11 |        6 | second     |         4565 |
|      12 |        6 | apparition |        48137 |
|      13 |        5 | premier    |        47557 |
|      14 |        5 | second     |        24677 |
|      15 |       10 | apparition |        10308 |
|      16 |       10 | premier    |        30526 |
|      17 |       10 | second     |        12770 |
|      19 |        4 | apparition |        64132 |
|      20 |        4 | premier    |        79894 |
|      21 |        4 | second     |        70226 |
|      22 |        4 | apparition |        77410 |
|      23 |        4 | premier    |        95731 |
|      24 |        3 | second     |        47358 |
|      25 |        3 | apparition |        41578 |
|      26 |        3 | premier    |        63537 |
|      29 |       12 | premier    |        98680 |
+---------+----------+------------+--------------+
32 rows in set (0,00 sec)
```