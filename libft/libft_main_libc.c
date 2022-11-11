#include "main.h"

int main(void)
{
	// isalpha
	printf("\n[isalpha]\n");

	char letter;
	
	letter = 'a';
	printf("input\t\t[%c]\n", letter);
	printf("origin\t\t[%d]\n", isalpha(letter));
	printf("ft\t\t[%d]\n\n", ft_isalpha(letter));

	letter = 'Z';
	printf("input\t\t[%c]\n", letter);
	printf("origin\t\t[%d]\n", isalpha(letter));
	printf("ft\t\t[%d]\n\n", ft_isalpha(letter));

	letter = '5';
	printf("input\t\t[%c]\n", letter);
	printf("origin\t\t[%d]\n", isalpha(letter));
	printf("ft\t\t[%d]\n\n", ft_isalpha(letter));

	letter = 0;
	printf("input\t\t[%c]\n", letter);
	printf("origin\t\t[%d]\n", isalpha(letter));
	printf("ft\t\t[%d]\n\n", ft_isalpha(letter));

	// toupper
	printf("\n[toupper]\n");

	letter = 'a';
	printf("input\t\t[%c]\n", letter);
	printf("origin\t\t[%d]\n", isalpha(letter));
	printf("ft\t\t[%d]\n\n", ft_isalpha(letter));

}