/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:56:27 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 21:48:54 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	futchar(char letter);

int	main(int argc, char **args)
{
	int	idx1;
	int	idx2;

	if (argc > 1)
	{
		idx1 = 1;
		while (idx1 < argc)
		{
			idx2 = 0;
			while (args[idx1][idx2])
			{
				futchar (args[idx1][idx2]);
				idx2++;
			}
			write (1, &"\n", 1);
			idx1++;
		}
	}
	return (0);
}

void	futchar(char letter)
{
	write (1, &letter, 1);
}
