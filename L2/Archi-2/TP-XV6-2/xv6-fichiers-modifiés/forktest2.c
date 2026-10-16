#include "types.h"
#include "user.h"

int main (void)
{
	int pid;
	pid = fork();
	if (pid > 0)
	{
		printf(1 , " from parent %d: child = %d is created\n", getpid() , pid);
		pid = wait();
		printf(1 , " from parent %d: child %d is done\n ", getpid(), pid);
	}
	
	else if (pid == 0)
	{
		printf(1 ," from child %d: process started from parent %d\n", getpid(), getppid());
		
		exit();
	}
	
	else
	{
		printf(1, " fork error\n");
	}
	
	exit();
}
