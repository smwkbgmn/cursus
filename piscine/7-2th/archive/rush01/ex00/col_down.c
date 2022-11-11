/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:57:49 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 21:44:06 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

/*
#include "./set_default.c"
#include "./print_table.c"
#include "./check_seeing.c"
#include "./swap_row.c"
*/


void	col_down(int input[4][4], int table[4][4], int offset)
{
	int	first;
	int moving;
	int seeing;
	int max;

	first = 3;
	seeing = 1;
	moving = 2;
	
	max = table[first][offset];
	while (moving >= 0)
	{
		printf ("input table, moving : %d, seeing : %d, max : %d\n", moving, seeing, max);
		print_table (table);

		if (check_seeing_col (table, offset, moving, &max) == 1)
			seeing++;
		
		else if (table[moving][offset] < max && seeing < input[1][offset])
		{
			swap_row(moving + 1, moving, table);
			set_default(&moving, &seeing, 1);
			max = table[first][offset];
		}
		
		if (seeing > input[1][offset])
		{
			swap_row(moving + 1, moving, table);
			set_default(&moving, &seeing, 1);
			max = table[first][offset];
		}
		moving--;
	}
}

			

