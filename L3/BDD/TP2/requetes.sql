-- a) Liste des étudiants (Nom, Sexe) appartenant à la formation L3 Info triée dans l’ordre décroissant des noms :
EXPLAIN PLAN FOR
SELECT e.NomE, e.Sexe FROM Etudiant e
JOIN Formation f ON e.CodeF = f.CodeF
WHERE f.Libelle = 'L3 Info'
ORDER BY e.NomE DESC;
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 2769416203

--------------------------------------------------------------------------------
--------------

| Id  | Operation                     | Name         | Rows  | Bytes | Cost (%CP
U)| Time     |

--------------------------------------------------------------------------------
--------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT              |              |     1 |    50 |     4  (2
5)| 00:00:01 |

|   1 |  SORT ORDER BY                |              |     1 |    50 |     4  (2
5)| 00:00:01 |

|   2 |   NESTED LOOPS                |              |     1 |    50 |     3   (
0)| 00:00:01 |

|   3 |    NESTED LOOPS               |              |     1 |    50 |     3   (
0)| 00:00:01 |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

|   4 |     TABLE ACCESS FULL         | ETUDIANT     |     1 |    30 |     2   (
0)| 00:00:01 |

|*  5 |     INDEX UNIQUE SCAN         | PK_FORMATION |     1 |       |     0   (
0)| 00:00:01 |

|*  6 |    TABLE ACCESS BY INDEX ROWID| FORMATION    |     1 |    20 |     1   (
0)| 00:00:01 |

--------------------------------------------------------------------------------

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
--------------


Predicate Information (identified by operation id):
---------------------------------------------------

   5 - access("E"."CODEF"="F"."CODEF")
   6 - filter("F"."LIBELLE"='L3 Info')

Note
-----

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
   - dynamic statistics used: dynamic sampling (level=2)
   - this is an adaptive plan

24 rows selected.
*/
/*
NOME                     S
------------------------ -
Yang                     M
Martin                   F
Gros                     F
Dupond                   M
Dubois                   M
*/

-- b) Répartition des étudiants selon le sexe :
EXPLAIN PLAN FOR
SELECT Sexe, COUNT(*) FROM Etudiant GROUP BY Sexe;
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 1145480021

-------------------------------------------------------------------------------
| Id  | Operation          | Name     | Rows  | Bytes | Cost (%CPU)| Time     |
-------------------------------------------------------------------------------
|   0 | SELECT STATEMENT   |          |     1 |     3 |     3  (34)| 00:00:01 |
|   1 |  HASH GROUP BY     |          |     1 |     3 |     3  (34)| 00:00:01 |
|   2 |   TABLE ACCESS FULL| ETUDIANT |     1 |     3 |     2   (0)| 00:00:01 |
-------------------------------------------------------------------------------

Note

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
-----
   - dynamic statistics used: dynamic sampling (level=2)

13 rows selected.
*/
/*
S   COUNT(*)
- ----------
M          6
F          5
*/

-- c) Liste des étudiants absents (Nom, Matiere) à certaines matières (ils n'ont pas été notés) :
EXPLAIN PLAN FOR
SELECT e.NomE, m.NomM FROM Etudiant e
CROSS JOIN Matiere m
LEFT JOIN Noter n ON e.NumEtu = n.NumEtu AND m.NumMat = n.NumMat
WHERE n.Note IS NULL;
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 3963098869

--------------------------------------------------------------------------------
-------------

| Id  | Operation                     | Name        | Rows  | Bytes | Cost (%CPU
)| Time     |

--------------------------------------------------------------------------------
-------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT              |             |     1 |    91 |     5   (0
)| 00:00:01 |

|*  1 |  FILTER                       |             |       |       |
 |          |

|   2 |   NESTED LOOPS OUTER          |             |     1 |    91 |     5   (0
)| 00:00:01 |

|   3 |    MERGE JOIN CARTESIAN       |             |     1 |    52 |     4   (0
)| 00:00:01 |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

|   4 |     TABLE ACCESS FULL         | ETUDIANT    |     1 |    27 |     2   (0
)| 00:00:01 |

|   5 |     BUFFER SORT               |             |     1 |    25 |     2   (0
)| 00:00:01 |

|   6 |      TABLE ACCESS FULL        | MATIERE     |     1 |    25 |     2   (0
)| 00:00:01 |

|   7 |    TABLE ACCESS BY INDEX ROWID| NOTER       |     1 |    39 |     1   (0

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
)| 00:00:01 |

|*  8 |     INDEX UNIQUE SCAN         | SYS_C008443 |     1 |       |     0   (0
)| 00:00:01 |

--------------------------------------------------------------------------------
-------------


Predicate Information (identified by operation id):
---------------------------------------------------

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

   1 - filter("N"."NOTE" IS NULL)
   8 - access("E"."NUMETU"="N"."NUMETU"(+) AND "M"."NUMMAT"="N"."NUMMAT"(+))

Note
-----
   - dynamic statistics used: dynamic sampling (level=2)

25 rows selected.
*/
/*
NOME                     NOMM
------------------------ --------------------
Bouziane                 Statistiques
Yang                     Programmation
Humbert                  Statistiques
Romain                   Statistiques
Romain                   Base de donnees
Gros                     G.P.A.O
Humbert                  Programmation
Paris                    Statistiques
Romain                   Programmation
Paris                    G.P.A.O
Romain                   G.P.A.O
Romain                   Logique

12 rows selected.
*/

-- d) Liste des étudiants (Nom) qui ont tous une note dans les matières :
EXPLAIN PLAN FOR
SELECT e.NomE FROM Etudiant e
WHERE NOT EXISTS (
    SELECT 1 FROM Matiere m
    LEFT JOIN Noter n ON e.NumEtu = n.NumEtu AND m.NumMat = n.NumMat
    WHERE n.Note IS NULL
);
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 3344930776

--------------------------------------------------------------------------------
--------------

| Id  | Operation                      | Name        | Rows  | Bytes | Cost (%CP
U)| Time     |

--------------------------------------------------------------------------------
--------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT               |             |     1 |    27 |     5   (
0)| 00:00:01 |

|*  1 |  FILTER                        |             |       |       |
  |          |

|   2 |   TABLE ACCESS FULL            | ETUDIANT    |     1 |    27 |     2   (
0)| 00:00:01 |

|*  3 |   FILTER                       |             |       |       |
  |          |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

|   4 |    NESTED LOOPS OUTER          |             |     1 |    52 |     3   (
0)| 00:00:01 |

|   5 |     TABLE ACCESS FULL          | MATIERE     |     1 |    13 |     2   (
0)| 00:00:01 |

|   6 |     TABLE ACCESS BY INDEX ROWID| NOTER       |     1 |    39 |     1   (
0)| 00:00:01 |

|*  7 |      INDEX UNIQUE SCAN         | SYS_C008443 |     1 |       |     0   (

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
0)| 00:00:01 |

--------------------------------------------------------------------------------
--------------


Predicate Information (identified by operation id):
---------------------------------------------------

   1 - filter( NOT EXISTS (SELECT 0 FROM "NOTER" "N","MATIERE" "M" WHERE
              "M"."NUMMAT"="N"."NUMMAT"(+) AND "N"."NUMETU"(+)=:B1 AND "N"."NOTE

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
" IS NULL))

   3 - filter("N"."NOTE" IS NULL)
   7 - access("N"."NUMETU"(+)=:B1 AND "M"."NUMMAT"="N"."NUMMAT"(+))

Note
-----
   - dynamic statistics used: dynamic sampling (level=2)

26 rows selected.
*/
/*
NOME
------------------------
Dupond
Dubois
Favier
Henri
Martin
*/

-- e) Liste des étudiants (Nom) qui n’ont aucune note dans les matières :
EXPLAIN PLAN FOR
SELECT e.NomE FROM Etudiant e
WHERE NOT EXISTS (
    SELECT 1 FROM Noter n
    WHERE e.NumEtu = n.NumEtu
);
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 3400618341

--------------------------------------------------------------------------------
--

| Id  | Operation          | Name        | Rows  | Bytes | Cost (%CPU)| Time
 |

--------------------------------------------------------------------------------
--


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT   |             |     1 |    40 |     3   (0)| 00:00:01
 |

|   1 |  NESTED LOOPS ANTI |             |     1 |    40 |     3   (0)| 00:00:01
 |

|   2 |   TABLE ACCESS FULL| ETUDIANT    |     1 |    27 |     2   (0)| 00:00:01
 |

|*  3 |   INDEX RANGE SCAN | SYS_C008443 |     1 |    13 |     1   (0)| 00:00:01
 |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
--


Predicate Information (identified by operation id):
---------------------------------------------------

   3 - access("E"."NUMETU"="N"."NUMETU")

Note

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
-----
   - dynamic statistics used: dynamic sampling (level=2)
   - this is an adaptive plan

20 rows selected.
*/
/*
NOME
------------------------
Romain
*/

-- f) Liste des étudiants (Nom) qui ont la plus basse note en Programmation :
EXPLAIN PLAN FOR
SELECT e.NomE FROM Etudiant e
JOIN Noter n ON e.NumEtu = n.NumEtu
JOIN Matiere m ON n.NumMat = m.NumMat
WHERE m.NomM = 'Programmation'
  AND n.Note = (
      SELECT MIN(n2.Note) FROM Noter n2
      JOIN Matiere m2 ON n2.NumMat = m2.NumMat
      WHERE m2.NomM = 'Programmation'
  );
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 3660965418

--------------------------------------------------------------------------------
-----------------

| Id  | Operation                         | Name        | Rows  | Bytes | Cost (
%CPU)| Time     |

--------------------------------------------------------------------------------
-----------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT                  |             |     1 |    91 |     7
  (0)| 00:00:01 |

|   1 |  NESTED LOOPS                     |             |     1 |    91 |     4
  (0)| 00:00:01 |

|   2 |   NESTED LOOPS                    |             |     1 |    91 |     4
  (0)| 00:00:01 |

|   3 |    NESTED LOOPS                   |             |     1 |    66 |     3
  (0)| 00:00:01 |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

|*  4 |     TABLE ACCESS FULL             | NOTER       |     1 |    39 |     2
  (0)| 00:00:01 |

|   5 |      SORT AGGREGATE               |             |     1 |    51 |
     |          |

|   6 |       NESTED LOOPS SEMI           |             |     1 |    51 |     3
  (0)| 00:00:01 |

|   7 |        TABLE ACCESS FULL          | NOTER       |     1 |    26 |     2

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
  (0)| 00:00:01 |

|*  8 |        TABLE ACCESS BY INDEX ROWID| MATIERE     |     1 |    25 |     1
  (0)| 00:00:01 |

|*  9 |         INDEX UNIQUE SCAN         | PK_MATIERE  |     1 |       |     0
  (0)| 00:00:01 |

|  10 |     TABLE ACCESS BY INDEX ROWID   | ETUDIANT    |     1 |    27 |     1
  (0)| 00:00:01 |


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|* 11 |      INDEX UNIQUE SCAN            | PK_ETUDIANT |     1 |       |     0
  (0)| 00:00:01 |

|* 12 |    INDEX UNIQUE SCAN              | PK_MATIERE  |     1 |       |     0
  (0)| 00:00:01 |

|* 13 |   TABLE ACCESS BY INDEX ROWID     | MATIERE     |     1 |    25 |     1
  (0)| 00:00:01 |

--------------------------------------------------------------------------------
-----------------

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------


Predicate Information (identified by operation id):
---------------------------------------------------

   4 - filter("N"."NOTE"= (SELECT MIN("N2"."NOTE") FROM "MATIERE" "M2","NOTER"
              "N2","MATIERE" "M2" WHERE "N2"."NUMMAT"="M2"."NUMMAT" AND "M2"."NO
MM"='Programmation'

              AND "N2"."NUMMAT"="M2"."NUMMAT" AND "M2"."NOMM"='Programmation'))
   8 - filter("M2"."NOMM"='Programmation')

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
   9 - access("N2"."NUMMAT"="M2"."NUMMAT")
  11 - access("E"."NUMETU"="N"."NUMETU")
  12 - access("N"."NUMMAT"="M"."NUMMAT")
  13 - filter("M"."NOMM"='Programmation')

Note
-----
   - dynamic statistics used: dynamic sampling (level=2)
   - this is an adaptive plan

37 rows selected.
*/
/*
NOME
------------------------
Dupond
Henri
*/

-- g) Liste des étudiants (Nom, Moyenne générale) triée du moins bon au meilleur :
EXPLAIN PLAN FOR
SELECT e.NomE, ROUND(AVG(n.Note), 2) AS Moyenne_Generale FROM Etudiant e
JOIN Noter n ON e.NumEtu = n.NumEtu
GROUP BY e.NomE
ORDER BY Moyenne_Generale ASC;
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 4014261184

--------------------------------------------------------------------------------
--------------

| Id  | Operation                      | Name        | Rows  | Bytes | Cost (%CP
U)| Time     |

--------------------------------------------------------------------------------
--------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT               |             |     1 |    53 |     5  (4
0)| 00:00:01 |

|   1 |  SORT ORDER BY                 |             |     1 |    53 |     5  (4
0)| 00:00:01 |

|   2 |   HASH GROUP BY                |             |     1 |    53 |     5  (4
0)| 00:00:01 |

|   3 |    NESTED LOOPS                |             |     1 |    53 |     3   (
0)| 00:00:01 |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

|   4 |     NESTED LOOPS               |             |     1 |    53 |     3   (
0)| 00:00:01 |

|   5 |      TABLE ACCESS FULL         | NOTER       |     1 |    26 |     2   (
0)| 00:00:01 |

|*  6 |      INDEX UNIQUE SCAN         | PK_ETUDIANT |     1 |       |     0   (
0)| 00:00:01 |

|   7 |     TABLE ACCESS BY INDEX ROWID| ETUDIANT    |     1 |    27 |     1   (

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
0)| 00:00:01 |

--------------------------------------------------------------------------------
--------------


Predicate Information (identified by operation id):
---------------------------------------------------

   6 - access("E"."NUMETU"="N"."NUMETU")


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Note
-----
   - dynamic statistics used: dynamic sampling (level=2)
   - this is an adaptive plan

24 rows selected.
*/
/*
NOME                     MOYENNE_GENERALE
------------------------ ----------------
Paris                                9.33
Favier                                9.5
Dupond                                9.7
Bouziane                            10.25
Henri                                10.4
Gros                                11.13
Humbert                             11.33
Yang                                11.38
Dubois                               11.4
Martin                               13.8

10 rows selected.
*/

-- h) Liste des étudiants (Nom, Note) qui ont une note de programmation supérieure à toutes les notes (de toutes les matières) de l’étudiant Dubois :
EXPLAIN PLAN FOR
SELECT e.NomE, n.Note  FROM Etudiant e
JOIN Noter n ON e.NumEtu = n.NumEtu
JOIN Matiere m ON n.NumMat = m.NumMat
WHERE m.NomM = 'Programmation'
  AND n.Note > (
      SELECT MAX(n2.Note) FROM Etudiant e2
      JOIN Noter n2 ON e2.NumEtu = n2.NumEtu
      WHERE e2.NomE = 'Dubois'
  );
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 4107443717

--------------------------------------------------------------------------------
-----------------

| Id  | Operation                         | Name        | Rows  | Bytes | Cost (
%CPU)| Time     |

--------------------------------------------------------------------------------
-----------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT                  |             |     1 |    91 |     7
  (0)| 00:00:01 |

|   1 |  NESTED LOOPS                     |             |     1 |    91 |     4
  (0)| 00:00:01 |

|   2 |   NESTED LOOPS                    |             |     1 |    91 |     4
  (0)| 00:00:01 |

|   3 |    NESTED LOOPS                   |             |     1 |    66 |     3
  (0)| 00:00:01 |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

|*  4 |     TABLE ACCESS FULL             | NOTER       |     1 |    39 |     2
  (0)| 00:00:01 |

|   5 |      SORT AGGREGATE               |             |     1 |    53 |
     |          |

|   6 |       NESTED LOOPS                |             |     1 |    53 |     3
  (0)| 00:00:01 |

|   7 |        TABLE ACCESS BY INDEX ROWID| ETUDIANT    |     1 |    27 |     1

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
  (0)| 00:00:01 |

|*  8 |         INDEX UNIQUE SCAN         | SYS_C008436 |     1 |       |     1
  (0)| 00:00:01 |

|*  9 |        TABLE ACCESS FULL          | NOTER       |     1 |    26 |     2
  (0)| 00:00:01 |

|  10 |     TABLE ACCESS BY INDEX ROWID   | ETUDIANT    |     1 |    27 |     1
  (0)| 00:00:01 |


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|* 11 |      INDEX UNIQUE SCAN            | PK_ETUDIANT |     1 |       |     0
  (0)| 00:00:01 |

|* 12 |    INDEX UNIQUE SCAN              | PK_MATIERE  |     1 |       |     0
  (0)| 00:00:01 |

|* 13 |   TABLE ACCESS BY INDEX ROWID     | MATIERE     |     1 |    25 |     1
  (0)| 00:00:01 |

--------------------------------------------------------------------------------
-----------------

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------


Predicate Information (identified by operation id):
---------------------------------------------------

   4 - filter("N"."NOTE"> (SELECT MAX("N2"."NOTE") FROM "NOTER" "N2","ETUDIANT"
"E2"

              WHERE "E2"."NOME"='Dubois' AND "E2"."NUMETU"="N2"."NUMETU"))
   8 - access("E2"."NOME"='Dubois')
   9 - filter("E2"."NUMETU"="N2"."NUMETU")

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
  11 - access("E"."NUMETU"="N"."NUMETU")
  12 - access("N"."NUMMAT"="M"."NUMMAT")
  13 - filter("M"."NOMM"='Programmation')

Note
-----
   - dynamic statistics used: dynamic sampling (level=2)
   - this is an adaptive plan

36 rows selected.
*/
/*
NOME                           NOTE
------------------------ ----------
Martin                           18
*/

-- i) Augmenter de 2 points les notes de Programmation de tous les étudiants présents :
EXPLAIN PLAN FOR
UPDATE Noter
SET Note = Note + 2
WHERE NumMat = (
    SELECT NumMat FROM Matiere
    WHERE NomM = 'Programmation'
)
AND Note IS NOT NULL;
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 3174463328

-------------------------------------------------------------------------------
| Id  | Operation           | Name    | Rows  | Bytes | Cost (%CPU)| Time     |
-------------------------------------------------------------------------------
|   0 | UPDATE STATEMENT    |         |     1 |    26 |     4   (0)| 00:00:01 |
|   1 |  UPDATE             | NOTER   |       |       |            |          |
|*  2 |   TABLE ACCESS FULL | NOTER   |     1 |    26 |     2   (0)| 00:00:01 |
|*  3 |    TABLE ACCESS FULL| MATIERE |     1 |    25 |     2   (0)| 00:00:01 |
-------------------------------------------------------------------------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Predicate Information (identified by operation id):
---------------------------------------------------

   2 - filter("NOTE" IS NOT NULL AND "NUMMAT"= (SELECT "NUMMAT" FROM
              "MATIERE" "MATIERE" WHERE "NOMM"='Programmation'))
   3 - filter("NOMM"='Programmation')

Note
-----
   - dynamic statistics used: dynamic sampling (level=2)

21 rows selected.
*/
/*
8 rows updated.
*/

-- j) Créer la vue VueF et lister les étudiants (Nom) masculins de la formation L3 Info :
EXPLAIN PLAN FOR
CREATE OR REPLACE VIEW VueF AS
SELECT e.NomE, e.Sexe, f.Libelle FROM Etudiant e
JOIN Formation f ON e.CodeF = f.CodeF;
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 3174463328

-------------------------------------------------------------------------------
| Id  | Operation           | Name    | Rows  | Bytes | Cost (%CPU)| Time     |
-------------------------------------------------------------------------------
|   0 | UPDATE STATEMENT    |         |     1 |    26 |     4   (0)| 00:00:01 |
|   1 |  UPDATE             | NOTER   |       |       |            |          |
|*  2 |   TABLE ACCESS FULL | NOTER   |     1 |    26 |     2   (0)| 00:00:01 |
|*  3 |    TABLE ACCESS FULL| MATIERE |     1 |    25 |     2   (0)| 00:00:01 |
-------------------------------------------------------------------------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Predicate Information (identified by operation id):
---------------------------------------------------

   2 - filter("NOTE" IS NOT NULL AND "NUMMAT"= (SELECT "NUMMAT" FROM
              "MATIERE" "MATIERE" WHERE "NOMM"='Programmation'))
   3 - filter("NOMM"='Programmation')

Note
-----
   - dynamic statistics used: dynamic sampling (level=2)

21 rows selected.
*/
/*
View created.
*/

EXPLAIN PLAN FOR
SELECT NomE FROM VueF
WHERE Sexe = 'M' AND Libelle = 'L3 Info';
SELECT * FROM TABLE (DBMS_XPLAN.Display);
/*
PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Plan hash value: 1769904618

--------------------------------------------------------------------------------
-------------

| Id  | Operation                    | Name         | Rows  | Bytes | Cost (%CPU
)| Time     |

--------------------------------------------------------------------------------
-------------


PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
|   0 | SELECT STATEMENT             |              |     1 |    50 |     3   (0
)| 00:00:01 |

|   1 |  NESTED LOOPS                |              |     1 |    50 |     3   (0
)| 00:00:01 |

|   2 |   NESTED LOOPS               |              |     1 |    50 |     3   (0
)| 00:00:01 |

|*  3 |    TABLE ACCESS FULL         | ETUDIANT     |     1 |    30 |     2   (0
)| 00:00:01 |

PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------

|*  4 |    INDEX UNIQUE SCAN         | PK_FORMATION |     1 |       |     0   (0
)| 00:00:01 |

|*  5 |   TABLE ACCESS BY INDEX ROWID| FORMATION    |     1 |    20 |     1   (0
)| 00:00:01 |

--------------------------------------------------------------------------------
-------------



PLAN_TABLE_OUTPUT
--------------------------------------------------------------------------------
Predicate Information (identified by operation id):
---------------------------------------------------

   3 - filter("E"."SEXE"='M')
   4 - access("E"."CODEF"="F"."CODEF")
   5 - filter("F"."LIBELLE"='L3 Info')

Note
-----
   - dynamic statistics used: dynamic sampling (level=2)
   - this is an adaptive plan

24 rows selected.
*/
/*
NOME
------------------------
Dupond
Dubois
Yang
*/