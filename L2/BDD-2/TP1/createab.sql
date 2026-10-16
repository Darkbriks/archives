-- Date : 25/10/2023
-- Classe : L2-Info-Groupe1
-- Etudiant : Antoine Patron 22001126

-- Supprime les tables si elles existent
DROP TABLE IF EXISTS vol;
DROP TABLE IF EXISTS pilote;
DROP TABLE IF EXISTS avion;

-- Table pilote
CREATE TABLE IF NOT EXISTS pilote (
    numpil INT NOT NULL AUTO_INCREMENT,
    nompil VARCHAR(20) NOT NULL,
    vilpil VARCHAR(20) NOT NULL,
    salairepil VARCHAR(20) NOT NULL,
    CONSTRAINT pk_pilote PRIMARY KEY (numpil)
);

-- Table avion
CREATE TABLE IF NOT EXISTS avion (
    numav INT NOT NULL AUTO_INCREMENT,
    nomav VARCHAR(20) NOT NULL,
    localisav VARCHAR(20) NOT NULL,
    capamaxav INT NOT NULL,
    CONSTRAINT pk_avion PRIMARY KEY (numav)
);

-- Table vol
CREATE TABLE IF NOT EXISTS vol (
    numvol INT NOT NULL AUTO_INCREMENT,
    numpil INT NOT NULL,
    numav INT NOT NULL,
    departvol date NOT NULL,
    dureevol decimal(6,2) NOT NULL,
    vildevol VARCHAR(20) NOT NULL,
    vilarrvol VARCHAR(20) NOT NULL,
    CONSTRAINT pk_vol PRIMARY KEY (numvol),
    CONSTRAINT fk_vol_pilote FOREIGN KEY (numpil) REFERENCES pilote (numpil),
    CONSTRAINT fk_vol_avion FOREIGN KEY (numav) REFERENCES avion (numav)
);

-- Q1.10.1.1
-- INSERT into pilote VALUES (1, 'Tim');
-- INSERT into pilote VALUES (1, 'John');
-- On peut observer que l'insertion de Tim a fonctionné mais pas celle de John car il y a une contrainte d'unicité sur le numéro de pilote

-- Q1.11.1.3
-- INSERT into pilote VALUES (2, 'John');

-- Q1.11.1.4
-- INSERT into avion VALUES (1, 'A320');
-- INSERT into avion VALUES (2, 'A320');

-- Q1.11.1.5
-- INSERT into vol VALUES (1, 3, 99, '2017-01-15', 3.5);

-- Q1.11.1.7
-- SELECT * from vol;

-- Q1.11.1.8
-- DELETE from vol WHERE numvol=1;
-- SELECT * from vol;

-- Q1.11.1.11
-- INSERT into vol VALUES (1, 1, 2, '2017-01-15', 3.5);

-- Insertion des données des question precedantes avec la structure complete
INSERT into pilote (nompil, vilpil, salairepil) VALUES ('Tim', 'Lilles', 3000);
INSERT into pilote (nompil, vilpil, salairepil) VALUES ('John', 'Calais', 2000);
SELECT * from pilote;

INSERT into avion (nomav, localisav, capamaxav) VALUES ('A320', 'Paris C de G', 250);
INSERT into avion (nomav, localisav, capamaxav) VALUES ('A320', 'Paris Roissy', 275);
SELECT * from avion;

INSERT into vol (numpil, numav, departvol, dureevol, vildevol, vilarrvol) VALUES (2, 1, '2017-01-15', 3.5, 'Lille', 'Paris C de G');
SELECT * from vol