#include "main.h"

int main (void)
{
	int a;

	a = 0xf;
	// ft_printf("ft [%c]\n", 'A');
	// ft_printf("ft [%p]\n", &a);
	// ft_printf("ft [%d]\n", 'A');
	// ft_printf("ft [%i]\n", 'A');
	// ft_printf("ft [%u]\n", -1);
	// ft_printf("ft [%x]\n", 2147483647);
	// ft_printf("ft [%X]\n", 2147483647);
	// ft_printf("ft [%%]\n");
	ft_printf("ft [%c][%s][%p][%d][%i][%u][%x][%X][%%]\n", 'A', "abcde", &a, a, a, -1, 2147483647, 2147483647);
	ft_printf("ft [%c][%s][%p][%d][%i][%u][%x][%X][%%]\n", 0, (char *)0, (void *)0, 0, 0, 0, 0, 0);
	
	printf("\n");

	// printf("origin [%c]\n", 'A');
	// printf("origin [%p]\n", &a);
	// printf("origin [%d]\n", 'A');
	// printf("origin [%i]\n", 'A');
	// printf("origin [%u]\n", -1);
	// printf("origin [%x]\n", 2147483647);
	// printf("origin [%X]\n", 2147483647);
	// printf("origin [%%]\n");
	printf("origin [%c][%p][%d][%i][%u][%x][%X][%%]\n", 'A', &a, a, a, -1, 2147483647, 2147483647);
	printf("origin [%c][%s][%p][%d][%i][%u][%x][%X][%%]\n", 0, (char *)0, (void *)0, 0, 0, 0, 0, 0);


	return (0);
}