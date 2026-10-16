import sqlite3

def connection(base, _tuple):
    conn=sqlite3.connect(base)
    cur=conn.cursor()
    
    cur.execute("CREATE TABLE IF NOT EXISTS personne (nom text primary key, prenom text, age int);")
    cur.execute("INSERT INTO personne VALUES (?, ?, ?);", _tuple)
    
    conn.commit()
    conn.close()
    
def rentrer_note(base):
    conn=sqlite3.connect(base)
    cur=conn.cursor()
    
    cur.execute("CREATE TABLE IF NOT EXISTS eleve (nom text primary key, note int);")
    
    quitter=False
    while not quitter:
        _tuple=(str(input("nom de l'eleve : ")),str(input("note de l'eleve : ")))
        
        if _tuple[0] == "Quitter":
            quitter = False
            return
        
        cur.execute("INSERT INTO eleve VALUES (?, ?);", _tuple)
        conn.commit()
        
    conn.close()
    
def consulter_all_note(base):
    conn=sqlite3.connect(base)
    cur=conn.cursor()
    
    cur.execute("CREATE TABLE IF NOT EXISTS eleve (nom text primary key, note int);")
    cur.execute("SELECT * FROM eleve;")
    
    l=[]
    while True:
        l.append(cur.fetchone())
        if l[-1] == None:
            l.pop()
            break
    conn.close()
    return l

def consulter_note(base):
    conn=sqlite3.connect(base)
    cur=conn.cursor()
    
    cur.execute("CREATE TABLE IF NOT EXISTS eleve (nom text primary key, note int);")
    
    while True:
        nom = str(input("nom de l'eleve : "))
        if nom in ["Q", "q", "Quitter"]:
            break
        
        cur.execute("SELECT * FROM eleve WHERE nom=?;", (nom,))
        print(cur.fetchone())
        
    conn.close()
    
    
        
        
        
        
        
        
        