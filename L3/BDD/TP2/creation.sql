DROP TABLE Noter;
DROP TABLE Matiere;
DROP TABLE Etudiant;
DROP TABLE Formation;

CREATE TABLE Formation (
    CodeF NUMBER(2) CONSTRAINT PK_Formation PRIMARY KEY,
    Libelle VARCHAR2(10) NOT NULL
);

CREATE TABLE Etudiant (
    NumEtu NUMBER(2) CONSTRAINT PK_Etudiant PRIMARY KEY,
    NomE VARCHAR2(24) NOT NULL UNIQUE,
    DateNais DATE NOT NULL,
    Sexe CHAR(1) DEFAULT 'M' CHECK (Sexe IN ('F', 'M')),
    CodeF NUMBER(2),
    CONSTRAINT FK_Etudiant_Formation FOREIGN KEY (CodeF)
    REFERENCES Formation (CodeF)
    ON DELETE SET NULL
);

CREATE TABLE Matiere (
    NumMat NUMBER(2) CONSTRAINT PK_Matiere PRIMARY KEY,
    NomM VARCHAR2(20) NOT NULL,
    Coefficient NUMBER(2) NOT NULL CHECK (Coefficient > 0)
);

CREATE TABLE Noter (
    NumEtu NUMBER(2),
    NumMat NUMBER(2),
    Note NUMBER(4,2) CHECK (Note BETWEEN 0 AND 20),
    PRIMARY KEY (NumEtu, NumMat),
    CONSTRAINT FK_Noter_Etudiant FOREIGN KEY (NumEtu)
    REFERENCES Etudiant (NumEtu)
    ON DELETE CASCADE,
    CONSTRAINT FK_Noter_Matiere FOREIGN KEY (NumMat)
    REFERENCES Matiere (NumMat)
    ON DELETE CASCADE
);

/*
SQL> @/tmp/creation.sql

Table created.

Table created.

Table created.

Table created.
*/