/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:11:20 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/28 17:41:32 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initialize(int table[4][4])
{
	int num;
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		num = row;
		col = 0;
		while (col < 4)
		{
			table[row][col] = num % 4 + 1;
			num++;
			col++;
		}
		row++;
	}
}
