Lancer le conteneur Docker
```bash
docker run -d --name oracle-db --hostname mydb --domainname mydocker.com -p 1521:1521 -p 5500:5500 -e ORACLE_SID=MYCDB -e ORACLE_PDB=MYPDB -e ORACLE_PWD=your_oracle_password -e ORACLE_EDITION=ee -e ENABLE_ARCHIVELOG=true -v OracleDBData:/opt/oracle/oradata container-registry.oracle.com/database/enterprise:latest
```
user-name: sys
password: your_oracle_password

Se connecter au conteneur Docker - Installation Windows
```bash
docker exec -it oracle-db sqlplus sys/root@//localhost:1521/MYCDB as sysdba
```

Se connecter au conteneur Docker - Installation Linux
```bash
docker exec -it 40a90e bash
```
```bash
sqlplus / as sysdba
```

Copier un fichier dans le conteneur Docker
```bash
docker cp /path/to/file oracle-db:/tmp/path/to/file
```

Exécuter un script SQL dans le conteneur Docker (une fois connecté)
```sql
@/tmp/path/to/script.sql
```