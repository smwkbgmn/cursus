/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:23:53 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/11 22:07:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_base(char *str, char *base, int radix);
char			*ft_itoa_base(long long nbr, char *base, int radix);
static int		base_valid(char *base, int *radix);
static int		is_there_same(char *str);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbr_int;
	int	rdx_from;
	int	rdx_to;

	if (base_valid(base_from, &rdx_from) == 0
		|| base_valid(base_to, &rdx_to) == 0)
		return (0);
	nbr_int = ft_atoi_base(nbr, base_from, rdx_from);
	return (ft_itoa_base((long long)nbr_int, base_to, rdx_to));
}

static int	base_valid(char *base, int *radix)
{
	*radix = 0;
	while (base[*radix])
		*radix += 1;
	if (*radix < 2)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		if ((9 <= *base && *base <= 13) || *base == ' ')
			return (0);
		if (is_there_same(base) == 1)
			return (0);
		base++;
	}
	return (1);
}

static int	is_there_same(char *str)
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
