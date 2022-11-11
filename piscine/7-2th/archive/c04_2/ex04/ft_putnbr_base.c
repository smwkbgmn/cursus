/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:44:00 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/08 21:07:09 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int		check_validation(char *str);
int		fstrlen(char *str);
void	print_number(int num, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_validation (base))
		return ;
	print_number (nbr, base);
}

int	check_validation(char *str)
{
	int	size;
	int	cnt;
	int	check;

	size = fstrlen (str);
	if (size <= 1)
		return (1);
	cnt = 0;
	while (cnt < size)
	{
		if (str[cnt] == '+' || str[cnt] == '-')
			return (1);
		check = cnt + 1;
		while (str[cnt] != str[check] && str[check])
			check++;
		if (check != size)
			return (1);
		cnt++;
	}
	return (0);
}

int	fstrlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}		

void	print_number(int num, char *base)
{
	int	length_base;

	length_base = fstrlen (base);
	if (num == -2147483648)
	{
		print_number (num / length_base, base);
		write (1, &base[(num % length_base) * -1], 1);
	}
	else if (num < 0)
	{
		write (1, &"-", 1);
		num *= -1;
		print_number (num / length_base, base);
		write (1, &base[num % length_base], 1);
	}
	else if (num >= length_base)
	{
		print_number (num / length_base, base);
		write (1, &base[num % length_base], 1);
	}
	else
		write (1, &base[num % length_base], 1);
}
