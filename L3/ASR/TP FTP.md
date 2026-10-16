**Réalisé par Patron Antoine et Mouanou banzouzi j'aime kora-karen**
# 1. Quelle directive permet d'inclure des modules supplémentaires dans la configuration de ProFTPD ?
Pour inclure des modules supplémentaires, il est possible d'utiliser `LoadModule`.
![[Q1-1.png]]
*Le module `exemple_module.c` n'existant pas, `proftpd` renvoi une erreur de la vérification de la syntaxe, mais la directive `LoadModule` est correctement reconnue*
![[Q1-2.png]]

# 2. Comment activer l'utilisation des utilisateurs FTP définis dans le système ?
Pour activer leur utilisation, il faut utiliser `UseFtpUsers on`, qui est déjà défini dans le fichier fourni.

# 3. Quelle option doit être désactivée pour empêcher la reprise des téléchargements interrompus ?
Pour la désactiver, il faut utiliser la directive `AllowStoreRestart off`.
![[Q3-1.png]]
![[Q3-2.png]]

# 4. Quelle directive permet d'interdire les connexions depuis des adresses IP étrangères ?
Pour interdire cela, on peut ajouter la directive `AllowForeignAddress off`.
![[Q4-1.png]]
![[Q4-2.png]]
*La connexion en `localhost` est acceptée.*
![[Q4-3.png]]

# 5. Comment configurer le serveur pour qu'il affiche un message spécifique lors de la connexion des utilisateurs ?
Pour afficher, on peut utiliser `DisplayLogin <chemin>`.
![[Q5-1.png]]
![[Q5-2.png]]

# 6. Quelle directive permet d'afficher un message de bienvenu personnalisé aux utilisateurs ?
On peut utiliser la directive `AccessGrantMsg <msg>`.
Par exemple :
```bash
AccessGrantMsg "Bienvenue %u sur le serveur FTP de L3 info"
```
![[Q6-1.png]]
![[Q6-2.png]]

# 7. Comment activer la prise en charge des connexions IPv6 ?
Pour activer les IPv6, on peut utiliser `UseIPv6 on`.
![[Q7-1.png]]
![[Q7-2.png]]

# 8. Quelle option doit être désactivée pour éviter les recherches d'identification des utilisateurs ?
On peut utiliser `PersistentPasswd off`.
![[Q8-1.png]]
![[Q8-2.png]]

# 9. Comment définir le nom du serveur FTP ?
Il faut pour cela utiliser la directive `ServerName "<Nom du Serveur>"`, qui est déjà présente dans la configuration de base fournie.

# 10. Quelle directive permet de configurer le serveur pour qu'il fonctionne en mode `inetd` ?
On peut utiliser la directive `ServerType inetd`.
![[Q10-1.png]]
![[Q10-2.png]]

# 11. Comment activer l'affichage différé du message de bienvenu ?
On peut utiliser `DelayedWelcome on`.
![[Q11.png]]

# 12. Quelle option permet de gérer les réponses multilignes conformément à la RFC 2228 ?
On peut configurer la directive `MultiLineRFC2228 on`.
![[Q12-1.png]]
*La directive est reconnue, mais dépréciée.*
![[Q12-2.png]]
# 13. Comment configurer le serveur pour qu'il soit le serveur par défaut ?
On peut utiliser `DefaultServer on`.
![[Q13-1.png]]
![[Q13-2.png]]

# 14. Quelle directive permet d'afficher les liens symboliques dans les listes de fichiers ?
On peut utiliser `ShowSymlinks on`.
![[Q14-1.png]]
![[Q14-2.png]]
# 15. Quelles directives permettent de définir les délais d'inactivité pour les transferts, les connexions stallées et les sessions inactives ?
On peut utiliser les directives `TimeoutIdle <time>` pour le délai d'inactivité, `TimeoutNoTransfer <time>` pour le délai sans transfert, et `TimeoutStalled <time>` pour le délai des connexions stallées.
Par exemple :
```bash
TimeoutIdle 600
TimeoutNoTransfer 120
TimeoutStalled 300
```
![[Q15-1.png]]
![[Q15-2.png]]

# 16. Comment configurer les messages d'affichage lors de la connexion et du changement de répertoire ?
On peut utiliser les directives `DisplayLogin <msg>`, et `DisplayChdir <msg>`.
![[Q16-1.png]]
![[Q16-2.png]]
# 17. Quelle directive permet de définir les options de liste des fichiers ?
On peut utiliser `ListOptions "<options>"`.
Par exemple :
```bash
ListOptions "-la"
```
![[Q17-1.png]]
![[Q17-2.png]]

# 18. Comment configurer un filtre pour interdire le téléchargement de fichiers avec certaines extensions ?
On peut utiliser `DenyFilter "\.exe$"`.
![[Q18-1.png]]
![[Q18-2.png]]
# 19. Quelle directive permet de définir le répertoire racine par défaut pour les utilisateurs ?
On peut configurer la directive `DefaultRoot /home/ftpuser`, déjà présente dans le fichier de configuration initial.

# 20. Comment désactiver la nécessité d'un shell valide pour les utilisateurs FTP ?
On peut utiliser `RequireValidShell off`, comme dans la configuration fournie.

# 21. Quelle directive permet de définir le port sur lequel le serveur FTP écoute ?
On peut configurer `Port 21`.
![[Q21-1.png]]
![[Q21-2.png]]

# 22. Comment définir l'utilisateur et le groupe sous lesquels le serveur FTP s'exécute ?
On peut configurer :
```bash
User user1
Group ftpuser
```
![[Q22-1.png]]
![[Q22-2.png]]
# 23. Quelle directive permet de définir les permissions par défaut pour les fichiers créés ?
On peut configurer la directive `Umask <permissions>`.
Par exemple :
```bash
Umask 022
```
![[Q23-1.png]]
![[Q23-2.png]]
# 24. Comment autoriser l'écrasement des fichiers existants ?
On peut utiliser la directive `AllowOverwrite on`.
![[Q24-1.png]]
![[Q24-2.png]]

# 25. Quelle directive permet de limiter le nombre de tentatives de connexion ?
On peut configurer `MaxLoginAttempts 3`.
![[Q25-1.png]]
![[Q25-2.png]]

# 26. Comment configurer les fichiers de journalisation des transferts et des événements système ?
On peut utiliser les directives :
```bash
TransferLog /var/log/proftpd/transfer.log
SystemLog /var/log/proftpd/system.log
ExtendedLog /var/log/proftpd/extended.log
```
![[Q26-1.png]]
![[Q26-2.png]]

# 27. Comment configurer les paramètres pour les utilisateurs anonymes, y compris les limites de clients et les permissions de répertoire ?
On peut utiliser les directives :
```bash
<Anonymous /home/ftp>
  User ftp
  Group ftp
  MaxClients 5
  DisplayLogin /etc/proftpd/anon_welcome.msg
  <Limit WRITE>
    DenyAll
  </Limit>
  <Directory uploads>
    <Limit READ>
      DenyAll
    </Limit>
    <Limit STOR>
      AllowAll
    </Limit>
  </Directory>
</Anonymous>
```
![[Q27-1.png]]
![[Q27-2.png]]