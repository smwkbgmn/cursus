/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:44:11 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:51:52 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int		check_validation(char *str);
int		fstrlen(char *str);
void	print_number(int num, char *base);
int		ft_atoi(char *str);

void	ft_atoi_base(char *sting, char *base)
{
	int	number;

	if (check_validation (base))
		return ;
	number = ft_atoi(string);
	print_number (number, base);
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
	while (cnt < size - 1)
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

int	ft_atoi(char *str)
{
	int	sign;
	int	number;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
		else
			str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number * sign);
}
