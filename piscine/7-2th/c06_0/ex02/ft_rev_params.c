/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:49:09 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/08 00:22:40 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **args)
{
	int	idx;

	while (argc > 1)
	{
		idx = 0;
		while (args[argc - 1][idx])
		{
			write (1, args[argc - 1] + idx, 1);
			idx++;
		}
		write (1, "\n", 1);
		argc--;
	}
	return (0);
}
