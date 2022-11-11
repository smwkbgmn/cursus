/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:14:01 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 20:33:07 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print_table.c"

void swap_row(int source, int target, int table[4][4]);
void swap_col(int source, int target, int table[4][4]);

void	check(int input[4][4], int table[4][4], int direction, int see_moving)
{
	printf ("input direction : %d, see_moving : %d\n", direction, see_moving);
	int	offset;
	int	moving;
	int seeing;

	int	first;
	int max;

	offset = 0;
	seeing = 1;

	if (direction == 0)
	{
		first = 0;
		moving = 1;
	}
	else if (direction == -1)
	{
		first = 3;
		moving = 2;
	}

	else if (direction < -1)
		return;

	while (see_moving < 2)
	{
		while (moving >= 0 && moving <= 3)
		{
			printf ("input moving : %d, seeing : %d\n", moving + 1, seeing);
			print_table (table);

			if (table[moving + direction][offset] > table[first][offset])
			{
				middle = first;
				exist = 0;

				if (direction == 0)
				{
					while (middle < moving)
					{
						if (table[middle][offset] > table[moving][offset])
							exist++;
						middle++;
					}
				}

				else
				{
					while (middle > moving)
					{
						if (table[middle][offset] > table[moving][offset])
							exist++;
						middle--;
					}
				}

				if (exist == 0)
					seeing++;
			}

			else if (table[moving + direction][offset] < table[first][offset])
			{
				swap_row (moving - 1, moving, table);

				if (direction == 0)
					moving = 0;
				else
					moving = 3;
				seeing = 1;
			}	

			if (seeing > input[see_moving][offset])
			{
				swap_row (moving - 1, moving, table);

				if (direction == 0)
					moving = 0;
				else
					moving = 3;
				seeing = 1;
			}		

			if (direction == 0)
				moving++;
			else
				moving--;
		}
		direction--;
		see_moving++;
		check (input, table, direction, see_moving);
	}
//	direction = 0;
}

void	swap_row(int source, int target, int table[4][4])
{
	int moving;
	int	temp;

	moving = 0;
	while (moving < 4)
	{
		temp = table[source][moving];
		table[source][moving] = table[target][moving];
		table[target][moving] = temp;
		moving++;
	}
}

void	swap_col(int source, int target, int table[4][4])
{
	int	moving;
	int temp;

	moving = 0;
	while (table[moving][source])
	{
		temp = table[moving][source];
		table[moving][source] = table[moving][target];
		table[moving][target] = temp;
		moving++;
	}
}

