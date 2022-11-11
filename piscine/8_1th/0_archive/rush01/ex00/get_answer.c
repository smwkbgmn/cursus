/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:02:14 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 22:51:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ary_malloc(void);
void	answer_default(int **answer);
void	get_input_int(char *input, int	**input_int);
void	finding(int	**answer, int **input_int);

int	**get_answer(char *input)
{
	int	**answer;
	int	**input_int;
	int	idx_free;

	answer = ary_malloc();
	input_int = ary_malloc();
	answer_default(answer);
	get_input_int(input, input_int);
	finding(answer, input_int);
	idx_free = 0;
	while (idx_free < 4)
		free(input_int[idx_free++]);
	free(input_int);
	return (answer);
}

int	**ary_malloc(void)
{
	int	**array;
	int	idx;

	array = (int **)malloc(4 * sizeof(int *));
	if (array == 0)
		return ((void *) 0);
	idx = 0;
	while (idx < 4)
	{
		array[idx] = (int *)malloc(4 * sizeof(int));
		if (array[idx] == 0)
			return ((void *)0);
		idx++;
	}
	return (array);
}

void	answer_default(int **answer)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			answer[r][c] = 0;
			c++;
		}
		r++;
	}
}

void	get_input_int(char *input, int	**input_int)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4 && *input)
		{
			if ('0' <= *input && *input <= '9')
			{
				input_int[r][c] = *input - '0';
				c++;
			}
			input++;
		}
		r++;
	}
}
