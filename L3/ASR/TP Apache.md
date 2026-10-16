Réalisé par Patron Antoine et Dubleumortier Thomas

# 7 Pages d'erreurs
Voici la démarche suivie pour réalisé des pages pour les erreurs 403 et 404 :
**Création des pages :**
![[Pasted image 20250429185438.png]]
![[Pasted image 20250429185444.png]]

**Modification du fichier de configuration `000-default.conf` :**
![[Pasted image 20250429172507.png]]

**Résultat :**
![[Pasted image 20250429185618.png]]

# 8 Protection des pages

### 1. Création du répertoire `prive`, permissions
![[Pasted image 20250429185926.png]]![[Pasted image 20250429185935.png]]

### 2. Création `.htaccess`
![[Pasted image 20250429190038.png]]

### 3. Dans ces conditions, ou se trouvera le fichier d'authentification ?
Il se trouvera dans le répertoire `/etc/apache2/`, et se nommera `users`

### 4. 5. 6. Création d'utilisateur avec `htpasswd`
![[Pasted image 20250429190556.png]]

### 8.
![[Pasted image 20250429204124.png]]

# 9 Réécriture d'URL
![[Pasted image 20250429210649.png]]
![[Pasted image 20250429193048.png]]

# 10 Redirection
![[Pasted image 20250429214826.png]]
![[Pasted image 20250429215016.png]]

# 11 Second site
Pour créer un second site, on peut suivre la procédure suivante :
![[Pasted image 20250429220458.png]]
![[Pasted image 20250429220509.png]]
