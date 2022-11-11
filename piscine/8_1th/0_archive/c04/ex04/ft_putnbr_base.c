/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:11:43 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/01 21:03:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_valid(char *base, int radix);
int		is_there_same(char *str);
void	print_number(long long nbr, char *base, int radix);

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	radix = 0;
	while (base[radix])
		radix++;
	if (base_valid(base, radix) == 0)
		return ;
	print_number((long long)nbr, base, radix);
}

int	base_valid(char *str, int radix)
{
	if (radix < 2)
		return (0);
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		if (is_there_same(str) == 1)
			return (0);
		str++;
	}
	return (1);
}

int	is_there_same(char *str)
{
	char	letter;

	letter = *str++;
	while (*str)
	{
		if (letter == *str)
			return (1);
		str++;
	}
	return (0);
}

void	print_number(long long nbr, char *base, int radix)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_number(nbr * -1, base, radix);
	}
	else if (nbr < radix)
		write(1, &base[nbr % radix], 1);
	else
	{
		print_number(nbr / radix, base, radix);
		write(1, &base[nbr % radix], 1);
	}
}
