#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define NB_LIGNES 10
#define NB_COLONNES 20

typedef char Ttab[NB_LIGNES][NB_COLONNES];

// Structure pour passere les args
typedef struct {
    int i;
    int j;
    Ttab *tab;
    sem_t *sem;
} ThreadArgs;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int compteur = 0;

int stop = 0;

char etat_suivant(int i, int j, Ttab tab) {
    // Retourne le prochain etat de la cellule de coordonnees (i,j) dans tab,
    // en fonction de ses cellules voisines :
    // si (i,j)='-' et si elle a exactement 3 cellules voisines egales a 'x'
    // alors retourne 'x'
    // sinon si (i,j)='x' et si elle a 2 ou 3 cellules voisines egales a 'x'
    // alors retourne 'x'
    // sinon retourne '-'
    int k, l;
    int nbVoisins = 0;
    if (i == 0)
        k = 0;
    else
        k = i - 1;
    for (; ((k < NB_LIGNES) && (k < i + 2)); k++) {
        if (j == 0)
            l = 0;
        else
            l = j - 1;
        for (; ((l < NB_COLONNES) && (l < j + 2)); l++)
            if (tab[k][l] == '+') nbVoisins++;
    }
    if ((tab[i][j] == '+') && ((nbVoisins == 3) || (nbVoisins == 4))) return '+';
    if ((tab[i][j] == '-') && (nbVoisins == 3)) return '+';
    return '-';
}

void affiche(Ttab tab){
    // affiche la grille tab[NB_LIGNES][NB_COLONNES]
    int i, j;
    for (i=0; i<NB_LIGNES; i++){
        for (j=0; j<NB_COLONNES; j++)
            printf("%c",tab[i][j]);
        printf("\n");
    }
    fflush(NULL);
}

void init(Ttab tab){
    // initialise la grille tab[NB_LIGNES][NB_COLONNES]
    // avec des valeurs aléatoires
    int i, j;
    for (i = 0; i < NB_LIGNES; i++) {
        for (j = 0; j < NB_COLONNES; j++) {
            int rd = rand() % 4;
            if (rd)
                tab[i][j] = '-';
            else
                tab[i][j] = '+';
        }
    }
}

void *thread_case(void *arg) {
    ThreadArgs *threadArgs = (ThreadArgs *)arg;

    char etat = etat_suivant(threadArgs->i, threadArgs->j, *threadArgs->tab);

    // Section critique
    pthread_mutex_lock(&mutex);
    compteur++;
    pthread_mutex_unlock(&mutex);

    sem_wait(threadArgs->sem);

    (*threadArgs->tab)[threadArgs->i][threadArgs->j] = etat;

    return NULL;
}

void *thread_central(void *arg) {
    ThreadArgs *threadArgs = (ThreadArgs *)arg;
    sem_t *sem = threadArgs->sem;

    while (stop == 0) {
        // si le compteur est égal au nombre de threads, on le remet à 0
        // Section critique
        pthread_mutex_lock(&mutex);
        if (compteur == NB_LIGNES * NB_COLONNES) {
            compteur = 0;
            pthread_mutex_unlock(&mutex);
            for (int i = 0; i < NB_LIGNES; i++) {
                for (int j = 0; j < NB_COLONNES; j++) {
                    sem_post(sem);
                }
            }
            printf("Grille :\n");
            affiche(*threadArgs->tab);
            stop++;
        } else {
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}

int main() {
    Ttab tab;
    init(tab);

    printf("Grille initiale :\n");
    affiche(tab);

    sem_t sem;
    sem_init(&sem, 0, 0);

    pthread_t threads[NB_LIGNES][NB_COLONNES];
    ThreadArgs threadArgs[NB_LIGNES][NB_COLONNES];

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            threadArgs[i][j].i = i;
            threadArgs[i][j].j = j;
            threadArgs[i][j].sem = &sem;
            threadArgs[i][j].tab = &tab;
            pthread_create(&threads[i][j], NULL, thread_case, &threadArgs[i][j]);
        }
    }

    ThreadArgs threadArgsCentral;
    threadArgsCentral.sem = &sem;
    threadArgsCentral.tab = &tab;

    pthread_t threadCentral;
    pthread_create(&threadCentral, NULL, thread_central, &threadArgsCentral);

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            pthread_join(threads[i][j], NULL);
        }
    }

    pthread_join(threadCentral, NULL);

    sem_destroy(&sem);

    return 0;
}

// Question 2 : Peut-on se passer du thread central ? Quelle est la difficulté s’il n y a plus de thread central ?
/*
 * On pourrait concevoir un système sans thread central, cepandant, chaque thread devrait s'occuper de la synchronisation avec les autres threads, augmentant la complexité de la synchronisation.
 */