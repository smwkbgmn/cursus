/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:35:26 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/08 17:07:53 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define STR_SIZE 2

int	check_print_validation(char **map, char structure[4])
{
	int	row;
	int	col;
	int	idx;

	row = 0;
	while (map[row] != 0)
	{
		col = 0;
		while (map[row][col] != 0)
		{
			idx = 0;
			while (idx < STR_SIZE)
			{
				if (map[row][col] == structure[idx])
					break ;
				idx++;
			}
			if (idx == STR_SIZE)
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}
