# TP 1 : Scripts python
## Exercice 1
```python
#!/usr/bin/env python3

import os
import sys
import stat

def change_txt_permissions(directory):
    """Change récursivement les permissions des fichiers .txt à 744."""
    
    for root, _, files in os.walk(directory):
        print(f"Traitement du répertoire : {root}")
        
        for file in files:
            if file.endswith(".txt"):
                file_path = os.path.join(root, file)
                try:
                    # Changer les permissions à 744 (rwxr--r--)
                    os.chmod(file_path, stat.S_IRWXU | stat.S_IRGRP | stat.S_IROTH)
                    print(f"\tPermissions changées : {file_path}")
                except Exception as e:
                    print(f"\tErreur sur {file_path} : {e}")

if __name__ == "__main__":
    # Vérification des arguments
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <répertoire>")
        sys.exit(1)

    directory = sys.argv[1]

    # Vérifier si le répertoire existe
    if not os.path.isdir(directory):
        print(f"Erreur : Le répertoire '{directory}' n'existe pas.")
        sys.exit(1)

    # Lancer le changement de permissions
    change_txt_permissions(directory)

```

## Exercice 2
### Question 2.A
```python
#!/usr/bin/env python3

import os
import sys

def count_files(directory):
    """Compte récursivement le nombre total de fichiers dans un répertoire."""
    total_files = 0

    for root, _, files in os.walk(directory):
        total_files += len(files)

    return total_files

if __name__ == "__main__":
    # Vérification des arguments
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <répertoire> <seuil>")
        sys.exit(1)

    directory = sys.argv[1]
    try:
        threshold = int(sys.argv[2])
    except ValueError:
        print("Erreur : Le seuil doit être un entier.")
        sys.exit(1)

    # Vérification de l'existence du répertoire
    if not os.path.isdir(directory):
        print(f"Erreur : Le répertoire '{directory}' n'existe pas.")
        sys.exit(1)

    # Comptage des fichiers et comparaison avec le seuil
    num_files = count_files(directory)
    print(f"{directory} contient {num_files} fichiers (seuil : {threshold})")

    if num_files > threshold:
        sys.exit(-1)  # Seuil dépassé
    else:
        sys.exit(0)   # Tout va bien
```

### Question 2.B
```python
#!/usr/bin/env python3

import os
import subprocess

PASSWD_FILE = "/etc/passwd"

def get_local_users():
    """Récupère les utilisateurs locaux (GID 1000) et leurs répertoires home."""
    users = []

    try:
        with open(PASSWD_FILE, "r") as f:
            for line in f:
                parts = line.strip().split(":")
                if len(parts) >= 7:
                    username, _, uid, gid, _, home_dir, _ = parts
                    if gid == "1000" and home_dir.startswith("/home/"):
                        users.append((username, home_dir))
    except Exception as e:
        print(f"Erreur lors de la lecture de {PASSWD_FILE} : {e}")
    
    return users

if __name__ == "__main__":
    users = get_local_users()
    if not users:
        print("Aucun utilisateur local trouvé.")
        exit(0)

    threshold = 100  # Modifier si nécessaire
    problematic_users = []

    for user, home_dir in users:
        if os.path.isdir(home_dir):
            print(f"Vérification du répertoire de {user} ({home_dir})...")

            # Exécute check_dir.py pour vérifier le nombre de fichiers
            result = subprocess.run(["python3", "check_dir.py", home_dir, str(threshold)], capture_output=True)
            
            if result.returncode == -1:
                print(f"Problème détecté pour {user} ! Trop de fichiers.")
                problematic_users.append(user)

    # Affichage des résultats
    if problematic_users:
        print("\nUtilisateurs avec trop de fichiers :")
        for user in problematic_users:
            print(f"  - {user}")
    else:
        print("\nAucun problème détecté.")
```

## Exercice 3
```python
#!/usr/bin/env python3

import os
import re
import subprocess
import ipaddress

def get_network_info():
    """Récupère l'adresse IP et le masque de sous-réseau via ifconfig."""
    try:
        result = subprocess.run(["/sbin/ifconfig", "eth0"], capture_output=True, text=True)
        output = result.stdout

        # Recherche de l'adresse IP
        ip_match = re.search(r'inet\s+(\d+\.\d+\.\d+\.\d+)', output)
        subnet_match = re.search(r'Mask:(\d+\.\d+\.\d+\.\d+)', output)

        if ip_match and subnet_match:
            ip_address = ip_match.group(1)
            subnet_mask = subnet_match.group(1)
            return ip_address, subnet_mask
        else:
            print("Erreur : Impossible de récupérer l'adresse IP et le masque réseau.")
            return None, None
    except Exception as e:
        print(f"Erreur lors de l'exécution de ifconfig : {e}")
        return None, None

def get_external_connections(local_network):
    """Liste les connexions TCP vers des adresses externes."""
    try:
        # Exécution de netstat pour récupérer les connexions TCP actives
        result = subprocess.run(["netstat", "-tn"], capture_output=True, text=True)
        output = result.stdout

        connections = []
        
        for line in output.split("\n"):
            parts = line.split()
            if len(parts) >= 5 and parts[0] == "tcp":
                local_addr, remote_addr, state = parts[3], parts[4], parts[5]
                
                # Extraction de l'adresse IP distante (host:port)
                remote_ip, remote_port = remote_addr.rsplit(":", 1)

                # Vérifier si l'adresse distante est externe
                if ipaddress.ip_address(remote_ip) not in local_network:
                    connections.append((remote_ip, remote_port, state))

        return connections

    except Exception as e:
        print(f"Erreur lors de l'exécution de netstat : {e}")
        return []

if __name__ == "__main__":
    # Récupérer l'IP et le masque réseau
    ip, mask = get_network_info()

    if ip and mask:
        # Déterminer le sous-réseau de la machine
        local_network = ipaddress.IPv4Network(f"{ip}/{mask}", strict=False)

        # Récupérer les connexions externes
        external_connections = get_external_connections(local_network)

        # Affichage des résultats
        if external_connections:
            print("\nConnexions TCP vers des machines externes :")
            print(f"{'Adresse distante':<20}{'Port':<10}{'État'}")
            print("-" * 45)
            for remote_ip, remote_port, state in external_connections:
                print(f"{remote_ip:<20}{remote_port:<10}{state}")
        else:
            print("Aucune connexion externe détectée.")
```

## Exercice 4
```python
#!/usr/bin/env python3

import psutil
import time

def monitor_system():
    """Surveille et affiche l'utilisation du CPU, de la mémoire et du disque toutes les 5 secondes."""
    
    try:
        while True:
            # Utilisation du CPU
            cpu_usage = psutil.cpu_percent(interval=1)

            # Utilisation de la mémoire
            memory_info = psutil.virtual_memory()
            memory_usage = memory_info.percent

            # Utilisation de l'espace disque (partition principale "/")
            disk_info = psutil.disk_usage("/")
            disk_usage = disk_info.percent

            # Affichage des résultats
            print("\nSurveillance du système :")
            print(f" -> CPU : {cpu_usage}%")
            print(f" -> Mémoire : {memory_usage}%")
            print(f" -> Disque : {disk_usage}%")
            
            # Pause de 5 secondes
            time.sleep(5)

    except KeyboardInterrupt:
        print("\nArrêt de la surveillance.")
    
if __name__ == "__main__":
    monitor_system()
```