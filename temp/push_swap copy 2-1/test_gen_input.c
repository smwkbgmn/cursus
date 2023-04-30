/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gen_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:48:56 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/20 19:29:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEFAULT -1

void	generate(FILE *fp, int *ary, int size);
short	is_there_same(int *ary, int size, int n);

int	main(int ac, char **av)
{
	int		size;

	size = atoi(*(av + 1));
	if (ac > 1 && size > 0)
	{
		srand(time(0));
		generate(fopen("test_in", "w"), malloc(sizeof(int) * size), size);
	}
	return (0);
}

void	generate(FILE *fp, int *ary, int size)
{
	int	idx;
	int	n_rand;

	idx = 0;
	while (idx < size)
	{
		ary[idx] = DEFAULT;
		n_rand = rand() % size;
		if (!is_there_same(ary, size, n_rand))
		{
			ary[idx] = n_rand;
			if (idx + 1 != size)
				fprintf(fp, "%d ", ary[idx]);
			else
				fprintf(fp, "%d", ary[idx]);
			idx++;
		}
	}
	fclose(fp);
}

short	is_there_same(int *ary, int size, int n)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (ary[idx] == n)
			return (1);
		else if (ary[idx] == -1)
			break ;
		else
			idx++;
	}
	return (0);
}
