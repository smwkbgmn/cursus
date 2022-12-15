/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:37 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/12 20:01:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*convert(long n, int len);
static size_t	get_len(long n);

char	*ft_itoa(int n)
{
	return (convert((long)n, get_len((long)n)));
}

static char	*convert(long n, size_t len)
{
	char	*n_str;

	n_str = malloc(len + 1);
	if (!n_str)
		return (0);
	if (n == 0)
		ft_strcpy(n_str, "0\0");
	else
	{
		if (n < 0)
		{
			*n_str = '-';
			n *= -1;
		}
		n_str[len] = 0;
		while (n > 0)
		{
			n_str[len--] = n % 10;
			n /= 10;
		}
	}
	return (n_str);
}

static size_t	get_len(long n)
{
	size_t	len;

	if (n == 0)
		len = 1;
	else
	{
		if (n < 0)
		{
			len = 1;
			n *= -1;
		}
		else
			len = 0;
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}
