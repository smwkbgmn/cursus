/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:06:35 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 18:33:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	set_oper(long long (*f[5])(int, int));
int		get_oper(char oper);
int		valid_oper(char *av);

int	main(int ac, char **av)
{
	long long	(*f[5])(int, int);
	int			oper;

	if (ac != 4)
		return (0);
	if (valid_oper(av[2]) == 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	oper = get_oper(av[2][0]);
	set_oper(f);
	if (ft_atoi(av[3]) == 0 && (oper == 2 || oper == 4))
	{
		if (oper == 2)
			write(1, "Stop : division by zero\n", 24);
		if (oper == 4)
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_putnbr(f[oper](ft_atoi(av[1]), ft_atoi(av[3])));
	write(1, "\n", 1);
	return (0);
}

void	set_oper(long long (*f[5])(int, int))
{
	f[0] = &plus;
	f[1] = &minus;
	f[2] = &div;
	f[3] = &multiple;
	f[4] = &mod;
}

int	get_oper(char oper)
{
	char	opers[6];
	int		idx;

	ft_strcpy(opers, "+-/*%");
	idx = 0;
	while (opers[idx])
	{
		if (oper == opers[idx])
			return (idx);
		idx++;
	}
	return (0);
}

int	valid_oper(char *av)
{
	char	opers[6];
	int		idx;

	ft_strcpy(opers, "+-/*%");
	idx = 0;
	while (av[idx])
		idx++;
	if (idx != 1)
		return (0);
	if (*av == '+' || *av == '-')
		return (1);
	if (*av == '/' || *av == '*' || *av == '%')
		return (1);
	return (0);
}
