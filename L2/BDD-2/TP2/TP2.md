# TP2 Patron Antoine

## Q1
### 1.3
#### 1.3.4 Verification des tables en utilisant la commande `describe`
```bash
mysql> describe acteur;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| num_act    | int         | NO   | PRI | NULL    |       |
| nom_act    | varchar(40) | NO   |     | NULL    |       |
| anNais_act | int         | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> describe realisateur;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| num_real    | int         | NO   | PRI | NULL    |       |
| nom_real    | varchar(40) | NO   |     | NULL    |       |
| anNais_real | int         | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
3 rows in set (0,00 sec)

mysql> describe salle;
+----------------+------+------+-----+---------+-------+
| Field          | Type | Null | Key | Default | Extra |
+----------------+------+------+-----+---------+-------+
| num_salle      | int  | NO   | PRI | NULL    |       |
| nbPlaces_salle | int  | NO   |     | NULL    |       |
+----------------+------+------+-----+---------+-------+
2 rows in set (0,00 sec)

mysql> describe film;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| num_film      | int         | NO   | PRI | NULL    |       |
| titre_film    | varchar(40) | NO   |     | NULL    |       |
| anSortie_film | int         | YES  |     | NULL    |       |
| budget_film   | int         | YES  |     | NULL    |       |
| genre_film    | varchar(40) | YES  |     | NULL    |       |
| num_real      | int         | NO   | MUL | NULL    |       |
| resume_film   | text        | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+
7 rows in set (0,00 sec)

mysql> describe jouer;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| num_act      | int         | NO   | PRI | NULL    |       |
| num_film     | int         | NO   | PRI | NULL    |       |
| role_jouer   | varchar(40) | YES  |     | NULL    |       |
| cachet_jouer | int         | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
4 rows in set (0,00 sec)

mysql> describe projection;
+------------------+--------------+------+-----+---------+-------+
| Field            | Type         | Null | Key | Default | Extra |
+------------------+--------------+------+-----+---------+-------+
| date_projection  | date         | NO   | PRI | NULL    |       |
| heure_projection | time         | NO   | PRI | NULL    |       |
| tarif_projection | decimal(4,2) | YES  |     | NULL    |       |
+------------------+--------------+------+-----+---------+-------+
3 rows in set (0,01 sec)

mysql> describe projeter;
+--------------------+------+------+-----+---------+-------+
| Field              | Type | Null | Key | Default | Extra |
+--------------------+------+------+-----+---------+-------+
| num_film           | int  | NO   | PRI | NULL    |       |
| num_salle          | int  | NO   | PRI | NULL    |       |
| date_projection    | date | NO   | PRI | NULL    |       |
| heure_projection   | time | NO   | PRI | NULL    |       |
| nbSpectateurs_proj | int  | NO   |     | 0       |       |
+--------------------+------+------+-----+---------+-------+
5 rows in set (0,00 sec)
```

### 1.4
#### 1.4.1
##### 1.4.1.6 Verification des tables données en utilisant la commande `SELECT`
```bash
mysql> SELECT * FROM salle;
+-----------+----------------+
| num_salle | nbPlaces_salle |
+-----------+----------------+
|         1 |             50 |
(...)
|         6 |            400 |
+-----------+----------------+
6 rows in set (0,00 sec)

mysql> SELECT * FROM realisateur;
+----------+--------------------+-------------+
| num_real | nom_real           | anNais_real |
+----------+--------------------+-------------+
|        1 | Edward Zwick       |        1952 |
(...)
|       13 | Claude Pinoteau    |        1925 |
+----------+--------------------+-------------+
13 rows in set (0,00 sec)

mysql> SELECT * FROM acteur;
+---------+------------------------+------------+
| num_act | nom_act                | anNais_act |
+---------+------------------------+------------+
|       1 | Tom Cruise             |       1962 |
(...)
|      29 | Sophie Marceau         |       1966 |
+---------+------------------------+------------+
29 rows in set (0,00 sec)


mysql> SELECT * FROM film;
+----------+------------------------------+---------------+-------------+-----------------------------------+----------+-------------+
| num_film | titre_film                   | anSortie_film | budget_film | genre_film                        | num_real | resume_film |
+----------+------------------------------+---------------+-------------+-----------------------------------+----------+-------------+
|        1 | The Last Samurai             |          2003 |     8000000 | ?op?                              | 1        |             |
(...)
|       12 | La boom                      |          1980 |     4000000 | Comedie, Drame, Romance           | 3        |             |
+----------+------------------------------+---------------+-------------+-----------------------------------+----------+-------------+
12 rows in set (0,00 sec)

mysql> SELECT * FROM projection;
+-----------------+------------------+------------------+
| date_projection | heure_projection | tarif_projection |
+-----------------+------------------+------------------+
| 2017-09-11      | 18:00:00         |             4.00 |
(...)
| 2017-10-01      | 20:00:00         |             5.00 |
+-----------------+------------------+------------------+
18 rows in set (0,00 sec)

mysql> SELECT * FROM projeter;
+----------+-----------+-----------------+------------------+--------------------+
| num_film | num_salle | date_projection | heure_projection | nbSpectateurs_proj |
+----------+-----------+-----------------+------------------+--------------------+
|       10 |         1 | 2017-09-11      | 18:00:00         |                 24 |
(...)
|        1 |         5 | 2017-10-01      | 20:00:00         |                 55 |
+----------+-----------+-----------------+------------------+--------------------+
27 rows in set (0,00 sec)

mysql> SELECT * FROM jouer;
+---------+----------+------------+--------------+
| num_act | num_film | role_jouer | cachet_jouer |
+---------+----------+------------+--------------+
|       1 |        1 | premier    |        55887 |
(...)
|      29 |       12 | premier    |        98680 |
+---------+----------+------------+--------------+
32 rows in set (0,00 sec)
```

##### 1.4.1.7 Supprimer la colone `photo_act` de la table `acteur`
```bash
mysql> ALTER TABLE acteur DROP photo_act;
```

##### 1.4.1.8 Supprimer la colone `resume_film` de la table `film`
```bash
mysql> ALTER TABLE film DROP resume_film;
Query OK, 0 rows affected (0,02 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM film WHERE num_film = 1;
+----------+------------------+---------------+-------------+------------+----------+
| num_film | titre_film       | anSortie_film | budget_film | genre_film | num_real |
+----------+------------------+---------------+-------------+------------+----------+
|        1 | The Last Samurai |          2003 |     8000000 | ?op?       |        1 |
+----------+------------------+---------------+-------------+------------+----------+
1 row in set (0,00 sec)
```

##### 1.4.1.9 Ajouter le realisateur `George Lucas` à la table `realisateur` avec une date de naissance a `NULL`
```bash
mysql> INSERT INTO realisateur (num_real, nom_real, anNais_real) VALUES (14, 'George Lucas', NULL);
Query OK, 1 row affected (0,00 sec)

mysql> SELECT * FROM realisateur WHERE num_real = 14;
+----------+--------------+-------------+
| num_real | nom_real     | anNais_real |
+----------+--------------+-------------+
|       14 | George Lucas |        NULL |
+----------+--------------+-------------+
1 row in set (0,00 sec)
```

##### 1.4.1.10 Ajouter les films :
- `Red Tails` de `George Lucas` sorti en `2012` avec un budget de `NULL` et de genre `NULL`
- `Star Wars: Episode IV - A New Hope` de `George Lucas` sorti en `1977` avec un budget de `NULL` et de genre `NULL`
- `Indiana Jones and the Crystal Skull` de `George Lucas` sorti en `2008` avec un budget de `NULL` et de genre `NULL`
```bash
mysql> INSERT INTO film (num_film, titre_film, anSortie_film, budget_film, genre_film, num_real) VALUES
    -> (13, 'Red Tails', 2012, NULL, NULL, 14),
    -> (14, 'Star Wars: Episode IV - A New Hope', 1977, NULL, NULL, 14),
    -> (15, 'Indiana Jones and the Crystal Skull', 2008, NULL, NULL, 14);
Query OK, 3 rows affected (0,01 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM film WHERE num_film >= 13;
+----------+-------------------------------------+---------------+-------------+------------+----------+
| num_film | titre_film                          | anSortie_film | budget_film | genre_film | num_real |
+----------+-------------------------------------+---------------+-------------+------------+----------+
|       13 | Red Tails                           |          2012 |        NULL | NULL       |       14 |
|       14 | Star Wars: Episode IV - A New Hope  |          1977 |        NULL | NULL       |       14 |
|       15 | Indiana Jones and the Crystal Skull |          2008 |        NULL | NULL       |       14 |
+----------+-------------------------------------+---------------+-------------+------------+----------+
3 rows in set (0,00 sec)
```

### 1.5
#### 1.5.1
##### 1.5.1.1 Lister les films dont le numero de realisateur est `1`, `4`, `7`, `14` ou `2540`
```bash
mysql> SELECT * FROM film WHERE num_real = 1 or num_real = 4 or num_real = 7 or num_real = 14 or num_real = 2540;
+----------+-------------------------------------+---------------+-------------+-------------------+----------+
| num_film | titre_film                          | anSortie_film | budget_film | genre_film        | num_real |
+----------+-------------------------------------+---------------+-------------+-------------------+----------+
|        1 | The Last Samurai                    |          2003 |     8000000 | ?op?              |        1 |
|        7 | Home                                |          2008 |     3000000 | film documentaire |        4 |
|        4 | Stella                              |          2008 |     4000000 | com?ie dramatique |        7 |
|       13 | Red Tails                           |          2012 |        NULL | NULL              |       14 |
|       14 | Star Wars: Episode IV - A New Hope  |          1977 |        NULL | NULL              |       14 |
|       15 | Indiana Jones and the Crystal Skull |          2008 |        NULL | NULL              |       14 |
+----------+-------------------------------------+---------------+-------------+-------------------+----------+
6 rows in set (0,00 sec)
```

##### 1.5.1.2 Lister les acteur dont le nom commance par `isa`
```bash
mysql> SELECT * FROM acteur WHERE nom_act like 'isa%';
+---------+------------------+------------+
| num_act | nom_act          | anNais_act |
+---------+------------------+------------+
|       9 | Isabelle Huppert |       1953 |
|      18 | Isabelle Ferrari |       1964 |
|      27 | Isabelle Adjani  |       1955 |
+---------+------------------+------------+
3 rows in set (0,00 sec)
```

##### 1.5.1.3 Lister les acteur dont le nom se termine par `ani`
```bash
mysql> SELECT * FROM acteur WHERE nom_act like '%ani';
+---------+-----------------+------------+
| num_act | nom_act         | anNais_act |
+---------+-----------------+------------+
|      27 | Isabelle Adjani |       1955 |
+---------+-----------------+------------+
1 row in set (0,00 sec)
```

##### 1.5.1.4 Lister les acteurs dont le nom contient `ol` er ne contient pas `go`
```bash
mysql> SELECT * FROM acteur WHERE nom_act like '%ol%' and nom_act not like '%go%';
+---------+------------------+------------+
| num_act | nom_act          | anNais_act |
+---------+------------------+------------+
|       4 | Angeline Jolie   |       1975 |
|      12 | Nicolas Giraud   |       1978 |
|      20 | Karole Rocher    |       1974 |
|      22 | Benjamin Biolay  |       1973 |
|      25 | André Dussolier  |       1946 |
+---------+------------------+------------+
5 rows in set (0,00 sec)
```

##### 1.5.1.5 Lister les acteurs dont le nom comporte la lettre `n` en 3éme position
```Bash
mysql> SELECT * FROM acteur WHERE nom_act like '__n%';
+---------+-----------------+------------+
| num_act | nom_act         | anNais_act |
+---------+-----------------+------------+
|       6 | Ben Stiller     |       1965 |
|      15 | Nanni Moretti   |       1953 |
|      22 | Benjamin Biolay |       1973 |
|      26 | Annie Cordy     |       1928 |
+---------+-----------------+------------+
4 rows in set (0,00 sec)
```

##### 1.5.1.6 Lister le numéro de film, son titre et le numéro de réalisateur du film dont le titre est `home`
```Bash
mysql> SELECT num_film, titre_film, num_real FROM film WHERE titre_film like 'home';
+----------+------------+----------+
| num_film | titre_film | num_real |
+----------+------------+----------+
|        7 | Home       |        4 |
+----------+------------+----------+
1 row in set (0,00 sec)
```

##### 1.5.1.7 Lister les acteurs nés avant 1950 ou après 1960 et dont le nom contient l’une des syllabes suivantes :  `cru`, `roc` et `cor`
```Bash
mysql> SELECT * FROM acteur WHERE (anNais_act < 1950 or anNais_act > 1960) and (nom_act like '%cru%' or nom_act like '%roc%' or nom_act like '%cor%');
+---------+---------------+------------+
| num_act | nom_act       | anNais_act |
+---------+---------------+------------+
|       1 | Tom Cruise    |       1962 |
|      20 | Karole Rocher |       1974 |
|      26 | Annie Cordy   |       1928 |
+---------+---------------+------------+
3 rows in set (0,00 sec)
```

##### 1.5.1.8 Lister les realisateurs dont l'année de naissance n'est pas connue
```Bash
mysql> SELECT * FROM realisateur WHERE anNais_real is NULL;
+----------+--------------+-------------+
| num_real | nom_real     | anNais_real |
+----------+--------------+-------------+
|       14 | George Lucas |        NULL |
+----------+--------------+-------------+
1 row in set (0,00 sec)
```

##### 1.5.1.9 Lister les films sortis en `2005` ou aprés, ayant un numero pair et dont le genre ne contient pas `drame`
```Bash
mysql> SELECT * FROM film WHERE anSortie_film >= 2005 and num_film % 2 = 0 and genre_film not like '%drame%';
+----------+----------------------------+---------------+-------------+--------------------------+----------+
| num_film | titre_film                 | anSortie_film | budget_film | genre_film               | num_real |
+----------+----------------------------+---------------+-------------+--------------------------+----------+
|        2 | Woman on the beach         |          2007 |     9000000 | Com?ie dramatique        |        9 |
|        4 | Stella                     |          2008 |     4000000 | com?ie dramatique        |        7 |
|        8 | Tonnere sous les tropiques |          2008 |     6000000 | Com?ie, Aventure, action |        3 |
+----------+----------------------------+---------------+-------------+--------------------------+----------+
3 rows in set (0,00 sec)
```

##### 1.5.1.10 Utiliser les fonction SQL `month` et `now` : `SELECT month(now()) from dual;`
```Bash
mysql> SELECT month(now()) from dual;
+--------------+
| month(now()) |
+--------------+
|           11 |
+--------------+
1 row in set (0,00 sec)
```

##### 1.5.1.11 Lister les projections de film en `mars 2017` classées par numéro de film
```Bash
mysql> SELECT * FROM projeter WHERE date_projection between '2017-03-01' and '2017-03-31' order by num_film;
Empty set (0,00 sec)
```

##### 1.5.1.12 Lister les differents numéros de film projetés dans une séance entre `18:00` et `20:00`
```Bash
mysql> SELECT distinct num_film FROM projeter WHERE heure_projection between '18:00:00' and '20:00:00';
+----------+
| num_film |
+----------+
|        1 |
|        4 |
|        5 |
|        8 |
|        9 |
|       10 |
|       11 |
+----------+
7 rows in set (0,00 sec)
```

##### 1.5.1.13 Lister le nom et la longeur du nom des acteurs : nommer cette dernière colone `longueur`
```Bash
mysql> SELECT nom_act, length(nom_act) as longueur FROM acteur;
+------------------------+----------+
| nom_act                | longueur |
+------------------------+----------+
| Tom Cruise             |       10 |
| Jean-Pierre Darroussin |       22 |
| Judith Henry           |       12 |
| Angeline Jolie         |       14 |
| John Malkovich         |       14 |
| Ben Stiller            |       11 |
| Jack Black             |       10 |
| Robert Downey Jr.      |       17 |
| Isabelle Huppert       |       16 |
| Olivier Gourmet        |       15 |
| Salomé Stéverin        |       15 |
| Nicolas Giraud         |       14 |
| Ursula Werner          |       13 |
| Horst Westphal         |       14 |
| Nanni Moretti          |       13 |
| Valeria Golino         |       14 |
| Alessandro Gassman     |       18 |
| Isabelle Ferrari       |       16 |
| Leora Barbara          |       13 |
| Karole Rocher          |       13 |
| Melissa Rodrigues      |       17 |
| Benjamin Biolay        |       15 |
| Guillaume Depardieu    |       19 |
| Catherine Frot         |       14 |
| André Dussolier        |       15 |
| Annie Cordy            |       11 |
| Isabelle Adjani        |       15 |
| Clint Eastwood         |       14 |
| Sophie Marceau         |       14 |
+------------------------+----------+
29 rows in set (0,00 sec)
```

##### 1.5.1.14 Lister les acteurs dont la longeur du nom est superieur a `15`
```Bash
mysql> SELECT * FROM acteur WHERE length(nom_act) > 15;
+---------+------------------------+------------+
| num_act | nom_act                | anNais_act |
+---------+------------------------+------------+
|       2 | Jean-Pierre Darroussin |       1953 |
|       8 | Robert Downey Jr.      |       1965 |
|       9 | Isabelle Huppert       |       1953 |
|      17 | Alessandro Gassman     |       1965 |
|      18 | Isabelle Ferrari       |       1964 |
|      21 | Melissa Rodrigues      |       1988 |
|      23 | Guillaume Depardieu    |       1971 |
+---------+------------------------+------------+
7 rows in set (0,00 sec)
```

##### 1.5.1.15 Lister les noms des realisateurs en lettres capitales
```Bash
mysql> SELECT upper(nom_real) FROM realisateur;
+--------------------+
| upper(nom_real)    |
+--------------------+
| EDWARD ZWICK       |
| CLINT EASTWOOD     |
| BEN STILLER        |
| URSULA MEIER       |
| RENÉ FÉRET         |
| ANDREAS DRESEN     |
| SYLVIE VERHEYDE    |
| PASCAL THOMAS      |
| HONG SANG-SOO      |
| ANNA NOVION        |
| ANTONELLO GRIMALDI |
| JOANN SFAR         |
| CLAUDE PINOTEAU    |
| GEORGE LUCAS       |
+--------------------+
14 rows in set (0,00 sec)
```

##### 1.5.1.16 Lister les `prénoms` et `noms` des acteurs
```Bash
mysql> SELECT substring(nom_act, 1, locate(' ', nom_act) - 1) as prenom, substring(nom_act, locate(' ', nom_act) + 1) as nom FROM acteur;
+-------------+------------+
| prenom      | nom        |
+-------------+------------+
| Tom         | Cruise     |
| Jean-Pierre | Darroussin |
| Judith      | Henry      |
| Angeline    | Jolie      |
| John        | Malkovich  |
| Ben         | Stiller    |
| Jack        | Black      |
| Robert      | Downey Jr. |
| Isabelle    | Huppert    |
| Olivier     | Gourmet    |
| Salomé      | Stéverin   |
| Nicolas     | Giraud     |
| Ursula      | Werner     |
| Horst       | Westphal   |
| Nanni       | Moretti    |
| Valeria     | Golino     |
| Alessandro  | Gassman    |
| Isabelle    | Ferrari    |
| Leora       | Barbara    |
| Karole      | Rocher     |
| Melissa     | Rodrigues  |
| Benjamin    | Biolay     |
| Guillaume   | Depardieu  |
| Catherine   | Frot       |
| André       | Dussolier  |
| Annie       | Cordy      |
| Isabelle    | Adjani     |
| Clint       | Eastwood   |
| Sophie      | Marceau    |
+-------------+------------+
29 rows in set (0,00 sec)
```

##### 1.5.1.17 Lister les acteurs classées par année de naissance croissante et par nom croissant
```Bash
mysql> SELECT * FROM acteur order by anNais_act asc, nom_act asc;
+---------+------------------------+------------+
| num_act | nom_act                | anNais_act |
+---------+------------------------+------------+
|      26 | Annie Cordy            |       1928 |
|      14 | Horst Westphal         |       1929 |
|      28 | Clint Eastwood         |       1930 |
|      13 | Ursula Werner          |       1943 |
|      25 | André Dussolier        |       1946 |
|       9 | Isabelle Huppert       |       1953 |
|       2 | Jean-Pierre Darroussin |       1953 |
|       5 | John Malkovich         |       1953 |
|      15 | Nanni Moretti          |       1953 |
|      27 | Isabelle Adjani        |       1955 |
|      24 | Catherine Frot         |       1956 |
|       1 | Tom Cruise             |       1962 |
|      10 | Olivier Gourmet        |       1963 |
|      18 | Isabelle Ferrari       |       1964 |
|      17 | Alessandro Gassman     |       1965 |
|       6 | Ben Stiller            |       1965 |
|       8 | Robert Downey Jr.      |       1965 |
|      29 | Sophie Marceau         |       1966 |
|      16 | Valeria Golino         |       1966 |
|       3 | Judith Henry           |       1968 |
|       7 | Jack Black             |       1969 |
|      23 | Guillaume Depardieu    |       1971 |
|      22 | Benjamin Biolay        |       1973 |
|      20 | Karole Rocher          |       1974 |
|       4 | Angeline Jolie         |       1975 |
|      12 | Nicolas Giraud         |       1978 |
|      11 | Salomé Stéverin        |       1985 |
|      21 | Melissa Rodrigues      |       1988 |
|      19 | Leora Barbara          |       1996 |
+---------+------------------------+------------+
29 rows in set (0,00 sec)
```

##### 1.5.1.18 Lister les projections classées par `tarif`, puis par `heure` et enfin par `date` de projection decroissante
```Bash
mysql> SELECT * FROM projection order by tarif_projection desc, heure_projection desc, date_projection desc;
+-----------------+------------------+------------------+
| date_projection | heure_projection | tarif_projection |
+-----------------+------------------+------------------+
| 2017-09-11      | 20:20:00         |             6.50 |
| 2017-09-17      | 20:15:00         |             6.00 |
| 2017-09-27      | 20:10:00         |             6.00 |
| 2017-09-13      | 20:20:00         |             5.00 |
| 2017-10-01      | 20:00:00         |             5.00 |
| 2017-09-14      | 22:00:00         |             4.50 |
| 2017-09-12      | 20:00:00         |             4.50 |
| 2017-09-14      | 18:00:00         |             4.50 |
| 2017-09-14      | 20:10:00         |             4.00 |
| 2017-09-13      | 18:30:00         |             4.00 |
| 2017-09-20      | 18:15:00         |             4.00 |
| 2017-09-11      | 18:00:00         |             4.00 |
| 2017-09-12      | 17:45:00         |             4.00 |
| 2017-09-17      | 17:30:00         |             4.00 |
| 2017-09-12      | 17:00:00         |             4.00 |
| 2017-09-12      | 16:20:00         |             3.00 |
| 2017-09-12      | 14:00:00         |             3.00 |
| 2017-09-12      | 12:05:00         |             3.00 |
+-----------------+------------------+------------------+
18 rows in set (0,00 sec)
```

## Q2
### 2.1
#### 2.1.1
##### 2.1.1.1 Créer la table `m̀ots`comportant une colone `mot` de type chaine variable de longueur maximale 4
```Bash
mysql> CREATE TABLE IF NOT EXISTS mots (mot VARCHAR(4));
Query OK, 0 rows affected (0,01 sec)
```

##### 2.1.1.2 Ajouter les mots suivants dans la table : `info`, `tech`, `net`, `comm`
```Bash
mysql> INSERT INTO mots (mot) VALUES ('info'), ('tech'), ('net'), ('comm');
Query OK, 4 rows affected (0,00 sec)
Records: 4  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM mots;
+------+
| mot  |
+------+
| info |
| tech |
| net  |
| comm |
+------+
4 rows in set (0,00 sec)
```

##### 2.1.1.3 Créer une requête donnant toutes les combinaisons possibles de 2 mots
```Bash
mysql> SELECT * FROM mots m1, mots m2;
+------+------+
| mot  | mot  |
+------+------+
| comm | info |
| net  | info |
| tech | info |
| info | info |
| comm | tech |
| net  | tech |
| tech | tech |
| info | tech |
| comm | net  |
| net  | net  |
| tech | net  |
| info | net  |
| comm | comm |
| net  | comm |
| tech | comm |
| info | comm |
+------+------+
16 rows in set (0,00 sec)
```

##### 2.1.1.4 Modifier le requête précédente en definissant une seule colonne `mot` pour le resultat
```Bash
mysql> SELECT concat(m1.mot, m2.mot) as mot FROM mots m1, mots m2;
+----------+
| mot      |
+----------+
| comminfo |
| netinfo  |
| techinfo |
| infoinfo |
| commtech |
| nettech  |
| techtech |
| infotech |
| commnet  |
| netnet   |
| technet  |
| infonet  |
| commcomm |
| netcomm  |
| techcomm |
| infocomm |
+----------+
16 rows in set (0,00 sec)
```

##### 2.1.1.5 Ameliorer la requête précédente en excluant les mots identiques
```Bash
mysql> SELECT concat(m1.mot, m2.mot) as mot FROM mots m1, mots m2 WHERE m1.mot not like m2.mot;
+----------+
| mot      |
+----------+
| comminfo |
| netinfo  |
| techinfo |
| commtech |
| nettech  |
| infotech |
| commnet  |
| technet  |
| infonet  |
| netcomm  |
| techcomm |
| infocomm |
+----------+
12 rows in set (0,00 sec)
```

##### 2.1.1.6 Créer une requête donnat tous les agencement possible de 3 mots differents
```Bash
mysql> SELECT concat(m1.mot, m2.mot, m3.mot) as mot FROM mots m1, mots m2, mots m3 WHERE m1.mot not like m2.mot and m1.mot not like m3.mot and m2.mot not like m3.mot;
+--------------+
| mot          |
+--------------+
| techcomminfo |
| netcomminfo  |
| technetinfo  |
| commnetinfo  |
| nettechinfo  |
| commtechinfo |
| infocommtech |
| netcommtech  |
| infonettech  |
| commnettech  |
| netinfotech  |
| comminfotech |
| infocommnet  |
| techcommnet  |
| infotechnet  |
| commtechnet  |
| techinfonet  |
| comminfonet  |
| infonetcomm  |
| technetcomm  |
| infotechcomm |
| nettechcomm  |
| techinfocomm |
| netinfocomm  |
+--------------+
24 rows in set (0,00 sec)
```

##### 2.1.1.7 Créer une requête donnant tous les agencement possible de 2 ou 3 mots differents classés par ordre alphabetique (union)
```Bash
mysql> SELECT concat(m1.mot, m2.mot) as mot FROM mots m1, mots m2 WHERE m1.mot not like m2.mot UNION SELECT concat(m1.mot, m2.mot, m3.mot) as mot FROM mots m1, mots m2, mots m3 WHERE m1.mot not like m2.mot and m1.mot not like m3.mot and m2.mot not like m3.mot order by mot;
+--------------+
| mot          |
+--------------+
| comminfo     |
| comminfonet  |
| comminfotech |
| commnet      |
| commnetinfo  |
| commnettech  |
| commtech     |
| commtechinfo |
| commtechnet  |
| infocomm     |
| infocommnet  |
| infocommtech |
| infonet      |
| infonetcomm  |
| infonettech  |
| infotech     |
| infotechcomm |
| infotechnet  |
| netcomm      |
| netcomminfo  |
| netcommtech  |
| netinfo      |
| netinfocomm  |
| netinfotech  |
| nettech      |
| nettechcomm  |
| nettechinfo  |
| techcomm     |
| techcomminfo |
| techcommnet  |
| techinfo     |
| techinfocomm |
| techinfonet  |
| technet      |
| technetcomm  |
| technetinfo  |
+--------------+
36 rows in set (0,00 sec)
```

### 2.2
#### 2.2.1
##### 2.2.1.1 Créer la table `termes` comportant une colone `terme` de type chaine variable de longueur maximale 16
```Bash
mysql> CREATE TABLE IF NOT EXISTS termes (terme VARCHAR(16));
Query OK, 0 rows affected (0,01 sec)
```

##### 2.2.1.2 Ajouter les mots suivant dans la table : `Belle marquise`, `vos beaux yeux`, `me font`, `mourir`, `d'amour`
```Bash
mysql> INSERT INTO termes (terme) VALUES ('Belle marquise'), ('vos beaux yeux'), ('me font'), ('mourir'), ('d''amour');
Query OK, 5 rows affected (0,00 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM termes;
+----------------+
| terme          |
+----------------+
| Belle marquise |
| vos beaux yeux |
| me font        |
| mourir         |
| d'amour        |
+----------------+
5 rows in set (0,00 sec)
```

##### 2.2.1.3 Créer la requête qui va permettre de lister toutes les permutations possibles des 5 termes differents
```Bash
mysql> SELECT concat(t1.terme, ' ', t2.terme, ' ', t3.terme, ' ', t4.terme, ' ', t5.terme) as phrase FROM termes t1, termes t2, termes t3, termes t4, termes t5 WHERE t1.terme not like t2.terme and t1.terme not like t3.terme and t1.terme not like t4.terme and t1.terme not like t5.terme and t2.terme not like t3.terme and t2.terme not like t4.terme and t2.terme not like t5.terme and t3.terme not like t4.terme and t3.terme not like t5.terme and t4.terme not like t5.terme;
+------------------------------------------------------+
| phrase                                               |
+------------------------------------------------------+
| me font mourir vos beaux yeux d'amour Belle marquise |
| mourir me font vos beaux yeux d'amour Belle marquise |
| vos beaux yeux mourir me font d'amour Belle marquise |
| mourir vos beaux yeux me font d'amour Belle marquise |
| vos beaux yeux me font mourir d'amour Belle marquise |
| me font vos beaux yeux mourir d'amour Belle marquise |
| me font d'amour vos beaux yeux mourir Belle marquise |
| d'amour me font vos beaux yeux mourir Belle marquise |
| vos beaux yeux d'amour me font mourir Belle marquise |
| d'amour vos beaux yeux me font mourir Belle marquise |
| vos beaux yeux me font d'amour mourir Belle marquise |
| me font vos beaux yeux d'amour mourir Belle marquise |
| mourir d'amour vos beaux yeux me font Belle marquise |
| d'amour mourir vos beaux yeux me font Belle marquise |
| vos beaux yeux d'amour mourir me font Belle marquise |
| d'amour vos beaux yeux mourir me font Belle marquise |
| vos beaux yeux mourir d'amour me font Belle marquise |
| mourir vos beaux yeux d'amour me font Belle marquise |
| mourir d'amour me font vos beaux yeux Belle marquise |
| d'amour mourir me font vos beaux yeux Belle marquise |
| me font d'amour mourir vos beaux yeux Belle marquise |
| d'amour me font mourir vos beaux yeux Belle marquise |
| me font mourir d'amour vos beaux yeux Belle marquise |
| mourir me font d'amour vos beaux yeux Belle marquise |
| me font mourir Belle marquise d'amour vos beaux yeux |
| mourir me font Belle marquise d'amour vos beaux yeux |
| Belle marquise mourir me font d'amour vos beaux yeux |
| mourir Belle marquise me font d'amour vos beaux yeux |
| Belle marquise me font mourir d'amour vos beaux yeux |
| me font Belle marquise mourir d'amour vos beaux yeux |
| me font d'amour Belle marquise mourir vos beaux yeux |
| d'amour me font Belle marquise mourir vos beaux yeux |
| Belle marquise d'amour me font mourir vos beaux yeux |
| d'amour Belle marquise me font mourir vos beaux yeux |
| Belle marquise me font d'amour mourir vos beaux yeux |
| me font Belle marquise d'amour mourir vos beaux yeux |
| mourir d'amour Belle marquise me font vos beaux yeux |
| d'amour mourir Belle marquise me font vos beaux yeux |
| Belle marquise d'amour mourir me font vos beaux yeux |
| d'amour Belle marquise mourir me font vos beaux yeux |
| Belle marquise mourir d'amour me font vos beaux yeux |
| mourir Belle marquise d'amour me font vos beaux yeux |
| mourir d'amour me font Belle marquise vos beaux yeux |
| d'amour mourir me font Belle marquise vos beaux yeux |
| me font d'amour mourir Belle marquise vos beaux yeux |
| d'amour me font mourir Belle marquise vos beaux yeux |
| me font mourir d'amour Belle marquise vos beaux yeux |
| mourir me font d'amour Belle marquise vos beaux yeux |
| vos beaux yeux mourir Belle marquise d'amour me font |
| mourir vos beaux yeux Belle marquise d'amour me font |
| Belle marquise mourir vos beaux yeux d'amour me font |
| mourir Belle marquise vos beaux yeux d'amour me font |
| Belle marquise vos beaux yeux mourir d'amour me font |
| vos beaux yeux Belle marquise mourir d'amour me font |
| vos beaux yeux d'amour Belle marquise mourir me font |
| d'amour vos beaux yeux Belle marquise mourir me font |
| Belle marquise d'amour vos beaux yeux mourir me font |
| d'amour Belle marquise vos beaux yeux mourir me font |
| Belle marquise vos beaux yeux d'amour mourir me font |
| vos beaux yeux Belle marquise d'amour mourir me font |
| mourir d'amour Belle marquise vos beaux yeux me font |
| d'amour mourir Belle marquise vos beaux yeux me font |
| Belle marquise d'amour mourir vos beaux yeux me font |
| d'amour Belle marquise mourir vos beaux yeux me font |
| Belle marquise mourir d'amour vos beaux yeux me font |
| mourir Belle marquise d'amour vos beaux yeux me font |
| mourir d'amour vos beaux yeux Belle marquise me font |
| d'amour mourir vos beaux yeux Belle marquise me font |
| vos beaux yeux d'amour mourir Belle marquise me font |
| d'amour vos beaux yeux mourir Belle marquise me font |
| vos beaux yeux mourir d'amour Belle marquise me font |
| mourir vos beaux yeux d'amour Belle marquise me font |
| vos beaux yeux me font Belle marquise d'amour mourir |
| me font vos beaux yeux Belle marquise d'amour mourir |
| Belle marquise me font vos beaux yeux d'amour mourir |
| me font Belle marquise vos beaux yeux d'amour mourir |
| Belle marquise vos beaux yeux me font d'amour mourir |
| vos beaux yeux Belle marquise me font d'amour mourir |
| vos beaux yeux d'amour Belle marquise me font mourir |
| d'amour vos beaux yeux Belle marquise me font mourir |
| Belle marquise d'amour vos beaux yeux me font mourir |
| d'amour Belle marquise vos beaux yeux me font mourir |
| Belle marquise vos beaux yeux d'amour me font mourir |
| vos beaux yeux Belle marquise d'amour me font mourir |
| me font d'amour Belle marquise vos beaux yeux mourir |
| d'amour me font Belle marquise vos beaux yeux mourir |
| Belle marquise d'amour me font vos beaux yeux mourir |
| d'amour Belle marquise me font vos beaux yeux mourir |
| Belle marquise me font d'amour vos beaux yeux mourir |
| me font Belle marquise d'amour vos beaux yeux mourir |
| me font d'amour vos beaux yeux Belle marquise mourir |
| d'amour me font vos beaux yeux Belle marquise mourir |
| vos beaux yeux d'amour me font Belle marquise mourir |
| d'amour vos beaux yeux me font Belle marquise mourir |
| vos beaux yeux me font d'amour Belle marquise mourir |
| me font vos beaux yeux d'amour Belle marquise mourir |
| vos beaux yeux me font Belle marquise mourir d'amour |
| me font vos beaux yeux Belle marquise mourir d'amour |
| Belle marquise me font vos beaux yeux mourir d'amour |
| me font Belle marquise vos beaux yeux mourir d'amour |
| Belle marquise vos beaux yeux me font mourir d'amour |
| vos beaux yeux Belle marquise me font mourir d'amour |
| vos beaux yeux mourir Belle marquise me font d'amour |
| mourir vos beaux yeux Belle marquise me font d'amour |
| Belle marquise mourir vos beaux yeux me font d'amour |
| mourir Belle marquise vos beaux yeux me font d'amour |
| Belle marquise vos beaux yeux mourir me font d'amour |
| vos beaux yeux Belle marquise mourir me font d'amour |
| me font mourir Belle marquise vos beaux yeux d'amour |
| mourir me font Belle marquise vos beaux yeux d'amour |
| Belle marquise mourir me font vos beaux yeux d'amour |
| mourir Belle marquise me font vos beaux yeux d'amour |
| Belle marquise me font mourir vos beaux yeux d'amour |
| me font Belle marquise mourir vos beaux yeux d'amour |
| me font mourir vos beaux yeux Belle marquise d'amour |
| mourir me font vos beaux yeux Belle marquise d'amour |
| vos beaux yeux mourir me font Belle marquise d'amour |
| mourir vos beaux yeux me font Belle marquise d'amour |
| vos beaux yeux me font mourir Belle marquise d'amour |
| me font vos beaux yeux mourir Belle marquise d'amour |
+------------------------------------------------------+
120 rows in set (0,00 sec)
```