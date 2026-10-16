# SQL
- DDL
    - CREATE TABLE
    ```sql
    CREATE TABLE table_name (
        column1 datatype,
        column2 datatype,
        column3 datatype,
        ....
    );
    ```
    - ALTER TABLE
    ```sql
    ALTER TABLE table_name
    ADD column_name datatype;
    ```
    - DROP
    ```sql
    DROP TABLE table_name;
    ```
- DML
    - INSERT INTO / INSERT ALL
    ```sql
    INSERT INTO table_name (column1, column2, column3, ...)
    VALUES (value1, value2, value3, ...);
    ```
    - UPDATE (condition)
    ```sql
    UPDATE table_name
    SET column1 = value1, column2 = value2, ...
    WHERE condition;
    ```
    - DELETE (condition)
    ```sql
    DELETE FROM table_name WHERE condition;
    ```
- DQL
    - SELECT
    ```sql
    SELECT column1, column2, ...
    FROM table_name;
   ```
    - OPERATEURS
        - UNION
        ```sql
        SELECT column_name(s) FROM table1
        UNION
        SELECT column_name(s) FROM table2;
        ```
        - DIFFERANCE
        ```sql
        SELECT column_name(s) FROM table1
        EXCEPT
        SELECT column_name(s) FROM table2;
        ```
        - PRODUIT CARTESIEN
            - Intersection -> Jointure
                - Naturelle
                - Interne
              ```sql
                SELECT column_name(s)
                FROM table1
                JOIN table2
                ON table1.column_name = table2.column_name;
                ```
            - Jointure externe
                - Full outer join
              ```sql
                SELECT column_name(s)
                FROM table1
                FULL OUTER JOIN table2
                ON table1.column_name = table2.column_name
                WHERE condition;
                ```
                - Left outer join
              ```sql
                SELECT column_name(s)
                FROM table1
                LEFT OUTER JOIN table2
                ON table1.column_name = table2.column_name
                WHERE condition;
                ```
                - Right outer join
              ```sql
                SELECT column_name(s)
                FROM table1
                RIGHT OUTER JOIN table2
                ON table1.column_name = table2.column_name
                WHERE condition;
                ```

# Exercice
1. Lister les categorie x produit</br>
```sql
SELECT * FROM Categorie, Produit WHERE Categorie.id = Produit.categorie_id;
```
2. Lister les client et leurs commandes; compléter par une sélec6on pour obtenir un résultat cohérent</br>
```sql
SELECT * FROM Client, Commande_client cc WHERE Client.id = cc.client_id;
```
3. Lister les produits, les produits commandés, et commande client; compléter par une sélec6on pour obtenir un résultat cohérent et une projec6on pour avoir le nom de client et les nom de produits commandés</br>
```sql
SELECT Produit.nom, Client.nom FROM Produit
INNER JOIN Produit_commande ON Produit.id = Produit_commande.produit_id
INNER JOIN Commande_client ON Produit_commande.commande_id = Commande_client.id
INNER JOIN Client ON Commande_client.client_id = Client.id;
```
4. Lister les noms de tous les produit et éventuellement les titres des catégories auxquels ils appartiennent</br>
```sql
SELECT Produit.nom, Categorie.titre FROM Produit
LEFT JOIN Categorie ON Produit.categorie_id = Categorie.id;
```
5. Lister les noms de tous les clients et éventuellement leurs commandes</br>
```sql
SELECT Client.nom, Commande_client.id FROM Client
LEFT JOIN Commande_client ON Client.id = Commande_client.client_id;
```
6. Lister le nombre de categorie
```sql
SELECT COUNT(*) FROM Categorie;
```
7. Lister le nombre de produit de la categorie DVD
```sql
SELECT COUNT(*) FROM Produit
INNER JOIN Categorie ON Produit.categorie_id = Categorie.id
WHERE Categorie.titre = 'DVD';
```
8. Lister le nombre de commande
```sql
SELECT COUNT(*) FROM Commande_client;
```
9. Lister le nombre de produits differants commandés
```sql
SELECT COUNT(DISTINCT produit_id) FROM Produit_commande;
```
10. Lister  la moyenne des prix
```sql
SELECT AVG(prix) FROM Produit;
```
11. Lister la moyenne de quantité des produits commandés
```sql
SELECT AVG(quantite) FROM Produit_commande;
```
12. Lister le nombre de produit par categorie
```sql
SELECT COUNT(Produit.id), Categorie.titre FROM Produit
INNER JOIN Categorie ON Produit.categorie_id = Categorie.id
GROUP BY Categorie.nom;
```
13. Lister la moyenne des quantités par numéro de produit
```sql
SELECT AVG(quantite), Produit.nom FROM Produit_commande
INNER JOIN Produit ON Produit_commande.produit_id = Produit.id
GROUP BY Produit.nom;
```
14. Lister la moyenne des quantités par commande
```sql
SELECT AVG(quantite), Commande_client.id FROM Produit_commande
INNER JOIN Commande_client ON Produit_commande.commande_id = Commande_client.id
GROUP BY Commande_client.id;
```
15. Lister le nombre de produits par categorie en ne conservant que les produits commandés
```sql
SELECT COUNT(Produit.id), Categorie.titre FROM Produit
INNER JOIN Categorie ON Produit.categorie_id = Categorie.id
INNER JOIN Produit_commande ON Produit.id = Produit_commande.produit_id
GROUP BY Categorie.nom;
```
16. Lister la moyenne de quantité par numero de produit en ne conservant que les produits ayant plus de 20 en quantité
```sql
SELECT AVG(quantite), Produit.nom FROM Produit_commande
INNER JOIN Produit ON Produit_commande.produit_id = Produit.id
WHERE quantite > 20
GROUP BY Produit.nom;
```
17. Lister la moyenne de quantité par numero de produit en ne conservant que les produits ayant moins de 200 en prix
```sql
SELECT AVG(quantite), Produit.nom FROM Produit_commande
INNER JOIN Produit ON Produit_commande.produit_id = Produit.id
WHERE prix < 200
GROUP BY Produit.nom;
```