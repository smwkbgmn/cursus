#include "main.h"

#include <unistd.h>
#include <limits.h>

int	main(void)
{
// 	printf("123456789A123456789A\n");
// 	printf("[%d]\n", printf("% s\n", "hi"));
// 	printf("[%d]\n", ft_printf("% s\n", "hi"));

// 	printf("[%d]", printf("%4294967296d", 12345));

	ft_printf("%0+100.1d, %0+100.1d, %0+100.1d, %0+100.1d, %0+100.1d, %0+100.1d, %0+100.1d, %0+100.1d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	// printf("\n");
	// ft_printf("hihi 2147483647 %5d   , %5d  %2147483647d hihi   ejfj", 1234, 1234, 1234);
	// ft_printf("%5d, %2147483647d", 1234, 1234);
// 	printf("[%d]\n", printf("%-1.100X, %-1.100X, %-1.100X, %-1.100X, %-1.100X, %-1.100X, 
// %-1.100X, %-1.100X, %-1.100X, %-1.100X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, 
// INT_MAX, UINT_MAX));
// 	printf("\n");


// 	printf("[%d]\n", ft_printf("%-1.100X, %-1.100X, %-1.100X, %-1.100X, %-1.100X, %-1.100X, 
// %-1.100X, %-1.100X, %-1.100X, %-1.100X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, 
// INT_MAX, UINT_MAX));
// 	printf("\n");
// 	printf("[%d]", ft_printf("%2147483646d", 12345));
// 	printf("[%d]", ft_printf("%4294967296d", 12345));

// 	printf("\n");

// 	printf("[%d]", ft_printf("%2147483647d", 12345));

// 	printf("%lu\n", ft_atoi_ulong("2147483648"));
	// printf("%lu\n", ft_atoi_ulong("4294967297"));

	printf("\n");

	system("leaks a.out");

	return (0);
}

// int main (void)
// {
// 	int		int_max = 2147483647;
// 	int		int_min = -2147483648;
// 	int		n = -10;
// 	int		*p = &n;
// 	int		*p_null = (int *)0;
// 	char	c = 'a';
// 	char	s[10] = "abcde";

// 	int	rst_origin;
// 	int	rst_ft;

// 	printf("123456789A123456789A\n");

// 	ft_printf("'a' (%%c)\t\t");
// 	rst_ft = ft_printf("[%c]", c);
// 	rst_origin = printf("[%c]", c);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("\"abcde\" (%%s)\t\t");
// 	rst_ft = ft_printf("[%s]", s);
// 	rst_origin = printf("[%s]", s);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);



// 	ft_printf("address_int * (%%p)\t");
// 	rst_ft = ft_printf("[%p]", p);
// 	rst_origin = printf("[%p]", p);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("address_null (%%p)\t");
// 	rst_ft = ft_printf("[%p]", p_null);
// 	rst_origin = printf("[%p]", p_null);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);



// 	ft_printf("%d (%%d)\t\t\t", n);
// 	rst_ft = ft_printf("[%d]", n);
// 	rst_origin = printf("[%d]", n);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("0 (%%d)\t\t\t");
// 	rst_ft = ft_printf("[%d]", 0);
// 	rst_origin = printf("[%d]", 0);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("%d (%%d)\t\t", int_max);
// 	rst_ft = ft_printf("[%d]", int_max);
// 	rst_origin = printf("[%d]", int_max);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("%d (%%d)\t\t", int_min);
// 	rst_ft = ft_printf("[%d]", int_min);
// 	rst_origin = printf("[%d]", int_min);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);



// 	ft_printf("%d (%%i)\t\t\t", n);
// 	rst_ft = ft_printf("[%i]", n);
// 	rst_origin = printf("[%i]", n);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("-1 (%%u)\t\t\t");
// 	rst_ft = ft_printf("[%u]", -1);	
// 	rst_origin = printf("[%u]", -1);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);



// 	ft_printf("%d (%%x)\t\t\t", n);
// 	rst_ft = ft_printf("[%x]", n);
// 	rst_origin = printf("[%x]", n);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("0 (%%x)\t\t\t");
// 	rst_ft = ft_printf("[%x]", 0);
// 	rst_origin = printf("[%x]", 0);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("2147483647 (%%x)\t\t");
// 	rst_ft = ft_printf("[%x]", int_max);
// 	rst_origin = printf("[%x]", int_max);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	ft_printf("-2147483648 (%%X)\t");
// 	rst_ft = ft_printf("[%X]", int_min);
// 	rst_origin = printf("[%X]", int_min);
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);



// 	ft_printf("%% (%%%%)\t\t\t");
// 	rst_ft = ft_printf("[%%]");
// 	rst_origin = printf("[%%]");
// 	printf("\n\t\t\t[%d][%d]\n\n", rst_ft, rst_origin);

// 	printf("\n");

// 	// ft_printf("%%d");


// 	system("leaks a.out");
// 	return (0);
// }
