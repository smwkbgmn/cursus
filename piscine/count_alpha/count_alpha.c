#include <stdio.h>

int		is_alpha(char letter);
void	init(char *input, int *cnt);
void	print_cnt(int *cnt, char *input);
int		is_end(int *cnt);

int	main(int ac, char **av)
{
	int		cnt[26];
	int		idx;

	if (ac != 2)
	{
		printf("\n");
		return (0);
	}

	av++;
	init(*av, cnt);
	idx = 0;
	while ((*av)[idx])
	{
		if (is_alpha((*av)[idx]) == 1)
			cnt[(*av)[idx] - 'a']++;
		idx++;
	}
	print_cnt(cnt, *av);
}

int	is_alpha(char letter)
{
	if ('a' <= letter && letter <= 'z')
		return (1);
	else if ('A' <= letter && letter <= 'Z')
		return (2);
	return (0);
}

void	init(char *input, int *cnt)
{
	int idx;

	idx = 0;
	while (idx < 26)
		cnt[idx++] = 0;
	while (*input)
	{
		if (is_alpha(*input) == 2)
			*input += 32;
		input++;
	}
}

void	print_cnt(int *cnt, char *input)
{
	int	idx;

	while (*input)
	{
		idx = *input - 'a';
		if (is_alpha(*input) == 1 && cnt[idx] != 0)
		{
			printf("%d%c", cnt[idx], *input);
			cnt[idx] = 0;
			if (is_end(cnt) != 1)
				printf(", ");
		}
		input++;
	}
	printf("\n");
}

int	is_end(int *cnt)
{
	int idx;

	idx = 0;
	while (idx < 26 && cnt[idx] == 0)
		idx++;
	if (idx == 26)
		return (1);
	return (0);
}