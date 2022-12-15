/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:37 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/23 17:57:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_len(long long n);
static char	*convert(long long n, int len);

char	*ft_itoa(int n)
{
	return (convert((long long)n, get_len((long long)n)));
}

static int	get_len(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*convert(long long n, int len)
{
	char	*n_str;

	n_str = malloc(len + 1);
	if (n_str == 0)
		return (0);
	n_str[len--] = 0;
	if (n == 0)
		n_str[0] = '0';
	if (n < 0)
	{
		n_str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		n_str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (n_str);
}
