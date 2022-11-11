/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:03:29 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 00:32:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	idx;

	if (argc <= 1)
		return (0);
	argc--;
	while (argc > 0)
	{
		idx = 0;
		while (argv[argc][idx])
			write(1, &argv[argc][idx++], 1);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
