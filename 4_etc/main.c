#include <stdio.h>

int	main(void)
{
	int a = 0;
	int b = 0;
	while (a < 5)
	{
		b = 0;
		while (b < 3)
		{
			printf("%d, %d\n", a, b);
			if (a == 3 && b == 2)
				break ;
			else
				b++;
		}
		a++;
	}
}