/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:42:47 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/01 21:11:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str, char *base, int radix);
int	base_valid(char *base, int radix);
int	is_there_same(char *str);
int	is_number(char letter, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	radix;

	radix = 0;
	while (base[radix])
		radix++;
	if (base_valid(base, radix) == 0)
		return (0);
	return (ft_atoi(str, base, radix));
}

int	ft_atoi(char *str, char *base, int radix)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_number(*str, base) == 1)
	{
		num = (num * radix) + *str - *base;
		str++;
	}
	return (num * sign);
}

int	base_valid(char *str, int radix)
{
	if (radix < 2)
		return (0);
	while (*str)
	{
		if (*str == '+' || *str == '-' || *str == ' ')
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

int	is_number(char letter, char *base)
{
	while (*base)
	{
		if (letter == *base)
			return (1);
		base++;
	}
	return (0);
}
