#include "types.h"
#include "user.h"

// Fonction pour générer un nombre aléatoire de "ticks"
int generateRandomTicks(int *previousX, int a, int c, int m) {
	*previousX = (a * (*previousX) + c) % m;
    	return *previousX % 10;
}

int main()
{
	// Paramètres pour l'algorithme de congruence linéaire
	int a = 1664525;
	int c = 1013904223;
	int m = 32;

	int numChildren = 5;  // Nombre de processus fils à créer
	int previousX = c % m; // Initialisation pour l'algorithme de congruence linéaire

	// Création des processus fils
	for (int i = 0; i < numChildren; i++)
	{
		int pid = fork();
		if (pid == 0)
		{
            		// Processus fils
            		int numTicks = generateRandomTicks(&previousX, a, c, m);
            		printf(1, "Child %d, Parent %d: %d ticks\n", getpid(), getppid(), numTicks);
            		for (int j = 0; j < numTicks; j++) { sleep(1); }
            		exit();
        	}
        	
        	else if (pid > 0)
        	{
			// Processus parent
			continue;
		} 
		
		else
		{
 			// Erreur
			printf(1, "Error: fork() failed\n");
			exit();
		}
	}
	
	// Attendre que tous les processus fils se terminent
	for (int i = 0; i < numChildren; i++) { wait(); }

	printf(1, "Parent %d: all children terminated\n", getpid());

	exit();
}
