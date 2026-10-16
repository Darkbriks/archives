DROP TABLE PRODUITS CASCADE CONSTRAINTS;
DROP TABLE RAYON CASCADE CONSTRAINTS;
DROP TABLE HYPERMARCHE CASCADE CONSTRAINTS;
DROP TABLE EMPLOYE CASCADE CONSTRAINTS;

CREATE TABLE EMPLOYE (
    NUMERO VARCHAR(7) CONSTRAINT pk_employe PRIMARY KEY,
    NOM VARCHAR(50) NOT NULL,
    PRENOM VARCHAR(50) NOT NULL,
    ADRESSE VARCHAR(100) NOT NULL
);

CREATE TABLE HYPERMARCHE (
    NUMERO VARCHAR(5) CONSTRAINT pk_hypermarche PRIMARY KEY,
    NOM VARCHAR(50) NOT NULL,
    ADRESSE VARCHAR(100) NOT NULL,
    VILLE VARCHAR(50) NOT NULL,
    CODEPOSTAL VARCHAR(10) NOT NULL,
    NUMERODIRECTEUR VARCHAR(7),
    CONSTRAINT fk_hypermarche_directeur FOREIGN KEY (NUMERODIRECTEUR) REFERENCES EMPLOYE(NUMERO)
);

CREATE TABLE RAYON (
    NUMERO VARCHAR(5) CONSTRAINT pk_rayon PRIMARY KEY,
    NOM VARCHAR(50) NOT NULL,
    DESCRIPTIF VARCHAR(255),
    CHIFFREAFFAIRE INTEGER NOT NULL,
    NUMEROHYPER VARCHAR(5) NOT NULL,
    NUMERORESPONSABLE VARCHAR(7),
    CONSTRAINT fk_rayon_hyper FOREIGN KEY (NUMEROHYPER) REFERENCES HYPERMARCHE(NUMERO),
    CONSTRAINT fk_rayon_responsable FOREIGN KEY (NUMERORESPONSABLE) REFERENCES EMPLOYE(NUMERO)
);

CREATE TABLE PRODUITS (
    NUMERO VARCHAR(6) CONSTRAINT pk_produits PRIMARY KEY,
    LIBELLE VARCHAR(50) NOT NULL,
    NUMERORAYON VARCHAR(5) NOT NULL,
    PRIXUNITAIRE DECIMAL(10, 2) NOT NULL,
    UNITE VARCHAR(20) NOT NULL,
    QUANTITESTOCKHYPER INT NOT NULL,
    CONSTRAINT fk_produits_rayon FOREIGN KEY (NUMERORAYON) REFERENCES RAYON(NUMERO)
);

/*
SQL> @/tmp/createtab.sql
Table dropped.
Table dropped.
Table dropped.
Table dropped.
Table created.
Table created.
Table created.
Table created.
*/

/*
SQL> DESC EMPLOYE;
Name                                      Null?    Type
----------------------------------------- -------- ----------------------------
NUMERO                                    NOT NULL VARCHAR2(7)
NOM                                       NOT NULL VARCHAR2(20)
PRENOM                                    NOT NULL VARCHAR2(20)
ADRESSE                                            VARCHAR2(50)

SQL> DESC HYPERMARCHE;
Name                                      Null?    Type
----------------------------------------- -------- ----------------------------
NUMERO                                    NOT NULL VARCHAR2(5)
NOM                                       NOT NULL VARCHAR2(20)
ADRESSE                                   NOT NULL VARCHAR2(50)
VILLE                                     NOT NULL VARCHAR2(20)
CODEPOSTAL                                NOT NULL VARCHAR2(5)
NUMERODIRECTEUR                                    VARCHAR2(7)

SQL> DESC RAYON;
Name                                      Null?    Type
----------------------------------------- -------- ----------------------------
NUMERO                                    NOT NULL VARCHAR2(5)
NOM                                       NOT NULL VARCHAR2(20)
DESCRIPTIF                                         VARCHAR2(255)
CHIFFREAFFAIRE                            NOT NULL NUMBER(38)
NUMEROHYPER                               NOT NULL VARCHAR2(5)
NUMERORESPONSABLE                                  VARCHAR2(7)

SQL> DESC PRODUITS;
Name                                      Null?    Type
----------------------------------------- -------- ----------------------------
NUMERO                                    NOT NULL VARCHAR2(6)
LIBELLE                                   NOT NULL VARCHAR2(20)
NUMERORAYON                               NOT NULL VARCHAR2(5)
PRIXUNITAIRE                              NOT NULL NUMBER(10,2)
UNITE                                     NOT NULL VARCHAR2(5)
QUANTITESTOCKHYPER                        NOT NULL NUMBER(38)
*/

/*
SQL> SELECT * FROM EMPLOYE;
no rows selected

SQL> SELECT * FROM HYPERMARCHE;
no rows selected

SQL> SELECT * FROM RAYON;
no rows selected

SQL> SELECT * FROM PRODUITS;
no rows selected
*/

/*
SQL> DESC SYS.USER_TABLES
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 TABLE_NAME                                NOT NULL VARCHAR2(128)
 TABLESPACE_NAME                                    VARCHAR2(30)
 CLUSTER_NAME                                       VARCHAR2(128)
 IOT_NAME                                           VARCHAR2(128)
 STATUS                                             VARCHAR2(8)
 PCT_FREE                                           NUMBER
 PCT_USED                                           NUMBER
 INI_TRANS                                          NUMBER
 MAX_TRANS                                          NUMBER
 INITIAL_EXTENT                                     NUMBER
 NEXT_EXTENT                                        NUMBER
 MIN_EXTENTS                                        NUMBER
 MAX_EXTENTS                                        NUMBER
 PCT_INCREASE                                       NUMBER
 FREELISTS                                          NUMBER
 FREELIST_GROUPS                                    NUMBER
 LOGGING                                            VARCHAR2(3)
 BACKED_UP                                          VARCHAR2(1)
 NUM_ROWS                                           NUMBER
 BLOCKS                                             NUMBER
 EMPTY_BLOCKS                                       NUMBER
 AVG_SPACE                                          NUMBER
 CHAIN_CNT                                          NUMBER
 AVG_ROW_LEN                                        NUMBER
 AVG_SPACE_FREELIST_BLOCKS                          NUMBER
 NUM_FREELIST_BLOCKS                                NUMBER
 DEGREE                                             VARCHAR2(10)
 INSTANCES                                          VARCHAR2(10)
 CACHE                                              VARCHAR2(5)
 TABLE_LOCK                                         VARCHAR2(8)
 SAMPLE_SIZE                                        NUMBER
 LAST_ANALYZED                                      DATE
 PARTITIONED                                        VARCHAR2(3)
 IOT_TYPE                                           VARCHAR2(12)
 TEMPORARY                                          VARCHAR2(1)
 SECONDARY                                          VARCHAR2(1)
 NESTED                                             VARCHAR2(3)
 BUFFER_POOL                                        VARCHAR2(7)
 FLASH_CACHE                                        VARCHAR2(7)
 CELL_FLASH_CACHE                                   VARCHAR2(7)
 ROW_MOVEMENT                                       VARCHAR2(8)
 GLOBAL_STATS                                       VARCHAR2(3)
 USER_STATS                                         VARCHAR2(3)
 DURATION                                           VARCHAR2(15)
 SKIP_CORRUPT                                       VARCHAR2(8)
 MONITORING                                         VARCHAR2(3)
 CLUSTER_OWNER                                      VARCHAR2(128)
 DEPENDENCIES                                       VARCHAR2(8)
 COMPRESSION                                        VARCHAR2(8)
 COMPRESS_FOR                                       VARCHAR2(30)
 DROPPED                                            VARCHAR2(3)
 READ_ONLY                                          VARCHAR2(3)
 SEGMENT_CREATED                                    VARCHAR2(3)
 RESULT_CACHE                                       VARCHAR2(7)
 CLUSTERING                                         VARCHAR2(3)
 ACTIVITY_TRACKING                                  VARCHAR2(23)
 DML_TIMESTAMP                                      VARCHAR2(25)
 HAS_IDENTITY                                       VARCHAR2(3)
 CONTAINER_DATA                                     VARCHAR2(3)
 INMEMORY                                           VARCHAR2(8)
 INMEMORY_PRIORITY                                  VARCHAR2(8)
 INMEMORY_DISTRIBUTE                                VARCHAR2(15)
 INMEMORY_COMPRESSION                               VARCHAR2(17)
 INMEMORY_DUPLICATE                                 VARCHAR2(13)
 DEFAULT_COLLATION                                  VARCHAR2(100)
 DUPLICATED                                         VARCHAR2(1)
 SHARDED                                            VARCHAR2(1)
 EXTERNALLY_SHARDED                                 VARCHAR2(1)
 EXTERNALLY_DUPLICATED                              VARCHAR2(1)
 EXTERNAL                                           VARCHAR2(3)
 HYBRID                                             VARCHAR2(3)
 CELLMEMORY                                         VARCHAR2(24)
 CONTAINERS_DEFAULT                                 VARCHAR2(3)
 CONTAINER_MAP                                      VARCHAR2(3)
 EXTENDED_DATA_LINK                                 VARCHAR2(3)
 EXTENDED_DATA_LINK_MAP                             VARCHAR2(3)
 INMEMORY_SERVICE                                   VARCHAR2(12)
 INMEMORY_SERVICE_NAME                              VARCHAR2(1000)
 CONTAINER_MAP_OBJECT                               VARCHAR2(3)
 MEMOPTIMIZE_READ                                   VARCHAR2(8)
 MEMOPTIMIZE_WRITE                                  VARCHAR2(8)
 HAS_SENSITIVE_COLUMN                               VARCHAR2(3)
 ADMIT_NULL                                         VARCHAR2(3)
 DATA_LINK_DML_ENABLED                              VARCHAR2(3)
 LOGICAL_REPLICATION                                VARCHAR2(8)

SQL> DESC SYS.USER_OBJECTS
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 OBJECT_NAME                                        VARCHAR2(128)
 SUBOBJECT_NAME                                     VARCHAR2(128)
 OBJECT_ID                                          NUMBER
 DATA_OBJECT_ID                                     NUMBER
 OBJECT_TYPE                                        VARCHAR2(23)
 CREATED                                            DATE
 LAST_DDL_TIME                                      DATE
 TIMESTAMP                                          VARCHAR2(19)
 STATUS                                             VARCHAR2(7)
 TEMPORARY                                          VARCHAR2(1)
 GENERATED                                          VARCHAR2(1)
 SECONDARY                                          VARCHAR2(1)
 NAMESPACE                                          NUMBER
 EDITION_NAME                                       VARCHAR2(128)
 SHARING                                            VARCHAR2(18)
 EDITIONABLE                                        VARCHAR2(1)
 ORACLE_MAINTAINED                                  VARCHAR2(1)
 APPLICATION                                        VARCHAR2(1)
 DEFAULT_COLLATION                                  VARCHAR2(100)
 DUPLICATED                                         VARCHAR2(1)
 SHARDED                                            VARCHAR2(1)
 IMPORTED_OBJECT                                    VARCHAR2(1)
 CREATED_APPID                                      NUMBER
 CREATED_VSNID                                      NUMBER
 MODIFIED_APPID                                     NUMBER
 MODIFIED_VSNID                                     NUMBER

SQL> DESC SYS.USER_CONSTRAINTS
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 OWNER                                              VARCHAR2(128)
 CONSTRAINT_NAME                           NOT NULL VARCHAR2(128)
 CONSTRAINT_TYPE                                    VARCHAR2(1)
 TABLE_NAME                                NOT NULL VARCHAR2(128)
 SEARCH_CONDITION                                   LONG
 SEARCH_CONDITION_VC                                VARCHAR2(4000)
 R_OWNER                                            VARCHAR2(128)
 R_CONSTRAINT_NAME                                  VARCHAR2(128)
 DELETE_RULE                                        VARCHAR2(9)
 STATUS                                             VARCHAR2(8)
 DEFERRABLE                                         VARCHAR2(14)
 DEFERRED                                           VARCHAR2(9)
 VALIDATED                                          VARCHAR2(13)
 GENERATED                                          VARCHAR2(14)
 BAD                                                VARCHAR2(3)
 RELY                                               VARCHAR2(4)
 LAST_CHANGE                                        DATE
 INDEX_OWNER                                        VARCHAR2(128)
 INDEX_NAME                                         VARCHAR2(128)
 INVALID                                            VARCHAR2(7)
 VIEW_RELATED                                       VARCHAR2(14)
 ORIGIN_CON_ID                                      NUMBER

SELECT COLUMN_NAME FROM USER_CONS_COLUMNS WHERE TABLE_NAME = 'INSTALLER';
no rows selected
*/