#include "main.h"

char	shift_odd_letter_case(unsigned int idx, char letter);
void	shift_odd_letter_case_iterri(unsigned int idx, char *letter);

int	main(void)
{
	// ft_substr
	printf("\n[ft_substr]\n");
	
	char origin[50] = "abcde 12345\0";
	int idx_start, len;

	printf("origin string\t[%s]\n", origin);
	printf("start\t\t[%d]\nlen\t\t[%d]\n", idx_start = 3, len = 5);
	printf("result\t\t[%s]\n", ft_substr(origin, idx_start, len));


	// ft_strjoin
	printf("\n[ft_strjoin]\n");

	char s1[50] = "HELLO";
	char s2[50] = "WORLD";

	printf("s1\t\t[%s]\n", s1);
	printf("s2\t\t[%s]\n", s2);
	printf("result\t\t[%s]\n", ft_strjoin(s1, s2));


	// ft_strtrim
	printf("\n[ft_strtrim]\n");

	char set[10] = " Hlowh ";

	strcpy(origin, " Hello World ? ");
	printf("origin string\t[%s]\n", origin);
	printf("set\t\t[%s]\n", set);
	printf("result\t\t[%s]\n", ft_strtrim(origin, set));


	// ft_split
	printf("\n[ft_split]\n");

	char **result;

	strcpy(origin, ",,,,a, b,,,c ,d22,,,");
	printf("origin string\t[%s]\n", origin);
	printf("delimiter\t[%c]\n", ',');

	result = ft_split(origin, ',');
	printf("result\t\t");
	while (*result)
		printf("[%s]", *result++);
	printf("\n");


	// ft_itoa
	printf("\n[ft_itoa]\n");

	printf("-2147483648\t[%s]\n", ft_itoa(-2147483648));
	printf("-345\t\t[%s]\n", ft_itoa(-345));
	printf("0\t\t[%s]\n", ft_itoa(0));
	printf("345\t\t[%s]\n", ft_itoa(345));
	printf("2147483647\t[%s]\n", ft_itoa(2147483647));


	// ft_strmapi
	printf("\n[ft_strmapi]\n");

	strcpy(origin, "aaaaaaaaaaa");
	printf("origin string\t[%s]\n", origin);
	printf("result\t\t[%s]\n", ft_strmapi(origin, &shift_odd_letter_case));


	// ft_striteri
	printf("\n[ft_striteri]\n");

	strcpy(origin, "bbbbbbbbbbb");
	printf("origin string\t[%s]\n", origin);
	ft_striteri(origin, &shift_odd_letter_case_iterri);
	printf("result\t\t[%s]\n", origin);


	////////////////////////////////////////////////////////////////////////


	// ft_putchar_fd
	printf("\n[ft_putchar_fd]\n");
	
	system("touch test.txt");

	int fd;

	fd = open("test.txt", O_WRONLY);
	ft_putchar_fd('A', fd);
	ft_putchar_fd('\n', fd);
	printf("* below text is a result of command \"cat -e\"\n");
	system("cat -e test.txt");
	close(fd);


	// ft_putstr_fd
	printf("\n[ft_putstr_fd]\n");
	
	fd = open("test.txt", O_WRONLY);
	ft_putstr_fd("B\n", fd);
	system("cat -e test.txt");
	close(fd);


	// ft_putendl_fd
	printf("\n[ft_putendl_fd]\n");
	
	fd = open("test.txt", O_WRONLY);
	ft_putendl_fd("Hello There !!", fd);
	// notice that there is no newline in the string passed as argument
	// newline must be included at the end of the string on result
	system("cat -e test.txt");
	close(fd);


	// ft_putnbr_fd
	printf("\n[ft_putnbr_fd]\n");
	
	fd = open("test.txt", O_WRONLY);
	ft_putnbr_fd(-2147483648, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(-345, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(0, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(345, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(2147483647, fd);
	write(fd, "\n", 1);
	system("cat -e test.txt");
	close(fd);

	system("rm test.txt");
}

char	shift_odd_letter_case(unsigned int idx, char letter)
{
	if (idx % 2 == 1)
	{
		if ('a' <= letter && letter <= 'z')
			return (letter - 32);
		else if ('a' <= letter && letter <= 'Z')
			return (letter + 32);
	}
	return (letter);
}

void	shift_odd_letter_case_iterri(unsigned int idx, char *letter)
{
	if (idx % 2 == 1)
	{
		if ('a' <= *letter && *letter <= 'z')
			*letter -= 32;
		else if ('a' <= *letter && *letter <= 'Z')
			*letter += 32;
	}
}		