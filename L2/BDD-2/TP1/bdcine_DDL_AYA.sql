-- Pour eviter des erreurs lors de la suppression des tables, on les supprime dans l'ordre inverse de leur création
drop TABLE IF EXISTS projeter;
drop TABLE IF EXISTS projection;
drop TABLE IF EXISTS salle;
drop TABLE IF EXISTS jouer;
drop TABLE IF EXISTS film;
drop TABLE IF EXISTS realisateur;
drop TABLE IF EXISTS acteur;

-- CREATION DES TABLES
CREATE TABLE acteur (
    -- Il faut donc rajouter le NOT NULL et l'AUTO_INCREMENT
    num_act int NOT NULL AUTO_INCREMENT,
    nom_act VARCHAR(40) not null,
    anNais_act int,
    -- Il manque la clée primaire, ce qui empêche de la referencer en clée étrangère dans la table jouer
    CONSTRAINT pk_num_act PRIMARY KEY (num_act)
);
CREATE TABLE realisateur(
    -- Il manquait le NOT NULL et le AUTO_INCREMENT, ce qui empêchait de créer la clée primaire (qui a besoin de ces deux conditions)
    num_real int NOT NULL AUTO_INCREMENT,
    nom_real VARCHAR(40) not null,
    anNais_real int, -- Il manquait la virgule
    CONSTRAINT pk_num_real PRIMARY KEY (num_real)
);

CREATE TABLE film(
    num_film int,
    nom_film VARCHAR(40) not null,
    anSortie_film int,
    budget_film int,
    genre_film VARCHAR(40),
    num_real int NOT NULL,
    resume_film text (2000),
    CONSTRAINT pk_num_film PRIMARY KEY (num_film),
    CONSTRAINT fk_num_real FOREIGN KEY(num_real) REFERENCES realisateur (num_real)
);

CREATE TABLE jouer(
    num_act int,
    num_film int,
    CONSTRAINT fk_num_act FOREIGN KEY (num_act) REFERENCES acteur (num_act),
    CONSTRAINT fk_num_film FOREIGN KEY (num_film) REFERENCES film (num_film)
);
CREATE TABLE salle(
    num_salle int,
    nbPlaces_salle int NOT NULL,
    CONSTRAINT pk_num_salle PRIMARY KEY (num_salle)
);
CREATE TABLE projection(
    date_projection DATE,
    heure_projection TIME,
    tarif_projection DECIMAL(4,2),
    -- Pour pouvoir utiliser la clée étrangère dans la table projeter, il faut que la clée primaire soit composée de date_projection et heure_projection
    CONSTRAINT pk_date_heure_projection PRIMARY KEY (date_projection, heure_projection)
);

CREATE TABLE projeter(
    num_salle int,
    date_projection DATE,
    heure_projection time,
    num_film int,
    nb_Spectateurs_proj int, -- Il manquait la virgule
    CONSTRAINT fk1_num_film FOREIGN KEY (num_film) REFERENCES film (num_film),
    CONSTRAINT fk_num_salle FOREIGN KEY (num_salle) REFERENCES salle (num_salle),
    -- Comme la clée primaire de projection est composée de deux attributs, il faut que la clée étrangère de projeter est la même composition
    CONSTRAINT fk_date_heure_projection FOREIGN KEY (date_projection, heure_projection) REFERENCES projection (date_projection, heure_projection)
);

-- INSERTION DES DONNEES
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (1, 100);
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (2, 200);

INSERT INTO salle (num_salle) VALUES (4); -- Erreur, mais c'est demandé dans le sujet
-- Il y a une erreur, la salle 4 n'est donc pas créée
-- UPDATE salle SET nbPlaces_salle = 300 WHERE num_salle = 4;
-- Il faut donc la créer a partir de 0
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (4, 300);

INSERT INTO salle (nbPlaces_salle) VALUES (400); -- Erreur, mais c'est demandé dans le sujet
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (5, 400);

INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (6, 99999999999); -- Erreur, mais c'est demandé dans le sujet
UPDATE salle SET nbPlaces_salle = 500 WHERE num_salle = 6;

-- SELECTION DES DONNEES
SELECT * FROM salle;

-- a
UPDATE salle SET nbPlaces_salle = 150 WHERE num_salle = 1;

-- b
UPDATE salle SET nbPlaces_salle = NULL WHERE num_salle = 2; -- Erreur, mais c'est demandé dans le sujet

-- c
UPDATE salle SET nbPlaces_salle = nbPlaces_salle + 50 WHERE num_salle > 1;

-- SELECTION DES DONNEES
SELECT * FROM salle;

-- 5
DELETE FROM salle WHERE nbPlaces_salle > 300;

-- 6
SELECT * FROM salle;

-- 7
DELETE FROM salle;
SELECT * FROM salle;