-- 1. Les descriptifs des rayons dont les chiffres d'affaire sont supérieurs à 1000 000.
SELECT DESCRIPTIF FROM RAYON WHERE CHIFFREAFFAIRE > 1000000;
/*
DESCRIPTIF
--------------------------------------------------------------------------------
V??tements
*/

-- 2. Les noms des hypermarchés se trouvant à Calais.
SELECT NOM FROM HYPERMARCHE WHERE VILLE = 'Calais';
/*
NOM
--------------------------------------------------
DO-SPORT
Dealer Price
*/

-- 3. Les noms des hypermarchés se trouvant dans le Pas de Calais.
SELECT NOM FROM HYPERMARCHE WHERE CODEPOSTAL LIKE '62%';
/*
NOM
--------------------------------------------------
Marrefour Coquelles
DO-SPORT
Dealer Price
*/

-- 4. Les noms et prénoms des responsables de rayons dont les chiffres d'affaires sont supérieurs à 1000000.
SELECT E.NOM, E.PRENOM FROM RAYON R
JOIN EMPLOYE E ON R.NUMERORESPONSABLE = E.NUMERO
WHERE R.CHIFFREAFFAIRE > 1000000;
/*
NOM
--------------------------------------------------
PRENOM
--------------------------------------------------
VASSEUR
Jacques
*/

-- 5. Les noms et prénoms des responsables de rayons de l'hypermarché 'Marrefour coquelles' et dont le chiffre d'affaire est inférieur à 500000.
SELECT E.NOM, E.PRENOM FROM RAYON R
JOIN EMPLOYE E ON R.NUMERORESPONSABLE = E.NUMERO
WHERE R.NUMEROHYPER = 'HYP12' AND R.CHIFFREAFFAIRE < 500000;
/*
no rows selected
*/

-- 6. Le nom du directeur de l’hypermarché se trouvant à Calais et contenant un rayon dont le chiffre d'affaire est inférieur à 500000 et dont le responsable est Max Stevenson.
SELECT E.NOM FROM HYPERMARCHE H
JOIN EMPLOYE E ON H.NUMERODIRECTEUR = E.NUMERO
JOIN RAYON R ON H.NUMERO = R.NUMEROHYPER
WHERE H.VILLE = 'Calais' AND R.CHIFFREAFFAIRE < 500000 AND E.NOM = 'Stevenson' AND E.PRENOM = 'Max';
/*
no rows selected
*/

-- 7. Le nom de l'hypermarché contenant un rayon dont le chiffre d'affaire est le plus haut.
SELECT H.NOM FROM RAYON R
JOIN HYPERMARCHE H ON R.NUMEROHYPER = H.NUMERO
WHERE R.CHIFFREAFFAIRE = (SELECT MAX(CHIFFREAFFAIRE) FROM RAYON);
/*
NOM
--------------------------------------------------
DO-SPORT
*/

SELECT H.NOM FROM RAYON R
JOIN HYPERMARCHE H ON R.NUMEROHYPER = H.NUMERO
ORDER BY R.CHIFFREAFFAIRE DESC FETCH FIRST 1 ROWS ONLY;
/*
 NOM
--------------------------------------------------
DO-SPORT
 */

-- 8. Le nom du responsable de rayon de l'hypermarché 'Marrefour Coquelles' dont le chiffre d'affaire est le plus haut.
SELECT E.NOM FROM RAYON R
JOIN EMPLOYE E ON R.NUMERORESPONSABLE = E.NUMERO
WHERE R.NUMEROHYPER = 'HYP12' AND R.CHIFFREAFFAIRE = (SELECT MAX(CHIFFREAFFAIRE) FROM RAYON WHERE NUMEROHYPER = 'HYP12');
/*
NOM
--------------------------------------------------
DURAND
*/

SELECT E.NOM FROM RAYON R
JOIN EMPLOYE E ON R.NUMERORESPONSABLE = E.NUMERO
WHERE R.NUMEROHYPER = 'HYP12'
ORDER BY R.CHIFFREAFFAIRE DESC FETCH FIRST 1 ROWS ONLY;
/*
NOM
--------------------------------------------------
DURAND
*/

-- 9. Le nom de l'hypermarché contenant un rayon dont le chiffre d'affaire n'est pas le plus haut.
SELECT DISTINCT H.NOM FROM RAYON R
JOIN HYPERMARCHE H ON R.NUMEROHYPER = H.NUMERO
WHERE R.CHIFFREAFFAIRE < (SELECT MAX(CHIFFREAFFAIRE) FROM RAYON);
/*
 NOM
--------------------------------------------------
Marrefour Coquelles
DO-SPORT
Dealer Price
*/

SELECT DISTINCT H.NOM FROM RAYON R
JOIN HYPERMARCHE H ON R.NUMEROHYPER = H.NUMERO
WHERE R.CHIFFREAFFAIRE != (SELECT MAX(CHIFFREAFFAIRE) FROM RAYON);
/*
 NOM
--------------------------------------------------
Marrefour Coquelles
DO-SPORT
Dealer Price
*/

-- 10. Le chiffre d'affaire total de tous les hypermarchés.
SELECT SUM(CHIFFREAFFAIRE) AS CA_TOTAL FROM RAYON;
/*
  CA_TOTAL
----------
  53700000
*/

-- 11. Le chiffre d'affaire total de l'hypermarché géré par 'Dupont' 'Jean' et contenant un rayon géré par 'Durand' 'Christophe'.
SELECT SUM(R.CHIFFREAFFAIRE) AS CA_TOTAL FROM HYPERMARCHE H
JOIN EMPLOYE E1 ON H.NUMERODIRECTEUR = E1.NUMERO
JOIN RAYON R ON H.NUMERO = R.NUMEROHYPER
JOIN EMPLOYE E2 ON R.NUMERORESPONSABLE = E2.NUMERO
WHERE E1.NOM = 'Dupont' AND E1.PRENOM = 'Jean' AND E2.NOM = 'Durand' AND E2.PRENOM = 'Christophe';
/*
  CA_TOTAL
----------
*/

-- 12. Les couples des hypermarchés dont la moyenne des chiffres d'affaires des rayons est supérieure à 1 500 000 euros.
SELECT H.NOM, SUM(R.CHIFFREAFFAIRE) AS CA_TOTAL FROM HYPERMARCHE H
JOIN RAYON R ON H.NUMERO = R.NUMEROHYPER
GROUP BY H.NOM HAVING AVG(R.CHIFFREAFFAIRE) > 1500000;
/*
NOM                                                  CA_TOTAL
-------------------------------------------------- ----------
DO-SPORT
*/