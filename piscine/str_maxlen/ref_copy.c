#include <unistd.h>
#include <stdlib.h>

char *find_str(char *str1, char *str2);
int check_match(char *str1, char *str2, int len_prev);
char *ft_strndup(char *old, int n);
void ft_putstr(char *str);

int main(int ac, char **av)
{
	char *str;
	int idx;

	str = 0;
	if (ac > 1)
	{
		str = av[1];
		idx = 2;
		while (idx < ac)
		{
			str = find_str(str, av[idx]);
			idx++;
		}
		ft_putstr(str);
	}
	ft_putstr("\n");
	return (0);
}

char *find_str(char *str1, char *str2)
{
	char *match;
	int len_match;
	int len_new;
	int idx1;
	int idx2;

	match = 0;
	len_match = 0;
	idx1 = 0;
	while (str1[idx1])
	{
		idx2 = 0;
		while (str2[idx2])
		{
			len_new = check_match(str1 + idx1, str2 + idx2, len_match);
			if (len_new)
			{
				if (match)
					free(match);
				match = ft_strndup(str1 + idx1, len_new);
				len_match = len_new;
			}
			idx2++;
		}
		idx1++;
	}
	if (match == 0)
		return (0);
	return (match);
}

int check_match(char *str1, char *str2, int len_prev)
{
	int idx;

	idx = 0;
	while (str1[idx] && str2[idx] && (str1[idx] == str2[idx]))
		idx++;
	if (idx > len_prev)
		return (idx);
	return (0);
}

char *ft_strndup(char *old, int n)
{
	char *new;
	int idx;

	new = malloc(sizeof(char) * (n + 1));
	idx = 0;
	while (idx < n)
	{
		new[idx] = old[idx];
		idx++;
	}
	new[n] = 0;
	return (new);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}