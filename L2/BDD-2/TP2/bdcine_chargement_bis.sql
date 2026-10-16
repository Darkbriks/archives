-- Nom : Patron
-- Prenom : Antoine
-- Date : 08/11/2023

use tp_cinema;

DELETE FROM jouer;
DELETE FROM projeter;
DELETE FROM film;
DELETE FROM projection;
DELETE FROM acteur;
DELETE FROM realisateur;
DELETE FROM salle;

-- Load data to table salle
LOAD DATA INFILE '/var/lib/mysql-files/cinema/salle.csv'
INTO TABLE salle
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
IGNORE 1 LINES;

-- Load data to table realisateur
LOAD DATA INFILE '/var/lib/mysql-files/cinema/realisateur.csv'
INTO TABLE realisateur
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
IGNORE 1 LINES;

-- Load data to table acteur
LOAD DATA INFILE '/var/lib/mysql-files/cinema/acteur.csv'
INTO TABLE acteur
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
IGNORE 1 LINES;

-- Load data to table film
LOAD DATA INFILE '/var/lib/mysql-files/cinema/film.csv'
INTO TABLE film
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
IGNORE 1 LINES;

-- Load data to table projection
LOAD DATA INFILE '/var/lib/mysql-files/cinema/projection.csv'
INTO TABLE projection
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
IGNORE 1 LINES;

-- Load data to table projeter
LOAD DATA INFILE '/var/lib/mysql-files/cinema/projeter.csv'
INTO TABLE projeter
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
IGNORE 1 LINES;

-- Load data to table jouer
LOAD DATA INFILE '/var/lib/mysql-files/cinema/jouer.csv'
INTO TABLE jouer
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
IGNORE 1 LINES;