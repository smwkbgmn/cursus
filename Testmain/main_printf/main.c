#include "main.h"

#include <unistd.h>

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


// 	return (0);
// }

// int main(void)
// {
		// int result;

	// printf("123456789A123456789A\n");
	// printf("%-.3d%d\n", 1, 1);
	// printf("%- 10.3d%d\n", 1, 1);
	// printf("%.10d\n", 1);
	// printf("%.0010d%d\n", 0, 1);


	// printf("%00005.00005d\n", 123);
	// ft_printf("%00005.00005d\n", 123);

	// printf("%d\n", printf("%5d\n", 123));
	// printf("%d\n", ft_printf("%5d\n", 123));

	// printf("% 05d% 05d% 05d\n", 123, 0, -123);
	// ft_printf("% 05d% 05d% 05d\n", 123, 0, -123);
	// printf("% .5d% .0d% .5d\n", 123, 0, -123);
	// ft_printf("% .5d% .0d% .5d\n", 123, 0, -123);

	// printf("%+05d%+05d%+05d\n", 123, 0, -123);
	// ft_printf("%+05d%+05d%+05d\n", 123, 0, -123);
	// printf("%+.5d%+.0d%+.5d\n", 123, 0, -123);
	// ft_printf("%+.5d%+.0d%+.5d\n", 123, 0, -123);

	// printf("%+.0d\n", 0);
	// ft_printf("%#.10x\n", 255);
	// ft_printf("%#.10x\n", 255);

	// ft_printf("%#.10x\n", 15);

	// ft_printf("%.0d%.10d\n", 0, 123);
	// ft_printf("%.0d\n", 0);

	// result = printf("%.0d\n", 0);
	// printf("result --- [%d]\n", result);


	// system("leaks a.out");
// 	return (0);
// }

int	main(void)
{
	printf("----------- ft ----------\n");

	ft_printf(" %c \n", '0');
	ft_printf("%c \n", '0' + 256);
	ft_printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	ft_printf(" %c %c %c \n", '1', '2', '3');
	ft_printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %c %c %c \n", 0, '1', '2');

	printf("----------- original ----------\n");

	printf(" %c \n", '0');
	printf("%c \n", '0' + 256);
	printf(" %c %c %c \n", '0', 0, '1');
	printf(" %c %c %c \n", ' ', ' ', ' ');
	printf(" %c %c %c \n", '1', '2', '3');
	printf(" %c %c %c \n", '2', '1', 0);
	printf(" %c %c %c \n", 0, '1', '2');
	return (0);
}