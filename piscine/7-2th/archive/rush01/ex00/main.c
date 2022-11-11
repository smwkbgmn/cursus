/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:14:13 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/30 12:14:04 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./initialize.c"
#include "./col_up.c"
#include "./col_down.c"
#include "./row_left.c"
#include "./row_right.c"

#include "./validation.c"

int	main(void)
{
	int	testinput[4][4] = {
		{1, 2, 3, 4},
		{2, 2, 2, 1},
		{4, 3, 2, 1},
		{1, 2, 2, 2}
		};

	int	table[4][4];
	int	offset;
	int val;

	initialize (table);

	//col_up (testinput, table, 0);
	//col_down (testinput, table, 0);
	//row_left (testinput, table, 0);
	//row_right (testinput, table, 0);


	val = 300;
	while (val-- > 0)
	{
		offset = 0;
		while (offset < 4)
		{
			col_up (testinput, table, offset);
			col_down (testinput, table, offset);
			row_left (testinput, table, offset);
			row_right (testinput, table, offset);
			offset++;
		}
	}
	
	//validation(testinput, table);

	
	//val = 0;
	//while (val == 1)
	//{
	//	val = validation (testinput, table);
	//}

	return (0);
}
