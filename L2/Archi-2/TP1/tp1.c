#include <unistd.h>

int y = 5;

int compute(int a, int b, int*x)
{
	return a + b + *x + y;
}

void _start(void)
{
	int x = 2;
	
	write(1, "begin\n", 6);
	x = compute(1, 2, &x);
	write(1, "end\n", 4);
	_exit(0);
}
