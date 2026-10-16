-- Date : 25/10/2023 ; 28/10/2023 ; 06/11/2023
-- Classe : L2-Info-Groupe1
-- Etudiant : Antoine Patron 22001126

-- Q1.13.2
-- Supprime les tables si elles existent
drop TABLE IF EXISTS projeter;
drop TABLE IF EXISTS projection;
drop TABLE IF EXISTS salle;
drop TABLE IF EXISTS jouer;
drop TABLE IF EXISTS film;
drop TABLE IF EXISTS realisateur;
drop TABLE IF EXISTS acteur;

-- Table acteur
CREATE TABLE IF NOT EXISTS acteur (
    num_act INT NOT NULL AUTO_INCREMENT,
    nom_act VARCHAR(40) NOT NULL,
    anNais_Act INT,
    CONSTRAINT pk_acteur PRIMARY KEY (num_act)
);

-- Table realisateur
CREATE TABLE IF NOT EXISTS realisateur (
    num_real INT NOT NULL AUTO_INCREMENT,
    nom_real VARCHAR(40) NOT NULL,
    anNais_real INT,
    CONSTRAINT pk_realisateur PRIMARY KEY (num_real)
);

-- Table film
CREATE TABLE film (
    num_film INT NOT NULL AUTO_INCREMENT,
    nom_film VARCHAR(40) not null,
    anSortie_film INT,
    budget_film INT,
    genre_film VARCHAR(40),
    num_real INT NOT NULL,
    resume_film TEXT(2000),
    CONSTRAINT pk_film PRIMARY KEY (num_film),
    CONSTRAINT fk_film_realisateur FOREIGN KEY(num_real) REFERENCES realisateur (num_real)
);

-- Table jouer
CREATE TABLE IF NOT EXISTS jouer (
    num_act INT NOT NULL,
    num_film INT NOT NULL,
    role_jouer VARCHAR(40),
    cachet_jouer INT,
    CONSTRAINT pk_jouer PRIMARY KEY (num_act, num_film),
    CONSTRAINT fk_jouer_acteur FOREIGN KEY (num_act) REFERENCES acteur (num_act),
    CONSTRAINT fk_jouer_film FOREIGN KEY (num_film) REFERENCES film (num_film)
);

-- Table salle
CREATE TABLE IF NOT EXISTS salle (
    num_salle INT NOT NULL,
    nbPlaces_salle INT NOT NULL,
    CONSTRAINT pk_salle PRIMARY KEY (num_salle)
);

-- Table projection
CREATE TABLE IF NOT EXISTS projection (
    date_projection DATE,
    heure_projection TIME,
    tarif_projection DECIMAL(4,2),
    CONSTRAINT pk_projection PRIMARY KEY (date_projection, heure_projection)
);

-- Table projeter
CREATE TABLE IF NOT EXISTS projeter (
    num_salle INT,
    date_projection DATE,
    heure_projection TIME,
    num_film INT,
    nb_spectateurs_proj INT,
    CONSTRAINT fk_projeter_numFilm FOREIGN KEY (num_film) REFERENCES film (num_film),
    CONSTRAINT fk_projeter_numSalle FOREIGN KEY (num_salle) REFERENCES salle (num_salle),
    CONSTRAINT fk_projeter_date FOREIGN KEY (date_projection, heure_projection) REFERENCES projection (date_projection, heure_projection)
);




-- Q1.14.1
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (1, 100);
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (2, 200);
-- INSERT INTO salle (num_salle) VALUES (4); -- Cette ligne provoque une erreur car le nombre de place ne peut être null
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (4, 300);

-- INSERT INTO salle (nbPlaces_salle) VALUES (400); -- Cette ligne provoque une erreur car le numero de salle ne peut être null
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (5, 400);

-- INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (6, 99999999999); -- Cette ligne provoque une erreur car le nombre de place est trop grand pour être stocké avec les contraintes de l'énoncé.
INSERT INTO salle (num_salle, nbPlaces_salle) VALUES (6, 500);



-- Q1.14.2
SELECT * FROM salle;



-- Q1.14.2.a
UPDATE salle SET nbPlaces_salle = 150 WHERE num_salle = 1;



-- Q1.14.2.b
-- UPDATE salle SET nbPlaces_salle = NULL WHERE num_salle = 2; -- Erreur, car le nombre de places ne peut être null



-- Q1.14.2.c
UPDATE salle SET nbPlaces_salle = nbPlaces_salle + 50 WHERE num_salle > 1;



-- Q1.14.4
SELECT * FROM salle;



-- Q1.14.5
DELETE FROM salle WHERE nbPlaces_salle > 300;



-- Q1.14.6
SELECT * FROM salle;

-- Q1.14.7
DELETE FROM salle;
SELECT * FROM salle;
