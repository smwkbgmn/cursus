/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:40:43 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/06 15:47:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	get_len(unsigned long dec, char *base);
static char		*get_str(unsigned long dec, char *base, short len);

char	*ft_itoa_ulong_base(unsigned long dec, char *base)
{
	return (get_str(dec, base, get_len(dec, base)));
}

static short	get_len(unsigned long dec, char *base)
{
	short	radix;
	short	len;

	if (dec == 0)
		len = 1;
	else
	{
		len = 0;
		radix = ft_strlen(base);
		while (dec > 0)
		{
			dec /= radix;
			len++;
		}
	}
	return (len);
}

static char	*get_str(unsigned long dec, char *base, short len)
{
	char	*result;
	short	radix;

	if (dec == 0)
		result = ft_strdup("0");
	else
	{
		radix = ft_strlen(base);
		result = ft_calloc(len + 1, 1);
		if (result)
		{
			while (len > 0)
			{
				result[len - 1] = base[dec % radix];
				dec /= radix;
				len--;
			}
		}
	}
	return (result);
}
