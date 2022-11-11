/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:30:39 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 21:54:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**get_answer(char *input);

int	check_value(int idx, char **argv)
{
	if (idx != 2)
		return (1);
	idx = 0;
	while (argv[1][idx])
		idx++;
	if (idx != 31)
		return (1);
	idx = 0;
	while (idx <= 30)
	{
		if (!(argv[1][idx] >= '1' && argv[1][idx] <= '4'))
			return (1);
		idx += 2;
	}
	idx = 1;
	while (idx <= 29)
	{
		if (argv[1][idx] != ' ')
			return (1);
		idx += 2;
	}
	return (0);
}

int	check_input(char **argv)
{
	int		col;
	int		row;
	char	num1;
	char	num2;

	col = 0;
	row = 16;
	while (col <= 6)
	{
		num1 = argv[1][col] + argv[1][col + 8] - '0';
		if (!(num1 >= '3' && num1 <= '5'))
			return (1);
		num2 = argv[1][row] + argv[1][row + 8] - '0';
		if (!(num2 >= '3' && num2 <= '5'))
			return (1);
		row += 2;
		col += 2;
	}
	return (0);
}

void	char_in_arr(char **argv, char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < 16)
	{
		str[k] = argv[1][i];
		k++;
		i += 2;
	}
	return ;
}

void	print(int **answer)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			write(1, &"01234"[answer[r][c]], 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int	main(int argc, char *argv[])
{
	int		**answer;
	int		idx_free;
	char	*str;

	if (check_value(argc, argv) || check_input(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * 17);
	char_in_arr(argv, str);
	answer = get_answer(str);
	if (answer[3][3] == 0)
		write(1, "Error\n", 6);
	else
		print(answer);
	free(str);
	idx_free = 0;
	while (idx_free < 4)
		free(answer[idx_free++]);
	free(answer);
	return (0);
}
