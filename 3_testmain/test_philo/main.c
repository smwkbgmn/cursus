#include <stdio.h>

int main (int ac, char **av)
{
	int *q[3];
	int a, b, c;

	a = 1;
	b = 2;
	c = 3;
	q[0] = &a;
	q[1] = &b;
	q[2] = &c;
	printf("%p, %p\n", &a, q[0]);
	printf("%p, %p\n", &b, q[1]);
	printf("%p, %p\n", &c, q[2]);
	// printf("%d %d %d\n", *q[0], *q[1], *q[2]);
}