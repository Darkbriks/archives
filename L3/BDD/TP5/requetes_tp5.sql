-- Patron Antoine

-- 1.
DROP TABLE Promotions;
CREATE TABLE Promotions (
    numero NUMBER CONSTRAINT pk_promotions PRIMARY KEY,
    numeroProduit VARCHAR2(6) CONSTRAINT fk_promotions_produits REFERENCES Produits(numero),
    pourcentage_remise NUMBER NOT NULL,
    date_debut DATE NOT NULL,
    date_fin DATE NOT NULL,
    encours INTEGER DEFAULT 1,
    qte_vendue INTEGER DEFAULT 0
);

CREATE OR REPLACE PROCEDURE DesactiverPromotions
IS
BEGIN
    UPDATE Promotions
    SET encours = 0
    WHERE date_fin < SYSDATE;
END;
/

INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (1, 'PR1234', 10, TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('31/12/2023', 'DD/MM/YYYY'));
INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (2, 'PR5783', 20, TO_DATE('01/01/2025', 'DD/MM/YYYY'), TO_DATE('31/12/2025', 'DD/MM/YYYY'));

SELECT * FROM Promotions;

EXECUTE DesactiverPromotions;

SELECT * FROM Promotions;

/*
Table dropped.

Table created.

Procedure created.

1 row created.

1 row created.

    NUMERO NUMERO POURCENTAGE_REMISE DATE_DEBU DATE_FIN     ENCOURS QTE_VENDUE
---------- ------ ------------------ --------- --------- ---------- ----------
         1 PR1234                 10 01-JAN-23 31-DEC-23          1          0
         2 PR5783                 20 01-JAN-25 31-DEC-25          1          0

PL/SQL procedure successfully completed.

    NUMERO NUMERO POURCENTAGE_REMISE DATE_DEBU DATE_FIN     ENCOURS QTE_VENDUE
---------- ------ ------------------ --------- --------- ---------- ----------
         1 PR1234                 10 01-JAN-23 31-DEC-23          0          0
         2 PR5783                 20 01-JAN-25 31-DEC-25          1          0
*/

-- 2.
CREATE OR REPLACE TRIGGER majuscule_nom_prenom
BEFORE INSERT ON EMPLOYE
FOR EACH ROW
BEGIN
    :NEW.nom := UPPER(:NEW.nom);
    :NEW.prenom := UPPER(:NEW.prenom);
END;
/

INSERT INTO EMPLOYE (numero, nom, prenom, adresse) VALUES ('EMP1000', 'dupont', 'jean', '332, rue jean-dupont, Calais');

SELECT * FROM EMPLOYE WHERE numero = 'EMP1000';

/*
Trigger created.

1 row created.

NUMERO     NOM
---------- --------------------------------------------------
PRENOM
--------------------------------------------------
ADRESSE
--------------------------------------------------------------------------------
EMP1000    DUPONT
JEAN
332, rue jean-dupont, Calais
*/

-- 3.
CREATE OR REPLACE TRIGGER encours_promotion
BEFORE INSERT ON Promotions
FOR EACH ROW
BEGIN
    IF SYSDATE BETWEEN :NEW.date_debut AND :NEW.date_fin THEN
        :NEW.encours := 1;
    ELSE
        :NEW.encours := 0;
    END IF;
END;
/

INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (3, 'PR6765', 30, TO_DATE('01/01/2025', 'DD/MM/YYYY'), TO_DATE('31/12/2025', 'DD/MM/YYYY'));
INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (4, 'PR6765', 30, TO_DATE('01/01/2021', 'DD/MM/YYYY'), TO_DATE('31/12/2021', 'DD/MM/YYYY'));

SELECT * FROM Promotions WHERE numero = 3 OR numero = 4;

/*
Trigger created.

1 row created.

    NUMERO NUMERO POURCENTAGE_REMISE DATE_DEBU DATE_FIN     ENCOURS QTE_VENDUE
---------- ------ ------------------ --------- --------- ---------- ----------
         3 PR6765                 30 01-JAN-25 31-DEC-25          1          0
         4 PR6765                 30 01-JAN-21 31-DEC-21          0          0
 */

-- 4.
CREATE OR REPLACE TRIGGER annuler_promotion
BEFORE INSERT ON Promotions
FOR EACH ROW
BEGIN
    IF :NEW.date_fin < SYSDATE THEN
        RAISE_APPLICATION_ERROR(-20001, 'La date de fin de la promotion est déjà dépassée.');
    END IF;
END;
/

INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (4, 'PR6765', 30, TO_DATE('01/01/2021', 'DD/MM/YYYY'), TO_DATE('31/12/2021', 'DD/MM/YYYY'));

/*
Trigger created.

Error starting at line : 1 in command -
INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (4, 'PR6765', 30, TO_DATE('01/01/2021', 'DD/MM/YYYY'), TO_DATE('31/12/2021', 'DD/MM/YYYY'))
Error report -

ORA-20001: La date de fin de la promotion est déjà dépassée.
ORA-06512: at "SYS.ANNULER_PROMOTION", line 4
ORA-04088: error during execution of trigger 'SYS.ANNULER_PROMOTION'
 */

-- 5.
CREATE OR REPLACE TRIGGER maj_chiffre_affaire
BEFORE UPDATE OF QUANTITESTOCKHYPER ON PRODUITS
FOR EACH ROW
BEGIN
    IF :OLD.QUANTITESTOCKHYPER > :NEW.QUANTITESTOCKHYPER THEN
        UPDATE RAYON
        SET CHIFFREAFFAIRE = CHIFFREAFFAIRE + (:OLD.QUANTITESTOCKHYPER - :NEW.QUANTITESTOCKHYPER) * :NEW.PRIXUNITAIRE
        WHERE NUMERO = :NEW.NUMERORAYON;
    END IF;
END;

SELECT * FROM RAYON WHERE NUMERO = 'RAY34';

UPDATE PRODUITS SET QUANTITESTOCKHYPER = 100 WHERE NUMERO = 'PR1234';

SELECT * FROM RAYON WHERE NUMERO = 'RAY34';

/*
Trigger created.

    NUMERO NOM       DESCRIPTIF                                CHIFFREAFFAIRE NUMEROHYPER NUMERORESPONSABLE
---------- ---------- ---------------------------------------- -------------- ----------- ----------------
RAY34     Boucherie Vente de viandes, volailles etc.             1000000 HYP12       EMP7862

1 row updated.

    NUMERO NOM       DESCRIPTIF                                CHIFFREAFFAIRE NUMEROHYPER NUMERORESPONSABLE
---------- ---------- ---------------------------------------- -------------- ----------- ----------------
RAY34     Boucherie Vente de viandes, volailles etc.             1004438 HYP12       EMP7862
*/

-- 6.
UPDATE PRODUITS SET QUANTITESTOCKHYPER = 100 WHERE NUMERO = 'PR1234';

CREATE OR REPLACE TRIGGER maj_qte_vendue
BEFORE UPDATE OF QUANTITESTOCKHYPER ON PRODUITS
FOR EACH ROW
BEGIN
    IF :OLD.QUANTITESTOCKHYPER > :NEW.QUANTITESTOCKHYPER THEN
        UPDATE Promotions
        SET qte_vendue = qte_vendue + (:OLD.QUANTITESTOCKHYPER - :NEW.QUANTITESTOCKHYPER)
        WHERE numeroProduit = :NEW.NUMERO AND encours = 1;
    END IF;
END;
/

INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (5, 'PR1234', 10, TO_DATE('01/01/2025', 'DD/MM/YYYY'), TO_DATE('31/12/2025', 'DD/MM/YYYY'));

SELECT * FROM Promotions WHERE numero = 5;

UPDATE PRODUITS SET QUANTITESTOCKHYPER = 90 WHERE NUMERO = 'PR1234';

SELECT * FROM Promotions WHERE numero = 5;

/*
1 row updated.

Trigger created.

1 row created.

    NUMERO NUMERO POURCENTAGE_REMISE DATE_DEBU DATE_FIN     ENCOURS QTE_VENDUE
---------- ------ ------------------ --------- --------- ---------- ----------
         5 PR1234                 10 01-JAN-25 31-DEC-25          1          0

1 row updated.

    NUMERO NUMERO POURCENTAGE_REMISE DATE_DEBU DATE_FIN     ENCOURS QTE_VENDUE
---------- ------ ------------------ --------- --------- ---------- ----------
         5 PR1234                 10 01-JAN-25 31-DEC-25          1         10
*/

-- 7.
CREATE OR REPLACE TRIGGER verifier_produit
BEFORE INSERT ON PRODUITS
FOR EACH ROW
DECLARE
    v_qte_stock INTEGER;
BEGIN
    SELECT COUNT(*) INTO v_qte_stock FROM PRODUITS
    WHERE LIBELLE = :NEW.LIBELLE AND NUMERORAYON = :NEW.NUMERORAYON;

    IF v_qte_stock > 0 THEN
        UPDATE PRODUITS
        SET QUANTITESTOCKHYPER = QUANTITESTOCKHYPER + :NEW.QUANTITESTOCKHYPER
        WHERE LIBELLE = :NEW.LIBELLE AND NUMERORAYON = :NEW.NUMERORAYON;

        RAISE_APPLICATION_ERROR(-20001, 'Un produit avec le même libellé existe déjà dans ce rayon.');
    END IF;
END;
/

INSERT INTO PRODUITS (NUMERO, LIBELLE, NUMERORAYON, PRIXUNITAIRE, UNITE, QUANTITESTOCKHYPER) VALUES ('PR1235', 'Viande', 'RAY34', 12.50, 'kg', 345);

SELECT * FROM PRODUITS WHERE LIBELLE = 'Viande' AND NUMERORAYON = 'RAY34';

INSERT INTO PRODUITS (NUMERO, LIBELLE, NUMERORAYON, PRIXUNITAIRE, UNITE, QUANTITESTOCKHYPER) VALUES ('PR1236', 'Viande', 'RAY34', 12.50, 'kg', 345);

SELECT * FROM PRODUITS WHERE LIBELLE = 'Viande' AND NUMERORAYON = 'RAY34';

/*
Trigger created.

1 row created.

NUMERO     LIBELLE NUMERORAYON PRIXUNITAIRE UNITE QUANTITESTOCKHYPER
---------- ------- ----------- ------------ ----- -------------------
PR1235     Viande  RAY34               12.5 kg                  345

ORA-20001: Un produit avec le même libellé existe déjà dans ce rayon.
ORA-06512: at "SYS.VERIFIER_PRODUIT", line 16
ORA-04088: error during execution of trigger 'SYS.VERIFIER_PRODUIT'

NUMERO     LIBELLE NUMERORAYON PRIXUNITAIRE UNITE QUANTITESTOCKHYPER
---------- ------- ----------- ------------ ----- -------------------
PR1235     Viande  RAY34               12.5 kg                  690
 */

-- 8.
DROP TABLE Logs;
CREATE TABLE Logs (
    numero NUMBER CONSTRAINT pk_logs PRIMARY KEY,
    date_log DATE NOT NULL,
    username VARCHAR2(30) NOT NULL,
    message VARCHAR2(100) NOT NULL
);

CREATE OR REPLACE TRIGGER log_promotions
AFTER INSERT OR UPDATE ON Promotions
FOR EACH ROW
BEGIN
    IF INSERTING THEN
        INSERT INTO Logs (numero, date_log, username, message) VALUES (1, SYSDATE, USER, 'Ajout dans la table Promotions');
    ELSIF UPDATING THEN
        INSERT INTO Logs (numero, date_log, username, message) VALUES (1, SYSDATE, USER, 'Modification dans la table Promotions');
    END IF;
END;
/

INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (6, 'PR1234', 10, TO_DATE('01/01/2025', 'DD/MM/YYYY'), TO_DATE('31/12/2025', 'DD/MM/YYYY'));

UPDATE Promotions SET pourcentage_remise = 20 WHERE numero = 6;

SELECT * FROM Logs;

/*
Table dropped.

Table created.

Trigger created.

1 row created.

1 row updated.

    NUMERO DATE_LOG  USERNAME MESSAGE
---------- --------- -------- --------------------------------------------------
         1 08-NOV-21 SYS      Ajout dans la table Promotions
         1 08-NOV-21 SYS      Modification dans la table Promotions
 */

CREATE OR REPLACE TRIGGER log_promotions
BEFORE INSERT OR UPDATE ON Promotions
FOR EACH ROW
DECLARE
    v_heure NUMBER;
BEGIN
    SELECT TO_NUMBER(TO_CHAR(SYSDATE, 'HH24')) INTO v_heure FROM DUAL;

    IF v_heure < 8 OR v_heure > 20 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Erreur : Hors des horaires de travail');
    ELSE
        IF INSERTING THEN
            INSERT INTO Logs (numero, date_log, username, message) VALUES (1, SYSDATE, USER, 'Ajout dans la table Promotions');
        ELSIF UPDATING THEN
            INSERT INTO Logs (numero, date_log, username, message) VALUES (1, SYSDATE, USER, 'Modification dans la table Promotions');
        END IF;
    END IF;
END;

INSERT INTO Promotions (numero, numeroProduit, pourcentage_remise, date_debut, date_fin) VALUES (7, 'PR1234', 10, TO_DATE('01/01/2025', 'DD/MM/YYYY'), TO_DATE('31/12/2025', 'DD/MM/YYYY'));

SELECT * FROM Logs;