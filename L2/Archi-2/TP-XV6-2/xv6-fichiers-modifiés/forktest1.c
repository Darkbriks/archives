
#include "types.h"
#include "user.h"

int main(void)
{
	printf(1, "+ ");
	fork();
	wait();
	printf(1, "* ");
	fork();
	wait();
	printf(1, "x ");
	exit();
}
