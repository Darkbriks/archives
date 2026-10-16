# Compte-rendu TP6 : Serveur DHCP sous Debian  
Dubleumortier Thomas
Patron Antoine

---

# 1. Configuration du Serveur DHCP  

## 1.1 Interfaces Réseau 
`/etc/network/interfaces`
### Serveur (VM1) :
#### Interface principale : `enp0s3` (NAT VirtualBox)
- IP : `10.0.2.15/24` *(accès internet)*  
#### Interface virtuelle : `enp0s3:0` (pour DHCP)
- IP statique : `172.16.15.1/24`  
 - Plage DHCP : `172.16.15.100` - `172.16.15.200`  

## 1.2 Fichiers de Configuration  

### /etc/network/interfaces :
*Suivi de la commande `sudo ifdown enp0s3:0 && sudo ifup enp0s3:0` pour s'assurer que les modifications sont prises en compte*
![[Screenshot_from_2025-05-04_22-48-40.png]]
### /etc/dhcp/dhcpd.conf :
![[Screenshot_from_2025-05-04_22-49-44.png]]
### /etc/default/isc-dhcp-server :
![[Screenshot_from_2025-05-04_22-50-31.png]]
### /etc/host.conf :
![[Screenshot_from_2025-05-04_22-51-26.png]]
![[Screenshot_from_2025-05-04_22-52-07.png]]
### /etc/networks :
![[Screenshot_from_2025-05-04_22-52-57.png]]

# Démarrage et test du serveur
```bash
sudo systemctl restart isc-dhcp-server
sudo systemctl status isc-dhcp-serve
```
![[Screenshot_from_2025-05-04_20-42-01.png]]

# 2. Configuration du Client (VM2)  
## 2.1 Réseau  
#### Mode VirtualBox : Réseau interne (intnet)  
#### Interface : enp0s3 (DHCP)  
- IP attribué par le serveur : `172.16.15.102/24` *(succès !)*  
- Passerelle : `172.16.15.1`  
- DNS : `172.16.15.1`  

Pour tester, nous avons utilisé deux instances de Debian dont le mode d'accès réseau est "Réseau interne" dans VirtualBox.  

## 2.2 Tests
### Renouvellement DHCP :  
![[Screenshot_from_2025-05-04_22-35-09.png]]
### Ping vers le serveur :
![[Screenshot_from_2025-05-04_22-38-55.png]]
### Conclusion des tests
Grâce aux commandes précédentes, et notamment à la commande `ping`, on peut observer que le serveur a correctement assigné une IP au client, et que les deux instances sont capables de communiquer entre par le biais de l'adresse IP attribué par le serveur.