-- Date : 08/11/2023
-- Classe : L2Info groupe 1
-- Etudiant : Patron Antoine 22001126

-- Q1
-- 1.3.4
describe acteur;
describe realisateur;
describe salle;
describe film;
describe jouer;
describe projection;
describe projeter;

-- 1.4.1.6
SELECT * FROM salle;
SELECT * FROM realisateur;
SELECT * FROM acteur;
SELECT * FROM film;
SELECT * FROM projection;
SELECT * FROM projeter;
SELECT * FROM jouer;

-- 1.4.1.7
ALTER TABLE acteur DROP photo_act;

-- 1.4.1.8
ALTER TABLE film DROP resume_film;
SELECT * FROM film WHERE num_film = 1;

-- 1.4.1.9
INSERT INTO realisateur (num_real, nom_real, anNais_real) VALUES (14, 'George Lucas', NULL);
SELECT * FROM realisateur WHERE num_real = 14;

-- 1.4.1.10
mysql> INSERT INTO film (num_film, titre_film, anSortie_film, budget_film, genre_film, num_real) VALUES
(13, 'Red Tails', 2012, NULL, NULL, 14),
(14, 'Star Wars: Episode IV - A New Hope', 1977, NULL, NULL, 14),
(15, 'Indiana Jones and the Crystal Skull', 2008, NULL, NULL, 14);
SELECT * FROM film WHERE num_film >= 13;

-- 1.5.1.1
SELECT * FROM film WHERE num_real = 1 or num_real = 4 or num_real = 7 or num_real = 14 or num_real = 2540;

-- 1.5.1.2
SELECT * FROM acteur WHERE nom_act like 'isa%';

-- 1.5.1.3
SELECT * FROM acteur WHERE nom_act like '%ani';

-- 1.5.1.4
SELECT * FROM acteur WHERE nom_act like '%ol%' and nom_act not like '%go%';

-- 1.5.1.5
SELECT * FROM acteur WHERE nom_act like '__n%';

-- 1.5.1.6
SELECT num_film, titre_film, num_real FROM film WHERE titre_film like 'home';

-- 1.5.1.7
SELECT * FROM acteur WHERE (anNais_act < 1950 or anNais_act > 1960) and (nom_act like '%cru%' or nom_act like '%roc%' or nom_act like '%cor%');

-- 1.5.1.8
SELECT * FROM realisateur WHERE anNais_real is NULL;

-- 1.5.1.9
SELECT * FROM film WHERE anSortie_film >= 2005 and num_film % 2 = 0 and genre_film not like '%drame%';

-- 1.5.1.10
SELECT month(now()) from dual;

-- 1.5.1.11
SELECT * FROM projeter WHERE date_projection between '2017-03-01' and '2017-03-31' order by num_film;

-- 1.5.1.12
SELECT distinct num_film FROM projeter WHERE heure_projection between '18:00:00' and '20:00:00';

-- 1.5.1.13
SELECT nom_act, length(nom_act) as longueur FROM acteur;

-- 1.5.1.14
SELECT * FROM acteur WHERE length(nom_act) > 15;

-- 1.5.1.15
SELECT upper(nom_real) FROM realisateur;

-- 1.5.1.16
SELECT substring(nom_act, 1, locate(' ', nom_act) - 1) as prenom, substring(nom_act, locate(' ', nom_act) + 1) as nom FROM acteur;

-- 1.5.1.17
SELECT * FROM acteur order by anNais_act asc, nom_act asc;

-- 1.5.1.18
SELECT * FROM projection order by tarif_projection desc, heure_projection desc, date_projection desc;

-- Q2
-- 2.1.1.1
CREATE TABLE IF NOT EXISTS mots (mot VARCHAR(4));

-- 2.1.1.2
INSERT INTO mots (mot) VALUES ('info'), ('tech'), ('net'), ('comm');
SELECT * FROM mots;

-- 2.1.1.3
SELECT * FROM mots m1, mots m2;

-- 2.1.1.4
SELECT concat(m1.mot, m2.mot) as mot FROM mots m1, mots m2;

-- 2.1.1.5
SELECT concat(m1.mot, m2.mot) as mot FROM mots m1, mots m2 WHERE m1.mot not like m2.mot;

-- 2.1.1.6
SELECT concat(m1.mot, m2.mot, m3.mot) as mot FROM mots m1, mots m2, mots m3 WHERE m1.mot not like m2.mot and m1.mot not like m3.mot and m2.mot not like m3.mot;

-- 2.1.1.7
SELECT concat(m1.mot, m2.mot) as mot FROM mots m1, mots m2 WHERE m1.mot not like m2.mot UNION SELECT concat(m1.mot, m2.mot, m3.mot) as mot FROM mots m1, mots m2, mots m3 WHERE m1.mot not like m2.mot and m1.mot not like m3.mot and m2.mot not like m3.mot order by mot;

-- 2.2.1.1
CREATE TABLE IF NOT EXISTS termes (terme VARCHAR(16));

-- 2.2.1.2
INSERT INTO termes (terme) VALUES ('Belle marquise'), ('vos beaux yeux'), ('me font'), ('mourir'), ('d''amour');
mysql> SELECT * FROM termes;

-- 2.2.1.3
SELECT concat(t1.terme, ' ', t2.terme, ' ', t3.terme, ' ', t4.terme, ' ', t5.terme) as phrase FROM termes t1, termes t2, termes t3, termes t4, termes t5 WHERE t1.terme not like t2.terme and t1.terme not like t3.terme and t1.terme not like t4.terme and t1.terme not like t5.terme and t2.terme not like t3.terme and t2.terme not like t4.terme and t2.terme not like t5.terme and t3.terme not like t4.terme and t3.terme not like t5.terme and t4.terme not like t5.terme;