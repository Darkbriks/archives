-- Patron Antoine

-- 1.1 Rollback et Commit
-- 1.1.1 Etude du rollback
INSERT INTO EMPLOYE (NUMERO, NOM, PRENOM, ADRESSE) VALUES ('EMP1190', 'ROGER', 'Stéphane', '362, rue stéphane-roger, Ardres');
INSERT INTO EMPLOYE (NUMERO, NOM, PRENOM, ADRESSE) VALUES ('EMP1401', 'DURAND', 'Nicolas', '397, rue noclas-rouselle, St-Omer');

SELECT * FROM EMPLOYE;
/*
1 row created.

1 row created.

NUMERO  NOM
------- --------------------------------------------------
PRENOM
--------------------------------------------------
ADRESSE
--------------------------------------------------------------------------------
EMP1090 DUPONT
Jean
332, rue jean-dupont, Calais

EMP1301 DUVIVIER
Renaud
345, rue renaud-duviver, Paris

EMP1208 GODART
Claude
674, rue claude-godart, Ardre

EMP2025 FONTAINE
Fabien
456, rue jean-louis, Calais

EMP1505 VASSEUR
Jacques
778, rue vasseur, Saint-Omer

EMP7645 BERNARD
Martin
876, rue martin, Sangatte

EMP2341 RICHARD
Philipe
955, rue bernard, Coudekerque

EMP8765 Hugo
Victor
432, rue victor-hugo, Frethun

EMP4328 Stevenson
Max
874, rue max-stevenson, Cologne

EMP7862 DURAND
Christophe
543, rue durand, Calais

EMP1190 ROGER
St??phane
362, rue st??phane-roger, Ardres

EMP1401 DURAND
Nicolas
397, rue noclas-rouselle, St-Omer


12 rows selected.
*/

ROLLBACK;
/*
Rollback complete;
*/

SELECT * FROM EMPLOYE;
/*
no rows selected
*/
-- Grâce au commandes précédantes, on peut déduire que rollback permet de revenir a un état précédant de la base de donnée

-- 1.1.2 Etude du commit
INSERT INTO EMPLOYE (NUMERO, NOM, PRENOM, ADRESSE) VALUES ('EMP1190', 'ROGER', 'Stéphane', '362, rue stéphane-roger, Ardres');
INSERT INTO EMPLOYE (NUMERO, NOM, PRENOM, ADRESSE) VALUES ('EMP1401', 'DURAND', 'Nicolas', '397, rue noclas-rouselle, St-Omer');

SELECT * FROM EMPLOYE;
/*
1 row created.

1 row created.

NUMERO  NOM
------- --------------------------------------------------
PRENOM
--------------------------------------------------
ADRESSE
--------------------------------------------------------------------------------
EMP1190 ROGER
St??phane
362, rue st??phane-roger, Ardres

EMP1401 DURAND
Nicolas
397, rue noclas-rouselle, St-Omer
*/

COMMIT;
/*
Commit complete
*/

SELECT * FROM EMPLOYE;
/*
NUMERO  NOM
------- --------------------------------------------------
PRENOM
--------------------------------------------------
ADRESSE
--------------------------------------------------------------------------------
EMP1190 ROGER
St??phane
362, rue st??phane-roger, Ardres

EMP1401 DURAND
Nicolas
397, rue noclas-rouselle, St-Omer
*/

ROLLBACK;
/*
Rollback complete.
*/

SELECT * FROM EMPLOYE;
/*
NUMERO  NOM
------- --------------------------------------------------
PRENOM
--------------------------------------------------
ADRESSE
--------------------------------------------------------------------------------
EMP1190 ROGER
St??phane
362, rue st??phane-roger, Ardres

EMP1401 DURAND
Nicolas
397, rue noclas-rouselle, St-Omer
*/
-- On peut en déduire que commit permet d'enregistrer l'état de la base de donnée, pour pouvoir y revenir plus tard avec un rollback

-- 1.2 Création dynamique de tables
DROP TABLE HABITANT_CALAIS;

CREATE TABLE HABITANT_CALAIS(NUMERO, NOM, PRENOM, ADRESSE)
AS SELECT NUMERO, NOM, PRENOM, ADRESSE FROM EMPLOYE
WHERE ADRESSE LIKE '%Calais%';
/*
Table dropped.

Table created.
*/

SELECT * FROM HABITANT_CALAIS;
/*
NUMERO  NOM
------- --------------------------------------------------
PRENOM
--------------------------------------------------
ADRESSE
--------------------------------------------------------------------------------
EMP1090 DUPONT
Jean
332, rue jean-dupont, Calais

EMP2025 FONTAINE
Fabien
456, rue jean-louis, Calais

EMP7862 DURAND
Christophe
543, rue durand, Calais
*/

--Créer la table HYPERMARCHE_RAYON à partir des tables HYPERMARCHE et RAYON qui ne contient que
--trois colonnes (HYPERMARCHE.NOM, RAYON.NOM, RAYON.CHIFFREAFFAIRE). Vous ne
--poserez aucune contrainte sur cette table
DROP TABLE HYPERMARCHE_RAYON;

CREATE TABLE HYPERMARCHE_RAYON(NOM_HYPERMARCHE, NOM_RAYON, CHIFFREAFFAIRE)
AS SELECT H.NOM, R.NOM, R.CHIFFREAFFAIRE FROM HYPERMARCHE H
JOIN RAYON R ON H.NUMERO = R.NUMEROHYPER;
/*
Table dropped.

Table created.
*/

SELECT * FROM HYPERMARCHE_RAYON;
/*
NOM_HYPERMARCHE
--------------------------------------------------
NOM_RAYON                                          CHIFFREAFFAIRE
-------------------------------------------------- --------------
Marrefour Coquelles
Boucherie                                                 1000000

DO-SPORT
Textile                                                  50000000

DO-SPORT
Chaussure                                                  800000

Marrefour Coquelles
Poissonnerie                                               950000

Dealer Price
L??gumes                                                   450000

Dealer Price
Boucherie                                                  500000


6 rows selected.
*/

-- 1.3 Bloc PL/SQL
SET SERVEROUTPUT ON;

-- 1.3.1 Ecrire un bloc PL/SQL qui lit au clavier les champs d'un employé et les insère dans la table EMPLOYE, avec le message "Employé Inséré".
ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro de l''employé : ';
ACCEPT NOM CHAR PROMPT 'Entrez le nom de l''employé : ';
ACCEPT PRENOM CHAR PROMPT 'Entrez le prénom de l''employé : ';
ACCEPT ADRESSE CHAR PROMPT exi'Entrez l''adresse de l''employé : ';

DECLARE
    V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
    V_NOM EMPLOYE.NOM%TYPE := '&NOM';
    V_PRENOM EMPLOYE.PRENOM%TYPE := '&PRENOM';
    V_ADRESSE EMPLOYE.ADRESSE%TYPE := '&ADRESSE';
BEGIN
    INSERT INTO EMPLOYE (NUMERO, NOM, PRENOM, ADRESSE) VALUES (V_NUMERO, V_NOM, V_PRENOM, V_ADRESSE);
    DBMS_OUTPUT.PUT_LINE('Employé inséré');
END;
/
/*
Entrez le numéro de l'employé : EMP0000
Entrez le nom de l'employé : un nom
Entrez le prénom de l'employé : un prenom
Entrez l'adresse de l'employé : une adresse
old   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := 'EMP0000';
old   3:     V_NOM EMPLOYE.NOM%TYPE := '&NOM';
new   3:     V_NOM EMPLOYE.NOM%TYPE := 'un nom';
old   4:     V_PRENOM EMPLOYE.PRENOM%TYPE := '&PRENOM';
new   4:     V_PRENOM EMPLOYE.PRENOM%TYPE := 'un prenom';
old   5:     V_ADRESSE EMPLOYE.ADRESSE%TYPE := '&ADRESSE';
new   5:     V_ADRESSE EMPLOYE.ADRESSE%TYPE := 'une adresse';

PL/SQL procedure successfully completed.
*/

SELECT * FROM EMPLOYE WHERE NUMERO = 'EMP0000';
/*
NUMERO  NOM
------- --------------------------------------------------
PRENOM
--------------------------------------------------
ADRESSE
--------------------------------------------------------------------------------
EMP0000 un nom
un prenom
une adresse
*/


-- 1.3.2 Ecrire un bloc PL/SQL qui lit au clavier le numéro d'un employé puis affiche les informations concernant cet employé.
ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro de l''employé : ';

DECLARE
    V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
    V_NOM EMPLOYE.NOM%TYPE;
    V_PRENOM EMPLOYE.PRENOM%TYPE;
    V_ADRESSE EMPLOYE.ADRESSE%TYPE;
BEGIN
    SELECT NOM, PRENOM, ADRESSE INTO V_NOM, V_PRENOM, V_ADRESSE FROM EMPLOYE WHERE NUMERO = V_NUMERO;
    DBMS_OUTPUT.PUT_LINE('Nom : ' || V_NOM || ', Prénom : ' || V_PRENOM || ', Adresse : ' || V_ADRESSE);
END;
/
/*
Entrez le numéro de l'employé : EMP0000
old   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := 'EMP0000';
Nom : un nom, Pr??nom : un prenom, Adresse : une adresse

PL/SQL procedure successfully completed.
*/

-- 1.3.3 Ecrire un bloc PL/SQL qui affiche la moyenne des prix des produits d'un hypermarché dont le numéro est rentré au clavier.
ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro de l''hypermarché : ';

DECLARE
    V_NUMERO HYPERMARCHE.NUMERO%TYPE := '&NUMERO';
    V_MOYENNE NUMBER;
BEGIN
    SELECT AVG(PRIXUNITAIRE) INTO V_MOYENNE FROM PRODUITS WHERE NUMERORAYON IN (SELECT NUMERO FROM RAYON WHERE NUMEROHYPER = V_NUMERO);
    DBMS_OUTPUT.PUT_LINE('La moyenne des prix des produits de l''hypermarché ' || V_NUMERO || ' est de ' || V_MOYENNE);
END;
/
/*
Entrez le numéro de l'hypermarché : HYP12
old   2:     V_NUMERO HYPERMARCHE.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO HYPERMARCHE.NUMERO%TYPE := 'HYP12';
La moyenne des prix des produits de l'hypermarch?? HYP12 est de 12.5

PL/SQL procedure successfully completed.
*/

-- 1.3.4
DROP TABLE PROMOTIONS;

CREATE TABLE PROMOTIONS(
NUMERO VARCHAR2(6),
NUMPRODUIT VARCHAR2(6),
POURCENTAGEREMISE NUMBER(4,2),
DATEDEBUT DATE,
DATEFIN DATE,
CONSTRAINT PK_PROMOTIONS PRIMARY KEY(NUMERO),
CONSTRAINT FK_PROMOTIONS_PRODUITS FOREIGN KEY(NUMPRODUIT) REFERENCES PRODUITS(NUMERO)
);

DROP SEQUENCE SEQ_PROMOTIONS;

CREATE SEQUENCE SEQ_PROMOTIONS
START WITH 1
INCREMENT BY 1
NOCACHE;

ACCEPT NUMEROPRODUIT CHAR PROMPT 'Entrez le numéro du produit : ';
ACCEPT POURCENTAGEREMISE NUMBER PROMPT 'Entrez le pourcentage de remise : ';

DECLARE
    V_NUMERO PROMOTIONS.NUMERO%TYPE := 'P' || TO_CHAR(SEQ_PROMOTIONS.NEXTVAL, 'FM0000');
    V_NUMPRODUIT PROMOTIONS.NUMPRODUIT%TYPE := '&NUMEROPRODUIT';
    V_POURCENTAGEREMISE PROMOTIONS.POURCENTAGEREMISE%TYPE := '&POURCENTAGEREMISE';
    V_DATEDEBUT PROMOTIONS.DATEDEBUT%TYPE := SYSDATE;
    V_DATEFIN PROMOTIONS.DATEFIN%TYPE := SYSDATE + 30;
    V_NOMBREPRODUITS NUMBER;
BEGIN
    SELECT COUNT(*) INTO V_NOMBREPRODUITS FROM PRODUITS WHERE NUMERO = V_NUMPRODUIT;
    IF V_NOMBREPRODUITS = 0 THEN
        DBMS_OUTPUT.PUT_LINE('Le produit ' || V_NUMPRODUIT || ' n''existe pas');
    ELSE
        INSERT INTO PROMOTIONS (NUMERO, NUMPRODUIT, POURCENTAGEREMISE, DATEDEBUT, DATEFIN) VALUES (V_NUMERO, V_NUMPRODUIT, V_POURCENTAGEREMISE, V_DATEDEBUT, V_DATEFIN);
        DBMS_OUTPUT.PUT_LINE('Promotion créée');
    END IF;
END;
/
-- Test sur un produit qui n'existe pas
/*
Table dropped.

Table created.

Sequence dropped.

Sequence created.

Entrez le numéro du produit : 000000
Entrez le pourcentage de remise : 5
old   3:     V_NUMPRODUIT PROMOTIONS.NUMPRODUIT%TYPE := '&NUMEROPRODUIT';
new   3:     V_NUMPRODUIT PROMOTIONS.NUMPRODUIT%TYPE := '000000';
old   4:     V_POURCENTAGEREMISE PROMOTIONS.POURCENTAGEREMISE%TYPE := '&POURCENTAGEREMISE';
new   4:     V_POURCENTAGEREMISE PROMOTIONS.POURCENTAGEREMISE%TYPE := '         5';
Le produit 000000 n'existe pas

PL/SQL procedure successfully completed.
*/
-- Test sur un produit qui existe
/*
Table dropped.

Table created.

Sequence dropped.

Sequence created.

Entrez le numéro du produit : PR1234
Entrez le pourcentage de remise : 5
old   3:     V_NUMPRODUIT PROMOTIONS.NUMPRODUIT%TYPE := '&NUMEROPRODUIT';
new   3:     V_NUMPRODUIT PROMOTIONS.NUMPRODUIT%TYPE := 'PR1234';
old   4:     V_POURCENTAGEREMISE PROMOTIONS.POURCENTAGEREMISE%TYPE := '&POURCENTAGEREMISE';
new   4:     V_POURCENTAGEREMISE PROMOTIONS.POURCENTAGEREMISE%TYPE := '         5';
Promotion cr????e

PL/SQL procedure successfully completed.
*/

SELECT * FROM PROMOTIONS;

/*
NUMERO NUMPRO POURCENTAGEREMISE DATEDEBUT DATEFIN
------ ------ ----------------- --------- ---------
P0001  PR1234                 5 15-JAN-25 14-FEB-25
*/

-- 1.3.5 Ecrire un bloc PL/SQL qui permet de mettre à jour le stock d'un produit dont le numéro est saisi au clavier.
SELECT QUANTITESTOCKHYPER FROM PRODUITS WHERE NUMERO = 'PR1234';
/*
QUANTITESTOCKHYPER
------------------
               345
*/

ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro du produit : ';
ACCEPT QUANTITE NUMBER PROMPT 'Entrez la quantité à ajouter : ';

DECLARE
    V_NUMERO PRODUITS.NUMERO%TYPE := '&NUMERO';
    V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '&QUANTITE';
    V_QUANTITEACTUELLE PRODUITS.QUANTITESTOCKHYPER%TYPE;
BEGIN
    SELECT QUANTITESTOCKHYPER INTO V_QUANTITEACTUELLE FROM PRODUITS WHERE NUMERO = V_NUMERO;
    UPDATE PRODUITS SET QUANTITESTOCKHYPER = V_QUANTITEACTUELLE + V_QUANTITE WHERE NUMERO = V_NUMERO;
    DBMS_OUTPUT.PUT_LINE('Stock mis à jour');
END;
/
/*
Entrez le numéro du produit : PR1234
Entrez la quantité à ajouter : 5
old   2:     V_NUMERO PRODUITS.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO PRODUITS.NUMERO%TYPE := 'PR1234';
old   3:     V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '&QUANTITE';
new   3:     V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '         5';
Stock mis ?? jour

PL/SQL procedure successfully completed.
*/

SELECT QUANTITESTOCKHYPER FROM PRODUITS WHERE NUMERO = 'PR1234';
/*
QUANTITESTOCKHYPER
------------------
               350
*/
/*
Entrez le numéro du produit : PR1234
Entrez la quantité à ajouter : -5
old   2:     V_NUMERO PRODUITS.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO PRODUITS.NUMERO%TYPE := 'PR1234';
old   3:     V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '&QUANTITE';
new   3:     V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '        -5';
Stock mis ?? jour

PL/SQL procedure successfully completed.
*/

SELECT QUANTITESTOCKHYPER FROM PRODUITS WHERE NUMERO = 'PR1234';
/*
QUANTITESTOCKHYPER
------------------
               345
*/

-- 1.3.6 Reprendre les questions 1.3.1 à 1.3.5, et rajouter la gestion des exceptions.
-- 1.3.6.1
ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro de l''employé : ';
ACCEPT NOM CHAR PROMPT 'Entrez le nom de l''employé : ';
ACCEPT PRENOM CHAR PROMPT 'Entrez le prénom de l''employé : ';
ACCEPT ADRESSE CHAR PROMPT 'Entrez l''adresse de l''employé : ';

DECLARE
    V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
    V_NOM EMPLOYE.NOM%TYPE := '&NOM';
    V_PRENOM EMPLOYE.PRENOM%TYPE := '&PRENOM';
    V_ADRESSE EMPLOYE.ADRESSE%TYPE := '&ADRESSE';
BEGIN
    INSERT INTO EMPLOYE (NUMERO, NOM, PRENOM, ADRESSE) VALUES (V_NUMERO, V_NOM, V_PRENOM, V_ADRESSE);
    DBMS_OUTPUT.PUT_LINE('Employé inséré');
EXCEPTION
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.PUT_LINE('L''employé existe déjà');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Erreur inconnue: ' || SQLERRM);
END;
/
/*
Entrez le numéro de l'employé : EMP0000
Entrez le nom de l'employé : un nom
Entrez le prénom de l'employé : un prenom
Entrez l'adresse de l'employé : une adresse
old   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := 'EMP0000';
old   3:     V_NOM EMPLOYE.NOM%TYPE := '&NOM';
new   3:     V_NOM EMPLOYE.NOM%TYPE := 'un nom';
old   4:     V_PRENOM EMPLOYE.PRENOM%TYPE := '&PRENOM';
new   4:     V_PRENOM EMPLOYE.PRENOM%TYPE := 'un prenom';
old   5:     V_ADRESSE EMPLOYE.ADRESSE%TYPE := '&ADRESSE';
new   5:     V_ADRESSE EMPLOYE.ADRESSE%TYPE := 'une adresse';
L'employ?? existe d??j??

PL/SQL procedure successfully completed.
*/

-- 1.3.6.2
ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro de l''employé : ';

DECLARE
    V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
    V_NOM EMPLOYE.NOM%TYPE;
    V_PRENOM EMPLOYE.PRENOM%TYPE;
    V_ADRESSE EMPLOYE.ADRESSE%TYPE;
BEGIN
    SELECT NOM, PRENOM, ADRESSE INTO V_NOM, V_PRENOM, V_ADRESSE FROM EMPLOYE WHERE NUMERO = V_NUMERO;
    DBMS_OUTPUT.PUT_LINE('Nom : ' || V_NOM || ', Prénom : ' || V_PRENOM || ', Adresse : ' || V_ADRESSE);
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('L''employé n''existe pas');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Erreur inconnue: ' || SQLERRM);
END;
/
/*
Entrez le numéro de l'employé : EMP9999
old   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO EMPLOYE.NUMERO%TYPE := 'EMP9999';
L'employ?? n'existe pas

PL/SQL procedure successfully completed.
*/

-- 1.3.6.3
ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro de l''hypermarché : ';

DECLARE
    V_NUMERO HYPERMARCHE.NUMERO%TYPE := '&NUMERO';
    V_MOYENNE NUMBER;
BEGIN
    SELECT AVG(PRIXUNITAIRE) INTO V_MOYENNE FROM PRODUITS WHERE NUMERORAYON IN (SELECT NUMERO FROM RAYON WHERE NUMEROHYPER = V_NUMERO);
    DBMS_OUTPUT.PUT_LINE('La moyenne des prix des produits de l''hypermarché ' || V_NUMERO || ' est de ' || V_MOYENNE);
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('L''hypermarché n''existe pas');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Erreur inconnue: ' || SQLERRM);
END;
/
/*
Entrez le numéro de l'hypermarché : HYP9999
old   2:     V_NUMERO HYPERMARCHE.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO HYPERMARCHE.NUMERO%TYPE := 'HYP9999';
L'hypermarch?? n'existe pas

PL/SQL procedure successfully completed.
*/

-- 1.3.6.4
ACCEPT NUMEROPRODUIT CHAR PROMPT 'Entrez le numéro du produit : ';
ACCEPT POURCENTAGEREMISE NUMBER PROMPT 'Entrez le pourcentage de remise : ';

DECLARE
    V_NUMERO PROMOTIONS.NUMERO%TYPE := 'P' || TO_CHAR(SEQ_PROMOTIONS.NEXTVAL, 'FM0000');
    V_NUMPRODUIT PROMOTIONS.NUMPRODUIT%TYPE := '&NUMEROPRODUIT';
    V_POURCENTAGEREMISE PROMOTIONS.POURCENTAGEREMISE%TYPE := '&POURCENTAGEREMISE';
    V_DATEDEBUT PROMOTIONS.DATEDEBUT%TYPE := SYSDATE;
    V_DATEFIN PROMOTIONS.DATEFIN%TYPE := SYSDATE + 30;
    V_NOMBREPRODUITS NUMBER;
BEGIN
    SELECT COUNT(*) INTO V_NOMBREPRODUITS FROM PRODUITS WHERE NUMERO = V_NUMPRODUIT;
    IF V_NOMBREPRODUITS = 0 THEN
        DBMS_OUTPUT.PUT_LINE('Le produit ' || V_NUMPRODUIT || ' n''existe pas');
    ELSE
        INSERT INTO PROMOTIONS (NUMERO, NUMPRODUIT, POURCENTAGEREMISE, DATEDEBUT, DATEFIN) VALUES (V_NUMERO, V_NUMPRODUIT, V_POURCENTAGEREMISE, V_DATEDEBUT, V_DATEFIN);
        DBMS_OUTPUT.PUT_LINE('Promotion créée');
    END IF;
EXCEPTION
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.PUT_LINE('La promotion existe déjà');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Erreur inconnue: ' || SQLERRM);
END;
/

-- 1.3.6.5
ACCEPT NUMERO CHAR PROMPT 'Entrez le numéro du produit : ';
ACCEPT QUANTITE NUMBER PROMPT 'Entrez la quantité à ajouter : ';

DECLARE
    V_NUMERO PRODUITS.NUMERO%TYPE := '&NUMERO';
    V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '&QUANTITE';
    V_QUANTITEACTUELLE PRODUITS.QUANTITESTOCKHYPER%TYPE;
BEGIN
    SELECT QUANTITESTOCKHYPER INTO V_QUANTITEACTUELLE FROM PRODUITS WHERE NUMERO = V_NUMERO;
    UPDATE PRODUITS SET QUANTITESTOCKHYPER = V_QUANTITEACTUELLE + V_QUANTITE WHERE NUMERO = V_NUMERO;
    DBMS_OUTPUT.PUT_LINE('Stock mis à jour');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Le produit n''existe pas');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Erreur inconnue: ' || SQLERRM);
END;
/
/*
Entrez le numéro du produit : PR9999
Entrez la quantité à ajouter : 5
old   2:     V_NUMERO PRODUITS.NUMERO%TYPE := '&NUMERO';
new   2:     V_NUMERO PRODUITS.NUMERO%TYPE := 'PR9999';
old   3:     V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '&QUANTITE';
new   3:     V_QUANTITE PRODUITS.QUANTITESTOCKHYPER%TYPE := '         5';
Le produit n'existe pas

PL/SQL procedure successfully completed.
*/