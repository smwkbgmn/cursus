/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:14:23 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 21:35:45 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char letter1, char letter2, char letter3);

int	main(int argc, char **args)
{
	// input : ./a.out "12" "ab"
	if (argc != 0)
	{		
		char c1;
		char c2;
		char c3;

		c1 = *(*(args+0)+0); // first value of "./a.out"
		c2 = *(*(args+0)+1); // second value of "./a.out"
		c3 = *(*(args+0)+2); // third value of "./a.out"
		printer (c1, c2, c3);

		c1 = *(*(args+0)+0); // first value of "./a.out"
		c2 = *(*(args+1)+0); // first value of "12"
		c3 = *(*(args+2)+0); // first value of "ab"
		printer (c1, c2, c3);

		c1 = args[0][0]; // first value of "./a.out"
		c2 = args[0][1]; // second value of "./a.out"
		c3 = args[0][2]; // third value of "./a.out"
		printer (c1, c2, c3);

		c1 = args[0][0]; // first value of "./a.out"
		c2 = args[1][0]; // first value of "12"
		c3 = args[2][0]; // first value of "ab"
		printer (c1, c2, c3);

		c1 = *args[0]; // first address of "./a.out"
		c2 = *args[1]; // first address of "12"
		c3 = *args[2]; // first address of "ab"
		printer (c1, c2, c3);

		write (1, args[0]+6, 1); // last value of "./a.out"
		write (1, args[1]+0, 1); // first value of "12"
		write (1, args[2]+1, 1); // second value of "ab"
		write (1, &"\n", 1);

		write (1, *args, 1); // first value of "./a.out"
		write (1, *args+6, 1); // last value of "./a.out"
		write (1, &" ", 1);
		args++;
		write (1, *args, 1); // first value of "12"
		write (1, *args+1, 1); // secondd value of "12"
		write (1, &" ", 1);
		args++;
		write (1, *args, 1); // first value of "ab"
		write (1, *args+1, 1); // second value of "ab"
		write (1, &"\n", 1);


	}
	
	return (0);
}

void	printer(char letter1, char letter2, char letter3)
{
	write (1, &letter1, 1);
	write (1, &" ", 1);
	write (1, &letter2, 1);
	write (1, &" ", 1);
	write (1, &letter3, 1);
	write (1, &" ", 1);
	write (1, &"\n", 1);
}

