/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:37 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/06 15:52:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_str(unsigned long n, size_t len);
static size_t	get_len(unsigned long n);

char	*ft_itoa_ulong(unsigned long n)
{
	return (get_str(n, get_len(n)));
}

static char	*get_str(unsigned long n, size_t len)
{
	char	*result;

	if (n == 0)
		result = ft_strdup("0");
	else
	{
		result = ft_calloc(len + 1, 1);
		if (result)
		{
			while (len > 0)
			{
				result[len - 1] = "0123456789"[n % 10];
				n /= 10;
				len--;
			}
		}
	}
	return (result);
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
