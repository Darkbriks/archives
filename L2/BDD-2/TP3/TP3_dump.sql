-- MySQL dump 10.13  Distrib 8.0.35, for Linux (x86_64)
--
-- Host: localhost    Database: tp_cinema
-- ------------------------------------------------------
-- Server version	8.0.35

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `acteur`
--

DROP TABLE IF EXISTS `acteur`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `acteur` (
  `num_act` int NOT NULL,
  `nom_act` varchar(40) NOT NULL,
  `anNais_act` int DEFAULT NULL,
  PRIMARY KEY (`num_act`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `acteur`
--

LOCK TABLES `acteur` WRITE;
/*!40000 ALTER TABLE `acteur` DISABLE KEYS */;
INSERT INTO `acteur` VALUES (1,'Tom Cruise',1962),(2,'Jean-Pierre Darroussin',1953),(3,'Judith Henry',1968),(4,'Angeline Jolie',1975),(5,'John Malkovich',1953),(6,'Ben Stiller',1965),(7,'Jack Black',1969),(8,'Robert Downey Jr.',1965),(9,'Isabelle Huppert',1953),(10,'Olivier Gourmet',1963),(11,'Salomé Stéverin',1985),(12,'Nicolas Giraud',1978),(13,'Ursula Werner',1943),(14,'Horst Westphal',1929),(15,'Nanni Moretti',1953),(16,'Valeria Golino',1966),(17,'Alessandro Gassman',1965),(18,'Isabelle Ferrari',1964),(19,'Leora Barbara',1996),(20,'Karole Rocher',1974),(21,'Melissa Rodrigues',1988),(22,'Benjamin Biolay',1973),(23,'Guillaume Depardieu',1971),(24,'Catherine Frot',1956),(25,'André Dussolier',1946),(26,'Annie Cordy',1928),(27,'Isabelle Adjani',1955),(28,'Clint Eastwood',1930),(29,'Sophie Marceau',1966);
/*!40000 ALTER TABLE `acteur` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `film`
--

DROP TABLE IF EXISTS `film`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `film` (
  `num_film` int NOT NULL,
  `titre_film` varchar(40) NOT NULL,
  `anSortie_film` int DEFAULT NULL,
  `budget_film` int DEFAULT NULL,
  `genre_film` varchar(40) DEFAULT NULL,
  `num_real` int NOT NULL,
  PRIMARY KEY (`num_film`),
  KEY `fk_film_realisateur` (`num_real`),
  CONSTRAINT `fk_film_realisateur` FOREIGN KEY (`num_real`) REFERENCES `realisateur` (`num_real`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `film`
--

LOCK TABLES `film` WRITE;
/*!40000 ALTER TABLE `film` DISABLE KEYS */;
INSERT INTO `film` VALUES (1,'The Last Samurai',2003,8000000,'?op?',1),(2,'Woman on the beach',2007,9000000,'Com?ie dramatique',9),(3,'Le crime est notre affaire',2008,1000000,'Com?ie polici?e',8),(4,'Stella',2008,4000000,'com?ie dramatique',7),(5,'Le septieme ciel',2008,2000000,'Com?ie',6),(6,'Comme une ?oile dans la nuit',2008,6000000,'Drame, Com?ie dramatique, Romance',5),(7,'Home',2008,3000000,'film documentaire',4),(8,'Tonnere sous les tropiques',2008,6000000,'Com?ie, Aventure, action',3),(9,'L\'?hange',2008,5000000,'Drame',2),(10,'Caos Calmo',2008,1000000,'Drame, Romance',11),(11,'Les grandes personnes',2007,1000000,'Com?ie dramatique',10),(12,'La boom',1980,4000000,'Comedie, Drame, Romance',13),(13,'Red Tails',2012,NULL,NULL,14),(14,'Star Wars: Episode IV - A New Hope',1977,NULL,NULL,14),(15,'Indiana Jones and the Crystal Skull',2008,NULL,NULL,14);
/*!40000 ALTER TABLE `film` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `jouer`
--

DROP TABLE IF EXISTS `jouer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `jouer` (
  `num_act` int NOT NULL,
  `num_film` int NOT NULL,
  `role_jouer` varchar(40) DEFAULT NULL,
  `cachet_jouer` int DEFAULT NULL,
  PRIMARY KEY (`num_act`,`num_film`),
  KEY `fk_jouer_film` (`num_film`),
  CONSTRAINT `fk_jouer_film` FOREIGN KEY (`num_film`) REFERENCES `film` (`num_film`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `jouer`
--

LOCK TABLES `jouer` WRITE;
/*!40000 ALTER TABLE `jouer` DISABLE KEYS */;
INSERT INTO `jouer` VALUES (1,1,'premier',55887),(1,2,'premier',90487),(1,6,'premier',80740),(2,3,'second',54618),(2,7,'second',1613),(2,11,'second',21846),(3,4,'apparition',96460),(3,11,'apparition',90175),(4,5,'premier',10202),(4,9,'premier',54198),(5,9,'second',95734),(6,8,'apparition',85961),(7,8,'premier',73347),(8,8,'second',71812),(9,7,'apparition',46566),(10,7,'premier',12263),(11,6,'second',4565),(12,6,'apparition',48137),(13,5,'premier',47557),(14,5,'second',24677),(15,10,'apparition',10308),(16,10,'premier',30526),(17,10,'second',12770),(19,4,'apparition',64132),(20,4,'premier',79894),(21,4,'second',70226),(22,4,'apparition',77410),(23,4,'premier',95731),(24,3,'second',47358),(25,3,'apparition',41578),(26,3,'premier',63537),(29,12,'premier',98680);
/*!40000 ALTER TABLE `jouer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mots`
--

DROP TABLE IF EXISTS `mots`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mots` (
  `mot` varchar(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mots`
--

LOCK TABLES `mots` WRITE;
/*!40000 ALTER TABLE `mots` DISABLE KEYS */;
INSERT INTO `mots` VALUES ('info'),('tech'),('net'),('comm');
/*!40000 ALTER TABLE `mots` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `projection`
--

DROP TABLE IF EXISTS `projection`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `projection` (
  `date_projection` date NOT NULL,
  `heure_projection` time NOT NULL,
  `tarif_projection` decimal(4,2) DEFAULT NULL,
  PRIMARY KEY (`date_projection`,`heure_projection`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `projection`
--

LOCK TABLES `projection` WRITE;
/*!40000 ALTER TABLE `projection` DISABLE KEYS */;
INSERT INTO `projection` VALUES ('2017-09-11','18:00:00',4.00),('2017-09-11','20:20:00',6.50),('2017-09-12','12:05:00',3.00),('2017-09-12','14:00:00',3.00),('2017-09-12','16:20:00',3.00),('2017-09-12','17:00:00',4.00),('2017-09-12','17:45:00',4.00),('2017-09-12','20:00:00',4.50),('2017-09-13','18:30:00',4.00),('2017-09-13','20:20:00',5.00),('2017-09-14','18:00:00',4.50),('2017-09-14','20:10:00',4.00),('2017-09-14','22:00:00',4.50),('2017-09-17','17:30:00',4.00),('2017-09-17','20:15:00',6.00),('2017-09-20','18:15:00',4.00),('2017-09-27','20:10:00',6.00),('2017-10-01','20:00:00',5.00);
/*!40000 ALTER TABLE `projection` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `projeter`
--

DROP TABLE IF EXISTS `projeter`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `projeter` (
  `num_film` int NOT NULL,
  `num_salle` int NOT NULL,
  `date_projection` date NOT NULL,
  `heure_projection` time NOT NULL,
  `nbSpectateurs_proj` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`num_salle`,`date_projection`,`heure_projection`,`num_film`),
  KEY `fk_projeter_film` (`num_film`),
  KEY `fk_projeter_projection` (`date_projection`,`heure_projection`),
  CONSTRAINT `fk_projeter_film` FOREIGN KEY (`num_film`) REFERENCES `film` (`num_film`),
  CONSTRAINT `fk_projeter_projection` FOREIGN KEY (`date_projection`, `heure_projection`) REFERENCES `projection` (`date_projection`, `heure_projection`) ON UPDATE CASCADE,
  CONSTRAINT `fk_projeter_salle` FOREIGN KEY (`num_salle`) REFERENCES `salle` (`num_salle`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `projeter`
--

LOCK TABLES `projeter` WRITE;
/*!40000 ALTER TABLE `projeter` DISABLE KEYS */;
INSERT INTO `projeter` VALUES (10,1,'2017-09-11','18:00:00',24),(9,1,'2017-09-12','14:00:00',32),(2,1,'2017-09-12','17:45:00',34),(11,1,'2017-09-13','18:30:00',31),(5,1,'2017-09-20','18:15:00',23),(1,1,'2017-10-01','20:00:00',34),(10,2,'2017-09-11','18:00:00',11),(9,2,'2017-09-12','17:00:00',51),(11,2,'2017-09-13','20:20:00',68),(5,2,'2017-09-20','18:15:00',49),(1,2,'2017-10-01','20:00:00',65),(10,3,'2017-09-11','20:20:00',42),(9,3,'2017-09-12','20:00:00',235),(4,3,'2017-09-14','18:00:00',143),(8,3,'2017-09-20','18:15:00',155),(1,3,'2017-10-01','20:00:00',154),(3,4,'2017-09-12','12:05:00',347),(3,4,'2017-09-12','16:20:00',279),(4,4,'2017-09-14','18:00:00',192),(9,4,'2017-09-17','17:30:00',19),(7,4,'2017-09-27','20:10:00',153),(1,4,'2017-10-01','20:00:00',56),(4,5,'2017-09-14','20:10:00',67),(3,5,'2017-09-14','22:00:00',82),(9,5,'2017-09-17','20:15:00',11),(7,5,'2017-09-27','20:10:00',72),(1,5,'2017-10-01','20:00:00',55);
/*!40000 ALTER TABLE `projeter` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `realisateur`
--

DROP TABLE IF EXISTS `realisateur`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `realisateur` (
  `num_real` int NOT NULL,
  `nom_real` varchar(40) NOT NULL,
  `anNais_real` int DEFAULT NULL,
  PRIMARY KEY (`num_real`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `realisateur`
--

LOCK TABLES `realisateur` WRITE;
/*!40000 ALTER TABLE `realisateur` DISABLE KEYS */;
INSERT INTO `realisateur` VALUES (1,'Edward Zwick',1952),(2,'Clint Eastwood',1930),(3,'Ben Stiller',1965),(4,'Ursula Meier',1971),(5,'René Féret',1945),(6,'Andreas Dresen',1963),(7,'Sylvie Verheyde',1967),(8,'Pascal Thomas',1945),(9,'Hong Sang-soo',1960),(10,'Anna Novion',1979),(11,'Antonello Grimaldi',1955),(12,'Joann Sfar',1971),(13,'Claude Pinoteau',1925),(14,'George Lucas',NULL);
/*!40000 ALTER TABLE `realisateur` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `salle`
--

DROP TABLE IF EXISTS `salle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `salle` (
  `num_salle` int NOT NULL,
  `nbPlaces_salle` int NOT NULL,
  PRIMARY KEY (`num_salle`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `salle`
--

LOCK TABLES `salle` WRITE;
/*!40000 ALTER TABLE `salle` DISABLE KEYS */;
INSERT INTO `salle` VALUES (1,50),(2,70),(3,250),(4,350),(5,100),(6,400);
/*!40000 ALTER TABLE `salle` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `termes`
--

DROP TABLE IF EXISTS `termes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `termes` (
  `terme` varchar(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `termes`
--

LOCK TABLES `termes` WRITE;
/*!40000 ALTER TABLE `termes` DISABLE KEYS */;
INSERT INTO `termes` VALUES ('Belle marquise'),('vos beaux yeux'),('me font'),('mourir'),('d\'amour');
/*!40000 ALTER TABLE `termes` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-11-15 11:21:59
