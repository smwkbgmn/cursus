#include "main.h"

int main (void)
{
	int a;

	ft_printf("ft [%c]\n", 'A');
	ft_printf("ft [%p]\n", &a);
	ft_printf("ft [%d]\n", 'A');
	ft_printf("ft [%i]\n", 'A');
	ft_printf("ft [%u]\n", -1);
	ft_printf("ft [%x]\n", 2147483647);
	ft_printf("ft [%X]\n", 2147483647);
	ft_printf("ft [%%]\n");

	printf("\n");

	printf("origin [%c]\n", 'A');
	printf("origin [%p]\n", &a);
	printf("origin [%d]\n", 'A');
	printf("origin [%i]\n", 'A');
	printf("origin [%u]\n", -1);
	printf("origin [%x]\n", 2147483647);
	printf("origin [%X]\n", 2147483647);
	printf("origin [%%]\n");


	return (0);
}