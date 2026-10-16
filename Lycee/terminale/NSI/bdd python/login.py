import sqlite3
import hashlib

def register_user(base, table):
    connection=sqlite3.connect(base)
    c=connection.cursor()
    c.execute("CREATE TABLE IF NOT EXISTS " + table + " (username text primary key, mdp text, phrase text);")
    
    username = str(input("nom de l'utilisateur : "))
    
    c.execute("SELECT * FROM " + table + " WHERE username=?;", (username,))
    while c.fetchone() != None:
        username = str(input("nom deja utliser, veuiller rentrer un nouveau nom : "))
        c.execute("SELECT * FROM " + table + " WHERE username=?;", (username,))
        
    _tuple = (username, hashlib.md5(str(input("mot de passe de l'utilisateur : ")).encode()).hexdigest(), str(input("phrase de l'utiliasateur : ")))
    
    c.execute("INSERT INTO " + table + " VALUES (?, ?, ?);", _tuple)
    
    connection.commit()
    connection.close()
    
    
    
def login(base, table):
    connection=sqlite3.connect(base)
    c=connection.cursor()
    c.execute("CREATE TABLE IF NOT EXISTS " + table + " (username text primary key, mdp text, phrase text);")

    username = str(input("nom de l'utilisateur : "))
    mdp = hashlib.md5(str(input("mot de passe de l'utilisateur : ")).encode()).hexdigest()
    
    c.execute("SELECT * FROM " + table + " WHERE username=? AND mdp=?;", (username, mdp))
    
    user = c.fetchone()
    connection.close()
    
    if user != None:
        return user[2]
    return "mot de passe ou nom d'utilisateur incorect"

def menu():
    print(" " + "_"*35)
    print("| Pour vous enregistrer, taper 1    |")
    print("| Pour vous connecter, taper 2      |")
    print("| Pour quitter, taper 3             |")
    print("|" + "_"*35 + "|\n ")
    
    reponse = str(input("Quelle action souhaitez vous executer ? "))
    
    if reponse == "3":
        return
    
    base = str(input("A quelle base souhaitez vous vous connecter ? "))
    table = str(input(str("A quelle table de cette base souhaitez vous vous connecter ? ")))
    
    if reponse == "1":
        return register_user(base, table)
    if reponse == "2":
        return login(base, table)
    return
    
    