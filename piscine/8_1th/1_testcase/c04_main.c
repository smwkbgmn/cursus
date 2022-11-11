#include <stdio.h>

#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"

int	main(void)
{
	printf("5 : %d\n", ft_strlen("abcde"));
	
	printf("\nabcde\n");
	ft_putstr("abcde");
	printf("\n\n");
	
	printf("-2147483648\n");
	ft_putnbr(-2147483648);
	printf("\n");
	
	printf("-345\n");
	ft_putnbr(-345);
	printf("\n");

	printf("0\n");
	ft_putnbr(0);
	printf("\n");

	printf("345\n");
	ft_putnbr(345);
	printf("\n");

	printf("2147483647\n");
	ft_putnbr(2147483647);
	printf("\n");

	
}
