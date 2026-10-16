# Démarrage, arrêt et redémarrage et status du serveur SQL
```bash
$ systemctl {start|stop|restart|status} mysql
```

# Accès à la console MySQL
```bash
$ mysql -u root -p
```
```bash
$ mysql -h localhost -u root -p
```

# Quelques commandes MySQL
## Aide
```bash
mysql> help
```
## Effacer l'écran
```bash
mysql> clear
```
## Sortir de la console MySQL
```bash
mysql> exit
```
## Afficher les bases de données
```bash
mysql> show databases;
```
## Créer une base de données
```bash
mysql> create database <nom de la base de données>;
```
## Utiliser une base de données
```bash
mysql> use <nom de la base de données>;
```
## Executer un script SQL
```bash
mysql> source <chemin du script SQL>;
```
## Afficher les variables d'environnement
### Varibles globales
```bash
mysql> show variables;
```
### Variables de jointure
```bash
mysql> show variables like 'join';
```
### Variables du jeu de caractères
```bash
mysql> show variables like 'character%';
```
## Afficher si le serveur est sensible a la casse
```bash
mysql> show character set where charset='latin1';
```
## Afficher les tables
```bash
mysql> show tables;
```
## Afficher la structure d'une table
```bash
mysql> describe <nom de la table>;
```