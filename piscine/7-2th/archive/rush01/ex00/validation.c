/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:11:29 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/30 12:06:43 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	validation(int input[4][4], int table[4][4])
{
	int	moving;
	int max;
	int	check;
	int seeing_col;
	int seeing_row; 
	int offset;
	
	check = 0;

	offset = 0;
	while (offset < 4)
	{
		moving = 0;
		while (moving < 4)
		{
			if (check_seeing_col (table, offset, moving, &max) == 1)
				seeing_col++;
			if (check_seeing_row (table, offset, moving, &max) == 1) 
				seeing_row++;
			moving++;
		}
		if (input[0][offset] != seeing_col)
			check++;
		if (input[2][offset] != seeing_row)
			check++;
		offset++;
	}
	
	offset = 0;
	while (offset < 4)
	{
		moving = 0;
		while (moving >= 0)
		{
			if (check_seeing_col (table, offset, moving, &max) == 1)
				seeing_col++;
			if (check_seeing_row (table, offset, moving, &max) == 1)
				seeing_row++;
			moving++;
		}
		if (input[1][offset] != seeing_col)
			check++;
		if (input[3][offset] != seeing_row)
			check++;
		offset++;
	}

	printf("check : %d\n", check);

	return (check);
}			
