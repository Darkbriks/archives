#include "types.h"
#include "user.h"
#include <stddef.h>

char buf[512];

void tail(char* arg, int lines)
{
	int n;
	int nb_lines = 0;
	int count = 0;
	int fd;
	
	if ((fd = open(arg, 0)) < 0)
	{
		printf(1, "tail: cannot open %s\n", arg);
		exit();
	}

	// Compter le nombre de lignes
	while ((n = read(fd, buf, sizeof(buf))) > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (buf[i] == '\n') { nb_lines++; }
		}
	}
	
	close(fd);
	if ((fd = open(arg, 0)) < 0)
	{
		printf(1, "tail: cannot open %s\n", arg);
		exit();
	}
	
	// Avencer jusqu'a la premiere ligne a ecrire
	while ((n = read(fd, buf, sizeof(buf))) > 0 && count < nb_lines - lines)
	{
		for (int i = 0; i < n && count < nb_lines - lines; i++)
		{
			if (buf[i] == '\n') { count++; }
		}
	}
	
	// Afficher le reste
	while((n = read(fd, buf, sizeof(buf))) > 0)
	{
		if (write(1, buf, n) != n)
		{
			printf(1, "tail: write error\n");
			exit();
		}
	}
	
	close(fd);

	if (n < 0)
	{
		printf(1, "tail: read error\n");
		exit();
	}
}

int main(int argc, char *argv[])
{
	int lines = 10;
	
	if (argc <= 1)
	{
		printf(1, "Usage: tail [-<lines>] <files>\n");
		exit();
	}
	
	if (argc == 2 && argv[1][0] != '-')
	{

		tail(argv[1], lines);
		exit();
  	}
  	
  	else if (argc == 3 && argv[1][0] == '-' && argv[1][1] != '\0')
  	{
		lines = atoi(argv[1] + 1);
		tail(argv[2], lines);
		exit();
	}
	
	else
	{
		printf(1, "Usage: tail [-<lines>] <file>\n");
		exit();
	}
}
