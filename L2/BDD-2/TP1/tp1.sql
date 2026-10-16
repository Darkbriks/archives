-- Date : 25/10/2023
-- Classe : L2-Info-Groupe1
-- Etudiant : Antoine Patron 22001126

-- Question 1.7 : Vérifier et (si possible) modifier un paramètre du SGBD
select @@sql_mode;
--set global sql_mode=’STRICT_ALL_TABLES,NO_AUTO_VALUE_ON_ZERO’;
--set @@session.sql_mode= ’STRICT_ALL_TABLES,NO_AUTO_VALUE_ON_ZERO’;