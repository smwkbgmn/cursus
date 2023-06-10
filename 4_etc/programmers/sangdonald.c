#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// L : the level of a hamberger
// X : the quantity that Sangdo ate from bottom to top
// Level_L burger : B + level_(L - 1) + P + level_(L - 1) + B

long	get_cnt_pattie(int l, long x);
char		*get_the_burger(int l, int l_current, char *bg_prev);
char		*assemble(char *bg_prev);

int	main(int ac, char **av)
{
	ac++;

	printf("%ld", get_cnt_pattie(atoi(*(av + 1)), atol(*(av + 2))));
	return (0);
}

long	get_cnt_pattie(int l, long x)
{
	char	*bg_l;
	long	size_eat;
	long	cnt_pattie;

	printf("l --- %d, x --- %ld\n", l, x);
	// if (l == 0)
	// 	bg_l = strdup("P");
	// else if (l == 1)
	// 	bg_l = strdup("BPPPB");
	// else
	bg_l = get_the_burger(l, 0, strdup("P"));
	size_eat = x;
	cnt_pattie = 0;
	while (size_eat-- > 0 && *bg_l)
	{
		if (*bg_l == 'P')
			cnt_pattie++;
		bg_l++;
	}
	bg_l--;
	while (size_eat-- > 0 && *bg_l)
	{
		if (*bg_l == 'P')
			cnt_pattie++;
		bg_l--;
	}
	return (cnt_pattie);
}

char	*get_the_burger(int l, int l_current, char *bg_prev)
{
	char	*bg_final;
	char	*bg_current;

	printf("loop --- [%d]\n", l_current);
	bg_current = assemble(bg_prev);
	printf("bg_current === %s\n", bg_current);
	// free(bg_prev);
	if (l_current < l - 1)
	{
		bg_final = get_the_burger(l, ++l_current, bg_current);
		// free(bg_current);
	}
	else
		return (bg_current);
	return (bg_final);
}

char	*assemble(char *bg_prev)
{
	char	*berger;

	berger = calloc(1 + strlen(bg_prev) + 1 + strlen(bg_prev) + 2, 1);
	// berger = calloc(1 + strlen(bg_prev) + 2, 1);
	strcat(berger, "B");
	strcat(berger, bg_prev);
	strcat(berger, "P");
	strcat(berger, bg_prev);
	strcat(berger, "B");
	return (berger);
}