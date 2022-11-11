/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:57:49 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 21:57:12 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	row_right(int input[4][4], int table[4][4], int offset)
{
	int	first;
	int moving;
	int seeing;
	int max;

	first = 3;
	seeing = 1;
	moving = 2;
	
	max = table[offset][first];
	while (moving >= 0)
	{
		printf ("input table, moving : %d, seeing : %d, max : %d\n", moving, seeing, max);
		print_table (table);

		if (check_seeing_row (table, offset, moving, &max) == 1)
			seeing++;
		
		else if (table[offset][moving] < max && seeing < input[3][offset])
		{
			swap_col(moving + 1, moving, table);
			set_default(&moving, &seeing, 1);
			max = table[offset][first];
		}
		
		if (seeing > input[3][offset])
		{
			swap_col(moving + 1, moving, table);
			set_default(&moving, &seeing, 1);
			max = table[offset][first];
		}
		moving--;
	}
}

			

