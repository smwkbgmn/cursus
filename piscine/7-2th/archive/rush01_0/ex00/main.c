/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:14:13 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 17:36:28 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./initialize.c"
#include "./check.c"
// #include "./validation.c"
// #include "./print_table.c"

// #include <unistd.h>
// #include <stdio.h>

int	main(void)
{
	int	testinput[4][4] = {
		{2, 3, 2, 1},
		{3, 2, 2, 2},
		{4, 3, 2, 1},
		{1, 2, 2, 2}
		};

	int	table[4][4];
	int val;

	initialize (table);
	// print_table (table);

	// printf("\n\n");

	check (testinput, table, 0, 0);
	// print_table (table);
	
	/*
	val = 0;
	while (val == 1)
	{
		check (testinput, table);
		val = validation (testinput, table);
	}
	*/

	return (0);
}
