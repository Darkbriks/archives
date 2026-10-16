Réalisé par Patron Antoine et Dubleumortier Thomas
# IP tables 
  
## 1. Interdire tout paquet entrant  
```bash  
iptables -t filter -P INPUT DROP
```
![[Pasted image 20250512151952.png]]

## 2. Interdire le protocole ICMP entrant  
```bash  
iptables -t filter -A INPUT -p icmp -j DROP
```
![[Pasted image 20250512152017.png]]

## 3. Interdire le protocole ICMP provenant de localhost  
```bash  
iptables -t filter -A INPUT -p icmp -s 127.0.0.1 -j DROP
```
![[Pasted image 20250512152028.png]]

## 4. Interdire tout paquet sortant à destination de localhost  
```bash  
iptables -t filter -A OUTPUT -d localhost -j DROP
```
![[Pasted image 20250512152041.png]]

## 5. Interdire un paquet s'il ne provient pas de localhost  
```bash  
iptables -t filter -A INPUT -s localhost -j ACCEPT
```
![[Pasted image 20250512152112.png]]

## 6. Interdire tout paquet entrant s'il provient de lo  
```bash  
iptables -t filter -A INPUT -j lo -j DROP
```
![[Pasted image 20250512152128.png]]

## 7. Interdire tout paquet sortant par eth0  
```bash  
iptables -t filter -A OUTPUT -o eth0 -j DROP
```
![[Pasted image 20250512152140.png]]

## 8. Interdire tout paquet sortant à destination du port ftp  
```bash  
iptables -t filter -A OUTPUT -p tcp --dport 21 -j DROP
```
![[Pasted image 20250512152151.png]]
## 9. Interdire tout paquet sortant par eth0 dont le N° de port destination est < à 1025  
```bash  
iptables -t filter -A OUTPUT -o eth0 -p tcp --dport 1024:65535 -j DROP
```
![[Pasted image 20250512152205.png]]

## 10. Interdire toute tentative d'initialisation de connexion TCP provenant de eth0  
```bash  
iptables -t filter -A INPUT -i eth0 -p tcp --tcp-flags ALL SYN -j DROP
```
![[Pasted image 20250512152230.png]]

## 11. Interdire tout paquet entrant correspondant à un ping  
```bash  
iptables -t filter -A INPUT -p icmp --icmp-type echo-request -j DROP
```
![[Pasted image 20250512152243.png]]

## 12. Interdire toute réponse à un ping  
```bash  
iptables -t filter -A OUTPUT -p icmp --icmp-type echo-reply -j DROP
```
![[Pasted image 20250512152255.png]]

## 13. Interdire tout paquet entrant par eth0 dont l'adresse mac n'est pas celle du voisin  
```bash  
iptables -t filter -A INPUT -i eth0 -m mac --mac-source 00:11:22:33:44:55 -j DROP
```
![[Pasted image 20250512152341.png]]

## 14. Positionner la police par défaut à DROP pour la chaîne INPUT, écrire une règle qui laisse entrer 5 tentatives de connexion TCP puis qui n'en laisse plus passer que 2 par minute, faire de même avec les pings  
```bash  
iptables -t filter -P INPUT DROP
iptables -t filter -A INPUT -p tcp --syn -m limit --limit 5/minute --limit-burst 5 -j ACCEPT
iptables -t filter -A INPUT -p icmp --icmp-type echo-request -m limit --limit 5/minute --limit-burst 5 -j ACCEPT
```
![[Pasted image 20250512152353.png]]

**On suppose que le burst a été consommé, combien de temps (sans tentative de connexion ou d'echo-request) faudra-t'il pour qu'on puisse à nouveau avoir 5 de ces paquets qui passent à la suite ?**
Il faut 1 minute pour que le burst soit rechargé, donc 1 minute pour avoir à nouveau 5 paquets qui passent à la suite.

## 15. Positionnez les règles par défaut à DROP pour les chaînes INPUT, OUTPUT, FORWARD, autoriser tout paquet relatif à une connexion déjà établie ou en rapport avec une connexion déjà établie en entrée, interdire tout paquet relatif à une connexion de type INVALID, autoriser tout paquet créant une nouvelle connexion en sortie à destination du port 80
```bash  
iptables -t filter -P INPUT DROP
iptables -t filter -P OUTPUT DROP
iptables -t filter -P FORWARD DROP
iptables -t filter -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
iptables -t filter -A INPUT -m state --state INVALID -j DROP
iptables -t filter -A OUTPUT -p tcp --dport 80 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
```
![[Pasted image 20250512152449.png]]

**Que faut-il modifier ici pour que l'on puisse naviguer sur le net ?**
Il faut ajouter une règle pour autoriser le trafic sortant sur les ports 80 (HTTP) et 443 (HTTPS) pour permettre la navigation sur le web.
Voici la règle qu'il faudrait ajouter :
```bash  
iptables -t filter -A OUTPUT -p tcp --dport 443 -m state --state NEW,ESTABLISHED,RELATED -j ACCEPT
```
