/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:35:20 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 00:27:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			write(1, *argv, 1);
			*argv += 1;
		}
		write(1, "\n", 1);
		argv += 1;
	}
	return (0);
}
