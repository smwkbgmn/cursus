#include <stdlib.h>
#include <string.h>

#define NUM(c) c - '0'

short	is_largest(const char *number, int len_rest);

char	*solution(const char *number, int k)
{
    char	*result;
	int		len;
	int		idx;

	len = strlen(number) - k;
	result = calloc(len + 1, 1);
	idx = 0;
	while (idx < len)
	{
		if (is_largest(number, len - idx))
			result[idx++] = *number;
		number++;
	}
    return (result);
}

short	is_largest(const char *number, int len_rest)
{
	int	num;

	num = NUM(*number);
	while (*(number + len_rest))
	{
		if (num < NUM(*++number))
			return (0);
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	char	n[20] = "4177252841";

	printf("input\t--- [%s]\n", n);
	printf("output\t--- [%s]\n", solution(n, 4));

	return (0);
}
