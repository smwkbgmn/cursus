/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:37 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/29 10:30:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*convert(unsigned long n, size_t len);
static size_t	get_len(unsigned long n);

char	*ft_itoa_long(unsigned long n)
{
	return (convert(n, get_len(n)));
}

static char	*convert(unsigned long n, size_t len)
{
	char	*n_str;

	n_str = malloc(len + 1);
	if (n_str)
	{
		if (n == 0)
			ft_strlcpy(n_str, "0", 2);
		else
		{
			n_str[len--] = 0;
			while (n > 0)
			{
				n_str[len--] = n % 10 + '0';
				n /= 10;
			}
		}
	}
	return (n_str);
}

static size_t	get_len(unsigned long n)
{
	size_t	len;

	if (n == 0)
		len = 1;
	else
	{
		len = 0;
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}
