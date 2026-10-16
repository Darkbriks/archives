use tp_cinema;

-- 2.1.1
SELECT nom_real, titre_film FROM realisateur JOIN film using (num_real) ORDER BY nom_real, titre_film;

-- 2.1.2
SELECT titre_film, nom_act, role_jouer FROM film JOIN jouer using (num_film) JOIN acteur using (num_act) ORDER BY titre_film, nom_act;

-- 2.1.3
SELECT nom_real, nom_act FROM realisateur JOIN film using (num_real) JOIN jouer using (num_film) JOIN acteur using (num_act) ORDER BY nom_real, nom_act;

-- 2.1.4
SELECT num_film, titre_film, budget_film FROM film JOIN jouer using (num_film) JOIN acteur using (num_act) WHERE anNais_act > 1950 ORDER BY titre_film;

-- 2.1.4.2
SELECT DISTINCT num_film, titre_film, budget_film FROM film JOIN jouer using (num_film) JOIN acteur using (num_act) WHERE anNais_act > 1950 ORDER BY titre_film;

-- 2.1.5
SELECT nom_act FROM acteur JOIN realisateur on (nom_act = nom_real) ORDER BY nom_act;

-- 2.2.1
SELECT NOW() AS 'Date du jour', DATE_ADD(NOW(), INTERVAL 5 DAY) AS 'Date décalée de 5 jours';

-- 2.2.2
SELECT NOW() AS 'Date du jour', DATE_ADD(NOW(), INTERVAL 5 MONTH) AS 'Date décalée de 5 mois';

-- 2.2.3
SELECT NOW() AS 'Date du jour', DATE_ADD(NOW(), INTERVAL 5 YEAR) AS 'Date décalée de 5 ans';

-- 2.2.4
SELECT date_projection, DATE_ADD(date_projection, INTERVAL 5 MONTH) AS 'Date décalée de 5 mois' FROM projection ORDER BY date_projection;

-- 2.2.5
SELECT date_projection, NOW(), DATEDIFF(NOW(), date_projection) AS 'Ecart' FROM projection ORDER BY date_projection;

-- 2.2.6
SELECT max(DATEDIFF(NOW(), date_projection)) AS 'Ecart max' FROM projection;

-- 2.2.7
SELECT WEEKDAY(NOW()) AS 'Jour de la semaine', WEEKDAY(NOW()) AS 'Jour du mois', MONTH(NOW()) AS 'Mois', YEAR(NOW()) AS 'Année';

-- 2.2.8
SELECT DISTINCT num_act, nom_act, anNais_act, WEEKDAY(date_projection) AS 'Jour de la semaine' FROM acteur JOIN jouer using (num_act) JOIN film using (num_film) JOIN projeter using (num_film) JOIN salle using (num_salle) WHERE WEEKDAY(date_projection) = 3 AND nbPlaces_salle > 300 ORDER BY nom_act;

-- 2.2.9
SELECT titre_film, nom_real, IFNULL(anNais_real, 'NA') AS 'Année de naissance' FROM film JOIN realisateur using (num_real) ORDER BY anNais_real, nom_real, titre_film;

-- 2.2.10
SELECT nom_act FROM acteur WHERE nom_act SOUNDS LIKE 'bnstlr' OR nom_act SOUNDS LIKE 'isbldjn' ORDER BY nom_act;

-- 2.2.11
SELECT DAYNAME(date_projection) AS 'Jour', num_salle AS 'Salle', date_projection AS 'le', heure_projection AS 'a', titre_film AS 'Titre' FROM projeter JOIN film using (num_film) WHERE MONTH(date_projection) = 9 AND YEAR(date_projection) = 2017 ORDER BY WEEKDAY(date_projection), num_salle, date_projection, heure_projection;

