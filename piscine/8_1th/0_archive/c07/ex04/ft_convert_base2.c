/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:24:05 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 13:49:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_number(char letter, char *base);
int		get_size(long long nbr_from, int rdx_to);

int	ft_atoi_base(char *str, char *base, int radix)
{
	int	num;
	int	sign;
	int	idx;

	num = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_number(*str, base) == 1)
	{
		idx = 0;
		while (*str != base[idx])
			idx++;
		num = (num * radix) + idx;
		str++;
	}
	return (num * sign);
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

char	*ft_itoa_base(long long nbr, char *base, int radix)
{
	char	*nbr_str;
	int		size;

	size = get_size(nbr, radix);
	nbr_str = (char *)malloc(sizeof(char) * (size + 1));
	if (nbr_str == 0)
		return (0);
	nbr_str[size--] = 0;
	if (nbr == 0)
		nbr_str[0] = base[0];
	if (nbr < 0)
	{
		nbr_str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr_str[size] = base[nbr % radix];
		nbr /= radix;
		size--;
	}
	return (nbr_str);
}

int	get_size(long long nbr_from, int rdx_to)
{
	int	size;

	size = 0;
	if (nbr_from == 0)
		return (++size);
	if (nbr_from < 0)
	{
		nbr_from *= -1;
		size++;
	}
	while (nbr_from > 0)
	{
		nbr_from /= rdx_to;
		size++;
	}
	return (size);
}
