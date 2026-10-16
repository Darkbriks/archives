#include "types.h"
#include "user.h"
#include <stddef.h>

char buf[512];

void head(int fd, int lines)
{
	int n, count = 0;

	while ((n = read(fd, buf, sizeof(buf))) > 0 && count < lines)
	{
		for (int i = 0; i < n && count < lines; i++)
		{
			if (write(1, &buf[i], 1) != 1)
			{
				printf(1, "head: write error\n");
				exit();
			}
			if (buf[i] == '\n') { count++; }
		}
	}

	if (n < 0)
	{
		printf(1, "head: read error\n");
		exit();
	}
}

int main(int argc, char *argv[])
{
	int fd, lines = 10;
	
	if (argc <= 1)
	{
		printf(1, "Usage: head [-<lines>] <files>\n");
		exit();
	}
	
	if (argc == 2 && argv[1][0] != '-')
	{
		if ((fd = open(argv[1], 0)) < 0)
		{
			printf(1, "head: cannot open %s\n", argv[1]);
			exit();
		}
  	}
  	
  	else if (argc == 3 && argv[1][0] == '-' && argv[1][1] != '\0')
  	{
		lines = atoi(argv[1] + 1);
		if ((fd = open(argv[2], 0)) < 0)
		{
			printf(1, "head: cannot open %s\n", argv[2]);
			exit();
		}
	}
	
	else
	{
		printf(1, "Usage: head [-<lines>] <file>\n");
		exit();
	}
	
	head(fd, lines);
	close(fd);

	exit();
}
