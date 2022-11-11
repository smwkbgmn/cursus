#include <unistd.h>
#include <stdlib.h>

char *search(char **input);
int cmp_to_others(char **input, char *buf);
int ft_strcmp(char *str, char *to_find);
void ft_strncat(char *dest, char *src, int n);

int main(int ac, char **av)
{
	char *result;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
			result = *av;
		else
			result = search(av);
		while (*result)
			write(1, result++, 1);
	}
	write(1, "\n", 1);

	return (0);
}

char *search(char **input)
{
	char *buf;
	int len;
	int idx;

	len = 0;
	while ((*input)[len])
		len++;

	buf = malloc(sizeof(char) * (len + 1));

	while (len > 0)
	{
		idx = 0;
		while ((*input)[idx + len - 1])
		{	
			ft_strncat(buf, (*input) + idx, len);
			if (cmp_to_others(input, buf) == 1)
				return (buf);
			idx++;
		}
		len--;
	}
	*buf = 0;
	return (buf);
}

int cmp_to_others(char **input, char *buf)
{
	input++;
	while (*input)
	{
		if (ft_strcmp(*input, buf) == 0)
			return (0);
		input++;
	}
	return (1);
}

int ft_strcmp(char *str, char *to_find)
{
	int idx;

	while (*str)
	{
		idx = 0;
		while (str[idx] == to_find[idx] && *str)
			idx++;
		if (to_find[idx] == 0)
			return (1);
		str++;
	}
	return (0);
}

void ft_strncat(char *dest, char *src, int n)
{
	while (n-- > 0)
		*dest++ = *src++;
	*dest = 0;
}